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

		int getFrameSheetCount();
		int getFrameCount();
		std::vector<std::string> getFrameNames();

		void clearFrameSheets();

	private:
		std::vector<FrameSheet *> frameSheets;
	};
}

#endif