#include "GazaPacker.hpp"

namespace Gaza
{
	namespace RectanglePacking
	{
		Packer::Packer(BaseHandler * handler)
		{
			this->handler = handler;

			maximumWidthPower = (unsigned int)Utility::round(Utility::log2(maximumImageWidth));
			maximumHeightPower = (unsigned int)Utility::round(Utility::log2(maximumImageHeight));

			currentPowerSum = 0;

			nextSet = true;

			currentWidthPower = 0;
			currentHeightPower = 0;

			handler->initialize(getContainerWidth(), getContainerHeight());
		}

		Packer::~Packer()
		{

		}

		sf::IntRect * Packer::addRectangle(unsigned int width, unsigned int height)
		{
			sf::IntRect * rectangle = new sf::IntRect(0, 0, width, height);
			rectangles.push_back(rectangle);
			bool success = handler->addRectangle(rectangle);

			while(!success)
			{
				bool resize = incrementContainerSize();

				if(!resize)
				{
					// we've resized, but there was a problem (meaning we resized to a size that was too big)
					return 0;
				}

				handler->initialize(getContainerWidth(), getContainerHeight());

				for(unsigned int i = 0; i < rectangles.size(); i++)
				{
					success = handler->addRectangle(rectangles[i]);
					if(!success)
					{
						// the rectangle will still not fit, so we'll need to resize again
						break;
					}
				}
			}

			return rectangle;
		}

		unsigned int Packer::getContainerWidth()
		{
			return Utility::power(2, currentWidthPower);
		}

		unsigned int Packer::getContainerHeight()
		{
			return Utility::power(2, currentHeightPower);
		}

		bool Packer::incrementContainerSize()
		{
			if(currentWidthPower == maximumWidthPower && currentHeightPower == maximumHeightPower)
			{
				return false;
			}
			
			unsigned int previousWidthPower = currentWidthPower;
			unsigned int previousHeightPower = currentHeightPower;

			if(nextSet)
			{
				nextSet = false;

				currentPowerSum += 1;

				if(currentPowerSum > maximumWidthPower)
				{
					currentWidthPower = maximumWidthPower;
				}
				else
				{
					currentWidthPower = currentPowerSum;
				}
				currentHeightPower = currentPowerSum - currentWidthPower;

				if(currentWidthPower > maximumWidthPower || currentHeightPower > maximumHeightPower)
				{
					// roll back changes
					nextSet = true;
					currentPowerSum -= 1;
					currentWidthPower = previousWidthPower;
					currentHeightPower = previousHeightPower;

					return false;
				}
			}
			else
			{
				currentHeightPower++;
				currentWidthPower--;

				if(currentWidthPower <= 0 || currentHeightPower <= 0 || currentWidthPower >= maximumWidthPower || currentHeightPower >= maximumHeightPower)
				{
					nextSet = true;
				}
			}

			return true;
		}
	}
}