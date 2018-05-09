#ifndef __APP_H_
#define __APP_H_

#include "glm/glm.hpp"

#include "Shader.h"
#include "Viewer.h"
#include "ObjContainer.h"

/*
 The App class is Repsonsible Composing the program and 
 Drawing the scene
 */
class App {
public:
    App(int winX, int winY, char* objFilePath);

    void render();
    void key_callback(int key, int action);
    int SetWindowSize(int x, int y);

private:
    int winX, winY;

    Shader *simpleShader;
    void setShaders();

    ObjectViewer *Camera;

    glm::mat4 projection;
    
    ObjContainer *obj;

    void updateProjection();
    void updateCamera();
};

#endif
