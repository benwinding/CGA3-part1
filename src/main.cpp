#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "App.h"

int winX = 700;
int winY = 500;

App* TheApp;
bool helpActive = true;

GLFWwindow* window;

// Called when the window is resized.
void reshape_callback(GLFWwindow *window, int x, int y) 
{
    TheApp->SetWindowSize(x, y);
    glViewport( 0, 0, x, y );
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

/**
 * Parse program arguments, read maze file, create maze object
 */
int ParseAndReadMazeFile(int argc, char **argv)
{
    std::ifstream infile;
    int mazeSize;
    int* mazeLayout;
    // Parse program arguments
    if(argc > 1) {
        if(argc == 3)
            helpActive = false;
        // Get first argument in argument array
        char* fileName = argv[1];
        std::cout << "Program input: " << fileName << '\n';
        try {
            TheApp = new App(winX, winY, fileName);
        } catch (std::exception const &e) {
            // If bad argument is provided, exit
            std::cout << "Bad filename recieved, exitting..." << std::endl;
            return 0;
        }
    }
    else {
        // If no argument is provided, exit
        std::cout << "No filename recieved, exitting..." << std::endl;
        return 0;
    }
    return 1;
}

void printHelp() 
{
    const char * helpScreen = R"V0G0N(
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        ~~~~ Welcome 2 Assignment 3! ~~~~
        ~~~~~~~~~~~~ Part 1 ~~~~~~~~~~~~~
        ~~~~~~~~ By Ben Winding ~~~~~~~~~
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    Usage: 
        ./assign3_part1 OBJ1 ... OBJN

    Keyboard:

    )V0G0N";
    if(helpActive)
        std::cout << helpScreen << std::endl;
}

void key_callback(GLFWwindow* window,
    int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE)
        glfwSetWindowShouldClose(window, GL_TRUE);

    TheApp->key_callback(key, action);
}

void setWindow()
{
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
    window = glfwCreateWindow(winX, winY, "Assignment 2: Maze", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(1);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    
    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) 
    {
        fprintf(stderr, "Failed to initialize GLEW\n");
        exit(1);
    }

    // Define callback functions and start main loop
    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, reshape_callback);
}   

void setOpenGlState()
{
    // Set OpenGL state we need for this application.
    glClearColor(0.5F, 0.5F, 0.5F, 0.5F);
    glEnable(GL_DEPTH_TEST);
}

int main (int argc, char **argv)
{
    // Print program help
    printHelp();
    setWindow();
    // Parse program arguments and read maze
    if (!ParseAndReadMazeFile(argc, argv)) 
    {
        exit(1);
    }
    setOpenGlState();
   
    while (!glfwWindowShouldClose(window))
    {
        TheApp->render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up
    delete TheApp;
    
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(0);
    
    return 0;
}
