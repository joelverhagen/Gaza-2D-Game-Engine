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
	cardFrames = generator.generate();

	changeState(new GameState(this, cardFrames));

	getRenderWindow()->SetFramerateLimit(60);
}

Application::~Application()
{
	delete cardFrames;
}

Gaza::ImageManager * Application::getImageManager()
{
	return &imageManager;
}