#include "GameState.hpp"

GameState::GameState(Gaza::Application * application, Gaza::FrameSheetCollection * cardFrames) : Gaza::BaseState(application)
{
	table = new Table(cardFrames, sf::Vector2f(5, 5));
	this->cardFrames = cardFrames;

	application->setSize(table->getWidth(), table->getHeight() + 150);
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
		else if(event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::LShift)
		{
			std::vector<std::vector<Card *> > validTriples = table->getValidTriples();
			for(int i = 0; i < validTriples.size(); i++)
			{
				for(int j = 0; j < 3; j++)
				{
					std::cout << table->getCardIndex(validTriples[i][j]) << ' ';
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
	}
}

void GameState::update()
{

}

void GameState::draw()
{
	application->getRenderWindow()->Clear(sf::Color(51, 153, 51));
	
	table->draw(application->getRenderWindow());

	application->getRenderWindow()->Display();
}