#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <iostream>
#include <string>
#include <map>

#include <SFML/Graphics.hpp>
#include "rapidxml.hpp"

namespace GazaEngine
{
	class SpriteSheet
	{
	private:
		map<string, sf::IntRect> rectangles;
		sf::Image * image;

	public:
		SpriteSheet();

		void loadFromFile(const string &filePath);
	
		void addRectangle(const string &name, sf::IntRect rectangle);
		void setImage(sf::Image * image);

		sf::IntRect getRectangle(const string &name);
		sf::Image * getImage();
	};
}


#endif