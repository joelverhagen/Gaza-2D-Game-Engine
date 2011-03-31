#ifndef GAZAFRAMESHEETCOLLECTION_HPP
#define GAZAFRAMESHEETCOLLECTION_HPP

#include "Gaza.hpp"
#include "GazaFrameSheet.hpp"
#include "GazaFrame.hpp"

#include <string>
#include <vector>

namespace Gaza
{
	class FrameSheetCollection
	{
	public:
		FrameSheetCollection();
		~FrameSheetCollection();

		void addFrameSheet(FrameSheet * frameSheet);
		Frame * getFrame(const std::string &name);

		std::vector<Frame *> getAnimationFrameList(const std::string &name);
		bool addAnimationFrameList(const std::string &name, const std::vector<Frame *> &frames);
		bool newAnimationFrameList(const std::string &name);
		bool addAnimationFrame(const std::string &name, Frame * frame);

		int getFrameSheetCount();
		int getFrameCount();
		std::vector<std::string> getFrameNames();

		void clearFrameSheets();

	private:
		std::vector<FrameSheet *> frameSheets;
		std::map<std::string, std::vector<Frame *> > animationFrameLists;
	};
}

#endif