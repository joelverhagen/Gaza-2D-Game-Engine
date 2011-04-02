#ifndef GAZAWINDOWPANEL_HPP
#define GAZAWINDOWPANEL_HPP

#include "Gaza.hpp"
#include "GazaApplication.hpp"

namespace Gaza
{
	class WindowPanel
	{
	public:
		WindowPanel(Application * application, const sf::Vector2f &position = sf::Vector2f(0.f, 0.f));
		virtual ~WindowPanel();

		virtual unsigned int getWidth() = 0;
		virtual unsigned int getHeight() = 0;

		virtual void handleClick(int x, int y) = 0;
		virtual void update() = 0;
		virtual void draw(sf::RenderTarget * renderTarget) = 0;

		Application * getApplication();

		sf::Vector2f getPosition();
		void setPosition(const sf::Vector2f &position);

	protected:
		Application * application;
		sf::Vector2f position;

	};
}

#endif