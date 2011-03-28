#ifndef GAZSUBIMAGE_HPP
#define GAZSUBIMAGE_HPP

#include "Gaza.hpp"

namespace Gaza
{
	class SubImage
	{
	public:
		SubImage();
		SubImage(const sf::IntRect &rectangle, sf::Image * image);

		sf::IntRect rectangle;
		sf::Image * image;
	};
}

#endif