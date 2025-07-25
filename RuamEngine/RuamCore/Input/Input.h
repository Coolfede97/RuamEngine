#pragma once
#include <string>
#include "Renderer.h"
#include "GLFW/glfw3.h"
#include "Camera.h"
#include "Vec3.h"
enum KeyCode
{
    // These values come from the ones of "glfw3.h"
    // Espaciado y entrada
    SpaceBar = 32,
    Quote = 39,     // Apostrophe
    Comma = 44,
    Minus = 45,
    Period = 46,
    Slash = 47,

    // Upper numbers (no numpad)
    Alpha0 = 48,
    Alpha1 = 49,
    Alpha2 = 50,
    Alpha3 = 51,
    Alpha4 = 52,
    Alpha5 = 53,
    Alpha6 = 54,
    Alpha7 = 55,
    Alpha8 = 56,
    Alpha9 = 57,

    Semicolon = 59,
    Equals = 61,

    // Letters
    A = 65, B, C, D, E, F, G, H, I, J,
    K, L, M, N, O, P, Q, R, S, T,
    U, V, W, X, Y, Z,

    LeftBracket = 91,
    Backslash = 92,
    RightBracket = 93,
    BackQuote = 96, // Grave accent

    // Function keys
    Escape = 256,
    Enter = 257,
    Tab = 258,
    Backspace = 259,
    Insert = 260,
    Delete = 261,
    RightArrow = 262,
    LeftArrow = 263,
    DownArrow = 264,
    UpArrow = 265,
    PageUp = 266,
    PageDown = 267,
    Home = 268,
    End = 269,

    CapsLock = 280,
    ScrollLock = 281,
    NumLock = 282,
    PrintScreen = 283,
    PauseBreak = 284,

    F1 = 290, F2, F3, F4, F5, F6,
    F7, F8, F9, F10, F11, F12,

    // Numpad
    Keypad0 = 320,
    Keypad1, Keypad2, Keypad3, Keypad4,
    Keypad5, Keypad6, Keypad7, Keypad8, Keypad9,
    KeypadPeriod = 330,
    KeypadDivide = 331,
    KeypadMultiply = 332,
    KeypadMinus = 333,
    KeypadPlus = 334,
    KeypadEnter = 335,
    KeypadEquals = 336,

    // Modifier keys
    LeftShift = 340,
    LeftControl = 341,
    LeftAlt = 342,
    LeftCommand = 343,  // GLFW_LEFT_SUPER
    RightShift = 344,
    RightControl = 345,
    RightAlt = 346,
    RightCommand = 347, // GLFW_RIGHT_SUPER

    Menu = 348
};

enum MouseMode
{
    // These values come from the ones of "glfw3.h"
    MouseNormal = 0x00034001,
    MouseHidden = 0x00034002,
    MouseDisabled = 0x00034003,
    MouseCaptured = 0x00034004
};
class Input
{
private:

    static GLFWwindow* m_window;
    static int m_windowWidth;
    static int m_windowHeight;

	static std::unordered_map<KeyCode, bool> m_keysPressed;
    static MouseMode m_currentMouseMode;
    
    static Vec3 m_mousePosPix;
    static Vec3 m_lastMousePosPix;
    static Vec3 m_mousePosNorm; // Mouse normalized position  (-1.0 <-> 1.0)
    static Vec3 m_lastMousePosNorm;

    static bool NullWindow();

public:

    static MouseMode GetCurrentMouseMode() { return Input::m_currentMouseMode; }
    static Vec3 GetMousePosPix() { return m_mousePosPix; }
    static Vec3 GetMousePosNorm() { return m_mousePosNorm; }
    static Vec3 GetMouseDelta() { return m_mousePosPix - m_lastMousePosPix; }
	static GLFWwindow* GetWindow() { return m_window; }
    static void SetMouseMode(MouseMode mode);
    static void SetWindow(GLFWwindow* newWindow) { m_window = newWindow; }
	static bool KeyPressed(KeyCode key) { return Input::m_keysPressed[key]; }
	static void UpdateInput();
    static void MouseCallback(GLFWwindow* p_window, double posX, double posY);	
};