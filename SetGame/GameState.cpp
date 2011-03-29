#include "GameState.hpp"

GameState::GameState(Gaza::Application * application, Gaza::FrameSheetCollection * cardFrames) : Gaza::BaseState(application)
{
	table = new Table(cardFrames, sf::Vector2f(5, 5));
	this->cardFrames = cardFrames;

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
		else if(event.Type == sf::Event::MouseButtonPressed && event.MouseButton.Button == sf::Mouse::Left)
		{
			table->handleClick(application->getRenderWindow()->GetInput().GetMouseX(), application->getRenderWindow()->GetInput().GetMouseY());
		}
	}
}

void GameState::update()
{

}

void GameState::draw()
{
	application->getRenderWindow()->Clear(sf::Color(102, 179, 255));
	
	table->draw(application->getRenderWindow());

	application->getRenderWindow()->Display();
}