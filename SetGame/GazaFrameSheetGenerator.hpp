#ifndef GAZAFRAMESHEETGENERATOR_HPP
#define GAZAFRAMESHEETGENERATOR_HPP

#include "Gaza.hpp"
#include "GazaFrameSheet.hpp"
#include "GazaFrameSheetCollection.hpp"
#include "GazaPacker.hpp"
#include "GazaUtility.hpp"

#include <algorithm>
#include <string>
#include <map>
#include <list>

namespace Gaza
{
	class FrameSheetGenerator
	{
	public:
		FrameSheetGenerator(ImageManager * imageManager);
		~FrameSheetGenerator();

		void addFrameSheet(FrameSheet * frameSheet);
		FrameSheetCollection * generate();

	protected:
		void setHandler(RectanglePacking::BaseHandler * handler);
		virtual void generateImages() = 0;
		void pushImage(const std::string &name, sf::Image * image);
		Frame * getFrame(const std::string &name);

		bool addAnimationFrameNameList(const std::string &name, const std::vector<std::string> &frameNames);
		bool newAnimationFrameNameList(const std::string &name);
		bool addAnimationFrameName(const std::string &name, const std::string &frameName);

	private:
		void removeImage(int index);
		void removeImages(int first, int last);

		ImageManager * imageManager;
		RectanglePacking::BaseHandler * handler;

		FrameSheetCollection inputFrameSheets;
		std::vector<std::pair<std::string, sf::Image *> > individualImages;

		std::map<std::string, std::vector<std::string> > animationFrameNameLists;
	};

	class SortPredicate 
	{
	public:
		bool operator()(const std::pair<std::string, sf::Image *> &a, const std::pair<std::string, sf::Image *> &b);
	};
}

#endif