#include "GazaSprite.hpp"

namespace Gaza
{
	Sprite::Sprite()
	{

	}

	void Sprite::click()
	{

	}

	void Sprite::update(float timeElapsed)
	{

	}

	void Sprite::setFrame(Frame * frame)
	{
		SetImage(*frame->image);
		SetSubRect(frame->rectangle);
	}
}