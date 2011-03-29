#ifndef EMPTYSPOT_HPP
#define EMPTYSPOT_HPP

#include "GazaFrameSheetCollection.hpp"
#include "GazaFrame.hpp"
#include "GazaSprite.hpp"

#include "Common.hpp"


class EmptySpot : public Gaza::Sprite
{
public:
	EmptySpot(Gaza::FrameSheetCollection * cardFrames);

private:
	Gaza::FrameSheetCollection * cardFrames;
};

#endif