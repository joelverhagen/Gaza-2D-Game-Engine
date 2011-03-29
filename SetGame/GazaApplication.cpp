#include "GazaApplication.hpp"

namespace Gaza
{
	Application::Application()
	{
		running = true;

		initialWindowWidth = 400;
		initialWindowHeight = 400;

		videoMode = 0;
		renderWindow = 0;
	}

	Application::~Application()
	{
		while(states.size() > 0)
		{
			delete states.top();
			states.pop();
		}

		delete renderWindow;
		delete videoMode;

		delete Logger::getInstance();
	}

	int Application::run()
	{
		videoMode = new sf::VideoMode(initialWindowWidth, initialWindowHeight, 32);

		renderWindow = new sf::RenderWindow(*videoMode, "Gaza Engine");

		renderWindow->SetFramerateLimit(60);

		while(running && states.size() > 0)
		{
			states.top()->handleEvents();

			states.top()->update();

			renderWindow->Clear(sf::Color::Black);
			states.top()->draw();
			renderWindow->Display();
		}

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

	void Application::changeState(BaseState * state)
	{
		if(!states.empty())
		{
			delete states.top();
			states.pop();
		}

		states.push(state);
	}

	void Application::setInitialWindowWidth(unsigned int initialWindowWidth)
	{
		this->initialWindowWidth = initialWindowWidth;
	}
	
	void Application::setInitialWindowHeight(unsigned int initialWindowHeight)
	{
		this->initialWindowHeight = initialWindowHeight;
	}
}