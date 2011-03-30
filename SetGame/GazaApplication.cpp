#include "GazaApplication.hpp"

namespace Gaza
{
	Application::Application()
	{
		running = true;

		videoMode = new sf::VideoMode(800, 600, 32);
		renderWindow = new sf::RenderWindow(*videoMode, "Gaza Engine", sf::Style::Titlebar | sf::Style::Close);
		renderWindow->Show(false);
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
		renderWindow->Show(true);

		while(running && states.size() > 0)
		{
			states.top()->handleEvents();

			states.top()->update();

			states.top()->draw();
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

	void Application::setSize(unsigned int width, unsigned int height)
	{
		renderWindow->SetSize(width, height);

		sf::View currentView = renderWindow->GetView();
		sf::View newView(sf::FloatRect(0.f, 0.f, (float)width, (float)height));

		renderWindow->SetView(newView);
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
}