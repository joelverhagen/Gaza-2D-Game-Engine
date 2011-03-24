#ifndef GAZABASEHANDLER_HPP
#define GAZABASEHANDLER_HPP

#include "Gaza.hpp"

namespace Gaza
{
	namespace RectanglePacking
	{
		class BaseHandler
		{
		public:
			virtual void initialize(unsigned int width, unsigned int height) = 0;
			virtual bool addRectangle(sf::IntRect * inputRectangle) = 0;
		};
	}
}

#endif