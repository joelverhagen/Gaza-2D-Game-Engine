#ifndef CARDSPRITESHEETGENERATOR_HPP
#define CARDSPRITESHEETGENERATOR_HPP

#include "GazaSpriteSheetGenerator.hpp"

class CardSpriteSheetGenerator : public Gaza::SpriteSheetGenerator
{
public:
	CardSpriteSheetGenerator(Gaza::ImageManager * imageManager, Gaza::SpriteSheet * spriteSheet);

	void generateImages();
};

#endif