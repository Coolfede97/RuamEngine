#include <iostream>

#include "RuamEngine.h"

#include "scenes/MenuScene.cpp"
#include "scenes/TestScene.cpp"
#include "components/Manager.h"
using namespace RuamEngine;

int main(void)
{
	Renderer::Init();

	{
		Input::SetWindow(Renderer::GetWindow());
		ImGui::CreateContext();
		ImGui_ImplGlfwGL3_Init(Renderer::GetWindow(), true);
		ImGui::StyleColorsDark();

		std::shared_ptr<Scene> menuScene = CreateMenuScene();
		SceneManager::setActiveScene(*menuScene);
		SceneManager::addScene(*menuScene);
		std::shared_ptr<Scene> testScene = CreateTestScene();
		SceneManager::addScene(*testScene);

		while (!glfwWindowShouldClose(Renderer::GetWindow()))
		{
			// ImGUI
			ImGui_ImplGlfwGL3_NewFrame();

			// Input
			Input::UpdateInput();

			// Time
			ruamTime::Time::Update();

			Renderer::BeginDraw();

			if (SceneManager::activeScene() != nullptr)
			{
				SceneManager::activeScene()->update();
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
	return 0;
}
