#ifndef DECK_HPP
#define DECK_HPP

#include "GazaSpriteSheetCollection.hpp"

#include "Common.hpp"
#include "Card.hpp"

#include <vector>
#include <stack>

class Deck
{
public:
	Deck(Gaza::SpriteSheetCollection * cardSprites);
	~Deck();

	Card * drawCard();

private:
	std::stack<Card *> cards;

};

#endif