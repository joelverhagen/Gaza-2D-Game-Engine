#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Common.hpp"

#include "GazaApplication.hpp"
#include "GazaFrameSheet.hpp"
#include "GazaImageManager.hpp"
#include "GazaLogger.hpp"

#include "GameState.hpp"
#include "CardFrameSheetGenerator.hpp"

class Application : public Gaza::Application
{
public:
	Application();
	~Application();

	Gaza::ImageManager * getImageManager();

private:
	Gaza::ImageManager imageManager;

	Gaza::FrameSheetCollection * cardSprites;
};

#endif