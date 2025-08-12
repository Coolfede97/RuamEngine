#include "Input.h"



bool getKeyDown(GLFWwindow* window, int key) {
    int state = glfwGetKey(window, key);
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}