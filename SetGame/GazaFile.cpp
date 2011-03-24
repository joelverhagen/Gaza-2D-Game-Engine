#include "GazaFile.hpp"

namespace Gaza
{
	namespace File
	{
		int getFileSize(const std::string &filePath)
		{
			std::ifstream inputFile(filePath.c_str(), std::ios::in | std::ios::binary);
	
			inputFile.seekg (0, std::ios::end);
			int length = (int)inputFile.tellg();
			inputFile.seekg (0, std::ios::beg);

			inputFile.close();
	
			return length;
		}

		char * getFile(const std::string &filePath, bool nullTerminate)
		{
			std::ifstream inputFile(filePath.c_str(), std::ios::in | std::ios::binary);
	
			if(!inputFile.is_open())
			{
				return 0;
			}
	
			int length = getFileSize(filePath);
	
			char * fileContents;
			if(nullTerminate)
			{
				fileContents = new char[length + 1];
				inputFile.read(fileContents, length);
				fileContents[length] = '\0';
			}
			else
			{
				fileContents = new char[length];
				inputFile.read(fileContents, length);
			}

			inputFile.close();
	
			return fileContents;
		}

		bool fileExists(const std::string &filePath)
		{
			std::ifstream inputFile(filePath.c_str(), std::ios::in | std::ios::binary);

			inputFile.close();
			
			return inputFile.good();
		}
	}
}