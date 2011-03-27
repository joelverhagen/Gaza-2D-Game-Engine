#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "GazaApplication.hpp"
#include "GazaBaseState.hpp"
#include "GazaLogger.hpp"

class GameState : public Gaza::BaseState
{
public:
	void initialize();
	void cleanup();

	virtual void handleEvents(Gaza::Application * application);
	virtual void update(Gaza::Application * application);
	virtual void draw(Gaza::Application * application);

	static GameState * getInstance();

protected:
	static GameState instance;
};

#endif