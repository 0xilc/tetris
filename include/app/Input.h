#pragma once
#include <unordered_map>
#include "GL/glew.h"
#include <GLFW/glfw3.h>

class Input
{
public:
    static void Init(GLFWwindow *window);
    static void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
    static bool IsKeyPressed(int key);

private:
    static GLFWwindow *s_Window;
    static std::unordered_map<int, bool> s_KeysPressed;
};
