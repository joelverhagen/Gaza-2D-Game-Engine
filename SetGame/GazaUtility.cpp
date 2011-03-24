#include "GazaUtility.hpp"

namespace Gaza
{
	namespace Utility
	{
		sf::IntRect zeroRectangle(0, 0, 0, 0);

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
		
		bool isZero(const sf::IntRect &rectangle)
		{
			return rectangle.Left == zeroRectangle.Left && rectangle.Top == zeroRectangle.Top && rectangle.Width == zeroRectangle.Width && rectangle.Height == zeroRectangle.Height;
		}

		void output(const sf::IntRect &rectangle)
		{
			std::cout << "{x: " << rectangle.Left << ", y: " << rectangle.Top << ", w: " << rectangle.Width << ", h: " << rectangle.Height << "}" << std::endl;
		}

		void output(const std::vector<std::string> &input)
		{
			std::cout << "[" << std::endl;
			for(int i = 0; i < input.size() - 1; i++)
			{
				std::cout << "   \"" << input[i] << "\"," << std::endl;
			}
			if(input.size() > 0)
			{
				std::cout << "   \"" << input[input.size() - 1] << "\"" << std::endl;
			}
			std::cout << "]" << std::endl;
		}
	}
}