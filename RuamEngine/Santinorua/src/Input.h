#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Vec2.h"
#include "Vec3.h"
#include "Renderer.h"
#include "EventManager.h"


const enum KeyCode {
    // These values come from the ones of "glfw3.h"
    // Espaciado y entrada
    SpaceBar_Key = 32,
    Quote_Key = 39,     // Apostrophe
    Comma_Key = 44,
    Minus_Key = 45,
    Period_Key = 46,
    Slash_Key = 47,

    // Upper numbers (no numpad)
    Key_0 = 48,
    Key_1 = 49,
    Key_2 = 50,
    Key_3 = 51,
    Key_4 = 52,
    Key_5 = 53,
    Key_6 = 54,
    Key_7 = 55,
    Key_8 = 56,
    Key_9 = 57,

    Semicolon_Key = 59,
    Equals_Key = 61,

    // Letters
    A_Key = 65, B_Key, C_Key, D_Key, E_Key, F_Key, G_Key, H_Key, I_Key, J_Key,
    K_Key, L_Key, M_Key, N_Key, O_Key, P_Key, Q_Key, R_Key, S_Key, T_Key,
    U_Key, V_Key, W_Key, X_Key, Y_Key, Z_Key,

    LeftBracket_Key = 91,
    Backslash_Key = 92,
    RightBracket_Key = 93,
    BackQuote_Key = 96,

    // Function keys
    Escape_Key = 256,
    Enter_Key = 257,
    Tab_Key = 258,
    Backspace_Key = 259,
    Insert_Key = 260,
    Delete_Key = 261,
    Right_Arrow = 262,
    Left_Arrow = 263,
    Down_Arrow = 264,
    Up_Arrow = 265,
    PageUp_Key = 266,
    PageDown_Key = 267,
    Home_Key = 268,
    End_Key = 269,

    CapsLock_Key = 280,
    ScrollLock_Key = 281,
    NumLock_Key = 282,
    PrintScreen_Key = 283,
    PauseBreak_Key = 284,

    F1_Key = 290, F2_Key, F3_Key, F4_Key, F5_Key, F6_Key,
    F7_Key, F8_Key, F9_Key, F10_Key, F11_Key, F12_Key,

    // Numpad
    Keypad_0 = 320,
    Keypad_1, Keypad_2, Keypad_3, Keypad_4,
    Keypad_5, Keypad_6, Keypad_7, Keypad_8, Keypad_9,
    Keypad_Period = 330,
    Keypad_Divide = 331,
    Keypad_Multiply = 332,
    Keypad_Minus = 333,
    Keypad_Plus = 334,
    Keypad_Enter = 335,
    Keypad_Equals = 336,

    // Modifier keys
    LeftShift_Key = 340,
    LeftControl_Key = 341,
    LeftAlt_Key = 342,
    LeftCommand_Key = 343,  // GLFW_LEFT_SUPER
    RightShift_Key = 344,
    RightControl_Key = 345,
    RightAlt_Key = 346,
    RightCommand_Key = 347, // GLFW_RIGHT_SUPER

    Menu_Key = 348
};

const enum MouseCode {
    Mouse_Left,
    Mouse_Right,
    Mouse_Middle,
    Mouse_Last = 7
};

enum CursorMode
{
    // These values come from the ones of "glfw3.h"
    MouseNormal = 0x00034001,
    MouseHidden = 0x00034002,
    MouseDisabled = 0x00034003,
    MouseCaptured = 0x00034004
};

class Input {
public:
    // Window
    static GLFWwindow* GetWindow() { return m_window; }
    static void SetWindow(GLFWwindow* newWindow) { m_window = newWindow; }

    // Keyboard
    static bool GetKeyDown(KeyCode key);
    static bool GetKeyUp(KeyCode key);
    

    //Mouse
    static void SetCursorMode(CursorMode mode);
    static CursorMode GetCursorMode();
    static bool GetButtonDown(MouseCode button);
    static bool GetButtonUp(MouseCode button);

    //void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

    // Not Implemented

    static Vec2 GetMousePosPix() { return m_mousePosPix; }
    static Vec2 GetMousePosNorm() { return m_mousePosNorm; }
    static Vec2 GetMouseDelta() { return m_mousePosPix - m_lastMousePosPix; }
    static void MouseCallback(GLFWwindow* p_window, double posX, double posY);



private:
    static GLFWwindow* m_window;
    static Vec2 m_mousePosPix;
    static Vec2 m_lastMousePosPix;
    static Vec2 m_mousePosNorm; // Mouse normalized position  (-1.0 <-> 1.0)
    static Vec2 m_lastMousePosNorm;

    void SetUp(GLFWwindow *window);
    static void UpdateInput();

    static void KeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods);
    static bool NullWindow();
};