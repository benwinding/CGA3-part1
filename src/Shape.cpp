#include <vector>
#include <array>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "Shape.h"

void PrintVerts(std::vector<float> &vertices) {
    for (int i = 0; i < vertices.size(); i = i + 8)
    {
        std::cout << "i = " << i / 8 << std::endl;
        std::cout << "  px = " << vertices[i+0] << std::endl;
        std::cout << "  py = " << vertices[i+1] << std::endl;
        std::cout << "  pz = " << vertices[i+2] << std::endl;
        std::cout << "  nx = " << vertices[i+3] << std::endl;
        std::cout << "  ny = " << vertices[i+4] << std::endl;
        std::cout << "  nz = " << vertices[i+5] << std::endl;
        std::cout << "  tx = " << vertices[i+6] << std::endl;
        std::cout << "  ty = " << vertices[i+7] << std::endl;
    }
}

void AddVert(std::vector<float> &vertices, float px, float py, float pz,
                float nx, float ny, float nz,
                float tx, float ty) {
    Vertex v;
    vertices.push_back(px);
    vertices.push_back(py);
    vertices.push_back(pz);
    vertices.push_back(nx);
    vertices.push_back(ny);
    vertices.push_back(nz);
    vertices.push_back(tx);
    vertices.push_back(ty);
}

void Shape::MakeCube(std::vector<float> &vertices) {
    // Positions            // Normals           // Texture Coords
    // far front
    AddVert(vertices, -1.0f, -1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   0.0f,  0.0f); // 1 
    AddVert(vertices, 1.0f, -1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   1.0f,  0.0f); // 2  
    AddVert(vertices, 1.0f,  1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   1.0f,  1.0f); // 3  
    AddVert(vertices, 1.0f,  1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   1.0f,  1.0f); // 3  
    AddVert(vertices, -1.0f,  1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   0.0f,  1.0f); // 4 
    AddVert(vertices, -1.0f, -1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   0.0f,  0.0f); // 1 

    /// near front
    AddVert(vertices, 1.0f,  -1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   0.0f,  0.0f); // b 
    AddVert(vertices, -1.0f, -1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   1.0f,  0.0f); // a 
    AddVert(vertices, -1.0f,  1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   1.0f,  1.0f); // d 
    AddVert(vertices, -1.0f,  1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   1.0f,  1.0f); // d 
    AddVert(vertices, 1.0f,   1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   0.0f,  1.0f); // c 
    AddVert(vertices, 1.0f,  -1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   0.0f,  0.0f); // b 

    /// left
    AddVert(vertices, -1.0f, -1.0f,  1.0f,   -1.0f,  0.0f,  0.0f,  0.0f,  0.0f); // a 
    AddVert(vertices, -1.0f, -1.0f, -1.0f,   -1.0f,  0.0f,  0.0f,  1.0f,  0.0f); // 1 
    AddVert(vertices, -1.0f,  1.0f, -1.0f,   -1.0f,  0.0f,  0.0f,  1.0f,  1.0f); // 4 
    AddVert(vertices, -1.0f,  1.0f, -1.0f,   -1.0f,  0.0f,  0.0f,  1.0f,  1.0f); // 4 
    AddVert(vertices, -1.0f,  1.0f,  1.0f,   -1.0f,  0.0f,  0.0f,  0.0f,  1.0f); // d 
    AddVert(vertices, -1.0f, -1.0f,  1.0f,   -1.0f,  0.0f,  0.0f,  0.0f,  0.0f); // a 

    /// right
    AddVert(vertices, 1.0f, -1.0f, -1.0f,    1.0f,  0.0f,  0.0f,   0.0f,  0.0f); // 2 
    AddVert(vertices, 1.0f, -1.0f,  1.0f,    1.0f,  0.0f,  0.0f,   1.0f,  0.0f); // b 
    AddVert(vertices, 1.0f,  1.0f,  1.0f,    1.0f,  0.0f,  0.0f,   1.0f,  1.0f); // c 
    AddVert(vertices, 1.0f,  1.0f,  1.0f,    1.0f,  0.0f,  0.0f,   1.0f,  1.0f); // c 
    AddVert(vertices, 1.0f,  1.0f, -1.0f,    1.0f,  0.0f,  0.0f,   0.0f,  1.0f); // 3 
    AddVert(vertices, 1.0f, -1.0f, -1.0f,    1.0f,  0.0f,  0.0f,   0.0f,  0.0f); // 2 

    /// floor
    AddVert(vertices, -1.0f, -1.0f, -1.0f,   0.0f, -1.0f,  0.0f,   0.0f,  1.0f); // 1 
    AddVert(vertices, 1.0f, -1.0f, -1.0f,   0.0f, -1.0f,  0.0f,   1.0f,  1.0f); // 2  
    AddVert(vertices, 1.0f, -1.0f,  1.0f,   0.0f, -1.0f,  0.0f,   1.0f,  0.0f); // b  
    AddVert(vertices, 1.0f, -1.0f,  1.0f,   0.0f, -1.0f,  0.0f,   1.0f,  0.0f); //    
    AddVert(vertices, -1.0f, -1.0f,  1.0f,   0.0f, -1.0f,  0.0f,   0.0f,  0.0f); // a 
    AddVert(vertices, -1.0f, -1.0f, -1.0f,   0.0f, -1.0f,  0.0f,   0.0f,  1.0f); // s 

    /// sky
    AddVert(vertices, -1.0f,  1.0f,  1.0f,   0.0f,  1.0f,  0.0f,   0.0f,  1.0f); // d 
    AddVert(vertices, 1.0f,  1.0f,  1.0f,   0.0f,  1.0f,  0.0f,   1.0f,  1.0f); // c  
    AddVert(vertices, 1.0f,  1.0f, -1.0f,   0.0f,  1.0f,  0.0f,   1.0f,  0.0f); // 3  
    AddVert(vertices, 1.0f,  1.0f, -1.0f,   0.0f,  1.0f,  0.0f,   1.0f,  0.0f); // 3  
    AddVert(vertices, -1.0f,  1.0f, -1.0f,   0.0f,  1.0f,  0.0f,   0.0f,  0.0f); // 4 
    AddVert(vertices, -1.0f,  1.0f,  1.0f,   0.0f,  1.0f,  0.0f,   0.0f,  1.0f); // d
}

