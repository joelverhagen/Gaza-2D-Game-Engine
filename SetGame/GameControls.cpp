#include "GameControls.hpp"

GameControls::GameControls(unsigned int width, int * score, Gaza::Application * application, const sf::Vector2f &position) : Gaza::WindowPanel(application, position)
{
	this->width = width;
	this->score = score;

	currentScore = getNewScore();
	scoreText = new sf::Text(currentScore);
	scoreText->SetPosition(position.x + 10, position.y + 10);

	currentTime = getNewTime();
	timeText = new sf::Text(currentTime);
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
	updateScoreText();
	updateTimeText();
}

void GameControls::draw(sf::RenderTarget * renderTarget)
{
	renderTarget->Draw(*scoreText);
	renderTarget->Draw(*timeText);
}

void GameControls::updateScoreText()
{
	std::string newScore = getNewScore();
	if(currentScore != newScore)
	{
		sf::Vector2f currentTextPosition = scoreText->GetPosition();

		delete scoreText;

		scoreText = new sf::Text(newScore);
		scoreText->SetPosition(currentTextPosition);
	}
}

void GameControls::updateTimeText()
{
	std::string newTime = getNewTime();
	if(currentTime != newTime)
	{
		sf::Vector2f currentTextPosition = timeText->GetPosition();

		delete timeText;

		timeText = new sf::Text(newTime);
		timeText->SetPosition(currentTextPosition);
	}
}
std::string GameControls::getNewScore()
{
	std::string newScore = "Score: ";
	newScore +=  Gaza::Utility::intToString(*score);
	return newScore;
}

std::string GameControls::getNewTime()
{
	std::string newTime = "Time: ";
	newTime += Gaza::Utility::intToString((int)Gaza::Utility::round(gameDuration.GetElapsedTime()));
	return newTime;
}