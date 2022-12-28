#pragma once
#include <string>
#include <vector>

class FileSystem
{
public:
	
	static std::vector<std::string> getDirectoriesList(const std::string & path);
	static std::vector<std::string> getDrivesList();
};