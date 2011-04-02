#include "GazaAnimatedSprite.hpp"

namespace Gaza
{
	AnimatedSprite::AnimatedSprite()
	{
		frameDelta = 0.f; // in seconds
		loopMaximum = 0;

		currentFrame = 0;
		timeElapsed = 0.f;
		loopCount = 0;
		finished = false;
	}

	AnimatedSprite::AnimatedSprite(const std::vector<Frame *> &frames, int frameRate, int loopMaximum)
	{
		setFrames(frames);
		setFrameRate(frameRate);
		this->loopMaximum = loopMaximum;

		currentFrame = 0;
		timeElapsed = 0.f;
		loopCount = 0;
		finished = false;
	}

	void AnimatedSprite::update(float frameTime)
	{
		if(frames.size() > 0 && !finished)
		{
			if(frameDelta == 0.f) // run the animation at the speed of updates
			{
				currentFrame = (currentFrame + 1) % frames.size();

				if(currentFrame == 0)
				{
					loopCount++;

					if(checkLoopCount())
					{
						return;
					}
				}
			}
			else
			{
				timeElapsed += frameTime;

				while(timeElapsed > frames.size() * frameDelta) // eliminate unnecessary full loop arounds
				{
					timeElapsed -= frames.size() * frameDelta;

					if(checkLoopCount())
					{
						return;
					}
				}

				while(timeElapsed > frameDelta) // skip frames to catch up
				{
					currentFrame = (currentFrame + 1) % frames.size();
					timeElapsed -= frameDelta;
					
					if(currentFrame == 0)
					{
						loopCount++;

						if(checkLoopCount())
						{
							return;
						}
					}
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

	bool AnimatedSprite::checkLoopCount()
	{
		if(loopCount >= loopMaximum && loopMaximum != 0)
		{
			finished = true;
			return true;
		}
		return false;
	}
}