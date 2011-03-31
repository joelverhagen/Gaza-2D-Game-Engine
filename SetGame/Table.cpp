#include "Table.hpp"

Table::Table(Gaza::FrameSheetCollection * cardSprites, Gaza::Application * application, sf::Vector2f &position)
{
	this->cardSprites = cardSprites;
	this->application = application;
	this->position = position;

	spacingX = 5;
	spacingY = 5;

	Gaza::Frame * emptySpotFrame = cardSprites->getFrame("emptySpot");
	cardWidth = emptySpotFrame->rectangle.Width;
	cardHeight = emptySpotFrame->rectangle.Height;

	deck = new Deck(cardSprites);

	for(unsigned int i = 0; i < maximumCards; i++)
	{
		emptySpots[i] = 0;
		cards[i] = 0;
	}

	unsigned int initialCards = 12;
	for(unsigned int i = 0; i < initialCards; i++)
	{
		Card * currentCard = deck->drawCard();
		currentCard->SetPosition(getIndexPosition(i));

		cards[i] = currentCard;
		sprites.push_back(currentCard);

		if(i == initialCards - 1)
		{
			if(!validTripleExists())
			{
				initialCards += 3;
			}
		}
	}

	for(unsigned int i = initialCards; i < maximumCards; i++)
	{
		EmptySpot * currentEmptySpot = new EmptySpot(cardSprites);
		currentEmptySpot->SetPosition(getIndexPosition(i));

		emptySpots[i] = currentEmptySpot;
		sprites.push_back(currentEmptySpot);
	}

	HighlightSpot * highlightSpot;

	highlightSpot = new HighlightSpot(cardSprites);
	highlightSpot->setFrameRate(30);
	highlightSpot->SetPosition(5, 5);
	sprites.insert(sprites.end(), highlightSpot);
}

Table::~Table()
{
	for(unsigned i = 0; i < sprites.size(); i++)
	{
		delete sprites[i];
	}
	delete deck;
}

void Table::draw(sf::RenderTarget * renderTarget)
{
	for(unsigned i = 0; i < sprites.size(); i++)
	{
		renderTarget->Draw(*sprites[i]);
	}
}

void Table::update()
{
	for(unsigned int i = 0; i < sprites.size(); i++)
	{
		sprites[i]->update(application->getRenderWindow()->GetFrameTime());
	}
}

void Table::handleClick(int x, int y)
{
	int index = getIndexFromCoordinates(x, y);
	if(index == -1)
    {
        return;
    }

	if(cards[index] != 0)
	{
		selectCard(cards[index]);
	}
}

void Table::addCard(Card * card)
{
	unsigned int currentIndex = 0;
	while(cards[currentIndex] != 0 && currentIndex < maximumCards)
	{
		currentIndex++;
	}

	// set the proper position of the card
	card->SetPosition(getIndexPosition(currentIndex));

	// delete the empty spot
	std::vector<Gaza::Sprite *>::iterator spriteIterator = std::find(sprites.begin(), sprites.end(), emptySpots[currentIndex]);
	if(spriteIterator != sprites.end())
	{
		sprites.erase(spriteIterator);
	}

	delete emptySpots[currentIndex];
	emptySpots[currentIndex] = 0;

	// place the card
	cards[currentIndex] = card;
	sprites.push_back(card);
	cards[currentIndex] = card;
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
				for(int i = 2; i >= 0; i--)
				{
					removeCard(selectedCards[i]);
				}

				while(!validTripleExists() && deck->getCardCount() > 0)
				{
					for(int i = 0; i < 3; i++)
					{
						Card * newCard = deck->drawCard();
						if(newCard != 0)
						{
							addCard(newCard);
						}
					}
				}
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

	// remove from cards array
	for(unsigned int i = 0; i < maximumCards; i++)
	{
		if(cards[i] == card)
		{
			cards[i] = 0;

			EmptySpot * newEmptySpot = new EmptySpot(cardSprites);
			newEmptySpot->SetPosition(card->GetPosition());
			emptySpots[i] = newEmptySpot;
			sprites.push_back(newEmptySpot);
		}
	}

	// remove from pointer lists
	std::vector<Card *>::iterator cardIterator = std::find(selectedCards.begin(), selectedCards.end(), card);
	if(cardIterator != selectedCards.end())
	{
		selectedCards.erase(cardIterator);
	}

	std::vector<Gaza::Sprite *>::iterator spriteIterator = std::find(sprites.begin(), sprites.end(), card);
	if(spriteIterator != sprites.end())
	{
		sprites.erase(spriteIterator);
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
	if(getValidTriples().size() == 0)
	{
		return false;
	}
	return true;
}

std::vector<std::vector<Card *> > Table::getValidTriples()
{
	std::vector<std::vector<Card *> > triples;

	std::vector<Card *> cardVector;
	for(unsigned int i = 0; i < maximumCards; i++)
	{
		if(cards[i] != 0)
		{
			cardVector.push_back(cards[i]);
		}
	}

	if(cardVector.size() < 3)
	{
		return triples;
	}

	std::sort(cardVector.begin(), cardVector.end());

	do
	{
		if(validTriple(cardVector[0], cardVector[1], cardVector[2]))
		{
			std::vector<Card *> triple;
			triple.push_back(cardVector[0]);
			triple.push_back(cardVector[1]);
			triple.push_back(cardVector[2]);

			triples.push_back(triple);
		}
	}
	while(Gaza::Utility::next_combination(cardVector.begin(), cardVector.begin() + 3, cardVector.end()));

	return triples;
}

// returns -1 on not found
int Table::getCardIndex(Card * card)
{
	for(unsigned int i = 0; i < maximumCards; i++)
	{
		if(card == cards[i])
		{
			return i;
		}
	}
	
	return -1;
}