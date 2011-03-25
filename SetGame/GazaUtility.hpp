#ifndef GAZAUTILITY_HPP
#define GAZAUTILITY_HPP

#include "Gaza.hpp"

#include <string>
#include <sstream>
#include <vector>
#include <math.h>  

namespace Gaza
{
	namespace Utility
	{
		int stringToInt(const std::string &input);
		std::string intToString(int input);

		int power(int base, int exponent);
		double round(double input);
#ifdef _MSC_VER
		double log2(double n);
#endif
	}

	std::ostream& operator <<(std::ostream &os, const sf::IntRect &input);
	std::ostream& operator <<(std::ostream &os, const sf::IntRect * &input);

	std::ostream& operator <<(std::ostream &os, const std::vector<sf::IntRect> &input);
	std::ostream& operator <<(std::ostream &os, const std::vector<sf::IntRect> * &input);

	std::ostream& operator <<(std::ostream &os, const std::vector<sf::IntRect *> &input);
	std::ostream& operator <<(std::ostream &os, const std::vector<sf::IntRect *> * &input);

	std::ostream& operator <<(std::ostream &os, const std::vector<std::string> &input);
	std::ostream& operator <<(std::ostream &os, const std::vector<std::string> * &input);
}

#endif