#include "SpriteSheet.h"

namespace GazaEngine
{
	SpriteSheet::SpriteSheet()
	{
		image = NULL;
	}

	void SpriteSheet::loadFromFile(const string &filePath)
	{
	
		rapidxml::xml_document<> document;
		TiXmlDocument document(filePath.c_str());
		bool success = document.LoadFile();
		if(!success)
		{
			throw runtime_error("The XML sprite sheet provided could not be loaded.");
		}

		TiXmlElement * root = document.RootElement();
		string imagePath = root->Attribute("path");
		image = new sf::Image();
		if(!image->LoadFromFile(imagePath))
		{
			throw runtime_error("The image specified by the sprite sheet could not be loaded.");
		}

		for(TiXmlElement * sprite = root->FirstChildElement(); sprite; sprite = sprite->NextSiblingElement())
		{
			string spriteName = sprite->Attribute("name");

			sf::IntRect rectangle;

			sprite->Attribute("x", &rectangle.Left);
			sprite->Attribute("y", &rectangle.Top);
			sprite->Attribute("width", &rectangle.Width);
			sprite->Attribute("height", &rectangle.Height);

			rectangles[spriteName] = rectangle;
		}
	}

	void SpriteSheet::addRectangle(const string &name, sf::IntRect rectangle)
	{
		if(rectangles.find(name) != rectangles.end())
		{
			throw runtime_error("A rectangle with name \""+name+"\" already exists."); 
		}
		rectangles[name] = rectangle;
	}

	void SpriteSheet::setImage(sf::Image * image)
	{
		this->image = image;
	}

	sf::IntRect SpriteSheet::getRectangle(const string &name)
	{
		if(rectangles.find(name) == rectangles.end())
		{
			throw runtime_error("A rectangle with name \""+name+"\" does not exist."); 
		}
		return rectangles[name];
	}

	sf::Image * SpriteSheet::getImage()
	{
		return image;
	}
}