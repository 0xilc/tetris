#include "app/App.h"
#include "app/Input.h"
#include "screens/game/GameScreen.h"
#include <glm/gtc/type_ptr.hpp>

App::App() {}

App::~App()
{
    glfwTerminate();
}

void App::Init()
{
    m_WindowState.sizeX = 800;
    m_WindowState.sizeY = 600;
    m_WindowState.title = "tetris/demo";
    m_Camera.Resize(m_WindowState.sizeX, m_WindowState.sizeY);

    if (!glfwInit()) {
        throw ("GLFW initialization error");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    m_WindowState.window = glfwCreateWindow(m_WindowState.sizeX, m_WindowState.sizeY, m_WindowState.title.c_str(), NULL, NULL);
    if (!m_WindowState.window) {
        glfwTerminate();
        throw ("GLFW initialization error");
    }

    glfwMakeContextCurrent(m_WindowState.window);
    glfwSetWindowUserPointer(m_WindowState.window, this);

    if (GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        exit(-1);
    }

    glfwSwapInterval(1);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // GLFW Events
    glfwSetWindowSizeCallback(m_WindowState.window, [](GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
        App* game = (App*)glfwGetWindowUserPointer(window);
        game->m_WindowState.sizeX = width;
        game->m_WindowState.sizeY = height;
        // Update Projection matrix on resize
        game->Resize(width, height);
    });

    // Keyboard Events
    Input::Init(m_WindowState.window);
}

void App::Run()
{
    GameScreen gameScreen;
    UBOManager uboManager;
    uboManager.CreateUBO("CameraData", UBOBindingPoints::CAMERA_DATA, 2 * sizeof(glm::mat4));

    float currentFrame, lastFrame, deltaTime;
    lastFrame = glfwGetTime();

    while (!glfwWindowShouldClose(m_WindowState.window)) 
    {
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        m_Camera.SetUniforms(uboManager);
        gameScreen.Update(deltaTime);
        gameScreen.Render();
        glfwSwapBuffers(m_WindowState.window);
        glfwPollEvents();
    }
}

void App::Resize(int newWidth, int newHeight)
{
    m_Camera.Resize(newWidth, newHeight);
}
