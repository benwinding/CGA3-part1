#include <stdio.h>
#include <string>
#include <iostream>
#include <unordered_map>

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "tiny_obj_loader.h"
#include "ObjContainer.h"
#include "FileUtils.h"
#include "Shape.h"

ObjContainer::ObjContainer(char* objFilePath) {    
    this->loadModel(objFilePath);    
}

void ObjContainer::Draw(int shaderID) {
    for (int i = 0; i < this->shapes.size(); ++i)
    {
        this->shapes[i].Draw(shaderID);
    }
}

// OBJ { SHAPES { FACES { VERTICES 

void log(std::string name, std::string val) {
    std::cout << name << " : " << val << std::endl;
}

void log(std::string name, float val) {
    std::cout << name << " : " << val << std::endl;
}

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
    for (size_t s = 0; s < shapes.size(); s++) {
        // Loop over faces(polygon)
        size_t index_offset = 0;
        for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
            int fv = shapes[s].mesh.num_face_vertices[f];

            std::vector<Vertex> shapeVertices;
            // Loop over vertices in the face.
            for (size_t v = 0; v < fv; v++) {
                // access to vertex
                tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
                tinyobj::real_t vx = attrib.vertices[3*idx.vertex_index+0];
                tinyobj::real_t vy = attrib.vertices[3*idx.vertex_index+1];
                tinyobj::real_t vz = attrib.vertices[3*idx.vertex_index+2];
                tinyobj::real_t nx = attrib.normals[3*idx.normal_index+0];
                tinyobj::real_t ny = attrib.normals[3*idx.normal_index+1];
                tinyobj::real_t nz = attrib.normals[3*idx.normal_index+2];
                // tinyobj::real_t tx = attrib.texcoords[2*idx.texcoord_index+0];
                // tinyobj::real_t ty = attrib.texcoords[2*idx.texcoord_index+1];
                // // Optional: vertex colors
                // tinyobj::real_t red = attrib.colors[3*idx.vertex_index+0];
                // tinyobj::real_t green = attrib.colors[3*idx.vertex_index+1];
                // tinyobj::real_t blue = attrib.colors[3*idx.vertex_index+2];

                Vertex currVertex = {};
                currVertex.Position = glm::vec3(vx, vy, vz);
                currVertex.Normal = glm::vec3(nx, ny, nz);
                // currVertex.TexCoords = glm::vec2(0,0);            
                // currVertex.TexCoords = vec2(tx, ty);
                shapeVertices.push_back(currVertex);
            }
            index_offset += fv;

            // per-face material
            int matId = shapes[s].mesh.material_ids[f];
            Shape currentShape(matId, shapeVertices);
            this->shapes.push_back(currentShape);
        }
    }
}
