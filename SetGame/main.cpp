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

	Gaza::Sprite * gSprite = collection->getSprite("redTwoStripedOvalUnselected");

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

	return 0;
}