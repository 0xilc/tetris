#pragma once
#include "GL/glew.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "rendering/TextureLoader.h"
#include "rendering/Material.h"
#include "rendering/UBOManager.h"

struct WindowState
{
    int sizeX;
    int sizeY;
    std::string title;
    GLFWwindow *window;
};

class App
{
public:
    App();
    ~App();
    void Init();
    void Run();

private:
    void Resize(int newWidth, int newHeight);
    WindowState m_WindowState;
    Camera m_Camera;
};