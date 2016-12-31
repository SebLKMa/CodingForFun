#pragma once
#include <string>

class FileIO
{
public:
	void copy(const std::string& src, const std::string& dest);
private:
	bool validateFiles(const std::string& inFile , const std::string& outFile);
};