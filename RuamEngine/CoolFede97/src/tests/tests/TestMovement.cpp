#include "TestMovement.h"

#include "Test.h"
#include "GLM/glm.hpp"
#include "GLM/gtc/matrix_transform.hpp"
#include "Camera.h"
#include "Renderer.h"
#include "Input.h"
#include "RuamTime.h"
namespace test
{
	TestMovement::TestMovement()
		: m_cameraSpeed(2.0f)
	{

	}

	TestMovement::~TestMovement()
	{

	}

	void TestMovement::Update()
	{

	}

	void TestMovement::Render()
	{

	}

	void TestMovement::ImGuiRender()
	{
		ImGui::SliderFloat("Camera Speed", &m_cameraSpeed, 2.0, 10.0f);
	}

	void TestMovement::MoveCamera(Camera& camera)
	{
		glm::vec3 camera_dir = camera.m_direction;
		glm::vec3 camera_up = camera.m_up;
		if (glm::length(glm::cross(camera_dir, camera_up)) == 0.0f)
			std::cout << "Error: camera_dir and camera_up can't be parallel (because it results in a NaN when normalizing 0)" << "\n";
		glm::vec3 direction = glm::vec3(0.0f, 0.0f, 0.0f);
		if (glfwGetKey(Input::GetWindow(), GLFW_KEY_D) == GLFW_PRESS)
		{
			direction += glm::normalize(glm::cross(camera_dir, camera_up));
		}
		if (glfwGetKey(Input::GetWindow(), GLFW_KEY_A) == GLFW_PRESS)
		{
			direction -= glm::normalize(glm::cross(camera_dir, camera_up));
		}
		if (glfwGetKey(Input::GetWindow(), GLFW_KEY_W) == GLFW_PRESS)
		{
			direction += camera_dir;
		}
		if (glfwGetKey(Input::GetWindow(), GLFW_KEY_S) == GLFW_PRESS)
		{
			direction -= camera_dir;
		}
		camera.m_position += direction * m_cameraSpeed * ruamTime::Time::DeltaTime();
	}

}