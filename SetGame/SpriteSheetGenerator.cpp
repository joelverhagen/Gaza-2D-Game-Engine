#include "SpriteSheetGenerator.h"

int SpriteSheetGenerator::maximumImageWidth = 2048;
int SpriteSheetGenerator::maximumImageHeight = 2048;

void SpriteSheetGenerator::generateIndividualImages()
{

}

SpriteSheet * SpriteSheetGenerator::generateOutputSpriteSheet()
{
	generateIndividualImages();



	SpriteSheet * spriteSheet = new SpriteSheet();
	

	return NULL;
}

SpriteSheetGenerator::SpriteSheetGenerator()
{

}

void SpriteSheetGenerator::addInputSpriteSheet(const string &key, SpriteSheet * spriteSheet)
{
	if(inputSpriteSheets.find(key) != inputSpriteSheets.end())
	{
		throw runtime_error("A sprite sheet with key \""+key+"\" already exists."); 
	}
	inputSpriteSheets[key] = spriteSheet;
}

SpriteSheet * SpriteSheetGenerator::getInputSpriteSheet(const string &key)
{
	if(inputSpriteSheets.find(key) == inputSpriteSheets.end())
	{
		throw runtime_error("A sprite sheet with key \""+key+"\" does not exist."); 
	}
	return inputSpriteSheets[key];
}