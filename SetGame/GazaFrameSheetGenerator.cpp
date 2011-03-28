#include "GazaFrameSheetGenerator.hpp"

namespace Gaza
{
	FrameSheetGenerator::FrameSheetGenerator(ImageManager * imageManager)
	{
		this->imageManager = imageManager;
		this->handler = 0;
	}

	FrameSheetGenerator::~FrameSheetGenerator()
	{

	}

	void FrameSheetGenerator::addFrameSheet(FrameSheet * frameSheet)
	{
		inputFrameSheets.addFrameSheet(frameSheet);
	}
	
	FrameSheetCollection * FrameSheetGenerator::generate()
	{
		if(handler == 0)
		{
			Logger::getInstance()->write("You must set a handler before you can run the generate function.");
			return 0;
		}

		generateImages();

		// the generator should not have ownership of the input sprite sheets, so empty references before the generator destructs
		inputFrameSheets.clearFrameSheets();

		if(individualImages.size() == 0)
		{
			return 0;
		}

		FrameSheetCollection * frameSheetCollection = new FrameSheetCollection();

		// sort the images
		std::stable_sort(individualImages.begin(), individualImages.end(), SortPredicate());

		// calculate optimal rectangle placement
		do
		{
			RectanglePacking::Packer * packer = new RectanglePacking::Packer(handler);

			std::vector<sf::IntRect *> rectangles;

			for(unsigned int i = 0; i < individualImages.size(); i++)
			{
				unsigned int currentWidth = individualImages[i].second->GetWidth();
				unsigned int currentHeight = individualImages[i].second->GetHeight();

				if(currentWidth > maximumImageWidth || currentHeight > maximumImageHeight)
				{
					Logger::getInstance()->write("An image was too large to fit inside the maximum image width or maximum image height.");
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

			FrameSheet * currentFrameSheet = new FrameSheet(imageManager);
			currentFrameSheet->setName(Utility::intToString(frameSheetCollection->getFrameSheetCount()));
			currentFrameSheet->setImage(currentImage);

			for(unsigned int i = 0; i < rectangles.size(); i++)
			{
				currentImage->Copy(*individualImages[i].second, rectangles[i]->Left, rectangles[i]->Top);
				currentFrameSheet->addRectangle(individualImages[i].first, *rectangles[i]);
			}

			removeImages(0, rectangles.size());

			for(unsigned int i = 0; i < rectangles.size(); i++)
			{
				delete rectangles[i];
			}

			delete packer;

			frameSheetCollection->addFrameSheet(currentFrameSheet);
		}
		while(individualImages.size() > 0);

		return frameSheetCollection;
	}

	void FrameSheetGenerator::setHandler(RectanglePacking::BaseHandler * handler)
	{
		this->handler = handler;
	}

	void FrameSheetGenerator::pushImage(const std::string &name, sf::Image * image)
	{
		imageManager->add(name, image);
		individualImages.push_back(std::pair<std::string, sf::Image *>(name, image));
	}

	Frame * FrameSheetGenerator::getFrame(const std::string &name)
	{
		return inputFrameSheets.getFrame(name);
	}

	void FrameSheetGenerator::removeImage(int index)
	{
		imageManager->release(individualImages[index].first);
		individualImages.erase(individualImages.begin() + index);
	}

	void FrameSheetGenerator::removeImages(int first, int last)
	{
		for(int i = first; i < last; i++)
		{
			imageManager->release(individualImages[i].first);
		}
		individualImages.erase(individualImages.begin() + first, individualImages.begin() + last);
	}

	bool SortPredicate::operator()(const std::pair<std::string, sf::Image *> &a, const std::pair<std::string, sf::Image *> &b)
	{
		// as recommended by http://www.flipcode.com/archives/Rectangle_Placement.shtml
		return (a.second->GetWidth() > b.second->GetWidth() && a.second->GetWidth() > b.second->GetHeight()) || (a.second->GetHeight() > b.second->GetWidth() && a.second->GetHeight() > b.second->GetHeight());
	}
}
