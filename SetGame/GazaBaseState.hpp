#ifndef GAZABASESTATE_HPP
#define GAZABASESTATE_HPP

#include "Gaza.hpp"
#include "GazaApplication.hpp"

namespace Gaza
{
	class BaseState
	{
	public:
		virtual void initialize() = 0;
		virtual void cleanup() = 0;

		virtual void handleEvents(Application * application) = 0;
		virtual void update(Application * application) = 0;
		virtual void draw(Application * application) = 0;

		void changeState(Application * application, BaseState * state);

	protected:
		BaseState();

	};
}

#endif