#include "Card.hpp"

Card::Card(CardColor cardColor, CardNumber cardNumber, CardPattern cardPattern, CardShape cardShape, Gaza::FrameSheetCollection * cardSprites)
{
	unselectedFrame = 0;
	selectedFrame = 0;

	this->cardColor = cardColor;
	this->cardNumber = cardNumber;
	this->cardPattern = cardPattern;
	this->cardShape = cardShape;

	std::string unselectedName = getSpriteName(cardColor, cardNumber, cardPattern, cardShape)+"Unselected";
	unselectedFrame = cardSprites->getFrame(unselectedName);

	if(unselectedFrame == 0)
	{
		Gaza::Logger::getInstance()->write("Sprite of name \""+unselectedName+"\" could not be found.");
		return;
	}

	std::string selectedName = getSpriteName(cardColor, cardNumber, cardPattern, cardShape)+"Selected";
	selectedFrame = cardSprites->getFrame(selectedName);

	if(selectedFrame == 0)
	{
		Gaza::Logger::getInstance()->write("Sprite of name \""+selectedName+"\" could not be found.");
		return;
	}

	setSelected(false);
}

Card::~Card()
{

}

CardColor Card::getCardColor()
{
	return cardColor;
}

CardNumber Card::getCardNumber()
{
	return cardNumber;
}

CardPattern Card::getCardPattern()
{
	return cardPattern;
}

CardShape Card::getCardShape()
{
	return cardShape;
}

bool Card::getSelected()
{
	return selected;
}

void Card::setSelected(bool selected)
{
	this->selected = selected;
	if(selected)
	{
		SetImage(*selectedFrame->image);
		SetSubRect(selectedFrame->rectangle);
	}
	else
	{
		SetImage(*unselectedFrame->image);
		SetSubRect(unselectedFrame->rectangle);
	}
}

void Card::toggleSelected()
{
	setSelected(!selected);
}

std::string Card::getSpriteName(CardColor cardColor, CardNumber cardNumber, CardPattern cardPattern, CardShape cardShape)
{
	std::string name;

	switch(cardColor)
	{
	case GREEN:
		name += "green";
		break;
	case PURPLE:
		name += "purple";
		break;
	case RED:
		name += "red";
		break;
	}

	switch(cardNumber)
	{
	case ONE:
		name += "One";
		break;
	case TWO:
		name += "Two";
		break;
	case THREE:
		name += "Three";
		break;
	}

	switch(cardPattern)
	{
	case EMPTY:
		name += "Empty";
		break;
	case SOLID:
		name += "Solid";
		break;
	case STRIPED:
		name += "Striped";
		break;
	}

	switch(cardShape)
	{
	case DIAMOND:
		name += "Diamond";
		break;
	case OVAL:
		name += "Oval";
		break;
	case SQUIGGLY:
		name += "Squiggly";
		break;
	}

	return name;
}