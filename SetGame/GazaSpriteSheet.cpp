#include "GazaSpriteSheet.hpp"

namespace Gaza
{
	SpriteSheet::SpriteSheet(ImageManager * imageManager)
	{
		this->imageManager = imageManager;
	}

	SpriteSheet::~SpriteSheet()
	{
		for(std::map<std::string, Sprite *>::iterator i = sprites.begin(); i != sprites.end(); i++)
		{
			delete (*i).second;
		}
		sprites.clear();

		if(name.size() != 0)
		{
			imageManager->release(name);
		}
	}

	std::string SpriteSheet::getName()
	{
		return name;
	}

	void SpriteSheet::setName(const std::string &name)
	{
		if(name.size() != 0)
		{
			imageManager->release(this->name);
		}
		this->name = name;
	}

	bool SpriteSheet::loadFromFile(const std::string &filePath)
	{
		char * fileData = File::getFile(filePath, true);

		bool result = loadFromMemory(fileData);

		delete fileData;

		return result;
	}

	bool SpriteSheet::loadFromMemory(char * fileData)
	{
		rapidxml::xml_document<> document;
		document.parse<0>(fileData);

		if(!document.first_node("SpriteSheet"))
		{
			std::cout << "The sprite sheet must have a root element of type SpriteSheet." << std::endl;
			return false;
		}

		rapidxml::xml_node<> * rootNode = document.first_node("SpriteSheet");

		if(!rootNode->first_attribute("name"))
		{
			std::cout << "The SpriteSheet element must have a name attribute." << std::endl;
			return false;
		}

		setName(rootNode->first_attribute("name")->value());

		if(!rootNode->first_attribute("filePath"))
		{
			std::cout << "The SpriteSheet element must have a filePath attribute." << std::endl;
			return false;
		}

		std::string filePath = rootNode->first_attribute("filePath")->value();

		if(!File::fileExists(filePath))
		{
			std::cout << "The SpriteSheet's filePath attribute must point to an existing image." << std::endl;
			return false;
		}

		sf::Image * image = new sf::Image();
		bool imageLoadResult = image->LoadFromFile(filePath);

		if(!imageLoadResult)
		{
			delete image;
			std::cout << "The SpriteSheet's filePath attribute must point to a valid image." << std::endl;
			return false;
		}

		setImage(image);

		if(!rootNode->first_node("Rectangle"))
		{
			std::cout << "The SpriteSheet element must have at least one Rectangle child node." << std::endl;
			return false;
		}

		for (rapidxml::xml_node<> * childNode = rootNode->first_node("Rectangle"); childNode; childNode = childNode->next_sibling("Rectangle"))
		{
			if(!childNode->first_attribute("left") || !childNode->first_attribute("top") || !childNode->first_attribute("width") || !childNode->first_attribute("height") || !childNode->first_attribute("name"))
			{
				std::cout << "Every Rectangle element must have an left, top, width, height, and name attribute." << std::endl;
				return false;
			}

			sf::IntRect rectangle;
			rectangle.Left = Utility::stringToInt(childNode->first_attribute("left")->value());
			rectangle.Top = Utility::stringToInt(childNode->first_attribute("top")->value());
			rectangle.Width = Utility::stringToInt(childNode->first_attribute("width")->value());
			rectangle.Height = Utility::stringToInt(childNode->first_attribute("height")->value());

			std::string name = childNode->first_attribute("name")->value();

			Sprite * sprite = new Sprite(rectangle, getImage());

			addSprite(name, sprite);
		}

		return true;
	}

	bool SpriteSheet::setImage(sf::Image * image)
	{
		if(name.size() == 0)
		{
			std::cout << "A name must be set before the image is set." << std::endl;
			return false;
		}
		imageManager->release(name);
		imageManager->add(name, image);

		return true;
	}

	bool SpriteSheet::addSprite(const std::string &name, Sprite * sprite)
	{
		if(sprites.find(name) != sprites.end())
		{
			std::cout << "A sprite with name \"" << name << "\" already exists." << std::endl;
			return false;
		}
		sprites[name] = sprite;
		return true;
	}

	Sprite * SpriteSheet::getSprite(const std::string &name)
	{
		if(sprites.find(name) == sprites.end())
		{
			return 0;
		}
		return sprites[name];
	}

	sf::Image * SpriteSheet::getImage()
	{
		return imageManager->get(name);
	}

	int SpriteSheet::getSpriteCount()
	{
		return sprites.size();
	}

	std::vector<std::string> SpriteSheet::getSpriteNames()
	{
		std::vector<std::string> names;

		for(std::map<std::string, Sprite *>::iterator i = sprites.begin(); i != sprites.end(); i++)
		{
			names.push_back((*i).first);
		}
		
		return names;
	}

}