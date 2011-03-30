#include "Deck.hpp"

Deck::Deck(Gaza::FrameSheetCollection * cardSprites)
{
	CardColor cardColors[3];
	cardColors[0] = GREEN;
	cardColors[1] = PURPLE;
	cardColors[2] = RED;

	CardNumber cardNumbers[3];
	cardNumbers[0] = ONE;
	cardNumbers[1] = TWO;
	cardNumbers[2] = THREE;

	CardPattern cardPatterns[3];
	cardPatterns[0] = EMPTY;
	cardPatterns[1] = SOLID;
	cardPatterns[2] = STRIPED;

	CardShape cardShapes[3];
	cardShapes[0] = DIAMOND;
	cardShapes[1] = OVAL;
	cardShapes[2] = SQUIGGLY;

	std::vector<Card *> cardList;

	for(int c = 0; c < 3; c++)
	{
		for(int n = 0; n < 3; n++)
		{
			for(int p = 0; p < 3; p++)
			{
				for(int s = 0; s < 3; s++)
				{
					cardList.push_back(new Card(cardColors[c], cardNumbers[n], cardPatterns[p], cardShapes[s], cardSprites));
				}
			}
		}
	}

	// Gaza::Utility::shuffle<Card *>(cardList);

	for(unsigned int i = 0; i < cardList.size(); i++)
	{
		cards.push(cardList[i]);
	}
}

Deck::~Deck()
{
	while(cards.size() > 0)
	{
		delete cards.top();
		cards.pop();
	}
}

Card * Deck::drawCard()
{
	if(cards.size() == 0)
	{
		return 0;
	}

	Card * card = cards.top();
	cards.pop();
	
	return card;
}