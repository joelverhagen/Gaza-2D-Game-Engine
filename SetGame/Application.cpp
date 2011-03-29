#include "Application.hpp"

Application::Application()
{
	Gaza::FrameSheet frameSheet(&imageManager);
	bool success = frameSheet.loadFromFile("cardFrames.xml");
	if(!success)
	{
		setRunning(false);
		return;
	}

	CardFrameSheetGenerator generator(&imageManager, &frameSheet);
	cardSprites = generator.generate();

	changeState(new GameState(this, cardSprites));
}

Application::~Application()
{
	delete cardSprites;
}

Gaza::ImageManager * Application::getImageManager()
{
	return &imageManager;
}