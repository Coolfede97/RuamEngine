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

<<<<<<< HEAD
		while (!glfwWindowShouldClose(Renderer::GetWindow()))
		{
=======
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


		// Put Scenes here


		/*test::Test* currentTest = nullptr;
		test::TestMenu* testMenu = new test::TestMenu(currentTest);
		currentTest = testMenu;

		testMenu->RegisterTest<test::TestClearColor>("Clear Color");
		testMenu->RegisterTest<test::TestMovement>("Movement Test");
		testMenu->RegisterTest<test::Sandbox>("Sandbox");*/

		while (!glfwWindowShouldClose(window)) {
>>>>>>> refs/remotes/origin/main
			// ImGUI
			ImGui_ImplGlfwGL3_NewFrame();

			// OpenGL
			GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

			glfwPollEvents();

			// Input
			Input::UpdateInput();

			// Time
			ruamTime::Time::Update();

<<<<<<< HEAD
			Renderer::BeginDraw();
=======
			// Events
			EventManager::HandleEvents();
>>>>>>> refs/remotes/origin/main

			if (SceneManager::ActiveScene() != nullptr)
			{
				SceneManager::ActiveScene()->update();
			}
			ImGui::Render();
			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

<<<<<<< HEAD
			Renderer::EndDraw();

			glfwPollEvents();
=======
			glfwSwapBuffers(window);
>>>>>>> refs/remotes/origin/main
		}
	}
	// Cleanup
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	Renderer::Shutdown();
	AudioSystem::shutdown();

	return 0;
}
