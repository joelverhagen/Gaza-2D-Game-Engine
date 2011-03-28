#ifndef DECK_HPP
#define DECK_HPP

#include "GazaFrameSheetCollection.hpp"

#include "Common.hpp"
#include "Card.hpp"

#include <vector>
#include <stack>

class Deck
{
public:
	Deck(Gaza::FrameSheetCollection * cardSprites);
	~Deck();

	Card * drawCard();

private:
	std::stack<Card *> cards;

};

#endif