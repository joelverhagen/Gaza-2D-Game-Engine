#include "Application.hpp"

Application::Application()
{
	Gaza::SpriteSheet spriteSheet(&imageManager);
	spriteSheet.loadFromFile("cardSprites.xml");

	CardSpriteSheetGenerator generator(&imageManager, &spriteSheet);
	cardSprites = generator.generate();

	GameState * gameState = GameState::getInstance();
	gameState->setCardSprites(cardSprites);
	changeState(gameState);
}

Application::~Application()
{
	delete cardSprites;
}

Gaza::ImageManager * Application::getImageManager()
{
	return &imageManager;
}