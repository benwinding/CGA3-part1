#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "App.h"

#define VALS_PER_VERT 3
#define VALS_PER_COLOUR 4
#define CUBE_NUM_TRIS 12      // number of triangles in a cube (2 per face)
#define CUBE_NUM_VERTICES 8     // number of vertices in a cube`

App::App(int winX, int winY, char* objFilePath)
{    
    this->setShaders();
    this->SetWindowSize(winX, winY);
    this->obj = new ObjContainer(objFilePath);
    this->Camera = new ObjectViewer(glm::vec3(0,4,10));
}

void App::render() 
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    // Set shader
    simpleShader->use();
    // Set Uniforms
    simpleShader->setMat4("projection_matrix", projection);
    simpleShader->setMat4("modelview_matrix", this->Camera->getViewMtx());
    // Draw objs
    this->obj->Draw();
}

void App::setShaders() 
{
    std::string prefix = "res/";
    this->simpleShader = new Shader(prefix + "simple.vert", prefix + "simple.frag");
}

void App::key_callback(int key, int action)
{
    if (action == GLFW_PRESS) 
    {
    }
}   

int App::SetWindowSize(int x, int y)
{
    this->winX = x;
    this->winY = y;
    this->updateProjection();
}

void App::updateProjection()
{
    float aspect = (float) this->winX / this->winY;    
    float fov = 85;
    projection = glm::perspective(glm::radians(fov), aspect, 0.005f, 1000.0f );
}

void App::updateCamera() 
{
}