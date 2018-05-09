#include <vector>
#include <array>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"

#include "Shape.h"

void Shape::MakeCube(std::vector<float> &vertices) {
    // Positions            // Normals           // Texture Coords
    // far front
    AddVertex(-1.0f, -1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   0.0f,  0.0f); // 1 
    AddVertex(1.0f, -1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   1.0f,  0.0f); // 2  
    AddVertex(1.0f,  1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   1.0f,  1.0f); // 3  
    AddVertex(1.0f,  1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   1.0f,  1.0f); // 3  
    AddVertex(-1.0f,  1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   0.0f,  1.0f); // 4 
    AddVertex(-1.0f, -1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   0.0f,  0.0f); // 1 

    /// near front
    AddVertex(1.0f,  -1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   0.0f,  0.0f); // b 
    AddVertex(-1.0f, -1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   1.0f,  0.0f); // a 
    AddVertex(-1.0f,  1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   1.0f,  1.0f); // d 
    AddVertex(-1.0f,  1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   1.0f,  1.0f); // d 
    AddVertex(1.0f,   1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   0.0f,  1.0f); // c 
    AddVertex(1.0f,  -1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   0.0f,  0.0f); // b 

    /// left
    AddVertex(-1.0f, -1.0f,  1.0f,   -1.0f,  0.0f,  0.0f,  0.0f,  0.0f); // a 
    AddVertex(-1.0f, -1.0f, -1.0f,   -1.0f,  0.0f,  0.0f,  1.0f,  0.0f); // 1 
    AddVertex(-1.0f,  1.0f, -1.0f,   -1.0f,  0.0f,  0.0f,  1.0f,  1.0f); // 4 
    AddVertex(-1.0f,  1.0f, -1.0f,   -1.0f,  0.0f,  0.0f,  1.0f,  1.0f); // 4 
    AddVertex(-1.0f,  1.0f,  1.0f,   -1.0f,  0.0f,  0.0f,  0.0f,  1.0f); // d 
    AddVertex(-1.0f, -1.0f,  1.0f,   -1.0f,  0.0f,  0.0f,  0.0f,  0.0f); // a 

    /// right
    AddVertex(1.0f, -1.0f, -1.0f,    1.0f,  0.0f,  0.0f,   0.0f,  0.0f); // 2 
    AddVertex(1.0f, -1.0f,  1.0f,    1.0f,  0.0f,  0.0f,   1.0f,  0.0f); // b 
    AddVertex(1.0f,  1.0f,  1.0f,    1.0f,  0.0f,  0.0f,   1.0f,  1.0f); // c 
    AddVertex(1.0f,  1.0f,  1.0f,    1.0f,  0.0f,  0.0f,   1.0f,  1.0f); // c 
    AddVertex(1.0f,  1.0f, -1.0f,    1.0f,  0.0f,  0.0f,   0.0f,  1.0f); // 3 
    AddVertex(1.0f, -1.0f, -1.0f,    1.0f,  0.0f,  0.0f,   0.0f,  0.0f); // 2 

    /// floor
    AddVertex(-1.0f, -1.0f, -1.0f,   0.0f, -1.0f,  0.0f,   0.0f,  1.0f); // 1 
    AddVertex(1.0f, -1.0f, -1.0f,   0.0f, -1.0f,  0.0f,   1.0f,  1.0f); // 2  
    AddVertex(1.0f, -1.0f,  1.0f,   0.0f, -1.0f,  0.0f,   1.0f,  0.0f); // b  
    AddVertex(1.0f, -1.0f,  1.0f,   0.0f, -1.0f,  0.0f,   1.0f,  0.0f); //    
    AddVertex(-1.0f, -1.0f,  1.0f,   0.0f, -1.0f,  0.0f,   0.0f,  0.0f); // a 
    AddVertex(-1.0f, -1.0f, -1.0f,   0.0f, -1.0f,  0.0f,   0.0f,  1.0f); // s 

    /// sky
    AddVertex(-1.0f,  1.0f,  1.0f,   0.0f,  1.0f,  0.0f,   0.0f,  1.0f); // d 
    AddVertex(1.0f,  1.0f,  1.0f,   0.0f,  1.0f,  0.0f,   1.0f,  1.0f); // c  
    AddVertex(1.0f,  1.0f, -1.0f,   0.0f,  1.0f,  0.0f,   1.0f,  0.0f); // 3  
    AddVertex(1.0f,  1.0f, -1.0f,   0.0f,  1.0f,  0.0f,   1.0f,  0.0f); // 3  
    AddVertex(-1.0f,  1.0f, -1.0f,   0.0f,  1.0f,  0.0f,   0.0f,  0.0f); // 4 
    AddVertex(-1.0f,  1.0f,  1.0f,   0.0f,  1.0f,  0.0f,   0.0f,  1.0f); // d
}

Shape::Shape() {    
    setVertices();
}

Shape::~Shape() { 
}

void Shape::SetMatId(size_t matId) { 
    this->materialId = matId;
}

void Shape::SetVertexBuffer() { 
}

size_t Shape::GetMaterialId() {
    return this->materialId;
}

