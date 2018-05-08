
/**
 * Draws a single cube in front of the camera.
 * Toggles Projection matrix, and depth buffer.
 */

#define GLFW_INCLUDE_NONE

#include <iostream>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Shader.h"

GLFWwindow* window;
int winX = 640;
int winY = 480;

#define VALS_PER_VERT 3
#define VALS_PER_COLOUR 4
#define CUBE_NUM_TRIS 12      // number of triangles in a cube (2 per face)
#define CUBE_NUM_VERTICES 8     // number of vertices in a cube`

Shader* simpleShader;
unsigned int cubeVaoHandle;
GLuint programID;

static void SetCamera()
{
    glm::mat4 projection;
    float aspect = (float) winX / winY;    
    projection = glm::perspective( (float)M_PI/4, aspect, 3.0f, 10.0f );

    // Load it to the shader program
    simpleShader->setMat4("projection_matrix", projection);        
}

void key_callback(GLFWwindow* window,
                  int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

void error_callback(int error, const char* description){  std::cerr << description; }

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

    // Set up callback functions and start our main loop
    glfwSetKeyCallback(window, key_callback);
}

void initOpengl() {
    // Initialise OpenGL state
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CCW);
}

void setShaders() {
    // Load shader and vertex data
    simpleShader = new Shader("res/simple.vert", "res/simple.frag");
}

unsigned int createVAO() {
    float Vertices[] = {
        // Positions            // Normals           // Texture Coords
        // far front
        -1.0f, -1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   0.0f,  0.0f, // 1
        1.0f, -1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   1.0f,  0.0f, // 2
        1.0f,  1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   1.0f,  1.0f, // 3
        1.0f,  1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   1.0f,  1.0f, // 3
        -1.0f,  1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   0.0f,  1.0f, // 4
        -1.0f, -1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   0.0f,  0.0f, // 1

        // near front
        1.0f,  -1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   0.0f,  0.0f, // b
        -1.0f, -1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   1.0f,  0.0f, // a
        -1.0f,  1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   1.0f,  1.0f, // d
        -1.0f,  1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   1.0f,  1.0f, // d
        1.0f,   1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   0.0f,  1.0f, // c
        1.0f,  -1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   0.0f,  0.0f, // b

        // left
        -1.0f, -1.0f,  1.0f,   -1.0f,  0.0f,  0.0f,  0.0f,  0.0f, // a
        -1.0f, -1.0f, -1.0f,   -1.0f,  0.0f,  0.0f,  1.0f,  0.0f, // 1
        -1.0f,  1.0f, -1.0f,   -1.0f,  0.0f,  0.0f,  1.0f,  1.0f, // 4
        -1.0f,  1.0f, -1.0f,   -1.0f,  0.0f,  0.0f,  1.0f,  1.0f, // 4
        -1.0f,  1.0f,  1.0f,   -1.0f,  0.0f,  0.0f,  0.0f,  1.0f, // d
        -1.0f, -1.0f,  1.0f,   -1.0f,  0.0f,  0.0f,  0.0f,  0.0f, // a

        // right
        1.0f, -1.0f, -1.0f,    1.0f,  0.0f,  0.0f,   0.0f,  0.0f, // 2
        1.0f, -1.0f,  1.0f,    1.0f,  0.0f,  0.0f,   1.0f,  0.0f, // b
        1.0f,  1.0f,  1.0f,    1.0f,  0.0f,  0.0f,   1.0f,  1.0f, // c
        1.0f,  1.0f,  1.0f,    1.0f,  0.0f,  0.0f,   1.0f,  1.0f, // c
        1.0f,  1.0f, -1.0f,    1.0f,  0.0f,  0.0f,   0.0f,  1.0f, // 3
        1.0f, -1.0f, -1.0f,    1.0f,  0.0f,  0.0f,   0.0f,  0.0f, // 2 

        // floor
        -1.0f, -1.0f, -1.0f,   0.0f, -1.0f,  0.0f,   0.0f,  1.0f, // 1
        1.0f, -1.0f, -1.0f,   0.0f, -1.0f,  0.0f,   1.0f,  1.0f, // 2
        1.0f, -1.0f,  1.0f,   0.0f, -1.0f,  0.0f,   1.0f,  0.0f, // b
        1.0f, -1.0f,  1.0f,   0.0f, -1.0f,  0.0f,   1.0f,  0.0f,
        -1.0f, -1.0f,  1.0f,   0.0f, -1.0f,  0.0f,   0.0f,  0.0f, // a
        -1.0f, -1.0f, -1.0f,   0.0f, -1.0f,  0.0f,   0.0f,  1.0f,

        //sky
        -1.0f,  1.0f,  1.0f,   0.0f,  1.0f,  0.0f,   0.0f,  1.0f, // d
        1.0f,  1.0f,  1.0f,   0.0f,  1.0f,  0.0f,   1.0f,  1.0f, // c
        1.0f,  1.0f, -1.0f,   0.0f,  1.0f,  0.0f,   1.0f,  0.0f, // 3
        1.0f,  1.0f, -1.0f,   0.0f,  1.0f,  0.0f,   1.0f,  0.0f, // 3
        -1.0f,  1.0f, -1.0f,   0.0f,  1.0f,  0.0f,   0.0f,  0.0f, // 4
        -1.0f,  1.0f,  1.0f,   0.0f,  1.0f,  0.0f,   0.0f,  1.0f  // d
    };
    unsigned int vaoHandle;
    glGenVertexArrays(1, &vaoHandle);
    glBindVertexArray(vaoHandle);

    unsigned int buffer;
    glGenBuffers(1, &buffer);

    // Set vertex attribute Postion
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 0));

    // Set vertex attribute Normal
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 3));

    // Set vertex attribute Texture Coordinates
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 6));

    // Un-bind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    return vaoHandle;
}
void setVertices() {
    cubeVaoHandle = createVAO();
}

void render() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    simpleShader->use();
    glBindVertexArray(cubeVaoHandle);

    glm::mat4 cameraMatrix;
    cameraMatrix = glm::translate(cameraMatrix, glm::vec3(0.0f, 0.0f, -5.0f));
    simpleShader->setMat4("modelview_matrix", cameraMatrix);

    glDrawArrays(GL_TRIANGLES, 0, CUBE_NUM_VERTICES);

    glBindVertexArray(0);
    glFlush();
}

int main(int argc, char **argv)
{
    initWindow();
    initOpengl();
    setShaders();
    setVertices();

    while (!glfwWindowShouldClose(window))
    {
        SetCamera();
        render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(0);

    return 0;
}   
