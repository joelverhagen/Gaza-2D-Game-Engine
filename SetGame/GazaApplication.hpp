#ifndef GAZAAPPLICATION_HPP
#define GAZAAPPLICATION_HPP

#include "Gaza.hpp"
#include "GazaStateManager.hpp"

#include <vector>

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
		virtual void initialize() = 0;
		virtual void cleanup() = 0;

		StateManager * stateManager;

	private:
		sf::RenderWindow * renderWindow;
		sf::VideoMode * videoMode;

		bool running;

	};
}

#endif