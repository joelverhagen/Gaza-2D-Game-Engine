#include "GameState.hpp"

GameState::GameState(Gaza::Application * application, Gaza::FrameSheetCollection * cardSprites) : Gaza::BaseState(application)
{
	table = new Table(cardSprites, sf::Vector2f(5, 5));
	this->cardSprites = cardSprites;

	application->setSize(table->getWidth(), table->getHeight());
}

GameState::~GameState()
{
	delete table;
}

void GameState::handleEvents()
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

void GameState::update()
{

}

void GameState::draw()
{
	table->draw(application->getRenderWindow());
}