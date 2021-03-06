#include "GazaFrameSheet.hpp"

namespace Gaza
{
	FrameSheet::FrameSheet(ImageManager * imageManager)
	{
		this->imageManager = imageManager;
	}

	FrameSheet::~FrameSheet()
	{
		for(std::map<std::string, Frame *>::iterator i = frames.begin(); i != frames.end(); i++)
		{
			delete (*i).second;
		}
		frames.clear();

		if(name.size() != 0)
		{
			imageManager->release(name);
		}
	}

	std::string FrameSheet::getName()
	{
		return name;
	}

	void FrameSheet::setName(const std::string &name)
	{
		if(name.size() != 0)
		{
			imageManager->release(this->name);
		}
		this->name = name;
	}

	bool FrameSheet::loadFromFile(const std::string &filePath)
	{
		char * fileData = File::getFile(filePath, true);

		if(fileData == 0)
		{
			Logger::getInstance()->write("The file \""+filePath+"\" could not be opened.");
			return false;
		}

		bool result = loadFromMemory(fileData);

		delete fileData;

		return result;
	}

	bool FrameSheet::loadFromMemory(char * fileData)
	{
		rapidxml::xml_document<> document;
		document.parse<0>(fileData);

		if(!document.first_node("FrameSheet"))
		{
			Logger::getInstance()->write("The sprite sheet must have a root element of type FrameSheet.");
			return false;
		}

		rapidxml::xml_node<> * rootNode = document.first_node("FrameSheet");

		if(!rootNode->first_attribute("name"))
		{
			Logger::getInstance()->write("The FrameSheet element must have a name attribute.");
			return false;
		}

		setName(rootNode->first_attribute("name")->value());

		if(!rootNode->first_attribute("filePath"))
		{
			Logger::getInstance()->write("The FrameSheet element must have a filePath attribute.");
			return false;
		}

		std::string filePath = rootNode->first_attribute("filePath")->value();

		if(!File::fileExists(filePath))
		{
			Logger::getInstance()->write("The FrameSheet's filePath attribute must point to an existing image.");
			return false;
		}

		sf::Image * image = new sf::Image();
		bool imageLoadResult = image->LoadFromFile(filePath);

		if(!imageLoadResult)
		{
			delete image;
			Logger::getInstance()->write("The FrameSheet's filePath attribute must point to a valid image.");
			return false;
		}

		setImage(image);

		if(!rootNode->first_node("Rectangle"))
		{
			Logger::getInstance()->write("The FrameSheet element must have at least one Rectangle child node.");
			return false;
		}

		for (rapidxml::xml_node<> * childNode = rootNode->first_node("Rectangle"); childNode; childNode = childNode->next_sibling("Rectangle"))
		{
			if(!childNode->first_attribute("left") || !childNode->first_attribute("top") || !childNode->first_attribute("width") || !childNode->first_attribute("height") || !childNode->first_attribute("name"))
			{
				Logger::getInstance()->write("Every Rectangle element must have an left, top, width, height, and name attribute.");
				return false;
			}

			sf::IntRect rectangle;
			rectangle.Left = Utility::stringToInt(childNode->first_attribute("left")->value());
			rectangle.Top = Utility::stringToInt(childNode->first_attribute("top")->value());
			rectangle.Width = Utility::stringToInt(childNode->first_attribute("width")->value());
			rectangle.Height = Utility::stringToInt(childNode->first_attribute("height")->value());

			std::string name = childNode->first_attribute("name")->value();

			addRectangle(name, rectangle);
		}

		return true;
	}

	std::string FrameSheet::saveToMemory()
	{
		rapidxml::xml_document<> document;
		rapidxml::xml_node<> * rootNode = document.allocate_node(rapidxml::node_element, "FrameSheet");
		document.append_node(rootNode);

		Utility::RapidXml::addAttribute(&document, rootNode, "name", name);

		rapidxml::xml_node<> * currentNode;
		for(std::map<std::string, Frame *>::iterator i = frames.begin(); i != frames.end(); i++)
		{
			currentNode = document.allocate_node(rapidxml::node_element, "Rectangle");
			rootNode->append_node(currentNode);

			Utility::RapidXml::addAttribute(&document, currentNode, "x", Utility::intToString((*i).second->rectangle.Left));
			Utility::RapidXml::addAttribute(&document, currentNode, "y", Utility::intToString((*i).second->rectangle.Top));
			Utility::RapidXml::addAttribute(&document, currentNode, "width", Utility::intToString((*i).second->rectangle.Width));
			Utility::RapidXml::addAttribute(&document, currentNode, "height", Utility::intToString((*i).second->rectangle.Height));
			Utility::RapidXml::addAttribute(&document, currentNode, "name", (*i).first);
		}

		std::string output;
		rapidxml::print(std::back_inserter(output), document, 0);

		return output;
	}

	bool FrameSheet::setImage(sf::Image * image)
	{
		if(name.size() == 0)
		{
			Logger::getInstance()->write("A name must be set before the image is set.");
			return false;
		}
		imageManager->release(name);
		imageManager->add(name, image);

		return true;
	}

	bool FrameSheet::addRectangle(const std::string &name, const sf::IntRect &rectangle)
	{
		if(frames.find(name) != frames.end())
		{
			Logger::getInstance()->write("A Frame with name \""+name+"\" already exists.");
			return false;
		}
		frames[name] = new Frame(rectangle, getImage());
		return true;
	}

	Frame * FrameSheet::getFrame(const std::string &name)
	{
		if(frames.find(name) == frames.end())
		{
			return 0;
		}
		return frames[name];
	}

	sf::Image * FrameSheet::getImage()
	{
		return imageManager->get(name);
	}

	int FrameSheet::getFrameCount()
	{
		return frames.size();
	}

	std::vector<std::string> FrameSheet::getFrameNames()
	{
		std::vector<std::string> names;

		for(std::map<std::string, Frame *>::iterator i = frames.begin(); i != frames.end(); i++)
		{
			names.push_back((*i).first);
		}
		
		return names;
	}

}