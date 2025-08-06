#pragma once

#include "Test.h"
#include "GLM/glm.hpp"
#include "GLM/gtc/matrix_transform.hpp"
#include "Camera.h"
#include "Renderer.h"
#include "Input.h"
#include "Time.h"
#include "imgui.h"
#include "Texture.h"
#include "VertexBufferLayout.h"

namespace test
{
	class TestMovement : public Test
	{
	public:
		TestMovement();
		~TestMovement();
		void Start() override;
		void Update() override;
		void Render() override;
		void ImGuiRender() override;
		void MoveCamera();
	private:

		float* m_CubeLocalVertices;
		glm::vec3* m_CubeGlobalPositions;

		VertexArray* m_VAO;
		VertexBuffer* m_VBO;
		VertexBufferLayout* m_Layout;
		Shader* m_Shader;
		Camera* m_Camera;
		float m_CubeGlobalPositionsCount;
		float m_CameraSpeed;
	};
}