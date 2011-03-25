// #include <vld.h>

#include <iostream>
using namespace std;

#include "GazaImageManager.hpp"
#include "GazaSpriteSheet.hpp"
#include "GazaSprite.hpp"
#include "CardSpriteSheetGenerator.hpp"
#include "GazaUtility.hpp"

#include "SFML/Graphics.hpp"

int main()
{
	Gaza::ImageManager * imageManager = new Gaza::ImageManager();

	Gaza::SpriteSheet * spriteSheet = new Gaza::SpriteSheet(imageManager);
	spriteSheet->loadFromFile("cardSprites.xml");

	CardSpriteSheetGenerator * generator = new CardSpriteSheetGenerator(imageManager, spriteSheet);
	Gaza::SpriteSheetCollection * collection = generator->generate();

	delete spriteSheet;

	Gaza::Sprite * gSprite = collection->getSprite("greenOneStripedOvalUnselected");

	if(gSprite == 0)
	{
		return 0;
	}

	sf::Sprite sprite;

	sprite.SetImage(*gSprite->image);
	sprite.SetSubRect(gSprite->rectangle);

	sf::RenderWindow window(sf::VideoMode(400, 400), "Test");

	bool running = true;

	sf::Event event;
	while(running)
	{
		while(window.GetEvent(event))
		{
			if(event.Type == sf::Event::Closed)
			{
				running = false;
			}
		}

		window.Clear();

		window.Draw(sprite);

		window.Display();
	}

	delete collection;
	delete generator;
	delete imageManager;

	return 0;
}