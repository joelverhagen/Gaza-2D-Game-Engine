#include "GazaUtility.hpp"

namespace Gaza
{
	namespace Utility
	{
		namespace RapidXml
		{
			void addAttribute(rapidxml::xml_document<> * document, rapidxml::xml_node<> * node, std::string key, std::string value)
			{
				char * keyAllocated = document->allocate_string(key.data(), key.size());
				char * valueAllocated = document->allocate_string(value.data(), value.size());
				rapidxml::xml_attribute<> * attribute = document->allocate_attribute(keyAllocated, valueAllocated, key.size(), value.size());
				node->append_attribute(attribute);
			}
		}

		int stringToInt(const std::string &input)
		{
			std::stringstream ss(input);
			int output;
			ss >> output;
			
			return output;
		}

		std::string intToString(int input)
		{
			std::stringstream ss;
			ss << input;
			return ss.str();
		}

		std::string floatToString(float input)
		{
			std::stringstream ss;
			ss << input;
			return ss.str();
		}
		
		int power(int base, int exponent)
		{
			if(exponent == 0)
			{
				return 1;
			}
			else
			{
				if(exponent % 2 == 0)
				{
					return power(base * base, exponent / 2);
				}
				else
				{
					return base * power(base, exponent - 1);
				}
			}
		}

		double round(double input)
		{
			return floor(input + 0.5);
		}

#ifdef _MSC_VER
		double log2(double n)  
		{  
			return log(n) / log(2.f);  
		}
#endif
	}

	std::ostream& operator <<(std::ostream &os, const sf::IntRect &input)
	{
		os << "{x: " << input.Left << ", y: " << input.Top << ", w: " << input.Width << ", h: " << input.Height << "}";

		return os;
	}

	std::ostream& operator <<(std::ostream &os, const sf::IntRect * &input)
	{
		os << *input;

		return os;
	}

	std::ostream& operator <<(std::ostream &os, const std::vector<sf::IntRect> &input)
	{
		if(input.size() == 0)
		{
			os << "[]" << std::endl;
			
			return os;
		}

		for(unsigned int i = 0; i < input.size() - 1; i++)
		{
			os << "   " << input[i] << "," << std::endl;
		}
		os << "   " << input[input.size() - 1] << std::endl << "]" << std::endl;

		return os;
	}

	std::ostream& operator <<(std::ostream &os, const std::vector<sf::IntRect> * &input)
	{
		os << *input;

		return os;
	}

	std::ostream& operator <<(std::ostream &os, const std::vector<sf::IntRect *> &input)
	{
		if(input.size() == 0)
		{
			os << "[]" << std::endl;
			
			return os;
		}

		for(unsigned int i = 0; i < input.size() - 1; i++)
		{
			os << "   " << *input[i] << "," << std::endl;
		}
		os << "   " << *input[input.size() - 1] << std::endl << "]" << std::endl;

		return os;
	}
	
	std::ostream& operator <<(std::ostream &os, const std::vector<sf::IntRect *> * &input)
	{
		os << *input;

		return os;
	}

	std::ostream& operator <<(std::ostream &os, const std::vector<std::string> &input)
	{
		if(input.size() == 0)
		{
			os << "[]" << std::endl;
			
			return os;
		}

		for(unsigned int i = 0; i < input.size() - 1; i++)
		{
			os << "   \"" << input[i] << "\"," << std::endl;
		}
		os << "   \"" << input[input.size() - 1] << "\"" << std::endl << "]" << std::endl;

		return os;
	}

	std::ostream& operator <<(std::ostream &os, const std::vector<std::string> * &input)
	{
		os << *input;

		return os;
	}	
}