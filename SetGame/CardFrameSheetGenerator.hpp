#ifndef CARDFRAMESHEETGENERATOR_HPP
#define CARDFRAMESHEETGENERATOR_HPP

#include "GazaFrameSheetGenerator.hpp"
#include "GazaScottHandler.hpp"

class CardFrameSheetGenerator : public Gaza::FrameSheetGenerator
{
public:
	CardFrameSheetGenerator(Gaza::ImageManager * imageManager, Gaza::FrameSheet * frameSheet);

	void generateImages();
	
private:
	Gaza::RectanglePacking::ScottHandler scottHandler;
};

#endif