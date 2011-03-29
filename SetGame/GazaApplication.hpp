#ifndef GAZAAPPLICATION_HPP
#define GAZAAPPLICATION_HPP

#include "Gaza.hpp"
#include "GazaBaseState.hpp"

#include <stack>

namespace Gaza
{
	class Application
	{
	public:
		Application();
		~Application();

		int run();

		void setRunning(bool running);
		bool getRunning();

		void setInitialWindowWidth(unsigned int initialWindowWidth);
		void setInitialWindowHeight(unsigned int initialWindowHeight);

		sf::RenderWindow * getRenderWindow();

	protected:
		void changeState(BaseState * state);

		std::stack<BaseState *> states;

	private:
		sf::RenderWindow * renderWindow;
		sf::VideoMode * videoMode;

		unsigned int initialWindowWidth;
		unsigned int initialWindowHeight;

		bool running;
	};
}

#endif