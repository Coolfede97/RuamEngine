#include <iostream>

#include "RuamEngine.h"

#include "assets/scenes/MenuScene.cpp"
#include "assets/scenes/SandboxScene.cpp"
#include "assets/components/Manager.h"

using namespace RuamEngine;

int main()
{
	Renderer::Init();
	AudioSystem::init();
	
	{
		Input::SetWindow(Renderer::GetWindow());
		ImGui::CreateContext();
		ImGui_ImplGlfwGL3_Init(Renderer::GetWindow(), true);
		ImGui::StyleColorsDark();

		const unsigned int menuScene = SceneManager::AddScene(0, CreateMenuScene);
		SceneManager::SetActiveScene(menuScene);
		const unsigned int sandboxScene = SceneManager::AddScene(1, CreateSandboxScene);

		while (!glfwWindowShouldClose(Renderer::GetWindow()))
		{
			// ImGUI
			ImGui_ImplGlfwGL3_NewFrame();

			// OpenGL
			GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

			glfwPollEvents();

			// Input
			Input::UpdateInput();

			// Time
			ruamTime::Time::Update();

			Renderer::BeginDraw();

			EventManager::HandleEvents();

			if (SceneManager::ActiveScene() != nullptr)
			{
				SceneManager::ActiveScene()->update();
			}
			ImGui::Render();
			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

			Renderer::EndDraw();

			glfwPollEvents();
		}
	}
	// Cleanup
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	Renderer::Shutdown();
	AudioSystem::shutdown();

	return 0;
}
