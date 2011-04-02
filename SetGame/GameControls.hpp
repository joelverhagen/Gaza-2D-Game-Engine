#ifndef GAMECONTROLS_HPP
#define GAMECONTROLS_HPP

#include "GazaWindowPanel.hpp"

class GameControls : public Gaza::WindowPanel
{
public:
	GameControls(unsigned int width, Gaza::Application * application, const sf::Vector2f &position);
	~GameControls();

	unsigned int getWidth();
	unsigned int getHeight();

	void handleClick(int x, int y);
	void update();
	void draw(sf::RenderTarget * renderTarget);

private:
	void updateTimeText();

	unsigned int width;
	sf::Text * scoreText;
	sf::Text * timeText;
	
	std::string currentTime;
	sf::Clock gameDuration;

};

#endif