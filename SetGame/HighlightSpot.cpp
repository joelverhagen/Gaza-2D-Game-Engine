#include "HighlightSpot.hpp"

HighlightSpot::HighlightSpot(Gaza::FrameSheetCollection * cardSprites) : Gaza::AnimatedSprite(cardSprites->getAnimationFrameList("highlightSpot"), 60, 1)
{

}