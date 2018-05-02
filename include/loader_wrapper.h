#ifndef _LOADER_WRAPPER_H_
#define _LOADER_WRAPPER_H_

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "glm/gtx/string_cast.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "stb_image.h"
#include "tiny_obj_loader.h"

#include "utils.h"

typedef struct {
  GLuint vb_id;  // vertex buffer id
  int numTriangles;
  size_t material_id;
} DrawObject;

class loader_wrapper
{

private:
	static void normalizeVector(glm::vec3 &v);
	static bool hasSmoothingGroup(const tinyobj::shape_t& shape);
	static void computeSmoothingNormals(const tinyobj::attrib_t& attrib, const tinyobj::shape_t& shape,
					std::map<int, glm::vec3>& smoothVertexNormals);
	static void CalcNormal(glm::vec3 N, glm::vec3 v0, glm::vec3 v1, glm::vec3 v2);

public:
	static bool LoadObjAndConvert(float bmin[3], float bmax[3],
					std::vector<DrawObject>* drawObjects,
					std::vector<tinyobj::material_t>& materials,
					std::map<std::string, GLuint>& textures,
					const char* filename);
	loader_wrapper();
	~loader_wrapper();
	
};

#endif