#ifndef GAZAFRAME_HPP
#define GAZAFRAME_HPP

#include "Gaza.hpp"

namespace Gaza
{
	class Frame
	{
	public:
		Frame();
		Frame(const sf::IntRect &rectangle, sf::Image * image);

		sf::IntRect rectangle;
		sf::Image * image;
	};
}

#endif