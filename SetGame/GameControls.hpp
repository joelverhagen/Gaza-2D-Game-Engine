#ifndef GAMECONTROLS_HPP
#define GAMECONTROLS_HPP

#include "GazaWindowPanel.hpp"

class GameControls : public Gaza::WindowPanel
{
public:
	GameControls(unsigned int width, int * score, Gaza::Application * application, const sf::Vector2f &position);
	~GameControls();

	unsigned int getWidth();
	unsigned int getHeight();

	void handleClick(int x, int y);
	void update();
	void draw(sf::RenderTarget * renderTarget);

private:
	void updateScoreText();
	void updateTimeText();

	std::string getNewScore();
	std::string getNewTime();

	unsigned int width;

	sf::Text * scoreText;
	sf::Text * timeText;

	int * score;
	sf::Clock gameDuration;
	
	std::string currentScore;
	std::string currentTime;
};

#endif