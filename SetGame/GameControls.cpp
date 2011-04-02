#include "GameControls.hpp"

GameControls::GameControls(unsigned int width, Gaza::Application * application, const sf::Vector2f &position) : Gaza::WindowPanel(application, position)
{
	this->width = width;

	scoreText = new sf::Text("Score:");
	scoreText->SetPosition(position.x + 10, position.y + 10);

	timeText = new sf::Text("Time: 0");
	timeText->SetPosition(position.x + 10, scoreText->GetPosition().y + scoreText->GetRect().Height + 10);
}

GameControls::~GameControls()
{
	delete scoreText;
	delete timeText;
}

unsigned int GameControls::getWidth()
{
	return width;
}

unsigned int GameControls::getHeight()
{
	return 100;
}

void GameControls::handleClick(int x, int y)
{

}

void GameControls::update()
{
	updateTimeText();
}

void GameControls::draw(sf::RenderTarget * renderTarget)
{
	renderTarget->Draw(*scoreText);
	renderTarget->Draw(*timeText);
}

void GameControls::updateTimeText()
{
	std::string newTime = Gaza::Utility::floatToString(Gaza::Utility::round(gameDuration.GetElapsedTime()));
	if(currentTime != newTime)
	{
		sf::Vector2f currentTextPosition = timeText->GetPosition();

		delete timeText;

		timeText = new sf::Text("Time: " + newTime);
		timeText->SetPosition(currentTextPosition);
	}
}