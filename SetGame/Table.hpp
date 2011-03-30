#ifndef TABLE_HPP
#define TABLE_HPP

#include "Common.hpp"
#include "Card.hpp"
#include "EmptySpot.hpp"
#include "Deck.hpp"

#include <vector>
#include <map>

class Table
{
public:
	Table(Gaza::FrameSheetCollection * cardSprites, sf::Vector2f &position = sf::Vector2f(0, 0));
	~Table();

	void draw(sf::RenderTarget * renderTarget);

	void handleClick(int x, int y);

	unsigned int getWidth();
	unsigned int getHeight();

private:
	unsigned int static cardColumns;
	unsigned int static cardRows;
	unsigned int static initialCards;

	int spacingX;
	int spacingY;

	unsigned int cardWidth;
	unsigned int cardHeight;

	sf::Vector2f getIndexPosition(int index);
	int getIndexFromCoordinates(int x, int y);
	int getIndexFromSpot(unsigned int spotX, unsigned int spotY);

	void handleCardClick(Card * card);

	bool validTriple(Card * a, Card * b, Card * c);
	bool validTripleExists();

	sf::Vector2f position;
	Gaza::FrameSheetCollection * cardSprites;
	
	std::vector<Gaza::Sprite *> sprites;
	std::vector<Card *> cards;
	std::vector<Card *> selectedCards;

	Deck * deck;
};

#endif