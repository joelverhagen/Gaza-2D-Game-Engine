#ifndef GAZAUTILITY_HPP
#define GAZAUTILITY_HPP

#include <SFML\Graphics.hpp>
#include <iostream>

#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include <limits.h>
#include <algorithm>

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

		template<class T>
		class SortIntPairPredicate
		{
		public:
			bool operator()(const std::pair<int, T> &a, const std::pair<int, T> &b)
			{
				return a.first < b.first;
			}
		};

		template<class T>
		void shuffle(std::vector<T> &input)
		{
			std::vector<std::pair<int, T> > pairs;
			
			for(unsigned int i = 0; i < input.size(); i++)
			{
				pairs.push_back(std::pair<int, T>(sf::Randomizer::Random(0, INT_MAX - 1), input[i]));
			}

			sort(pairs.begin(), pairs.end(), SortIntPairPredicate<T>());

			input.clear();

			for(unsigned int i = 0; i < pairs.size(); i++)
			{
				input.push_back(pairs[i].second);
			}
		}
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