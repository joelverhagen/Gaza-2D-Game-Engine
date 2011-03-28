#ifndef GAZALOGGER_HPP
#define GAZALOGGER_HPP

#include "GazaUtility.hpp"

#include <string>
#include <fstream>
#include <iostream>

namespace Gaza
{
	class Logger
	{
	public:
		static Logger * getInstance();
		void write(const std::string &input);
		void write(int input);
		~Logger();

	private:
		Logger();

		static Logger * instance;
		std::ofstream outputStream;

	};
}

#endif