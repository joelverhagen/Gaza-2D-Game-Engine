#include "Application.hpp"

Application::Application()
{
	getRenderWindow()->SetTitle("Set");

	Gaza::FrameSheet frameSheet(&imageManager);
	bool success = frameSheet.loadFromFile("cardFrames.xml");
	if(!success)
	{
		setRunning(false);
		return;
	}

	// frameSheet.saveToMemory();

	// setRunning(false);

	CardFrameSheetGenerator generator(&imageManager, &frameSheet);
	cardFrames = generator.generate();

	changeState(new GameState(this, cardFrames));
}

Application::~Application()
{
	delete cardFrames;
}

Gaza::ImageManager * Application::getImageManager()
{
	return &imageManager;
}