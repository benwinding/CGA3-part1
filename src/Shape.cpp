#include <vector>
#include <array>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "Shape.h"

void AddVert(std::vector<Vertex> &vertices, float px, float py, float pz,
                float nx, float ny, float nz,
                float tx, float ty) {
    Vertex v;
    v.Position = glm::vec3(px,py,pz);
    v.Normal = glm::vec3(nx,ny,nz);
    v.TexCoords = glm::vec2(tx,ty);
    vertices.push_back(v);
}

void Shape::MakeCube(std::vector<Vertex> &vertices) {
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

Shape::Shape(size_t materialId, std::vector<Vertex> vertices2) {
    std::vector<Vertex> vertices;
    MakeCube(vertices);
    this->materialId = materialId;
    this->vertexCount = vertices.size();
    this->setVertexBuffers(vertices);
}

Shape::~Shape() { 
}

size_t Shape::GetMaterialId() {
    return this->materialId;
}

void Shape::Draw(int shaderID) {
    glUseProgram(shaderID);

    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertexCount * 9);
    glBindVertexArray(0);

    glFlush();
}

void Shape::setVertexBuffers(std::vector<Vertex> vertices) {
    glGenVertexArrays(1, &this->VAO);
    glBindVertexArray(this->VAO);

    unsigned int buffer[1];
    glGenBuffers(1, buffer);

    glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    // vertex positions
    glEnableVertexAttribArray(0);   
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    // vertex normals
    glEnableVertexAttribArray(1);   
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
    // vertex texture coords
    glEnableVertexAttribArray(2);   
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

