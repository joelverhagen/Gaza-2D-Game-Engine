#include "Application.hpp"

Application::Application()
{
	cardSprites = 0;

	Gaza::FrameSheet frameSheet(&imageManager);
	bool success = frameSheet.loadFromFile("cardFrames.xml");
	if(!success)
	{
		setRunning(false);
		return;
	}

	CardFrameSheetGenerator generator(&imageManager, &frameSheet);
	cardSprites = generator.generate();

	GameState * gameState = GameState::getInstance();

	gameState->setCardSprites(cardSprites);

	changeState(gameState);
}

Application::~Application()
{
	if(cardSprites != 0)
	{
		delete cardSprites;
	}
}

Gaza::ImageManager * Application::getImageManager()
{
	return &imageManager;
}