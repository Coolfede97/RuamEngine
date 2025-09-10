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
		Renderer::m_basicDrawingData.m_vertexArray->Bind();

		auto quad = Vertex::CreateQuad(-0.5, -0.5);
		auto quadB = Vertex::CreateQuad(0.5f, 0.5f, Vec4(1.0f, 0.0f, 0.0f, 1.0f));

		std::cout << "READ FROM HERE: " << quad[1].m_position << "\n";
		std::cout << "READ FROM HERE: " << quad[1].m_color << "\n";


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

		//Renderer::m_basicDrawingData.m_vertexBuffer->AddBatchData(&quad, sizeof(quad));
		//Renderer::m_basicDrawingData.m_vertexBuffer->AddBatchData(&quadB, sizeof(quadB));
		Renderer::m_basicDrawingData.m_layout->Reset();
		Renderer::m_basicDrawingData.m_layout->Push<float>(3);
		Renderer::m_basicDrawingData.m_layout->Push<float>(4);

		Renderer::m_basicDrawingData.AddBatchData(vertices, vertices.size() * sizeof(Vertex), indices, indices.size() * sizeof(unsigned int));
		Renderer::m_basicDrawingData.m_shader = std::make_shared<Shader>("assets/shaders/GeneralVertexShader.glsl", "assets/shaders/GeneralFragmentShader.glsl");
		Renderer::m_basicDrawingData.m_shader->Bind();
		glm::mat4 model = glm::mat4(1.0f);
		Renderer::m_basicDrawingData.m_shader->SetUniformMat4f("u_model", model);
		Renderer::m_basicDrawingData.m_shader->SetUniformMat4f("u_view", model);
		Renderer::m_basicDrawingData.m_shader->SetUniformMat4f("u_projection", model);

		//Renderer::Draw(Renderer::m_basicDrawingData);
		//GLCall(glDrawElements(GL_TRIANGLES, Renderer::m_basicDrawingData.m_indexBuffer->GetIndexCount(), GL_UNSIGNED_INT, nullptr));


		//Renderer::m_basicDrawingData.m_vertexArray->Bind();
		//Renderer::m_basicDrawingData.m_shader->Bind();
		//Renderer::m_basicDrawingData.m_indexBuffer->Bind();

		//Renderer::Draw();

		/*std::cout << "Size of vertex buffer: " << Renderer::m_basicDrawingData.m_vertexBuffer->GetSize() << "\n";
		std::cout << "Size of index buffer: " << Renderer::m_basicDrawingData.m_indexBuffer->GetSize() << "\n";
		std::cout << "Update function called\n";*/
	};
	void update() 
	{
		render();
		//auto quad = Vertex::CreateQuad(-0.5, -0.5);
		//auto quadB = Vertex::CreateQuad(0.5f, 0.5f, Vec4(1.0f, 0.0f, 0.0f, 1.0f));

		//Vertex vertices[] =
		//{
		//	quad[0], quad[1], quad[2], quad[3],
		//	quadB[0], quadB[1], quadB[2], quadB[3]
		//};

		//unsigned int indices[] = {
		//	0, 1, 2,
		//	2, 3, 0,
		//	4, 5, 6,
		//	6, 7, 4
		//};

		//VertexArray va;
		//va.Bind();

		//VertexBuffer vb(vertices, 8 * sizeof(Vertex));
		//vb.Bind();

		//VertexBufferLayout layout;
		//layout.Push<float>(3);
		//layout.Push<float>(4);

		//va.AddBuffer(vb, layout);

		//IndexBuffer ib(nullptr, 12);
		//ib.SetSubData(indices, 0, sizeof(indices));

		//Shader shader("assets/shaders/GeneralVertexShader.glsl", "assets/shaders/GeneralFragmentShader.glsl");
		//shader.Bind();
		//glm::mat4 model = glm::mat4(1.0f);
		//shader.SetUniformMat4f("u_model", model);
		//shader.SetUniformMat4f("u_view", model);
		//shader.SetUniformMat4f("u_projection", model);

		//GLCall(glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, nullptr));

		///*std::cout << "Size of vertex buffer: " << Renderer::m_basicDrawingData.m_vertexBuffer->GetSize() << "\n";
		//std::cout << "Size of index buffer: " << Renderer::m_basicDrawingData.m_indexBuffer->GetSize() << "\n";
		//std::cout << "Update function called\n";*/

	};

};
