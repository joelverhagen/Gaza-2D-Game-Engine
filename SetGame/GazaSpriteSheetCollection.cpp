#include "GazaSpriteSheetCollection.hpp"

namespace Gaza
{
	SpriteSheetCollection::SpriteSheetCollection()
	{

	}

	SpriteSheetCollection::~SpriteSheetCollection()
	{
		for(unsigned int i = 0; i < spriteSheets.size(); i++)
		{
			delete spriteSheets[i];
		}
		spriteSheets.clear();
	}

	void SpriteSheetCollection::addSpriteSheet(SpriteSheet * spriteSheet)
	{
		spriteSheets.push_back(spriteSheet);
	}

	Sprite * SpriteSheetCollection::getSprite(const std::string &name)
	{
		Sprite * sprite = 0;
		for(unsigned int i = 0; i < spriteSheets.size(); i++)
		{
			sprite = spriteSheets[i]->getSprite(name);
			if(sprite != 0)
			{
				break;
			}
		}
		return sprite;
	}

	int SpriteSheetCollection::getSpriteSheetCount()
	{
		return spriteSheets.size();
	}

	int SpriteSheetCollection::getSpriteCount()
	{
		int sum = 0;

		for(unsigned int i = 0; i < spriteSheets.size(); i++)
		{
			sum += spriteSheets[i]->getSpriteCount();
		}

		return sum;
	}

	std::vector<std::string> SpriteSheetCollection::getSpriteNames()
	{
		std::vector<std::string> names;

		for(unsigned int i = 0; i < spriteSheets.size(); i++)
		{
			std::vector<std::string> currentNames = spriteSheets[i]->getSpriteNames();
			for(unsigned int j = 0; j < currentNames.size(); j++)
			{
				names.push_back(currentNames[j]);
			}
		}

		return names;
	}

	void SpriteSheetCollection::clearSpriteSheets()
	{
		spriteSheets.clear();
	}
}