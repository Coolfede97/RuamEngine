#pragma once

#include "Test.h"
#include "Renderer.h"
#include <Vertex.h>

namespace test
{
	class Sandbox : public Test
	{
	public:
		Sandbox();
		~Sandbox();
		
		void Start() override;	
		void Update() override;
		void Render() override;
		void ImGuiRender() override;
	private:

		float* m_SquareLocalVertices;

		VertexArray* m_VAO;
		VertexBuffer* m_VBO;
		VertexBufferLayout* m_Layout;
		Shader* m_Shader;
		};
}