#ifndef _A3_UTILS_H_
#define _A3_UTILS_H_

#include <string>

class FileUtils
{
public:
	static std::string GetBaseDir(const std::string& filepath);
	static bool FileExists(const std::string& abs_filename);
	static void CheckErrors(std::string desc);

private:	
	FileUtils();
	~FileUtils();
	
};

#endif