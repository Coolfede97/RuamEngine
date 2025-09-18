#pragma once

#include <Component.hpp>
#include "Renderer.h"
#include "Vertex.h"
#include "VertexBuffer.h"


using namespace RuamEngine;

class SandboxCom : public BaseRenderer
{
	using BaseRenderer::BaseRenderer;
	
	// It's called in update
	void render()
	{
		std::cout << "Render from component called\n";
		Renderer::m_basicDrawingData.m_vertexArray->Bind();

		int gridSide = 50; // k*k grid
		float padding = 0.01f;
		float screenX = 2.0f;
		float screenY = 2.0f;

		float quadWidth = screenX / gridSide - padding / 2;
		float quadHeight = screenY / gridSide - padding / 2;

		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;

		/*vertices.reserve(50000 * 4);
		indices.reserve(50000 * 6);*/

		Renderer::m_basicDrawingData.m_layout->Reset();
		Renderer::m_basicDrawingData.m_layout->Push<float>(3);
		Renderer::m_basicDrawingData.m_layout->Push<float>(4);

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
				
				unsigned int baseIndex = (row * gridSide + col) * 4;

				indices.push_back(baseIndex + 0);
				indices.push_back(baseIndex + 1);
				indices.push_back(baseIndex + 2);
				indices.push_back(baseIndex + 2);
				indices.push_back(baseIndex + 3);
				indices.push_back(baseIndex + 0);
				Renderer::m_basicDrawingData.AddBatchData(vertices, vertices.size() * sizeof(Vertex), indices, indices.size() * sizeof(unsigned int));
				vertices.clear();
				indices.clear();
			}
		}
	};
	void update() 
	{
		render();
	};

};
