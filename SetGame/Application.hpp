#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Common.hpp"

#include "GazaApplication.hpp"
#include "GazaSpriteSheet.hpp"
#include "GazaImageManager.hpp"
#include "GazaLogger.hpp"

#include "GameState.hpp"
#include "CardSpriteSheetGenerator.hpp"

class Application : public Gaza::Application
{
public:
	Application();
	~Application();

	Gaza::ImageManager * getImageManager();

private:
	Gaza::ImageManager imageManager;

	Gaza::SpriteSheetCollection * cardSprites;
};

#endif