#ifndef GAZASPRITE_HPP
#define GAZASPRITE_HPP

#include "Gaza.hpp"

namespace Gaza
{
	class Sprite
	{
	public:
		Sprite();
		Sprite(sf::IntRect &rectangle, sf::Image * image);

		sf::IntRect rectangle;
		sf::Image * image;
	};
}

#endif