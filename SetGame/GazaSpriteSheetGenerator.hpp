#ifndef GAZASPRITESHEETGENERATOR_HPP
#define GAZASPRITESHEETGENERATOR_HPP

#include "Gaza.hpp"
#include "GazaSpriteSheet.hpp"
#include "GazaSpriteSheetCollection.hpp"
#include "GazaPacker.hpp"
#include "GazaScottHandler.hpp"
#include "GazaUtility.hpp"

#include <string>
#include <map>
#include <list>

namespace Gaza
{
	class SpriteSheetGenerator
	{
	public:
		SpriteSheetGenerator(ImageManager * imageManager);
		~SpriteSheetGenerator();

		void addSpriteSheet(SpriteSheet * spriteSheet);
		SpriteSheetCollection * generate();

	protected:
		virtual void generateImages() = 0;
		void pushImage(const std::string &name, sf::Image * image);
		Sprite * getSprite(const std::string &name);

	private:
		void removeImage(int index);
		void removeImages(int first, int last);

		ImageManager * imageManager;

		SpriteSheetCollection inputSpriteSheets;
		std::vector<std::pair<std::string, sf::Image *> > individualImages;
	};
}

#endif