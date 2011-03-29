#ifndef GAZASPRITE_HPP
#define GAZASPRITE_HPP

#include "Gaza.hpp"

namespace Gaza
{
	class Sprite : public sf::Sprite
	{
	public:
		Sprite();

		virtual void click();
	};
}

#endif