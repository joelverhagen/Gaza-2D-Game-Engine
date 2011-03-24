#include "GazaSprite.hpp"

namespace Gaza
{
	Sprite::Sprite()
	{
		image = 0;
	}

	Sprite::Sprite(sf::IntRect &rectangle, sf::Image * image)
	{
		this->rectangle = rectangle;
		this->image = image;
	}
}