#ifndef GAZASPRITESHEET_HPP
#define GAZASPRITESHEET_HPP

#include "Gaza.hpp"
#include "GazaSprite.hpp"
#include "GazaFile.hpp"
#include "GazaUtility.hpp"
#include "GazaImageManager.hpp"

#include <map>
#include <string>
#include <vector>
#include "rapidxml.hpp"

namespace Gaza
{
	class SpriteSheet
	{
	public:
		SpriteSheet(ImageManager * imageManager);
		~SpriteSheet();

		std::string getName();
		void setName(const std::string &name);

		bool loadFromFile(const std::string &filePath);
		bool loadFromMemory(char * fileData);

		bool setImage(sf::Image * image);
		bool addSprite(const std::string &name, Sprite * sprite);
		
		Sprite * getSprite(const std::string &name);
		sf::Image * getImage();

		int getSpriteCount();
		std::vector<std::string> getSpriteNames();

	private:
		ImageManager * imageManager;

		std::string name;		
		std::map<std::string, Sprite *> sprites;
	};
}

#endif