#include "Table.hpp"

Table::Table(Gaza::FrameSheetCollection * cardSprites, sf::Vector2f &position)
{
	initialCards = 12;

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

		sprites[i] = currentCard;
		cards.push_back(currentCard);

		if(i == initialCards - 1)
		{
			if(!validTripleExists())
			{
				initialCards += 3;
			}
		}
	}

	for(unsigned int i = initialCards; i < 21; i++)
	{
		EmptySpot * currentEmptySpot = new EmptySpot(cardSprites);
		currentEmptySpot->SetPosition(getIndexPosition(i));

		sprites[i] = currentEmptySpot;
	}
}

Table::~Table()
{
	for(unsigned i = 0; i < maximumCards; i++)
	{
		delete sprites[i];
	}
	delete deck;
}

void Table::draw(sf::RenderTarget * renderTarget)
{
	for(unsigned i = 0; i < maximumCards; i++)
	{
		renderTarget->Draw(*sprites[i]);
	}
}

void Table::handleClick(int x, int y)
{
	int index = getIndexFromCoordinates(x, y);
	if(index == -1)
    {
        return;
    }

	for(unsigned int i = 0; i < cards.size(); i++)
	{
		sf::FloatRect bounds(cards[i]->GetPosition().x, cards[i]->GetPosition().y, cards[i]->GetSize().x, cards[i]->GetSize().y);
		if(bounds.Contains((float)x, (float)y))
		{
			selectCard(cards[i]);
		}
	}
}

void Table::selectCard(Card * card)
{
	std::vector<Card *>::iterator cardIterator = std::find(selectedCards.begin(), selectedCards.end(), card);
	if(cardIterator == selectedCards.end())
	{
		if(selectedCards.size() == 3)
		{
			return;
		}
		else
		{
			card->click();
			selectedCards.push_back(card);

			if(selectedCards.size() == 3 && validTriple(selectedCards[0], selectedCards[1], selectedCards[2]))
			{
				removeCard(selectedCards[2]);
				removeCard(selectedCards[1]);
				removeCard(selectedCards[0]);
			}
		}
	}
	else
	{
		card->click();
		selectedCards.erase(cardIterator);
	}
}

void Table::removeCard(Card * card)
{
	if(card == 0)
	{
		return;
	}

	// remove from pointer lists
	std::vector<Card *>::iterator cardIterator = std::find(selectedCards.begin(), selectedCards.end(), card);
	if(cardIterator != selectedCards.end())
	{
		selectedCards.erase(cardIterator);
	}

	cardIterator = std::find(cards.begin(), cards.end(), card);
	if(cardIterator != cards.end())
	{
		cards.erase(cardIterator);
	}

	for(unsigned int i = 0; i < initialCards; i++)
	{
		if(card == sprites[i])
		{
			EmptySpot * newEmptySpot = new EmptySpot(cardSprites);
			newEmptySpot->SetPosition(card->GetPosition());

			sprites[i] = newEmptySpot;
		}
	}

	// free memory
	delete card;
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

bool Table::validTriple(Card * a, Card * b, Card * c)
{
	return (
		(
			(a->getCardShape() == b->getCardShape() && a->getCardShape() == c->getCardShape() && c->getCardShape() == b->getCardShape()) ||
			(a->getCardShape() != b->getCardShape() && a->getCardShape() != c->getCardShape() && c->getCardShape() != b->getCardShape())
		)
		&&
		(
			(a->getCardColor() == b->getCardColor() && a->getCardColor() == c->getCardColor() && c->getCardColor() == b->getCardColor()) ||
			(a->getCardColor() != b->getCardColor() && a->getCardColor() != c->getCardColor() && c->getCardColor() != b->getCardColor())
		)
		&&
		(
			(a->getCardPattern() == b->getCardPattern() && a->getCardPattern() == c->getCardPattern() && c->getCardPattern() == b->getCardPattern()) ||
			(a->getCardPattern() != b->getCardPattern() && a->getCardPattern() != c->getCardPattern() && c->getCardPattern() != b->getCardPattern())
		)
		&&
		(
			(a->getCardNumber() == b->getCardNumber() && a->getCardNumber() == c->getCardNumber() && c->getCardNumber() == b->getCardNumber()) ||
			(a->getCardNumber() != b->getCardNumber() && a->getCardNumber() != c->getCardNumber() && c->getCardNumber() != b->getCardNumber())
		)
	);
}

bool Table::validTripleExists()
{
	bool success = false;

	std::sort(cards.begin(), cards.end());

	int count = 0;
	do
	{
		count++;
		if(validTriple(cards[0], cards[1], cards[2]))
		{
			success = true;
		}
	}
	while(Gaza::Utility::next_combination(cards.begin(), cards.begin() + 3, cards.end()));

	return success;
}