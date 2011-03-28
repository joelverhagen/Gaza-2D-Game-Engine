#include "GazaApplication.hpp"

namespace Gaza
{
	Application::Application()
	{
		running = true;
		videoMode = 0;
		renderWindow = 0;
	}

	Application::~Application()
	{
		while(states.size() > 0)
		{
			states.top()->cleanup();
			delete states.top();
			states.pop();
		}

		delete renderWindow;
		delete videoMode;

		delete Logger::getInstance();
	}

	int Application::run()
	{
		videoMode = new sf::VideoMode(600, 600, 32);

		renderWindow = new sf::RenderWindow(*videoMode, "Gaza Engine");

		renderWindow->SetFramerateLimit(60);

		while(running)
		{
			states.top()->handleEvents(this);

			states.top()->update(this);

			renderWindow->Clear(sf::Color::Black);
			states.top()->draw(this);
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
			states.top()->cleanup();
			states.pop();
		}

		states.push(state);
		state->initialize();
	}
}