#include "HighlightSpot.hpp"

HighlightSpot::HighlightSpot(Gaza::FrameSheetCollection * cardSprites)
{
	std::vector<Gaza::Frame *> frames;
	for(int i = 0; i < 10; i++)
	{
		frames.push_back(cardSprites->getFrame("highlightSpot" + Gaza::Utility::intToString(i)));
	}

	setFrames(frames);
	setFrameRate(0);
}