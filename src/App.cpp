#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "App.h"

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
    shader->use();
    // Set Uniforms
    shader->setMat4("projection_matrix", projection);
    shader->setMat4("modelview_matrix", this->Camera->getViewMtx());
    // Draw objs
    this->obj->Draw();
}

void App::setShaders() 
{
    std::string prefix = "res/";
    this->simpleShader = new Shader(prefix + "simple.vert", prefix + "simple.frag");
    this->otherShader = new Shader(prefix + "simple2.vert", prefix + "simple2.frag");
    this->shader = this->simpleShader;
}

void App::key_callback(int key, int action)
{
    if (action == GLFW_PRESS) 
    {
        switch(key) 
        {
            case GLFW_KEY_B:
                cycleDebugView();
                break;
            case GLFW_KEY_D:
                cycleLighting();
                break;
            case GLFW_KEY_T:
                toggleLightTexture();
                break;
        }
    }
}

void App::cycleDebugView() 
{
    this->currentDebugView = (this->currentDebugView + 1) % 3 ;
    switch (this->currentDebugView) {
        case WIRE_FRAME:
            this->shader = this->simpleShader;
            this->obj->IsWireframe = true;
            break;
        case NORMAL:
            this->shader = this->simpleShader;
            this->obj->IsWireframe = false;
            break;        
        case DIFFUSE:
            this->shader = this->otherShader;
            break;
    }
}

void App::cycleLighting() 
{    
}

void App::toggleLightTexture() 
{    
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
