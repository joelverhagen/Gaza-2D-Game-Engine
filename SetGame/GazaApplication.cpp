#include "GazaApplication.hpp"

namespace Gaza
{
	Application::Application()
	{
		running = true;

		videoMode = new sf::VideoMode(600, 600, 32);
		renderWindow = new sf::RenderWindow(*videoMode, "Gaza Engine");
		renderWindow->SetFramerateLimit(60);

		stateManager = new StateManager();
	}

	Application::~Application()
	{
		delete stateManager;
		delete renderWindow;
		delete videoMode;
	}

	int Application::run()
	{
		initialize();

		while(running)
		{
			stateManager->currentState()->handleEvents(this);
			stateManager->currentState()->update(this);
			stateManager->currentState()->draw(this);
		}

		cleanup();

		return 0;
	}

	void Application::setRunning(bool running)
	{
		this->running = running;
	}

	bool Application::getRunning()
	{
		return running;
	}

	sf::RenderWindow * Application::getRenderWindow()
	{
		return renderWindow;
	}
}