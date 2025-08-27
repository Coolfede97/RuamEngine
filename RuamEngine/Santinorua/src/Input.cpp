#include "Input.h"


GLFWwindow* Input::m_window = nullptr;
int key_callback;

bool Input::NullWindow()
{
    if (m_window == nullptr) return true;
    return false;
}

bool Input::GetKeyDown(KeyCode key) {
    // Return True if the key is down

    return glfwGetKey(m_window, key) == GLFW_PRESS;
}

bool Input::GetKeyUp(const KeyCode key) {
    // Return True if the key is up

    return glfwGetKey(m_window, key) == GLFW_RELEASE;
}

void Input::SetCursorMode(const CursorMode mode)
{
    glfwSetInputMode(m_window, GLFW_CURSOR, mode);
}

CursorMode Input::GetCursorMode() {
    return static_cast<CursorMode>(glfwGetInputMode(m_window, GLFW_CURSOR));
}

bool Input::GetButtonDown(MouseCode button) {
    // Return True if the mouse button is down

    return glfwGetMouseButton(m_window, button) == GLFW_PRESS;
}

bool Input::GetButtonUp(const MouseCode button) {
    // Return True if the key is up

    return glfwGetMouseButton(m_window, button) == GLFW_RELEASE;
}

void Input::KeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods) {
    // Handle key events
    if (action == GLFW_PRESS) {
        // Key pressed
        // std::cout << "Key pressed: " << key << std::endl;
        eventManager.Publish(OnKeyPressEvent(key));
    } else if (action == GLFW_RELEASE) {
        // Key released
        eventManager.Publish(OnKeyReleaseEvent(key));
    }
}

void Input::SetUp(GLFWwindow* window) {
    // Set the window pointer
    m_window = window;

}

void Input::UpdateInput() {
    if (NullWindow()) {
        return;
    }

    glfwSetKeyCallback(m_window, KeyEvent);

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