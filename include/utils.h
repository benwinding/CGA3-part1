#ifndef _A3_UTILS_H_
#define _A3_UTILS_H_

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

class utils
{
public:
	static std::string GetBaseDir(const std::string& filepath);
	static bool FileExists(const std::string& abs_filename);
	static void CheckErrors(std::string desc);

private:	
	utils();
	~utils();
	
};

#endif