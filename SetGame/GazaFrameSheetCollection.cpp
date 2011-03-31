#include "GazaFrameSheetCollection.hpp"

namespace Gaza
{
	FrameSheetCollection::FrameSheetCollection()
	{

	}

	FrameSheetCollection::~FrameSheetCollection()
	{
		for(unsigned int i = 0; i < frameSheets.size(); i++)
		{
			delete frameSheets[i];
		}
		frameSheets.clear();
	}

	void FrameSheetCollection::addFrameSheet(FrameSheet * frameSheet)
	{
		frameSheets.push_back(frameSheet);
	}

	Frame * FrameSheetCollection::getFrame(const std::string &name)
	{
		Frame * frame = 0;
		for(unsigned int i = 0; i < frameSheets.size(); i++)
		{
			frame = frameSheets[i]->getFrame(name);
			if(frame != 0)
			{
				break;
			}
		}
		return frame;
	}

	std::vector<Frame *> FrameSheetCollection::getAnimationFrameList(const std::string &name)
	{
		if(animationFrameLists.find(name) == animationFrameLists.end())
		{
			return std::vector<Frame *>();
		}
		return animationFrameLists[name];
	}
	
	bool FrameSheetCollection::addAnimationFrameList(const std::string &name, const std::vector<Frame *> &frames)
	{
		if(animationFrameLists.find(name) == animationFrameLists.end())
		{
			Logger::getInstance()->write("A list of Frames with name \""+name+"\" does not exist.");
			return false;
		}

		for(unsigned int i = 0; i < frames.size(); i++)
		{
			addAnimationFrame(name, frames[i]);
		}

		return true;
	}

	bool FrameSheetCollection::addAnimationFrameList(const std::string &name, const std::vector<std::string> &frameNames)
	{
		if(animationFrameLists.find(name) == animationFrameLists.end())
		{
			Logger::getInstance()->write("A list of Frames with name \""+name+"\" does not exist.");
			return false;
		}

		for(unsigned int i = 0; i < frameNames.size(); i++)
		{
			addAnimationFrame(name, frameNames[i]);
		}

		return true;
	}

	bool FrameSheetCollection::newAnimationFrameList(const std::string &name)
	{
		if(animationFrameLists.find(name) != animationFrameLists.end())
		{
			Logger::getInstance()->write("A list of Frames with name \""+name+"\" already exists.");
			return false;
		}
		animationFrameLists[name] = std::vector<Frame *>();
		return true;
	}
	
	bool FrameSheetCollection::addAnimationFrame(const std::string &name, Frame * frame)
	{
		if(animationFrameLists.find(name) == animationFrameLists.end())
		{
			Logger::getInstance()->write("A list of Frames with name \""+name+"\" does not exist.");
			return false;
		}
		animationFrameLists[name].push_back(frame);
		return true;
	}

	bool FrameSheetCollection::addAnimationFrame(const std::string &name, const std::string &frameName)
	{
		Frame * frame = getFrame(frameName);
		if(frame == 0)
		{
			return false;
		}
		return addAnimationFrame(name, frame);
	}

	int FrameSheetCollection::getFrameSheetCount()
	{
		return frameSheets.size();
	}

	int FrameSheetCollection::getFrameCount()
	{
		int sum = 0;

		for(unsigned int i = 0; i < frameSheets.size(); i++)
		{
			sum += frameSheets[i]->getFrameCount();
		}

		return sum;
	}

	std::vector<std::string> FrameSheetCollection::getFrameNames()
	{
		std::vector<std::string> names;

		for(unsigned int i = 0; i < frameSheets.size(); i++)
		{
			std::vector<std::string> currentNames = frameSheets[i]->getFrameNames();
			for(unsigned int j = 0; j < currentNames.size(); j++)
			{
				names.push_back(currentNames[j]);
			}
		}

		return names;
	}

	void FrameSheetCollection::clearFrameSheets()
	{
		frameSheets.clear();
	}
}