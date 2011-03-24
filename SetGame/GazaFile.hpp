#ifndef GAZAFILE_HPP
#define GAZAFILE_HPP

#include "Gaza.hpp"

#include <string>
#include <fstream>

namespace Gaza
{
	namespace File
	{
		int getFileSize(const std::string &filePath);
		char * getFile(const std::string &filePath, bool nullTerminate = false);
		bool fileExists(const std::string &filePath);
	}
}

#endif