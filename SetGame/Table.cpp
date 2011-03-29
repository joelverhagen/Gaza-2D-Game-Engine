#include "Table.hpp"

unsigned int Table::cardColumns = 7;
unsigned int Table::cardRows = 3;
unsigned int Table::initialCards = 12;

Table::Table(Gaza::FrameSheetCollection * cardSprites, sf::Vector2f &position)
{
	this->cardSprites = cardSprites;
	this->position = position;

	spacingX = 5;
	spacingY = 5;

	Gaza::Frame * emptySpotFrame = cardSprites->getFrame("emptySpot");
	cardWidth = emptySpotFrame->rectangle.Width;
	cardHeight = emptySpotFrame->rectangle.Height;

	deck = new Deck(cardSprites);

	for(unsigned int i = 0; i < initialCards; i++)
	{
		Card * currentCard = deck->drawCard();
		currentCard->SetPosition(getIndexPosition(i));

		table.push_back(currentCard);
	}

	for(unsigned int i = initialCards; i < 21; i++)
	{
		EmptySpot * currentEmptySpot = new EmptySpot(cardSprites);
		currentEmptySpot->SetPosition(getIndexPosition(i));

		table.push_back(currentEmptySpot);
	}
}

Table::~Table()
{
	for(unsigned i = 0; i < table.size(); i++)
	{
		delete table[i];
	}
	delete deck;
}

void Table::draw(sf::RenderTarget * renderTarget)
{
	for(unsigned i = 0; i < table.size(); i++)
	{
		renderTarget->Draw(*table[i]);
	}
}

sf::Vector2f Table::getIndexPosition(int index)
{
	return sf::Vector2f(position.x + (index / cardRows) * (cardWidth + spacingX), position.y + (index % cardRows) * (cardHeight + spacingY));
}

unsigned int Table::getWidth()
{
	return cardColumns * (cardWidth + spacingX) + spacingX;
}

unsigned int Table::getHeight()
{
	return cardRows * (cardHeight + spacingY) + spacingY;
}