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
    this->IsWireframe = false;
}

void ObjContainer::Draw() {
    for (int i = 0; i < this->shapes.size(); ++i)
    {
        if (this->IsWireframe)
            this->shapes[i].DrawWireframe();
        else
            this->shapes[i].DrawNormal();            
    }
}

// OBJ { SHAPES { VERTICES 

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
        Shape currShape;
        // Loop over faces(polygon)
        size_t index_offset = 0;
        for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
            int fv = shapes[s].mesh.num_face_vertices[f];
            // Loop over vertices in the face.
            // Assumed 3 vertices to a FACE
            for (size_t v = 0; v < fv; v++) {
                // access to vertex
                tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
                tinyobj::real_t vx = attrib.vertices[3*idx.vertex_index+0];
                tinyobj::real_t vy = attrib.vertices[3*idx.vertex_index+1];
                tinyobj::real_t vz = attrib.vertices[3*idx.vertex_index+2];
                tinyobj::real_t nx = attrib.normals[3*idx.normal_index+0];
                tinyobj::real_t ny = attrib.normals[3*idx.normal_index+1];
                tinyobj::real_t nz = attrib.normals[3*idx.normal_index+2];
                tinyobj::real_t tx = 0; //attrib.texcoords[2*idx.texcoord_index+0];
                tinyobj::real_t ty = 0; //attrib.texcoords[2*idx.texcoord_index+1];
                // // Optional: vertex colors
                // tinyobj::real_t red = attrib.colors[3*idx.vertex_index+0];
                // tinyobj::real_t green = attrib.colors[3*idx.vertex_index+1];
                // tinyobj::real_t blue = attrib.colors[3*idx.vertex_index+2];

                currShape.AddVertex(vx,vy,vz,nx,ny,nz,tx,ty);
            }
            index_offset += fv;
        }
        int matId = shapes[s].mesh.material_ids[0];
        currShape.SetMatId(matId);
        currShape.SetVertices();
        this->shapes.push_back(currShape);
    }
}
