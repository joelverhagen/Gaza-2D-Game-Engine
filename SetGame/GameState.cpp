#include "GameState.hpp"

GameState * GameState::instance = 0;

GameState::GameState()
{
	table = 0;
}

void GameState::setCardSprites(Gaza::FrameSheetCollection * cardSprites)
{
	this->cardSprites = cardSprites;
}

void GameState::initialize()
{
	cleanup();

	table = new Table(cardSprites, sf::Vector2f(10, 20));
}

void GameState::cleanup()
{
	if(table != 0)
	{
		delete table;
	}
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
	table->draw(application->getRenderWindow());
}

GameState * GameState::getInstance()
{
	if(instance == 0)
	{
		instance = new GameState();
	}

	return instance;
}