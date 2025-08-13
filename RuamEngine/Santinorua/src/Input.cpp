#include "Input.h"

MouseType Input::m_currentMouseType = MouseType::MouseNormal;

GLFWwindow* Input::m_window = nullptr;
int Input::m_windowWidth = 0;
int Input::m_windowHeight = 0;


bool Input::NullWindow()
{
    if (m_window == nullptr) return true;
    return false;
}

bool Input::GetKeyDown(KeyCode key) {
    // Return True if the key is down

    ASSERT(!NullWindow()); // Input::SetWindow() must be called as soon as the window is created.

    const int state = glfwGetKey(m_window, key);
    return state == GLFW_PRESS;
}

bool Input::GetKeyUp(KeyCode key) {
    // Return True if the key is down

    ASSERT(!NullWindow()); // Input::SetWindow() must be called as soon as the window is created.

    const int state = glfwGetKey(m_window, key);
    return state == GLFW_RELEASE;
}

void Input::SetMouseType(MouseType type)
{
    m_currentMouseType = type;
    glfwSetInputMode(m_window, GLFW_CURSOR, type);
}

// void Input::MouseCallback(GLFWwindow* p_window, double posX, double posY)
// {
//     glfwGetWindowSize(m_window, &m_windowWidth, &m_windowHeight);
//
//     m_lastMousePosPix = m_mousePosPix;
//     m_mousePosPix = Vec2(posX - m_windowWidth / 2.0f, (m_windowHeight / 2.0f) - posY);
//
//     m_lastMousePosNorm = m_mousePosNorm;
//     m_mousePosNorm = Vec2(posX / (m_windowWidth / 2.0f) - 1.0f, 1.0f - (posY / (m_windowHeight / 2.0f)));
//
// }