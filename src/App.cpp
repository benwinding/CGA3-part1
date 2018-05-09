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
    this->winX = winX;
    this->winY = winY;
    this->obj = new ObjContainer(objFilePath);
    this->setShaders();
    // this->setVertices();
    // this->SetWindowSize(winX, winY);
    // this->Camera = new ObjectViewer(glm::vec3(0,4,10));

    // this->setShaders();
    // this->setBackgroundColour();
}

App::~App()
{
}

void App::render() 
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    simpleShader->use();

    // Set Uniforms
    glm::mat4 cameraMatrix;
    cameraMatrix = glm::mat4(1.0f);
    cameraMatrix = glm::translate(cameraMatrix, glm::vec3(0.0f, 0.0f, -5.0f));
    simpleShader->setMat4("modelview_matrix", cameraMatrix);

    float aspect = (float) winX / winY;    
    glm::mat4 projection;
    projection = glm::mat4(1.0f);
    projection = glm::perspective( (float)M_PI/4, aspect, 0.001f, 10.0f );
    simpleShader->setMat4("projection_matrix", projection);        

    this->obj->Draw();

    // Update the camera, and draw the scene.
    // glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // glm::vec3 at(1.0f, 10.0f, 0.0f);
    // glm::vec3 target(0.0f, 1.0f, 0.0f);
    // glm::vec3 up(0.0f, 1.0f, 0.0f);

    // Camera->update(at, target, up);

    // updateProjection();

    // simpleShader->setMat4("view", Camera->getViewMtx());
    // simpleShader->setMat4("projection", this->projection);
    // simpleShader->setMat4("model", glm::mat4());

    // int shaderID = this->simpleShader->GetId();

    // obj->Draw(shaderID);
}

void App::setShaders() 
{
    std::string prefix = "res/";
    // Set up the shaders we are to use. 0 indicates error.
    this->simpleShader = new Shader(prefix + "simple.vert", prefix + "simple.frag");
}

void App::setBackgroundColour() 
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
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
    // float fov = 85;
    // this->projection = glm::perspective(glm::radians(fov), (float) winX / winY, 0.5f, 10000.0f );
}
