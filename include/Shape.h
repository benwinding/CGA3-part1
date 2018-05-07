#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <vector>
#include <array>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

class Shape
{

public:
    Shape(size_t materialId, std::vector<Vertex> vertices);
    ~Shape();

    void Draw(int shaderID);
    size_t GetMaterialId();

private:
    void MakeCube(std::vector<Vertex> &vertices);
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
    
    int vertexCount;
    size_t materialId;

    void loadModel(char* filePath);
    void setVertexBuffers(std::vector<Vertex> vertices);
};

#endif