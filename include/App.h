#ifndef __APP_H_
#define __APP_H_

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Shader.h"
#include "Viewer.h"

// Repsonsible Composing the program and 
class App {
private:
    int winX, winY;

    Viewer *Camera;
    ObjectViewer *ObjCam;
    PlayerViewer *PlayerCam;

    glm::mat4 projection;

    int CompileShader(std::string vertPath, std::string fragPath);  
    void MoveStraight(float angle);
    void SetShaders();

    void updateProjection();

public:
    App(int winX, int winY, int mazeSize, int* mazeConfig);
    ~App();

    void render();

    void key_callback(int key, int action);

    int SetWindowSize(int x, int y);
};

#endif
