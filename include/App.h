#ifndef __APP_H_
#define __APP_H_

#include "glm/glm.hpp"

#include "Shader.h"
#include "Viewer.h"
#include "ObjContainer.h"
#include "InputState.h"

enum debugViewType
{
   WIRE_FRAME,
   NORMAL,
   DIFFUSE
};

/*
 The App class is Repsonsible Composing the program and 
 Drawing the scene
 */
class App {
public:
    App(int winX, int winY, char* objFilePath);

    void render();
    void key_callback(int key, int action);
    void mouseBtn_callback(int button, int action);
    void mouseMove_callback(double x, double y);

    int SetWindowSize(int x, int y);


private:
    int winX, winY;

    ObjContainer *obj;
    ObjContainer *obj2;

    InputState mouseInput;

    Shader *shader;
    Shader *simpleShader;
    Shader *otherShader;
    void setShaders();

    int currentDebugView;
    void cycleDebugView();
    void cycleLighting();
    void toggleLightTexture();

    glm::mat4 projection;
    void updateProjection();

    ObjectViewer *Camera;
};

#endif
