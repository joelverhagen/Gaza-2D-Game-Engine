#ifndef GAZASPRITESHEETGENERATOR_HPP
#define GAZASPRITESHEETGENERATOR_HPP

#include "Gaza.hpp"
#include "GazaSpriteSheet.hpp"
#include "GazaSpriteSheetCollection.hpp"
#include "GazaPacker.hpp"
#include "GazaScottHandler.hpp"
#include "GazaUtility.hpp"

#include <algorithm>
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
		void setHandler(RectanglePacking::BaseHandler * handler);
		virtual void generateImages() = 0;
		void pushImage(const std::string &name, sf::Image * image);
		SubImage * getSubImage(const std::string &name);

	private:
		void removeImage(int index);
		void removeImages(int first, int last);

		ImageManager * imageManager;
		RectanglePacking::BaseHandler * handler;

		SpriteSheetCollection inputSpriteSheets;
		std::vector<std::pair<std::string, sf::Image *> > individualImages;
	};

	class SortPredicate 
	{
	public:
		bool operator()(const std::pair<std::string, sf::Image *> &a, const std::pair<std::string, sf::Image *> &b);
	};
}

#endif