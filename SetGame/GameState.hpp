#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "GazaFrameSheetCollection.hpp"
#include "GazaApplication.hpp"
#include "GazaBaseState.hpp"
#include "GazaLogger.hpp"

#include "Deck.hpp"
#include "Card.hpp"

class GameState : public Gaza::BaseState
{
public:
	GameState();
	~GameState();

	void setCardSprites(Gaza::FrameSheetCollection * cardSprites);

	void initialize();
	void cleanup();

	void handleEvents(Gaza::Application * application);
	void update(Gaza::Application * application);
	void draw(Gaza::Application * application);

	static GameState * getInstance();	

protected:
	Gaza::FrameSheetCollection * cardSprites;

	static GameState * instance;
};

#endif