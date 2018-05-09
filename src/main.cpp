
/**
 * Draws a single cube in front of the camera.
 * Toggles Projection matrix, and depth buffer.
 */

#define GLFW_INCLUDE_NONE

#include <iostream>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp> // ...so now that's defined we can import GLM itself.
#include "glm/gtc/matrix_transform.hpp" // Needed for the perspective() method

#include "App.h"

GLFWwindow* window;
int winX = 640;
int winY = 480;

App* TheApp;
    
void key_callback(GLFWwindow* window,
                  int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    TheApp->key_callback(key, action);
}

void error_callback(int error, const char* description){  std::cerr << description; }

void windowResize_callback(GLFWwindow *window, int x, int y) 
{
    TheApp->SetWindowSize(x, y);
    glViewport( 0, 0, x, y );
}

void initWindow() {
    glfwSetErrorCallback(error_callback);
    
    if (!glfwInit()) {
        exit(1);
    }

    // Specify that we want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create the window and OpenGL context
    window = glfwCreateWindow(winX, winY, "Here is a cube", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(1);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    
    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        exit(1);
    }

    // Callback functions
    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, windowResize_callback);
}

void initOpengl() {
    // Initialise OpenGL state
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CCW);
}

int main(int argc, char **argv)
{
    initWindow();
    initOpengl();
    TheApp = new App(winX, winY, argv[1]);

    while (!glfwWindowShouldClose(window))
    {
        TheApp->render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(0);

    return 0;
}   
