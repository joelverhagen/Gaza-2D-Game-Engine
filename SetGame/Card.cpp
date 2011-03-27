#include "Card.hpp"

std::string Card::getSpriteName(CardColor cardColor, CardNumber cardNumber, CardPattern cardPattern, CardShape cardShape)
{
	std::string name;

	switch(cardColor)
	{
	case green:
		name += "green";
		break;
	case purple:
		name += "purple";
		break;
	case red:
		name += "red";
		break;
	}

	switch(cardNumber)
	{
	case one:
		name += "One";
		break;
	case two:
		name += "Two";
		break;
	case three:
		name += "Three";
		break;
	}

	switch(cardPattern)
	{
	case empty:
		name += "Empty";
		break;
	case solid:
		name += "Solid";
		break;
	case striped:
		name += "Striped";
		break;
	}

	switch(cardShape)
	{
	case diamond:
		name += "Diamond";
		break;
	case oval:
		name += "Oval";
		break;
	case squiggly:
		name += "Squiggly";
		break;
	}

	return name;
}

Card::Card(CardColor cardColor, CardNumber cardNumber, CardPattern cardPattern, CardShape cardShape, Gaza::SpriteSheetCollection * cardSprites)
{
	this->cardColor = cardColor;
	this->cardNumber = cardNumber;
	this->cardPattern = cardPattern;
	this->cardShape = cardShape;

	Gaza::Sprite * subImage = cardSprites->getSprite(getSpriteName(cardColor, cardNumber, cardPattern, cardShape));
	sprite.SetImage(*subImage->image);
	sprite.SetSubRect(subImage->rectangle);
}