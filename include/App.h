#ifndef __APP_H_
#define __APP_H_

#include "glm/glm.hpp"

#include "Shader.h"
#include "Viewer.h"
#include "ObjContainer.h"

// Repsonsible Composing the program and 
class App {
public:
    App(int winX, int winY, char* objFilePath);
    ~App();

    void render();
    void key_callback(int key, int action);
    int SetWindowSize(int x, int y);

private:
    int winX, winY;

    ObjectViewer *Camera;
    glm::mat4 projection;

    Shader *simpleShader;

    ObjContainer *obj;

    void updateProjection();
    void setShaders();
    void setBackgroundColour();
};

#endif
