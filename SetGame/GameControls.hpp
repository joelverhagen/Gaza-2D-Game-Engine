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

	void handleClick(int x, int y) ;
	void update() ;
	void draw(sf::RenderTarget * renderTarget);

private:
	unsigned int width;
	sf::Shape shape;

};

#endif