#include <stdio.h>
#include <iostream>

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "tiny_obj_loader.h"
#include "ObjContainer.h"
#include "FileUtils.h"

ObjContainer::ObjContainer(char* objFilePath) {    
    this->loadModel(objFilePath);    
    this->setVertexBuffers();
    this->setIndiceBuffers();    
}

void ObjContainer::Draw(int shaderID) {
    glBindVertexArray(this->vb_id);

    glm::mat4 model = glm::mat4();
    int modelUniformHandle = glGetUniformLocation(shaderID, "model");
    if (modelUniformHandle == -1)
        exit(1);
    glUniformMatrix4fv(modelUniformHandle, 1, false, glm::value_ptr(model));

    glDrawArrays(GL_TRIANGLES, 0, this->numTriangles);
}

// OBJ { SHAPES { FACES { VERTICES 

void ObjContainer::loadModel(char* objFilePath) {
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string base_dir = FileUtils::GetBaseDir(objFilePath);
    if (base_dir.empty()) {
        base_dir = ".";
    }
    base_dir += "/";

    std::string err;
    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &err, objFilePath, base_dir.c_str());

    if (!err.empty()) { // `err` may contain warning message.
        std::cerr << err << std::endl;
    }

    if (!ret) {
        exit(1);
    }

    // Loop over shapes
    for (const auto& shape : shapes) {
        for (const auto& index : shape.mesh.indices) {
            Vertex vertex = {};
            vertex.pos = {
                attrib.vertices[3 * index.vertex_index + 0],
                attrib.vertices[3 * index.vertex_index + 1],
                attrib.vertices[3 * index.vertex_index + 2]
            };

            // vertex.texCoord = {
            //     attrib.texcoords[2 * index.texcoord_index + 0],
            //     1.0f - attrib.texcoords[2 * index.texcoord_index + 1]
            // };

            vertex.color = {
                attrib.colors[3 * index.vertex_index + 0],
                attrib.colors[3 * index.vertex_index + 1],
                attrib.colors[3 * index.vertex_index + 2],
            };

            vertices.push_back(vertex);
            indices.push_back(indices.size());            
        }
    }
}

void ObjContainer::setVertexBuffers() {
    int bufferSize = sizeof(vertices[0]) * vertices.size();
    int vertexSize = sizeof(vertices[0]);

    glGenVertexArrays(1, &this->vb_id);
    glBindVertexArray(this->vb_id);

    unsigned int buffer[3];
    glGenBuffers(3, buffer);

    // Set vertex attribute Postion
    glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
    glBufferData(GL_ARRAY_BUFFER, bufferSize, &vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, (GLvoid*)(sizeof(GLfloat) * 0));

    // Set vertex attribute Normal
    glBindBuffer(GL_ARRAY_BUFFER, buffer[1]);
    glBufferData(GL_ARRAY_BUFFER, bufferSize, &vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, vertexSize, (GLvoid*)(sizeof(GLfloat) * 3));

    // Set vertex attribute Texture Coordinates
    glBindBuffer(GL_ARRAY_BUFFER, buffer[2]);
    glBufferData(GL_ARRAY_BUFFER, bufferSize, &vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, vertexSize, (GLvoid*)(sizeof(GLfloat) * 6));

    // Un-bind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void ObjContainer::setIndiceBuffers() {

}
