#include "GameState.hpp"

GameState GameState::instance;

void GameState::initialize()
{

}

void GameState::cleanup()
{

}

void GameState::handleEvents(Gaza::Application * application)
{
	sf::Event event;
	while(application->getRenderWindow()->GetEvent(event))
	{
		if(event.Type == sf::Event::Closed)
		{
			application->setRunning(false);
		}
	}
}

void GameState::update(Gaza::Application * application)
{

}

void GameState::draw(Gaza::Application * application)
{

}

GameState * GameState::getInstance()
{
	return &instance;
}