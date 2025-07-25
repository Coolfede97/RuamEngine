#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <assert.h>

#include "Renderer.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h" 
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"
#include "Camera.h"
#include "RuamTime.h"

#include "GLM/glm.hpp"
#include "GLM/gtc/matrix_transform.hpp"
#include <filesystem>

#include "Vec3.h"

#include "imgui.h"
#include "imgui_impl_glfw_gl3.h"

#include "Input.h"

#include "tests/TestClearColor.h"

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	{

		/* Create a windowed mode window and its OpenGL context */
		window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
		Input::SetWindow(window);
		ImGui::CreateContext();
		ImGui_ImplGlfwGL3_Init(window, true);
		ImGui::StyleColorsDark();

		if (!window)
		{
			glfwTerminate();
			return -1;
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(window);

		glfwSwapInterval(1);

		if (glewInit() != GLEW_OK)
		{
			std::cout << "Error!" << "\n";
		}

		glEnable(GL_DEPTH_TEST);

		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		float vertices[] = {
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
		};

		glm::vec3 cubePositions[] = {
	glm::vec3(0.0f,  0.0f,  0.0f),
	glm::vec3(2.0f,  5.0f, -15.0f),
	glm::vec3(-1.5f, -2.2f, -2.5f),
	glm::vec3(-3.8f, -2.0f, -12.3f),
	glm::vec3(2.4f, -0.4f, -3.5f),
	glm::vec3(-1.7f,  3.0f, -7.5f),
	glm::vec3(1.3f, -2.0f, -2.5f),
	glm::vec3(1.5f,  2.0f, -2.5f),
	glm::vec3(1.5f,  0.2f, -1.5f),
	glm::vec3(-1.3f,  1.0f, -1.5f),
	glm::vec3(0.0f,   0.0f,   0.0f),
	glm::vec3(-2.0f,  -5.0f,  15.0f),
	glm::vec3(1.5f,   2.2f,   2.5f),
	glm::vec3(3.8f,   2.0f,  12.3f),
	glm::vec3(-2.4f,   0.4f,   3.5f),
	glm::vec3(1.7f,  -3.0f,   7.5f),
	glm::vec3(-1.3f,   2.0f,   2.5f),
	glm::vec3(-1.5f,  -2.0f,   2.5f),
	glm::vec3(-1.5f,  -0.2f,   1.5f),
	glm::vec3(1.3f,  -1.0f,   1.5f)

		};

		VertexArray va;
		VertexBuffer vb(vertices, 5 * 36 * sizeof(float));
		VertexBufferLayout layout;
		layout.Push<float>(3);
		layout.Push<float>(2);

		va.AddBuffer(vb, layout);

		Shader shader("CoolFede97/res/shaders/BasicVertex.glsl", "CoolFede97/res/shaders/BasicFragment.glsl");
		shader.Bind();

		Texture texture("CoolFede97/res/textures/francoKO.jpg");
		texture.Bind();
		// The second parameter is 0 because that's the slot where we've created the texture 
		// (that's why the ir no parameter in bind)
		shader.SetUniform1i("u_Texture", 0);

		shader.Unbind();

		Camera camera;
		ruamTime::Time time;

		test::TestClearColor test;

		while (!glfwWindowShouldClose(window))
		{
			// ImGUI
			ImGui_ImplGlfwGL3_NewFrame();

			Input::UpdateInput();
			if (Input::KeyPressed(KeyCode::SpaceBar)) Input::SetMouseMode(MouseMode::MouseDisabled);
			time.Update();

			test.OnUpdate(time.DeltaTime());
			test.OnRender();

			test.OnImGuiRender();

			shader.Bind();

			float camera_speed = 2.5f * time.DeltaTime();
			Input::MoveCamera(camera, camera_speed);

			shader.SetUniformMat4f("u_view", camera.GetViewMatrix());
			shader.SetUniformMat4f("u_projection", camera.GetProjectionMatrix());

			for (int i = 0; i < sizeof(cubePositions) / sizeof(cubePositions[0]); i++)
			{
				glm::mat4 model = glm::mat4(1.0f);
				//model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(1.0f, 1.0f, 1.0f));
				model = glm::translate(model, cubePositions[i]);
				shader.SetUniformMat4f("u_model", model);
				va.Bind();
				glDrawArrays(GL_TRIANGLES, 0, 36);
			}

			ImGui::Render();
			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

			glfwSwapBuffers(window);

			glfwPollEvents();

		}

	}
	// Cleanup
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
	return 0;
}