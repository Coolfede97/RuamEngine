#include <iostream>

#include "RuamEngine.h"

#include "assets/scenes/MenuScene.cpp"
#include "assets/scenes/SandboxScene.cpp"
#include "assets/components/Manager.h"

using namespace RuamEngine;

int main(void)
{
	Renderer::Init();

	{
		Input::SetWindow(Renderer::GetWindow());
		ImGui::CreateContext();
		ImGui_ImplGlfwGL3_Init(Renderer::GetWindow(), true);
		ImGui::StyleColorsDark();

		const unsigned int menuScene = SceneManager::addScene(0, CreateMenuScene);
		SceneManager::setActiveScene(menuScene);
		const unsigned int sandboxScene = SceneManager::addScene(1, CreateSandboxScene);

		while (!glfwWindowShouldClose(Renderer::GetWindow()))
		{
			// ImGUI
			ImGui_ImplGlfwGL3_NewFrame();

			// Input
			Input::UpdateInput();

			// Time
			ruamTime::Time::Update();

			Renderer::BeginDraw();

			SceneManager::update();
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
	return 0;
}
