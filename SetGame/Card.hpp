#ifndef CARD_HPP
#define CARD_HPP

#include "Common.hpp"

#include "GazaSprite.hpp"
#include "GazaSpriteSheetCollection.hpp"

#include <string>

class Card
{
public:
	Card(CardColor cardColor, CardNumber cardNumber, CardPattern cardPattern, CardShape cardShape, Gaza::SpriteSheetCollection * cardSprites);

private:
	static std::string getSpriteName(CardColor cardColor, CardNumber cardNumber, CardPattern cardPattern, CardShape cardShape);

	CardColor cardColor;
	CardNumber cardNumber;
	CardPattern cardPattern;
	CardShape cardShape;

	sf::Sprite sprite;
};

#endif