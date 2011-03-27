#include "GazaLogger.hpp"

namespace Gaza
{
	Logger * Logger::instance = 0;

	Logger * Logger::getInstance()
	{
		if(instance == 0)
		{
			instance = new Logger;
		}

		return instance;
	}

	void Logger::write(const std::string &input)
	{
		outputStream << input << std::endl;
		outputStream.flush();
	}

	Logger::~Logger()
	{
		outputStream.close();
	}

	Logger::Logger()
	{
		outputStream.open("log.txt", std::ios::app);
	}
}