#include "Input.h"


std::unordered_map<KeyCode, bool> Input::m_keysPressed = {
    {SpaceBar, false}, {Quote, false}, {Comma, false}, {Minus, false}, {Period, false}, {Slash, false},
    {Alpha0, false}, {Alpha1, false}, {Alpha2, false}, {Alpha3, false}, {Alpha4, false},
    {Alpha5, false}, {Alpha6, false}, {Alpha7, false}, {Alpha8, false}, {Alpha9, false},
    {Semicolon, false}, {Equals, false},
    {A, false}, {B, false}, {C, false}, {D, false}, {E, false}, {F, false}, {G, false}, {H, false}, {I, false}, {J, false},
    {K, false}, {L, false}, {M, false}, {N, false}, {O, false}, {P, false}, {Q, false}, {R, false}, {S, false}, {T, false},
    {U, false}, {V, false}, {W, false}, {X, false}, {Y, false}, {Z, false},
    {LeftBracket, false}, {Backslash, false}, {RightBracket, false}, {BackQuote, false},
    {Escape, false}, {Enter, false}, {Tab, false}, {Backspace, false}, {Insert, false}, {Delete, false},
    {RightArrow, false}, {LeftArrow, false}, {DownArrow, false}, {UpArrow, false},
    {PageUp, false}, {PageDown, false}, {Home, false}, {End, false},
    {CapsLock, false}, {ScrollLock, false}, {NumLock, false},
    {PrintScreen, false}, {PauseBreak, false},
    {F1, false}, {F2, false}, {F3, false}, {F4, false}, {F5, false}, {F6, false},
    {F7, false}, {F8, false}, {F9, false}, {F10, false}, {F11, false}, {F12, false},
    {Keypad0, false}, {Keypad1, false}, {Keypad2, false}, {Keypad3, false}, {Keypad4, false},
    {Keypad5, false}, {Keypad6, false}, {Keypad7, false}, {Keypad8, false}, {Keypad9, false},
    {KeypadPeriod, false}, {KeypadDivide, false}, {KeypadMultiply, false}, {KeypadMinus, false},
    {KeypadPlus, false}, {KeypadEnter, false}, {KeypadEquals, false},
    {LeftShift, false}, {LeftControl, false}, {LeftAlt, false}, {LeftCommand, false},
    {RightShift, false}, {RightControl, false}, {RightAlt, false}, {RightCommand, false},
    {Menu, false}
};
MouseMode Input::m_currentMouseMode = MouseMode::MouseNormal;

GLFWwindow* Input::m_window = nullptr;
int Input::m_windowWidth = 0;
int Input::m_windowHeight = 0;

Vec3 Input::m_mousePosPix = Vec3::Zero();
Vec3 Input::m_lastMousePosPix = Vec3::Zero();
Vec3 Input::m_mousePosNorm = Vec3::Zero();// Mouse normalized position  (-1.0 <-> 1.0)
Vec3 Input::m_lastMousePosNorm = Vec3::Zero();

bool Input::NullWindow()
{
    if (m_window == nullptr) return true;
    return false;
}

void Input::SetMouseMode(MouseMode mode)
{
	glfwSetInputMode(m_window, GLFW_CURSOR, mode);
}

void Input::UpdateInput()
{
	ASSERT(!NullWindow()); // ASSERT if there is no window. Input::SetWindow() must be called as soon as the window is created.
    for (const auto& pair : m_keysPressed)
    {
        m_keysPressed[pair.first] = glfwGetKey(m_window, pair.first) == GLFW_PRESS;
    }
}

void Input::MouseCallback(GLFWwindow* p_window, double posX, double posY)
{
    glfwGetWindowSize(m_window, &m_windowWidth, &m_windowHeight);

    m_lastMousePosPix = m_mousePosPix;
    m_mousePosPix = Vec3(posX - m_windowWidth / 2.0f, (m_windowHeight / 2.0f) - posY);

    m_lastMousePosNorm = m_mousePosNorm;
    m_mousePosNorm = Vec3(posX / (m_windowWidth / 2.0f) - 1.0f, 1.0f - (posY / (m_windowHeight / 2.0f)));

}

