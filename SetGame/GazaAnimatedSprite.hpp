#ifndef GAZAANIMATEDSPRITE_HPP
#define GAZAANIMATEDSPRITE_HPP

#include "Gaza.hpp"
#include "GazaSprite.hpp"

#include <vector>

namespace Gaza
{
	class AnimatedSprite : public Sprite
	{
	public:
		AnimatedSprite();
		AnimatedSprite(const std::vector<Frame *> &frames, int frameRate = 0);

		void update(float timeElapsed); // input the time since the last update
		
		void setFrames(const std::vector<Frame *> &frames); // setter for the frames vector

		// setter indirectly for the frameDelta value. input is in frames per second
		// if 0 is used for the frameRate, then the frame increments at every update
		void setFrameRate(unsigned int frameRate); 
		
	private:
		std::vector<Frame *> frames; // holds all of the frames of the animation in order
		int currentFrame; // the index of the current frame in the frames vector
		float frameDelta; // in seconds per frame
	};
}

#endif