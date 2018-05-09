#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <vector>
#include <array>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

class Shape
{

public:
    Shape();
    ~Shape();

    void SetMatId(size_t matId);
    void SetVertices();

    void DrawShape();
    size_t GetMaterialId();
    void AddVertex(float px, float py, float pz,
                float nx, float ny, float nz,
                float tx, float ty);
private:
    std::vector<float> vertices;
    
    int vertexCount;
    size_t materialId;
    unsigned int VAO;

    void loadModel(char* filePath);
};

#endif