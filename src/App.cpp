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
    this->obj2 = new ObjContainer(objFilePath);

    this->Camera = new ObjectViewer(glm::vec3(0,1,5));
}

void App::render() 
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    Camera->update(mouseInput);    
    // Set shader
    shader->use();
    // Set Uniforms
    shader->setMat4("projection", projection);
    shader->setMat4("view", this->Camera->getViewMtx());
    // Draw objs
    this->obj->Draw();

    glm::mat4 newViewMtx = glm::translate(this->Camera->getViewMtx(), glm::vec3(2.0f, 0.0f, 0.0f) );
    shader->setMat4("view", newViewMtx);
    this->obj2->Draw();

    glFlush();
}

void App::setShaders() 
{
    std::string prefix = "res/";
    this->simpleShader = new Shader(prefix + "simple.vert", prefix + "simple.frag");
    this->otherShader = new Shader(prefix + "simple2.vert", prefix + "simple2.frag");
    this->shader = this->simpleShader;
}

void App::mouseBtn_callback(int button, int action)
{
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
        mouseInput.rMousePressed = true;
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE) {
        mouseInput.rMousePressed = false;
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        mouseInput.lMousePressed = true;
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
        mouseInput.lMousePressed = false;
    }                
}

void App::mouseMove_callback(double x, double y)
{
    mouseInput.update((float)x, (float)y);
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
            std::cout << "- Debug Mode : WIRE_FRAME" << std::endl;
            this->shader = this->simpleShader;
            shader->setInt("debugMode", this->currentDebugView);
            this->obj->IsWireframe = true;
            this->obj2->IsWireframe = true;
            break;
        case NORMAL:
            std::cout << "- Debug Mode : NORMAL" << std::endl;
            this->shader = this->simpleShader;
            shader->setInt("debugMode", this->currentDebugView);
            this->obj->IsWireframe = false;
            this->obj2->IsWireframe = false;
            break;        
        case DIFFUSE:
            std::cout << "- Debug Mode : DIFFUSE" << std::endl;
            this->shader = this->simpleShader;
            shader->setInt("debugMode", this->currentDebugView);
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
