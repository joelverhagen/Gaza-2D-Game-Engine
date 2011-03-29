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

void Table::handleClick(int x, int y)
{
	int index = getIndexFromCoordinates(x, y);
	if(index == -1)
    {
        return;
    }
}

unsigned int Table::getWidth()
{
	return cardColumns * (cardWidth + spacingX) + spacingX;
}

unsigned int Table::getHeight()
{
	return cardRows * (cardHeight + spacingY) + spacingY;
}

sf::Vector2f Table::getIndexPosition(int index)
{
	return sf::Vector2f(position.x + (index / cardRows) * (cardWidth + spacingX), position.y + (index % cardRows) * (cardHeight + spacingY));
}

int Table::getIndexFromCoordinates(int x, int y)
{
	// set mouse coordinate origin to the upper left corner of the table card draw area
	x -= (int)position.x;
	y -= (int)position.y;

	// if the the adjusted mouse coordinate are less than zero, quit
	if (x < 0 || y < 0)
	{
		return -1;
	}

	// check whether the click was inside the padding between cards
	if (x % (cardWidth + spacingX) >= cardWidth || (y % (cardHeight + spacingY) >= cardHeight))
	{
		return -1;
	}

	// normalize the mouse coordinates to the upper left corner of the card being selected
	x -= (x % (cardWidth + spacingX));
	y -= (y % (cardHeight + spacingY));

	// calculate the xSlot and ySlot base on the mouse coordinates
	unsigned int spotX = x / cardWidth;
	unsigned int spotY = y / cardHeight;

	// if the xSlot or ySlot are outside the possible card table size, quit
	if (spotX >= cardColumns || spotY >= cardRows)
	{
		return -1;
	}

	return getIndexFromSpot(spotX, spotY);
}

int Table::getIndexFromSpot(unsigned int spotX, unsigned int spotY)
{
    return spotY + cardRows * spotX;
}