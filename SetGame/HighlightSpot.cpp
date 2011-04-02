#include "HighlightSpot.hpp"

HighlightSpot::HighlightSpot(Gaza::FrameSheetCollection * cardSprites) : Gaza::AnimatedSprite(cardSprites->getAnimationFrameList("highlightSpot"), 20, 1)
{

}