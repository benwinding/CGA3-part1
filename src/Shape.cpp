#include <vector>
#include <array>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "Shape.h"

Shape::Shape(size_t materialId, std::vector<Vertex> vertices) {
    this->materialId = materialId;
    this->vertices = vertices;
    this->setVertexBuffers();
}

Shape::~Shape() { 
}

size_t Shape::GetMaterialId() {
    return this->materialId;
}

void Shape::Draw(int shaderID) {
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
    glBindVertexArray(0);
}

void Shape::setVertexBuffers() {
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
  
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &this->vertices[0], GL_STATIC_DRAW);  

    // vertex positions
    glEnableVertexAttribArray(0);   
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    // vertex normals
    glEnableVertexAttribArray(1);   
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
    // vertex texture coords
    glEnableVertexAttribArray(2);   
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));

    glBindVertexArray(0);
}

