#include <stdio.h>
#include <iostream>
#include <string.h>
#define _USE_MATH_DEFINES
#include <cmath>

#include "glm/gtx/string_cast.hpp"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "App.h"
#include "Shader.h"
#include <GLFW/glfw3.h>

App::App(int winX, int winY, int mazeSize, int* mazeConfig)
{
    this->SetWindowSize(winX, winY);
    
    this->ObjCam = new ObjectViewer(glm::vec3(0,mazeSize*1.4,0.5));
    this->PlayerCam = new PlayerViewer(glm::vec3(0,0,0), mazeSize);
    this->Camera = PlayerCam;

    this->SetShaders();
}

App::~App()
{
    delete this->ObjCam;
    delete this->PlayerCam;
}

void App::SetShaders()
{
    std::string prefix = "res/shaders/";
}

void App::render() 
{
    // Update the camera, and draw the scene.
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    Camera->update(glm::vec3(12,10,0),glm::vec3(0,0,0),glm::vec3(0,1,0));

    // int currentId;
    // currentId = wallsShader->GetId();
    // wallsShader->use();
    // wallsShader->setMat4("projection", this->projection);
    // wallsShader->setMat4("view", Camera->getViewMtx());

    // wallsShader->setRgb("material.colour", 200, 200, 200);
    // wallsShader->setInt("material.diffuse", 0);
    // wallsShader->setInt("material.specular", 1);
    // wallsShader->setFloat("material.shininess", 32.f);

    // wallsShader->setInt("numLights", 2);
    // std::string light1 = "allLights[0].";
    // wallsShader->setInt(light1 + "isDirectional", 1);
    // wallsShader->setVec3(light1 + "position", ThePlayer->GetLocation3());
    // wallsShader->setVec3(light1 + "direction", ThePlayer->GetDirection3());
    // wallsShader->setFloat(light1 + "cutOff", glm::cos(glm::radians(12.5f)));
    // wallsShader->setFloat(light1 + "outerCutOff", glm::cos(glm::radians(25.5f)));
    // wallsShader->setRgb(light1 + "ambient", 125, 125, 125);
    // wallsShader->setRgb(light1 + "diffuse", 125, 125, 125);
    // wallsShader->setRgb(light1 + "specular", 125, 125, 125);
    // wallsShader->setFloat(light1 + "constant", 0.80f);
    // wallsShader->setFloat(light1 + "linear", 0.09f);
    // wallsShader->setFloat(light1 + "quadratic", 0.032f);

    // std::string light2 = "allLights[1].";
    // wallsShader->setInt(light2 + "isDirectional", 0);
    // wallsShader->setVec3(light2 + "position", TheMaze->GetGoalLocation3());
    // wallsShader->setRgb(light2 + "ambient", 255, 255, 255);
    // wallsShader->setRgb(light2 + "diffuse", 100, 10, 10);
    // wallsShader->setFloat(light2 + "constant", 0.80f);
    // wallsShader->setFloat(light2 + "linear", 0.09f);
    // wallsShader->setFloat(light2 + "quadratic", 0.032f);

    // NoTexture->Use();

    // if(this->TexturesOn) TextureBoundry->Use();
    // wallsShader->setRgb("material.colour", 200, 80, 80);
    // TheMaze->renderMazeBoundary(currentId);

    // if(this->TexturesOn) TextureFloor->Use();
    // wallsShader->setRgb("material.colour", 100, 100, 100);
    // TheMaze->renderMazeFloor(currentId);

    // if(this->TexturesOn) TextureWalls->Use();
    // wallsShader->setRgb("material.colour", 124, 68, 42);
    // TheMaze->renderWalls(currentId);

    // if(this->TexturesOn) TextureHat->Use();
    // wallsShader->setRgb("material.colour", 0, 255, 0);
    // ThePlayer->renderHat(currentId);

    // NoTexture->Use();
    // if(this->Camera == ObjCam)
    //     ThePlayer->renderPlayer(currentId);

    // if(this->TexturesOn) TextureMirror->Use();
    // wallsShader->setRgb("material.colour", 255, 0, 0);
    // TheMaze->renderGoal(currentId);
}

void App::key_callback(int key, int action)
{
    if (action == GLFW_PRESS) 
    {
        switch(key) 
        {
            case '1':
                Camera = PlayerCam;
                break;
            case '2':
                Camera = ObjCam;
                break;
            case GLFW_KEY_T:
                // toggleTextures();
                break;
            case GLFW_KEY_H:
                // this->ThePlayer->ToggleHat();
                break;
            case GLFW_KEY_UP:
                // this->MoveStraight(180);
                break;
            case GLFW_KEY_DOWN:
                // this->MoveStraight(0);
                break;
        }
    }
    switch(key) 
    {
        case GLFW_KEY_LEFT:
            // ThePlayer->PanLeft();
            break;
        case GLFW_KEY_RIGHT:
            // ThePlayer->PanRight();
            break;
        case GLFW_KEY_A:
            // ThePlayer->TiltUp();
            break;
        case GLFW_KEY_Z:
            // ThePlayer->TiltDown();
            break;
        default:
            break;
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
    float fov = 85;
    this->projection = glm::perspective(glm::radians(fov), (float) winX / winY, 0.5f, 10000.0f );
}
