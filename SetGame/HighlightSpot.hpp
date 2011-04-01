#ifndef HIGHLIGHTSPOT_HPP
#define HIGHLIGHTSPOT_HPP

#include "GazaFrameSheetCollection.hpp"
#include "GazaAnimatedSprite.hpp"

#include <vector>

class HighlightSpot : public Gaza::AnimatedSprite
{
public:
	HighlightSpot(Gaza::FrameSheetCollection * cardSprites);

private:
	Gaza::FrameSheetCollection * cardFrames;
};

#endif