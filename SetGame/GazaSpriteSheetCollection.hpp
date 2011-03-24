#ifndef GAZASPRITESHEETCOLLECITON_HPP
#define GAZASPRITESHEETCOLLECITON_HPP

#include "Gaza.hpp"
#include "GazaSpriteSheet.hpp"
#include "GazaSprite.hpp"

#include <string>
#include <vector>

namespace Gaza
{
	class SpriteSheetCollection
	{
	public:
		SpriteSheetCollection();
		~SpriteSheetCollection();

		void addSpriteSheet(SpriteSheet * spriteSheet);
		Sprite * getSprite(const std::string &name);

		int getSpriteSheetCount();
		int getSpriteCount();
		std::vector<std::string> getSpriteNames();

		void clearSpriteSheets();

	private:
		std::vector<SpriteSheet *> spriteSheets;
	};
}

#endif