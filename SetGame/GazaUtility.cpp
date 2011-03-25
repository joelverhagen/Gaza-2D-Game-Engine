#include "GazaUtility.hpp"

namespace Gaza
{
	namespace Utility
	{
		sf::IntRect zeroRectangle(0, 0, 0, 0);

		bool isZero(const sf::IntRect &rectangle)
		{
			return rectangle.Left == zeroRectangle.Left && rectangle.Top == zeroRectangle.Top && rectangle.Width == zeroRectangle.Width && rectangle.Height == zeroRectangle.Height;
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

		/* std::string toString(const sf::IntRect &input)
		{
			std::stringstream ss;

			ss << "{x: " << input.Left << ", y: " << input.Top << ", w: " << input.Width << ", h: " << input.Height << "}";

			return ss.str();
		}

		std::string toString(const sf::IntRect * &input)
		{
			std::stringstream ss;
			ss << "{x: " << input->Left << ", y: " << input->Top << ", w: " << input->Width << ", h: " << input->Height << "}";
			return ss.str();
		}

		std::string toString(const std::vector<std::string> &input)
		{
			std::stringstream ss;

			ss << "[" << std::endl;
			for(unsigned int i = 0; i < input.size() - 1; i++)
			{
				ss << "   \"" << input[i] << "\"," << std::endl;
			}
			if(input.size() > 0)
			{
				ss << "   \"" << input[input.size() - 1] << "\"" << std::endl;
			}
			ss << "]" << std::endl;
		}

		void output(const std::vector<sf::IntRect> &input)
		{
			std::cout << "[" << std::endl;
			for(unsigned int i = 0; i < input.size() - 1; i++)
			{
				std::cout << "   \"" << input[i] << "\"," << std::endl;
			}
			if(input.size() > 0)
			{
				std::cout << "   \"" << input[input.size() - 1] << "\"" << std::endl;
			}
			std::cout << "]" << std::endl;
		}

		void output(const std::vector<sf::IntRect *> &input)
		{
			std::cout << "[" << std::endl;
			for(unsigned int i = 0; i < input.size() - 1; i++)
			{
				std
				output(input[i], false);
				std::cout << "," << std::endl;
			}
			if(input.size() > 0)
			{
				output(input[i], true);
			}
			std::cout << "]" << std::endl;
		} */
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