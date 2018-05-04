#ifndef _OBJ_CONTAINER_
#define _OBJ_CONTAINER_

#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

typedef struct {
    glm::vec3 pos;
    glm::vec3 color;
    glm::vec2 texCoord;
} Vertex;

class ObjContainer
{

public:
    ObjContainer(char* objFilePath);
    ~ObjContainer();

    void Draw(int shaderID);

private:
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;

    GLuint vb_id;
    int numTriangles;
    size_t material_id;

    void loadModel(char* filePath);
    void setVertexBuffers();
    void setIndiceBuffers();

};

#endif