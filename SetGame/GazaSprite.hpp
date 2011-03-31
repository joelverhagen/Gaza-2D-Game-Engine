#ifndef GAZASPRITE_HPP
#define GAZASPRITE_HPP

#include "Gaza.hpp"
#include "GazaFrame.hpp"

namespace Gaza
{
	class Sprite : public sf::Sprite
	{
	public:
		Sprite();

		virtual void click();
		virtual void update(float timeElapsed = 0.f);
		void setFrame(Frame * frame);
	};
}

#endif