#include "GazaStateManager.hpp"

namespace Gaza
{
	StateManager::StateManager()
	{

	}

	StateManager::~StateManager()
	{

	}

	void StateManager::addState(BaseState * state)
	{
		states.push(state);
	}

	BaseState * StateManager::currentState()
	{
		return states.top();
	}
}