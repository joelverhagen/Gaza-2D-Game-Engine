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

		// TODO: sort the images before insertion

		do
		{
			RectanglePacking::ScottHandler * scottHandler = new RectanglePacking::ScottHandler();
			RectanglePacking::Packer * packer = new RectanglePacking::Packer(scottHandler);

			std::vector<sf::IntRect *> rectangles;

			for(unsigned int i = 0; i < individualImages.size(); i++)
			{
				unsigned int currentWidth = individualImages[i].second->GetWidth();
				unsigned int currentHeight = individualImages[i].second->GetHeight();

				if(currentWidth > maximumImageWidth || currentHeight > maximumImageHeight)
				{
					std::cout << "An image was too large to fit inside the maximum image width or maximum image height" << std::endl;
					removeImage(i);
					i--;
					continue;
				}

				sf::IntRect * rectangle = packer->addRectangle(currentWidth, currentHeight);

				if(rectangle == 0)
				{
					break;
				}

				rectangles.push_back(rectangle);
			}

			sf::Image * currentImage = new sf::Image();
			currentImage->Create(packer->getContainerWidth(), packer->getContainerHeight(), sf::Color(0, 0, 0, 0));

			SpriteSheet * currentSpriteSheet = new SpriteSheet(imageManager);
			currentSpriteSheet->setName(Utility::intToString(spriteSheetCollection->getSpriteSheetCount()));
			currentSpriteSheet->setImage(currentImage);

			for(unsigned int i = 0; i < rectangles.size(); i++)
			{
				currentImage->Copy(*individualImages[i].second, rectangles[i]->Left, rectangles[i]->Top);
				currentSpriteSheet->addSprite(individualImages[i].first, new Sprite(*rectangles[i], currentImage));
			}

			removeImages(0, rectangles.size());

			for(unsigned int i = 0; i < rectangles.size(); i++)
			{
				delete rectangles[i];
			}

			delete packer;
			delete scottHandler;

			spriteSheetCollection->addSpriteSheet(currentSpriteSheet);
		}
		while(individualImages.size() > 0);

		return spriteSheetCollection;
	}

	void SpriteSheetGenerator::pushImage(const std::string &name, sf::Image * image)
	{
		imageManager->add(name, image);
		individualImages.push_back(std::pair<std::string, sf::Image *>(name, image));
	}

	Sprite * SpriteSheetGenerator::getSprite(const std::string &name)
	{
		return inputSpriteSheets.getSprite(name);
	}

	void SpriteSheetGenerator::removeImage(int index)
	{
		imageManager->release(individualImages[index].first);
		individualImages.erase(individualImages.begin() + index);
	}

	void SpriteSheetGenerator::removeImages(int first, int last)
	{
		for(int i = first; i < last; i++)
		{
			imageManager->release(individualImages[i].first);
		}
		individualImages.erase(individualImages.begin() + first, individualImages.begin() + last);
	}
}
