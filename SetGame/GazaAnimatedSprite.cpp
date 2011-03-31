#include "GazaAnimatedSprite.hpp"

namespace Gaza
{
	AnimatedSprite::AnimatedSprite()
	{
		currentFrame = 0;
		frameDelta = 0.f; // in seconds
	}

	void AnimatedSprite::update(float timeElapsed)
	{
		if(frames.size() > 0)
		{
			if(frameDelta == 0.f) // run the animation at the speed of updates
			{
				currentFrame++;
			}
			else
			{
				while(timeElapsed > frames.size() * frameDelta) // eliminate unnecessary full loop arounds
				{
					timeElapsed -= frames.size() * frameDelta;
				}

				while(timeElapsed > frameDelta) // skip frames to catch up
				{
					currentFrame = (currentFrame + 1) % frames.size();
					timeElapsed -= frameDelta;
				}
			}

			setFrame(frames[currentFrame]);
		}
	}

	void AnimatedSprite::setFrames(const std::vector<Frame *> &frames)
	{
		this->frames = frames;
	}

	void AnimatedSprite::setFrameRate(unsigned int frameRate)
	{
		if(frameRate == 0)
		{
			frameDelta = 0.f;
		}
		else
		{
			frameDelta = 1.f / frameRate;
		}
	}
}