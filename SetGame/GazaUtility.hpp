#ifndef GAZAUTILITY_HPP
#define GAZAUTILITY_HPP

#include <SFML\Graphics.hpp>

#include "rapidxml.hpp"

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
		namespace RapidXml
		{
			void addAttribute(rapidxml::xml_document<> * document, rapidxml::xml_node<> * node, std::string key, std::string value);
		}

		int stringToInt(const std::string &input);
		std::string intToString(int input);
		std::string floatToString(float input);

		int power(int base, int exponent);
		double round(double input);
#ifdef _MSC_VER
		double log2(double n);
#endif
		
		template <typename Iterator>
		bool next_combination(const Iterator first, Iterator k, const Iterator last)
		{
			// Credits: Mark Nelson http://marknelson.us
			if ((first == last) || (first == k) || (last == k))
				return false;
			Iterator i1 = first;
			Iterator i2 = last;
			++i1;
			if (last == i1)
				return false;
			i1 = last;
			--i1;
			i1 = k;
			--i2;
			while (first != i1)
			{
				if (*--i1 < *i2)
				{
					Iterator j = k;
					while (!(*i1 < *j)) ++j;
					std::iter_swap(i1,j);
					++i1;
					++j;
					i2 = k;
					std::rotate(i1,j,last);
					while (last != j)
					{
						++j;
						++i2;
					}
					std::rotate(k,i2,last);
					return true;
				}
			}
			std::rotate(first,k,last);
			return false;
		}

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
			if(input.size() < 1)
			{
				return;
			}

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