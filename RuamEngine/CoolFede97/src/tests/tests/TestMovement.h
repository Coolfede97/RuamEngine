#pragma once

#include "Test.h"
#include "GLM/glm.hpp"
#include "GLM/gtc/matrix_transform.hpp"
#include "Camera.h"
#include "Renderer.h"
#include "Input.h"
#include "Time.h"
#include "imgui.h"

namespace test
{
	class TestMovement : public Test
	{
	public:
		TestMovement();
		~TestMovement();
		void Update() override;
		void Render() override;
		void ImGuiRender() override;
		void MoveCamera(Camera& camera);
		float m_cameraSpeed;
	};
}