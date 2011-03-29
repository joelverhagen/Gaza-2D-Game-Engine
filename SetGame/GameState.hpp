#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "GazaFrameSheetCollection.hpp"
#include "GazaApplication.hpp"
#include "GazaBaseState.hpp"
#include "GazaLogger.hpp"

#include "Table.hpp"

class GameState : public Gaza::BaseState
{
public:
	GameState(Gaza::Application * application, Gaza::FrameSheetCollection * cardFrames);

	~GameState();

	void handleEvents();
	void update();
	void draw();

protected:
	Gaza::FrameSheetCollection * cardFrames;
	Table * table;
};

#endif