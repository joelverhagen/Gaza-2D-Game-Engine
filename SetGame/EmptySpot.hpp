#ifndef EMPTYSPOT_HPP
#define EMPTYSPOT_HPP

#include "GazaFrameSheetCollection.hpp"
#include "GazaFrame.hpp"

#include "Common.hpp"


class EmptySpot : public sf::Sprite
{
public:
	EmptySpot(Gaza::FrameSheetCollection * cardSprites);

private:
	Gaza::FrameSheetCollection * cardSprites;
};

#endif