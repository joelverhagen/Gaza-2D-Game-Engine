#include "GameState.hpp"

GameState * GameState::instance = 0;

GameState::GameState()
{
	deck = 0;
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

	deck = new Deck(cardSprites);
}

void GameState::cleanup()
{
	if(deck != 0)
	{
		delete deck;
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

}

GameState * GameState::getInstance()
{
	if(instance == 0)
	{
		instance = new GameState();
	}

	return instance;
}