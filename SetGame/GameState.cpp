#include "GameState.hpp"

GameState::GameState(Gaza::Application * application, Gaza::FrameSheetCollection * cardFrames) : Gaza::BaseState(application)
{
	this->cardFrames = cardFrames;

	score = 0;

	table = new Table(cardFrames, &score, application, sf::Vector2f(5, 5));
	gameControls = new GameControls(table->getWidth(), &score, application, sf::Vector2f(0.f, (float)table->getHeight()));

	application->setSize(table->getWidth(), table->getHeight() + gameControls->getHeight());
}

GameState::~GameState()
{
	delete table;
	delete gameControls;
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
	gameControls->update();
}

void GameState::draw()
{
	application->getRenderWindow()->Clear(sf::Color(51, 153, 51));
	
	table->draw(application->getRenderWindow());
	gameControls->draw(application->getRenderWindow());

	application->getRenderWindow()->Display();
}