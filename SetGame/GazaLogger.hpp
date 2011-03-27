#ifndef GAZALOGGER_HPP
#define GAZALOGGER_HPP

#include <string>
#include <fstream>

namespace Gaza
{
	class Logger
	{
	public:
		static Logger * getInstance();
		void write(const std::string &input);
		~Logger();

	private:
		Logger();

		static Logger * instance;
		std::ofstream outputStream;

	};
}

#endif