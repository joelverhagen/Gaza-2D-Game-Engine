#include "GazaPacker.hpp"

namespace Gaza
{
	namespace RectanglePacking
	{
		Packer::Packer(BaseHandler * handler)
		{
			this->handler = handler;

			currentPower = 8;
			calculateCurrentPower();

			handler->initialize(containerWidth, containerHeight);
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
					return 0;
				}

				handler->initialize(containerWidth, containerHeight);

				for(unsigned int i = 0; i < rectangles.size(); i++)
				{
					success = handler->addRectangle(rectangles[i]);
					if(!success)
					{
						break;
					}
				}
				
			}

			return rectangle;
		}

		unsigned int Packer::getContainerWidth()
		{
			return containerWidth;
		}

		unsigned int Packer::getContainerHeight()
		{
			return containerHeight;
		}

		void Packer::calculateCurrentPower()
		{
			containerWidth = Utility::power(2, currentPower);
			containerHeight = Utility::power(2, currentPower);
		}

		bool Packer::incrementContainerSize()
		{
			currentPower++;
			calculateCurrentPower();

			if(containerWidth > maximumImageWidth || containerHeight > maximumImageHeight)
			{
				currentPower--;
				calculateCurrentPower();

				return false;
			}

			return true;
		}
	}
}