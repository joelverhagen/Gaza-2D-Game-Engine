#include "GazaSpriteSheetGenerator.hpp"

namespace Gaza
{
	SpriteSheetGenerator::SpriteSheetGenerator(ImageManager * imageManager)
	{
		this->imageManager = imageManager;
	}

	SpriteSheetGenerator::~SpriteSheetGenerator()
	{
		// the generator should not have ownership of the input sprite sheets
		inputSpriteSheets.clearSpriteSheets();
	}

	void SpriteSheetGenerator::addSpriteSheet(SpriteSheet * spriteSheet)
	{
		inputSpriteSheets.addSpriteSheet(spriteSheet);
	}
	
	SpriteSheetCollection * SpriteSheetGenerator::generate()
	{
		generateImages();

		if(individualImages.size() == 0)
		{
			return 0;
		}

		SpriteSheetCollection * spriteSheetCollection = new SpriteSheetCollection();

		Utility::RectanglePacker * currentRectanglePacker = new Utility::RectanglePacker(maximumImageWidth, maximumImageHeight);
		
		sf::Image * currentImage = new sf::Image();
		currentImage->Create(maximumImageWidth, maximumImageWidth, sf::Color(0, 0, 0, 0));

		SpriteSheet * currentSpriteSheet = new SpriteSheet(imageManager);
		currentSpriteSheet->setName(Utility::intToString(spriteSheetCollection->getSpriteSheetCount()));
		currentSpriteSheet->setImage(currentImage);

		while(individualImages.size() > 0)
		{
			std::pair<std::string, sf::Image *> pair = individualImages.front();
			sf::Image * currentIndividualImage = pair.second;
			sf::IntRect rectangle(0, 0, currentIndividualImage->GetWidth(), currentIndividualImage->GetHeight());

			if((unsigned int)rectangle.Width > maximumImageWidth || (unsigned int)rectangle.Height > maximumImageHeight)
			{
				std::cout << "An image was too large to fit inside the maximum image width or maximum image height" << std::endl;
				popImage();
				continue;
			}

			// add one pixel border to avoid
			rectangle.Width += 1;
			rectangle.Height += 1;

			rectangle = currentRectanglePacker->addRectangle(rectangle);

			rectangle.Width -= 1;
			rectangle.Height -= 1;

			if(Utility::isZero(rectangle))
			{
				// need a new sprite sheet
				spriteSheetCollection->addSpriteSheet(currentSpriteSheet);
				
				delete currentRectanglePacker;
				currentRectanglePacker = new Utility::RectanglePacker(maximumImageWidth, maximumImageHeight);

				currentImage = new sf::Image();
				currentImage->Create(maximumImageWidth, maximumImageWidth, sf::Color(0, 0, 0, 0));

				currentSpriteSheet = new SpriteSheet(imageManager);
				currentSpriteSheet->setName(Utility::intToString(spriteSheetCollection->getSpriteSheetCount()));
				currentSpriteSheet->setImage(currentImage);
			}
			else
			{
				currentImage->Copy(*currentIndividualImage, rectangle.Left, rectangle.Top);
				currentSpriteSheet->addSprite(pair.first, new Sprite(rectangle, currentImage));
				popImage();
			}
		}

		delete currentRectanglePacker;

		spriteSheetCollection->addSpriteSheet(currentSpriteSheet);

		return spriteSheetCollection;
	}

	void SpriteSheetGenerator::pushImage(const std::string &name, sf::Image * image)
	{
		imageManager->add(name, image);
		individualImages.push(std::pair<std::string, sf::Image *>(name, image));
	}

	Sprite * SpriteSheetGenerator::getSprite(const std::string &name)
	{
		return inputSpriteSheets.getSprite(name);
	}

	void SpriteSheetGenerator::popImage()
	{
		std::pair<std::string, sf::Image *> pair = individualImages.front();
		imageManager->release(pair.first);
		individualImages.pop();
	}
}
