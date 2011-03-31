#ifndef TABLE_HPP
#define TABLE_HPP

#include "GazaApplication.hpp"

#include "Common.hpp"
#include "Card.hpp"
#include "EmptySpot.hpp"
#include "Deck.hpp"
#include "HighlightSpot.hpp"

#include <vector>
#include <map>

class Table
{
public:
	Table(Gaza::FrameSheetCollection * cardSprites, Gaza::Application * application, sf::Vector2f &position = sf::Vector2f(0, 0));
	~Table();

	void draw(sf::RenderTarget * renderTarget);

	void handleClick(int x, int y);

	unsigned int getWidth();
	unsigned int getHeight();

	std::vector<std::vector<Card *> > getValidTriples();
	bool validTriple(Card * a, Card * b, Card * c);
	bool validTripleExists();

	void update();

	int getCardIndex(Card * card);

private:
	const unsigned int static cardColumns = 7;
	const unsigned int static cardRows = 3;
	const unsigned int static maximumCards = cardColumns * cardRows;

	int spacingX;
	int spacingY;

	unsigned int cardWidth;
	unsigned int cardHeight;

	sf::Vector2f getIndexPosition(int index);
	int getIndexFromCoordinates(int x, int y);
	int getIndexFromSpot(unsigned int spotX, unsigned int spotY);

	void addCard(Card * card);
	void selectCard(Card * card);
	void removeCard(Card * card);

	Gaza::Application * application;

	sf::Vector2f position;
	Gaza::FrameSheetCollection * cardSprites;
	
	std::vector<Gaza::Sprite *> sprites; // keep track of all sprites for drawing
	
	EmptySpot * emptySpots[maximumCards]; // keep track of indices of empty spots
	Card * cards[maximumCards]; // keep track of indices of cards

	std::vector<Card *> selectedCards; // keep track of selected cards

	Deck * deck;
};

#endif