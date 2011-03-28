#ifndef GAZASPRITESHEET_HPP
#define GAZASPRITESHEET_HPP

#include "Gaza.hpp"
#include "GazaSubImage.hpp"
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
		bool addRectangle(const std::string &name, const sf::IntRect &rectangle);
		
		SubImage * getSubImage(const std::string &name);
		sf::Image * getImage();

		int getSubImageCount();
		std::vector<std::string> getSubImageNames();

	private:
		ImageManager * imageManager;

		std::string name;		
		std::map<std::string, SubImage *> subImages;
	};
}

#endif