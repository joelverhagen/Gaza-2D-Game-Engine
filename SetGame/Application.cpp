#include "Application.hpp"

void Application::initialize()
{
	imageManager = new Gaza::ImageManager();
	
	stateManager->addState(GameState::getInstance());
}

void Application::cleanup()
{
	delete imageManager;
}

Gaza::ImageManager * Application::getImageManager()
{
	return imageManager;
}