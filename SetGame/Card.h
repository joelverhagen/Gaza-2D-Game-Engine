#ifndef CARD_H
#define CARD_H

#include "Common.h"
#include "SpriteSheet.h"

class Card
{
private:
	static sf::Image * image;
	sf::IntRect rectangle;
	sf::Sprite sprite;
public:
	static void initialize(sf::Image * image);
	Card(SpriteSheet &spriteSheet);

	sf::Sprite getSprite();
};

#endif