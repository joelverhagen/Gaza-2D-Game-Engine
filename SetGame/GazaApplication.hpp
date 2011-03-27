#ifndef GAZAAPPLICATION_HPP
#define GAZAAPPLICATION_HPP

#include "Gaza.hpp"
#include "GazaStateManager.hpp"

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

		sf::RenderWindow * getRenderWindow();

	protected:
		void changeState(BaseState * state);

		std::stack<BaseState *> states;

	private:
		sf::RenderWindow * renderWindow;
		sf::VideoMode * videoMode;

		bool running;

	};
}

#endif