#include <iostream>

#include "RuamEngine.h"

#include "scenes/MenuScene.cpp"
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

		Scene menuScene("Menu Scene");
		Object& manager = menuScene.newObject();
		manager.addComponent<Manager>();
		SceneManager::setActiveScene(menuScene);
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

				ImGui::Begin("Test");
				ImGui::End();
			}
			ImGui::Render();
			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

			Renderer::EndDraw();

			glfwPollEvents();

		}
		/*delete currentTest;
		if (currentTest != testMenu)
			delete testMenu;*/

	}
	// Cleanup
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	Renderer::Shutdown();
	return 0;
}
