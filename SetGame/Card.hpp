#ifndef CARD_HPP
#define CARD_HPP

#include "Common.hpp"

#include "GazaSubImage.hpp"
#include "GazaSpriteSheetCollection.hpp"
#include "GazaLogger.hpp"

#include <string>

class Card
{
public:
	Card(CardColor cardColor, CardNumber cardNumber, CardPattern cardPattern, CardShape cardShape, Gaza::SpriteSheetCollection * cardSprites);

	void draw(sf::RenderTarget &target);

	CardColor getCardColor();
	CardNumber getCardNumber();
	CardPattern getCardPattern();
	CardShape getCardShape();

	bool getSelected();
	void toggleSelected();

private:
	static std::string getSpriteName(CardColor cardColor, CardNumber cardNumber, CardPattern cardPattern, CardShape cardShape);

	bool selected;

	CardColor cardColor;
	CardNumber cardNumber;
	CardPattern cardPattern;
	CardShape cardShape;

	sf::Sprite unselectedSprite;
	sf::Sprite selectedSprite;
};

#endif