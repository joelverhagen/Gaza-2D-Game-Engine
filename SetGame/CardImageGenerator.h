#ifndef CARDIMAGEGENERATOR_H
#define CARDIMAGEGENERATOR_H

#include "SpriteSheetGenerator.h"

class CardImageGenerator : public SpriteSheetGenerator
{
protected:
	void generateIndividualImages();
public:
	CardImageGenerator(SpriteSheet * spriteSheet);
};

#endif