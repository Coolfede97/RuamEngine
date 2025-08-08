#include "Sandbox.h"

#include "Renderer.h"
#include "imgui.h"
#include "VertexBufferLayout.h"
#include "Texture.h"
namespace test
{

	Sandbox::Sandbox()
	{
		Start();
	}

	Sandbox::~Sandbox()
	{

	}

	void Sandbox::Start()
	{
		GLCall(glClearColor(0.24f, 0.24f, 0.16f, 1.0f));

		
		auto quad = Vertex::CreateQuad(0.0f, 0.0f, 0.0f);
		Vertex vertices[4];
		memcpy(vertices, quad.data(), sizeof(vertices));
		
		//float quadVertices[40] = {
		//	// v0
		//	-0.5f, -0.5f, 0.0f,                 // position
		//	0.2f, 0.2f, 0.27f, 1.0f,            // color
		//	0.0f, 0.0f,                         // texCoords
		//	0.0f,                               // texID

		//	// v1
		//	0.5f, -0.5f, 0.0f,
		//	0.2f, 0.2f, 0.27f, 1.0f,
		//	1.0f, 0.0f,
		//	0.0f,

		//	// v2
		//	0.5f, 0.5f, 0.0f,
		//	0.2f, 0.2f, 0.27f, 1.0f,
		//	1.0f, 1.0f,
		//	0.0f,

		//	// v3
		//	-0.5f, 0.5f, 0.0f,
		//	0.2f, 0.2f, 0.27f, 1.0f,
		//	0.0f, 1.0f,
		//	0.0f
		//};


		m_VAO = new VertexArray();
		m_VBO = new VertexBuffer(quad.data(), sizeof(quad));
		/*
		float bufferData[40];
		glGetNamedBufferSubData(m_VBO->GetID(), 0, sizeof(bufferData), bufferData);
		std::cout << "Buffer Data: " << bufferData[5] << "\n";*/

		m_Layout = new VertexBufferLayout();
		m_Layout->Push<float>(3); // Position
		m_Layout->Push<float>(4); // Color
		m_Layout->Push<float>(2); // Texture Coordinates
		m_Layout->Push<float>(1); // Texture ID
		m_VAO->AddBuffer(*m_VBO, *m_Layout);

		unsigned int indices[] =
		{
			0, 1, 2,
			2, 3, 0
		};

		m_IBO = new IndexBuffer(indices, 6);

		m_Shader = new Shader("CoolFede97/res/shaders/basic/BasicVertex.txt", "CoolFede97/res/shaders/basic/BasicFragment.txt");
		m_Shader->Bind();


	}

	void Sandbox::Update()
	{

	}

	void Sandbox::Render()
	{
		m_Shader->Bind();
		m_VAO->Bind();
		glDrawElements(GL_TRIANGLES, m_IBO->GetCount(), GL_UNSIGNED_INT, nullptr);
	}

	void Sandbox::ImGuiRender()
	{
	}

}