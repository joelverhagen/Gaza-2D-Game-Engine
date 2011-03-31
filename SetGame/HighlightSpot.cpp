#include "HighlightSpot.hpp"

HighlightSpot::HighlightSpot(Gaza::FrameSheetCollection * cardSprites)
{
	setFrames(cardSprites->getAnimationFrameList("highlightSpot"));
	setFrameRate(60);
}