#ifndef _OBJ_CONTAINER_
#define _OBJ_CONTAINER_

#include <vector>
#include <array>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include "Shape.h"

class ObjContainer
{

public:
    ObjContainer(char* objFilePath);
    ~ObjContainer();

    void Draw();

private:
    std::vector<Shape> shapes;
    void loadModel(char* filePath);
};

#endif