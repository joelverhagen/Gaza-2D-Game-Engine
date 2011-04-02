#include "GameControls.hpp"

GameControls::GameControls(unsigned int width, Gaza::Application * application, const sf::Vector2f &position) : Gaza::WindowPanel(application, position)
{
	this->width = width;

	shape.AddPoint(position.x, position.y, sf::Color::Red);
	shape.AddPoint(position.x + getWidth(), position.y, sf::Color::Green);
	shape.AddPoint(position.x + getWidth(), position.y + getHeight(), sf::Color::Yellow);
	shape.AddPoint(position.x, position.y + getHeight(), sf::Color::Blue);
}

GameControls::~GameControls()
{

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

}

void GameControls::draw(sf::RenderTarget * renderTarget)
{
	renderTarget->Draw(shape);
}