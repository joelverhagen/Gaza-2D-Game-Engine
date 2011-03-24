#ifndef SPRITESHEETGENERATOR_H
#define SPRITESHEETGENERATOR_H

#include <iostream>
#include <string>
#include <queue>
#include <map>

#include <SFML/Graphics.hpp>
#include "tinyxml.h"

#include "SpriteSheet.h"

using namespace std;

class SpriteSheetGenerator
{
protected:
	static int maximumImageWidth;
	static int maximumImageHeight;

	vector<sf::Image *> individualImages;
	map<string, SpriteSheet *> inputSpriteSheets;

	virtual void generateIndividualImages();
public:
	SpriteSheetGenerator();
	void addInputSpriteSheet(const string &key, SpriteSheet * spriteSheet);
	SpriteSheet * getInputSpriteSheet(const string &key);
	virtual SpriteSheet * generateOutputSpriteSheet();
};

#endif