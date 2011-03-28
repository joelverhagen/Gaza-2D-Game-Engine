#include "EmptySpot.hpp"

EmptySpot::EmptySpot(Gaza::FrameSheetCollection * cardSprites)
{
	this->cardSprites = cardSprites;

	Gaza::Frame * emptySpotFrame = cardSprites->getFrame("emptySpot");

	SetImage(*emptySpotFrame->image);
	SetSubRect(emptySpotFrame->rectangle);
}