//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//#include <assert.h>
//using namespace std;
//
//#include "Renderer.h"
//
//#include "VertexBuffer.h"
//#include "VertexBufferLayout.h"
//#include "IndexBuffer.h" 
//#include "VertexArray.h"
//#include "Shader.h"
//#include "Texture.h"
//
//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//
//#include "imgui/imgui.h"
//#include "imgui/imgui_impl_glfw_gl3.h"
//
//int main(void)
//{
//    GLFWwindow* window;
//
//    /* Initialize the library */
//    if (!glfwInit())
//        return -1;
//
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    {
//
//        /* Create a windowed mode window and its OpenGL context */
//        window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
//        if (!window)
//        {
//            glfwTerminate();
//            return -1;
//        }
//
//        /* Make the window's context current */
//        glfwMakeContextCurrent(window);
//
//        glfwSwapInterval(1);
//
//        if (glewInit() != GLEW_OK)
//        {
//            cout << "Error!" << "\n";
//        }
//
//        glEnable(GL_DEPTH_TEST);
//
//        GLCall(glEnable(GL_BLEND));
//        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
//
//		float vertices[] = {
//	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//		};
//
//		glm::vec3 cubePositions[] = {
//	glm::vec3(0.0f,  0.0f,  0.0f),
//	glm::vec3(2.0f,  5.0f, -15.0f),
//	glm::vec3(-1.5f, -2.2f, -2.5f),
//	glm::vec3(-3.8f, -2.0f, -12.3f),
//	glm::vec3(2.4f, -0.4f, -3.5f),
//	glm::vec3(-1.7f,  3.0f, -7.5f),
//	glm::vec3(1.3f, -2.0f, -2.5f),
//	glm::vec3(1.5f,  2.0f, -2.5f),
//	glm::vec3(1.5f,  0.2f, -1.5f),
//	glm::vec3(-1.3f,  1.0f, -1.5f),
//	glm::vec3(0.0f,   0.0f,   0.0f),
//	glm::vec3(-2.0f,  -5.0f,  15.0f),
//	glm::vec3(1.5f,   2.2f,   2.5f),
//	glm::vec3(3.8f,   2.0f,  12.3f),
//	glm::vec3(-2.4f,   0.4f,   3.5f),
//	glm::vec3(1.7f,  -3.0f,   7.5f),
//	glm::vec3(-1.3f,   2.0f,   2.5f),
//	glm::vec3(-1.5f,  -2.0f,   2.5f),
//	glm::vec3(-1.5f,  -0.2f,   1.5f),
//	glm::vec3(1.3f,  -1.0f,   1.5f)
//
//		};
//
//        VertexArray va;
//        VertexBuffer vb(vertices, 5 * 36 * sizeof(float));
//        VertexBufferLayout layout;
//        layout.Push<float>(3);
//        layout.Push<float>(2);
//
//        va.AddBuffer(vb, layout);
//
//
//        Shader shader("res/shaders/BasicVertex.glsl", "res/shaders/BasicFragment.glsl");
//        shader.Bind();
//
//        Texture texture("res/textures/francoKO.jpg");
//        texture.Bind();
//        // The second parameter is 0 because that's the slot where we've created the texture 
//        // (that's why the ir no parameter in bind)
//        shader.SetUniform1i("u_Texture", 0);
//
//        shader.Unbind();
//
//
//		ImGui::CreateContext();
//		ImGui_ImplGlfwGL3_Init(window, true);
//		ImGui::StyleColorsDark();
//
//		float r = 0;
//		float g = 0;
//		float b = 0;
//		float speed  = 10;
//
//		glm::vec3 translation(0, 0, 0);
//        while (!glfwWindowShouldClose(window))
//        {
//
//			ImGui_ImplGlfwGL3_NewFrame();
//
//			{
//				ImGui::SliderFloat3("Translation", &translation.x, 0.0f, 10.0f);
//				ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
//			}
//
//
//			r = (sin(glfwGetTime() * 10.0f) + 1.0f) / 2.0f;
//			g = (sin(glfwGetTime() * 4.0f + 2.0f) + 1.0f) / 2.0f;
//			b = (sin(glfwGetTime() * 4.0f + 4.0f) + 1.0f) / 2.0f;
//
//			glClearColor(r, g, b, 1.0f);
//			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//            shader.Bind();
//
//
//			glm::mat4 view = glm::mat4(1.0f);
//			view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
//			shader.SetUniformMat4f("u_view", view);
//
//			glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
//			shader.SetUniformMat4f("u_projection", projection);
//
//            for (int i = 0; i < sizeof(cubePositions)/sizeof(cubePositions[0]); i++)
//            {
//				glm::mat4 model = glm::mat4(1.0f);
//				model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(1.0f, 1.0f, 1.0f));
//				model = glm::translate(model, cubePositions[i]+translation);
//				shader.SetUniformMat4f("u_model", model);
//				va.Bind();
//				glDrawArrays(GL_TRIANGLES, 0, 36);
//            }
//
//			ImGui::Render();
//			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
//
//
//            glfwSwapBuffers(window);
//
//            glfwPollEvents();
//
//        }
//
//    }
//	ImGui_ImplGlfwGL3_Shutdown();
//	ImGui::DestroyContext();
//    glfwTerminate();
//    return 0;
//}