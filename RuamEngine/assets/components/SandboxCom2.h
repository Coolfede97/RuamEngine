#pragma once

#include <Component.hpp>
#include "Renderer.h"
#include "Vertex.h"
#include "VertexBuffer.h"


using namespace RuamEngine;

class SandboxCom2 : public BaseRenderer
{
	using BaseRenderer::BaseRenderer;

	// It's called in update
	void render()
	{
		/*std::cout << "Render from component called\n";
		Renderer::m_basicDrawingData.m_vertexArray->Bind();

		auto quad = Vertex::CreateQuad(-0.5, -0.5);
		auto quadB = Vertex::CreateQuad(0.5f, 0.5f, Vec4(1.0f, 0.0f, 0.0f, 1.0f));

		std::vector<Vertex> vertices =
		{
			quad[0], quad[1], quad[2], quad[3],
			quadB[0], quadB[1], quadB[2], quadB[3]
		};

		std::vector<unsigned int> indices = {
			0, 1, 2,
			2, 3, 0,
			4, 5, 6,
			6, 7, 4
		};

		Renderer::m_basicDrawingData.m_layout->Reset();
		Renderer::m_basicDrawingData.m_layout->Push<float>(3);
		Renderer::m_basicDrawingData.m_layout->Push<float>(4);

		Renderer::m_basicDrawingData.AddBatchData(vertices, vertices.size() * sizeof(Vertex), indices, indices.size() * sizeof(unsigned int));
		Renderer::m_basicDrawingData.m_shader->Bind();
		glm::mat4 model = glm::mat4(1.0f);
		Renderer::m_basicDrawingData.m_shader->SetUniformMat4f("u_model", model);
		Renderer::m_basicDrawingData.m_shader->SetUniformMat4f("u_view", model);
		Renderer::m_basicDrawingData.m_shader->SetUniformMat4f("u_projection", model);*/
	};
	void update()
	{
		render();
	};

};
