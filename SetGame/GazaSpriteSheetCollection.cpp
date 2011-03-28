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

	SubImage * SpriteSheetCollection::getSubImage(const std::string &name)
	{
		SubImage * subImage = 0;
		for(unsigned int i = 0; i < spriteSheets.size(); i++)
		{
			subImage = spriteSheets[i]->getSubImage(name);
			if(subImage != 0)
			{
				break;
			}
		}
		return subImage;
	}

	int SpriteSheetCollection::getSpriteSheetCount()
	{
		return spriteSheets.size();
	}

	int SpriteSheetCollection::getSubImageCount()
	{
		int sum = 0;

		for(unsigned int i = 0; i < spriteSheets.size(); i++)
		{
			sum += spriteSheets[i]->getSubImageCount();
		}

		return sum;
	}

	std::vector<std::string> SpriteSheetCollection::getSubImageNames()
	{
		std::vector<std::string> names;

		for(unsigned int i = 0; i < spriteSheets.size(); i++)
		{
			std::vector<std::string> currentNames = spriteSheets[i]->getSubImageNames();
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