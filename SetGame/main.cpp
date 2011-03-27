// #include <vld.h>

#include "Application.hpp"


int main()
{
	/* Gaza::ImageManager * imageManager = new Gaza::ImageManager();

	Gaza::SpriteSheet * spriteSheet = new Gaza::SpriteSheet(imageManager);
	spriteSheet->loadFromFile("cardSprites.xml");

	CardSpriteSheetGenerator * generator = new CardSpriteSheetGenerator(imageManager, spriteSheet);
	Gaza::SpriteSheetCollection * collection = generator->generate();

	delete spriteSheet;

	Gaza::Sprite * gSprite = collection->getSprite("greenOneStripedOvalUnselected");

	sf::Sprite sprite;

	if(gSprite != 0)
	{
		sprite.SetImage(*gSprite->image);
		sprite.SetSubRect(gSprite->rectangle);
	} */

	Application application;

	return application.run();
}