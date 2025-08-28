#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "input.h"

int main(void) {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    Input::SetWindow(window);
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    /* Loop until the user closes the window */


    // Test event subscriptions
    Input::eventManager.Subscribe<OnKeyPressEvent>([](const OnKeyPressEvent& event) {
        std::cout << "Key Pressed: " << event.key << std::endl;
    });

    Input::eventManager.Subscribe<OnKeyReleaseEvent>([](const OnKeyReleaseEvent& event) {
        std::cout << "Key Released: " << event.key << std::endl;
    });

    //Input::SetCursorMode(MouseDisabled);
    while (!glfwWindowShouldClose(window))
    {

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        // Update input
        Input::UpdateInput();

        //std::cout << "Mouse Position: " << Input::GetCursorPosPix().x << ", " << Input::GetCursorPosPix().y << std::endl;
        //std::cout << "Mouse Normalized: " << Input::GetCursorPosNorm().x << ", " << Input::GetCursorPosNorm().y << std::endl;



        Input::eventManager.HandleEvents();
    }

    glfwTerminate();
    return 0;
}