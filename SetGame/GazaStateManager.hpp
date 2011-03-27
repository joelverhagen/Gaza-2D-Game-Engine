#ifndef GAZASTATEMANAGER_HPP
#define GAZASTATEMANAGER_HPP

#include "Gaza.hpp"
#include "GazaBaseState.hpp"

#include <stack>

namespace Gaza
{
	class StateManager
	{
	public:
		StateManager();
		~StateManager();

		void addState(BaseState * state);
		BaseState * currentState();

	private:
		std::stack<BaseState *> states;
	};
}

#endif