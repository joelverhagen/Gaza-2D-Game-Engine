#include "Card.h"

sf::Image * Card::image = NULL;

void Card::initialize(sf::Image * inputImage)
{
	image = inputImage;
}

Card::Card(SpriteSheet &spriteSheet)
{
	sprite.SetImage(*image);

	sprite.SetColor(sf::Color(255, 0, 0));
}

sf::Sprite Card::getSprite()
{
	return sprite;
}