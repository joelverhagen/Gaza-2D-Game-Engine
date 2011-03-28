#include "GameState.hpp"

GameState * GameState::instance = 0;

GameState::GameState()
{

}

GameState::~GameState()
{
	cleanup();
}

void GameState::setCardSprites(Gaza::SpriteSheetCollection * cardSprites)
{
	this->cardSprites = cardSprites;
}

void GameState::initialize()
{
	cleanup();
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
	if(instance == 0)
	{
		instance = new GameState();
	}

	return instance;
}