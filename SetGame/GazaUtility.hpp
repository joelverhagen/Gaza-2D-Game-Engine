#ifndef GAZAUTILITY_HPP
#define GAZAUTILITY_HPP

#include "Gaza.hpp"

#include <string>
#include <sstream>
#include <vector>

namespace Gaza
{
	namespace Utility
	{
		static sf::IntRect zeroIntRect;

		int stringToInt(const std::string &input);
		std::string intToString(int input);
		bool isZero(const sf::IntRect &rectangle);
		void output(const sf::IntRect &rectangle);
		void output(const std::vector<std::string> &input);
	}
}

#endif