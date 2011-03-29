#ifndef GAZABASESTATE_HPP
#define GAZABASESTATE_HPP

#include "Gaza.hpp"
#include "GazaApplication.hpp"

namespace Gaza
{
	class BaseState
	{
	public:
		BaseState(Gaza::Application * application);

		virtual ~BaseState();

		virtual void handleEvents() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;

	protected:
		Application * application;
	};
}

#endif