#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "GazaSpriteSheetCollection.hpp"
#include "GazaApplication.hpp"
#include "GazaBaseState.hpp"
#include "GazaLogger.hpp"

class GameState : public Gaza::BaseState
{
public:
	void setCardSprites(Gaza::SpriteSheetCollection * cardSprites);

	void initialize();
	void cleanup();

	void handleEvents(Gaza::Application * application);
	void update(Gaza::Application * application);
	void draw(Gaza::Application * application);

	static GameState * getInstance();	

protected:
	Gaza::SpriteSheetCollection * cardSprites;

	static GameState instance;
};

#endif