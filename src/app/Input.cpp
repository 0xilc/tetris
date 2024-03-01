#include "app/Input.h"

GLFWwindow* Input::s_Window = nullptr;
std::unordered_map<int, bool> Input::s_KeysPressed;

void Input::Init(GLFWwindow* window) {
    s_Window = window;
    glfwSetKeyCallback(window, Input::KeyCallback);
}

void Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) 
    {
        s_KeysPressed[key] = true;
    }
    else if (action == GLFW_RELEASE) 
    {
        s_KeysPressed[key] = false;
    }
}

bool Input::IsKeyPressed(int key) 
{
    auto it = s_KeysPressed.find(key);
    if (it != s_KeysPressed.end()) {
        return it->second;
    }
    return false;
}
