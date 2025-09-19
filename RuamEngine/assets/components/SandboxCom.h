#pragma once

#include <Component.hpp>
#include "Renderer.h"
#include "Vertex.h"
#include "VertexBuffer.h"


using namespace RuamEngine;

class SandboxCom : public BaseRenderer
{
	using BaseRenderer::BaseRenderer;
	
	int gridSide = 50; // k*k grid
	float padding = 0.01f;
	float screenX = 2.0f;
	float screenY = 2.0f;

	float quadWidth = screenX / gridSide - padding / 2;
	float quadHeight = screenY / gridSide - padding / 2;

	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	unsigned int indexCount = 0;

	// It's called in update
	void render()
	{
		Renderer::m_basicDrawingData.m_vertexArray->Bind();

		vertices.reserve(gridSide * gridSide * 4);
		indices.reserve(gridSide * gridSide * 6);


		Renderer::m_basicDrawingData.m_shader->Bind();
		glm::mat4 model = glm::mat4(1.0f);
		Renderer::m_basicDrawingData.m_shader->SetUniformMat4f("u_model", model);
		Renderer::m_basicDrawingData.m_shader->SetUniformMat4f("u_view", model);
		Renderer::m_basicDrawingData.m_shader->SetUniformMat4f("u_projection", model);	

		for (int row = 0; row < gridSide; row++)
		{
			for (int col = 0; col < gridSide; col++)
			{				
				auto newQuad = Vertex::CreateQuad
				(
					quadWidth,
					col * (screenX / gridSide - 0.5f * padding) + col * padding + quadWidth / 2 - screenX / 2,
					row * (screenY / gridSide - 0.5f * padding) + row * padding + quadHeight / 2 - screenY / 2
				);
				vertices.insert(vertices.end(), newQuad.begin(), newQuad.end());
				
				std::vector<unsigned int> newIndices =
				{
					indexCount + 0, indexCount + 1, indexCount + 2,indexCount + 2, indexCount + 3, indexCount + 0
				};

				indices.insert(indices.end(), newIndices.begin(), newIndices.end());

				indexCount += 4;

				if (sizeof(Vertex) * vertices.size() + sizeof(Vertex) * 4 >= Renderer::m_basicDrawingData.m_vertexBuffer->GetMaxSize()
					||
					sizeof(unsigned int) * indices.size() + sizeof(unsigned int) * 6 >= Renderer::m_basicDrawingData.m_indexBuffer->GetMaxSize()
					)
				{
					if (Renderer::m_basicDrawingData.AddBatchData(vertices, vertices.size() * sizeof(Vertex), indices, indices.size() * sizeof(unsigned int)))
					{
						vertices.clear();
						indices.clear();
						indexCount = 0;
					}
				}
			}
		}
	};
	void update() 
	{
		render();
	};

};