#define CUBE_NUM_VERTICES 36
#define CUBE_NUM_TRIS 12
#define VALS_PER_VERT 8

void Shape::Draw() {
    glBindVertexArray(VAO);

    glDrawArrays(GL_TRIANGLES, 0, CUBE_NUM_VERTICES);
    glBindVertexArray(0);
    glFlush();
}

void Shape::AddVertex(float px, float py, float pz,
            float nx, float ny, float nz,
            float tx, float ty) {
    vertices.push_back(px);
    vertices.push_back(py);
    vertices.push_back(pz);
    vertices.push_back(nx);
    vertices.push_back(ny);
    vertices.push_back(nz);
    vertices.push_back(tx);
    vertices.push_back(ty);
}

void Shape::setVertices() {
    float Vertices[] = {
        // Positions            // Normals           // Texture Coords
        // far front
        -1.0f, -1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   0.0f,  0.0f, // 1
        1.0f, -1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   1.0f,  0.0f, // 2
        1.0f,  1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   1.0f,  1.0f, // 3
        1.0f,  1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   1.0f,  1.0f, // 3
        -1.0f,  1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   0.0f,  1.0f, // 4
        -1.0f, -1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   0.0f,  0.0f, // 1

        // near front
        1.0f,  -1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   0.0f,  0.0f, // b
        -1.0f, -1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   1.0f,  0.0f, // a
        -1.0f,  1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   1.0f,  1.0f, // d
        -1.0f,  1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   1.0f,  1.0f, // d
        1.0f,   1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   0.0f,  1.0f, // c
        1.0f,  -1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   0.0f,  0.0f, // b

        // left
        -1.0f, -1.0f,  1.0f,   -1.0f,  0.0f,  0.0f,  0.0f,  0.0f, // a
        -1.0f, -1.0f, -1.0f,   -1.0f,  0.0f,  0.0f,  1.0f,  0.0f, // 1
        -1.0f,  1.0f, -1.0f,   -1.0f,  0.0f,  0.0f,  1.0f,  1.0f, // 4
        -1.0f,  1.0f, -1.0f,   -1.0f,  0.0f,  0.0f,  1.0f,  1.0f, // 4
        -1.0f,  1.0f,  1.0f,   -1.0f,  0.0f,  0.0f,  0.0f,  1.0f, // d
        -1.0f, -1.0f,  1.0f,   -1.0f,  0.0f,  0.0f,  0.0f,  0.0f, // a

        // right
        1.0f, -1.0f, -1.0f,    1.0f,  0.0f,  0.0f,   0.0f,  0.0f, // 2
        1.0f, -1.0f,  1.0f,    1.0f,  0.0f,  0.0f,   1.0f,  0.0f, // b
        1.0f,  1.0f,  1.0f,    1.0f,  0.0f,  0.0f,   1.0f,  1.0f, // c
        1.0f,  1.0f,  1.0f,    1.0f,  0.0f,  0.0f,   1.0f,  1.0f, // c
        1.0f,  1.0f, -1.0f,    1.0f,  0.0f,  0.0f,   0.0f,  1.0f, // 3
        1.0f, -1.0f, -1.0f,    1.0f,  0.0f,  0.0f,   0.0f,  0.0f, // 2 

        // floor
        -1.0f, -1.0f, -1.0f,   0.0f, -1.0f,  0.0f,   0.0f,  1.0f, // 1
        1.0f, -1.0f, -1.0f,   0.0f, -1.0f,  0.0f,   1.0f,  1.0f, // 2
        1.0f, -1.0f,  1.0f,   0.0f, -1.0f,  0.0f,   1.0f,  0.0f, // b
        1.0f, -1.0f,  1.0f,   0.0f, -1.0f,  0.0f,   1.0f,  0.0f,
        -1.0f, -1.0f,  1.0f,   0.0f, -1.0f,  0.0f,   0.0f,  0.0f, // a
        -1.0f, -1.0f, -1.0f,   0.0f, -1.0f,  0.0f,   0.0f,  1.0f,

        //sky
        -1.0f,  1.0f,  1.0f,   0.0f,  1.0f,  0.0f,   0.0f,  1.0f, // d
        1.0f,  1.0f,  1.0f,   0.0f,  1.0f,  0.0f,   1.0f,  1.0f, // c
        1.0f,  1.0f, -1.0f,   0.0f,  1.0f,  0.0f,   1.0f,  0.0f, // 3
        1.0f,  1.0f, -1.0f,   0.0f,  1.0f,  0.0f,   1.0f,  0.0f, // 3
        -1.0f,  1.0f, -1.0f,   0.0f,  1.0f,  0.0f,   0.0f,  0.0f, // 4
        -1.0f,  1.0f,  1.0f,   0.0f,  1.0f,  0.0f,   0.0f,  1.0f  // d
    };
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int buffer;
    glGenBuffers(1, &buffer);

    // Set vertex attribute Postion
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 0));

    // Set vertex attribute Normal
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 3));

    // Set vertex attribute Texture Coordinates
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 6));

    // Un-bind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
