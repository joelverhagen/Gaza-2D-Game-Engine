#include "GazaWindowPanel.hpp"

namespace Gaza
{
	WindowPanel::WindowPanel(Application * application, const sf::Vector2f &position)
	{
		this->application = application;
		this->position = position;
	}

	WindowPanel::~WindowPanel()
	{

	}

	Application * WindowPanel::getApplication()
	{
		return application;
	}

	sf::Vector2f WindowPanel::getPosition()
	{
		return position;
	}

	void WindowPanel::setPosition(const sf::Vector2f &position)
	{
		this->position = position;
	}
}