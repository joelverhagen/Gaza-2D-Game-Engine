#ifndef GAZASPRITESHEETCOLLECITON_HPP
#define GAZASPRITESHEETCOLLECITON_HPP

#include "Gaza.hpp"
#include "GazaSpriteSheet.hpp"
#include "GazaSubImage.hpp"

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
		SubImage * getSubImage(const std::string &name);

		int getSpriteSheetCount();
		int getSubImageCount();
		std::vector<std::string> getSubImageNames();

		void clearSpriteSheets();

	private:
		std::vector<SpriteSheet *> spriteSheets;
	};
}

#endif