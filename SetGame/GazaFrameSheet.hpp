#ifndef GAZAFRAMESHEET_HPP
#define GAZAFRAMESHEET_HPP

#include "Gaza.hpp"
#include "GazaFrame.hpp"
#include "GazaFile.hpp"
#include "GazaUtility.hpp"
#include "GazaImageManager.hpp"

#include <map>
#include <string>
#include <vector>
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"

namespace Gaza
{
	class FrameSheet
	{
	public:
		FrameSheet(ImageManager * imageManager);
		~FrameSheet();

		std::string getName();
		void setName(const std::string &name);

		bool loadFromFile(const std::string &filePath);
		bool loadFromMemory(char * fileData);

		std::string saveToMemory(); // returns string of XML representing the frame sheet

		bool setImage(sf::Image * image);
		bool addRectangle(const std::string &name, const sf::IntRect &rectangle);
		
		Frame * getFrame(const std::string &name);
		sf::Image * getImage();

		int getFrameCount();
		std::vector<std::string> getFrameNames();

	private:
		ImageManager * imageManager;

		std::string name;		
		std::map<std::string, Frame *> frames;
	};
}

#endif