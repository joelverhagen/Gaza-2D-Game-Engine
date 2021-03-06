#ifndef TABLE_HPP
#define TABLE_HPP

#include "GazaApplication.hpp"
#include "GazaWindowPanel.hpp"

#include "Common.hpp"
#include "Card.hpp"
#include "EmptySpot.hpp"
#include "Deck.hpp"
#include "HighlightSpot.hpp"

#include <vector>
#include <map>

class Table : public Gaza::WindowPanel
{
public:
	Table(Gaza::FrameSheetCollection * cardSprites, int * score, Gaza::Application * application, sf::Vector2f &position = sf::Vector2f(0, 0));
	~Table();

	unsigned int getWidth();
	unsigned int getHeight();

	void handleClick(int x, int y);
	void update();
	void draw(sf::RenderTarget * renderTarget);

	std::vector<std::vector<Card *> > getValidTriples();
	bool validTriple(Card * a, Card * b, Card * c);
	bool validTripleExists();

	void highlightValidTriple();

	int getCardIndex(Card * card);

private:
	const unsigned int static cardColumns = 7;
	const unsigned int static cardRows = 3;
	const unsigned int static maximumCards = cardColumns * cardRows;

	int spacingX;
	int spacingY;

	int * score;

	unsigned int cardWidth;
	unsigned int cardHeight;

	sf::Vector2f getIndexPosition(int index);
	int getIndexFromCoordinates(int x, int y);
	int getIndexFromSpot(unsigned int spotX, unsigned int spotY);

	void ensureValidTripleExists();

	void addCard(Card * card);
	void selectCard(Card * card);
	void removeCard(Card * card);

	void removeSprite(Gaza::Sprite * sprite);

	Gaza::FrameSheetCollection * cardSprites;
	
	std::vector<Gaza::Sprite *> sprites; // keep track of all sprites for drawing
	
	EmptySpot * emptySpots[maximumCards]; // keep track of indices of empty spots
	Card * cards[maximumCards]; // keep track of indices of cards

	std::vector<Card *> selectedCards; // keep track of selected cards
	std::vector<HighlightSpot *> highlightSpots;

	Deck * deck;
};

#endif