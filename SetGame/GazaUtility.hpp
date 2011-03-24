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
		bool isZero(const sf::IntRect &rectangle);

		int power(int base, int exponent);

		int stringToInt(const std::string &input);
		std::string intToString(int input);
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