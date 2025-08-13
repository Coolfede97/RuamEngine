// RuamEngine.cpp : Defines the entry point for the application.
//

#include "RuamEngine.h"

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
		window = glfwCreateWindow(640, 480, "Cool Game", NULL, NULL);
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


		// Put Scenes here


		/*test::Test* currentTest = nullptr;
		test::TestMenu* testMenu = new test::TestMenu(currentTest);
		currentTest = testMenu;

		testMenu->RegisterTest<test::TestClearColor>("Clear Color");
		testMenu->RegisterTest<test::TestMovement>("Movement Test");
		testMenu->RegisterTest<test::Sandbox>("Sandbox");*/

		while (!glfwWindowShouldClose(window))
		{
			// ImGUI
			ImGui_ImplGlfwGL3_NewFrame();

			// Input
			Input::UpdateInput();

			// Time
			ruamTime::Time::Update();

			// OpenGL
			GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

			/*if (currentTest)
			{
				currentTest->Update();
				currentTest->Render();
				ImGui::Begin("Test");
				if (currentTest != testMenu && ImGui::Button("<-"))
				{
					delete currentTest;
					currentTest = testMenu;
				}
				currentTest->ImGuiRender();
				ImGui::End();
			}*/

			ImGui::Render();
			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

			glfwSwapBuffers(window);

			glfwPollEvents();

		}
		/*delete currentTest;
		if (currentTest != testMenu)
			delete testMenu;*/

	}
	// Cleanup
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
	return 0;
}
