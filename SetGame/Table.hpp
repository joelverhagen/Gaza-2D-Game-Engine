#ifndef TABLE_HPP
#define TABLE_HPP

#include "Common.hpp"
#include "Card.hpp"
#include "EmptySpot.hpp"
#include "Deck.hpp"

#include <vector>

class Table
{
public:
	Table(Gaza::FrameSheetCollection * cardSprites, sf::Vector2f &position = sf::Vector2f(0, 0));
	~Table();

	void draw(sf::RenderTarget * renderTarget);

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

	sf::Vector2f position;
	Gaza::FrameSheetCollection * cardSprites;
	std::vector<sf::Drawable *> table;
	Deck * deck;
};

#endif