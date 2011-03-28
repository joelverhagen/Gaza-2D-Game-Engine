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
		std::cout << input << std::endl;
		outputStream << input << std::endl;
		outputStream.flush();
	}

	void Logger::write(int input)
	{
		write(Utility::intToString(input));
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