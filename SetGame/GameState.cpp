#include "GameState.hpp"

GameState::GameState(Gaza::Application * application, Gaza::FrameSheetCollection * cardFrames) : Gaza::BaseState(application)
{
	table = new Table(cardFrames, application, sf::Vector2f(5, 5));
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
		else if(event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Z)
		{
			table->highlightValidTriple();
		}
	}
}

void GameState::update()
{
	table->update();
}

void GameState::draw()
{
	application->getRenderWindow()->Clear(sf::Color(51, 153, 51));
	
	table->draw(application->getRenderWindow());

	application->getRenderWindow()->Display();
}