Shape::Shape(size_t materialId, std::vector<float> vertices2) {
    std::vector<float> vertices;
    MakeCube(vertices);
    this->materialId = materialId;
    this->vertexCount = vertices.size();
    // PrintVerts(vertices);
    this->setVertexBuffers(vertices);
}

Shape::~Shape() { 
}

size_t Shape::GetMaterialId() {
    return this->materialId;
}

#define CUBE_NUM_VERTICES 36
#define CUBE_NUM_TRIS 12
#define VALS_PER_VERT 8

void Shape::Draw(int shaderID) {
    glUseProgram(shaderID);

    glDrawElements(GL_TRIANGLES, CUBE_NUM_TRIS*3, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
    glFlush();
}

void Shape::setVertexBuffers(std::vector<float> vec) {
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

    glGenVertexArrays(1, &this->VAO);
    glBindVertexArray(this->VAO);

    unsigned int buffer[3];
    glGenBuffers(3, buffer);

    // Set vertex attribute Postion
    glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 0));

    // Set vertex attribute Normal
    glBindBuffer(GL_ARRAY_BUFFER, buffer[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 3));

    // Set vertex attribute Texture Coordinates
    glBindBuffer(GL_ARRAY_BUFFER, buffer[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 6));

    // Un-bind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);



    // double Vertices[vec.size()];
    // std::copy(vec.begin(), vec.end(), Vertices);

    // glGenVertexArrays(1, &this->VAO);
    // glBindVertexArray(this->VAO);

    // unsigned int buffer[3];
    // glGenBuffers(3, buffer);

    // // Set vertex attribute Postion
    // glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
    // glEnableVertexAttribArray(0);
    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 0));

    // // Set vertex attribute Normal
    // glBindBuffer(GL_ARRAY_BUFFER, buffer[1]);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
    // glEnableVertexAttribArray(1);
    // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 3));

    // // Set vertex attribute Texture Coordinates
    // glBindBuffer(GL_ARRAY_BUFFER, buffer[2]);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
    // glEnableVertexAttribArray(2);
    // glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 6));

    // // Un-bind
    // glBindBuffer(GL_ARRAY_BUFFER, 0);
    // glBindVertexArray(0);
}

