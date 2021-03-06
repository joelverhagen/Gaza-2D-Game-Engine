#ifndef GAZARECTANGLEPACKER_HPP
#define GAZARECTANGLEPACKER_HPP

#include "Gaza.hpp"
#include "GazaUtility.hpp"
#include "GazaBaseHandler.hpp"

#include <vector>

namespace Gaza
{
	namespace RectanglePacking
	{
		class Packer
		{
		public:
			Packer(BaseHandler * handler);
			~Packer();

			sf::IntRect * addRectangle(unsigned int width, unsigned int height);

			unsigned int getContainerWidth();
			unsigned int getContainerHeight();

		protected:
			void calculateCurrentPower();
			bool incrementContainerSize();

			BaseHandler * handler;

			std::vector<sf::IntRect *> rectangles;

			unsigned int maximumWidthPower;
			unsigned int maximumHeightPower;

			unsigned int currentPowerSum;

			bool nextSet;

			unsigned int currentWidthPower;
			unsigned int currentHeightPower;
		};
	}
}

#endif