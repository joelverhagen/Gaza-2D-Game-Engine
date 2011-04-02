#include "CardFrameSheetGenerator.hpp"

CardFrameSheetGenerator::CardFrameSheetGenerator(Gaza::ImageManager * imageManager, Gaza::FrameSheet * frameSheet) : FrameSheetGenerator(imageManager)
{
	setHandler(&scottHandler);
	addFrameSheet(frameSheet);
}

void CardFrameSheetGenerator::generateImages()
{
	// push the empty spot image
	Gaza::Frame * emptySpot = getFrame("emptySpot");
	sf::Image * emptySpotImage = new sf::Image();
	emptySpotImage->Create(emptySpot->rectangle.Width, emptySpot->rectangle.Height);
	emptySpotImage->Copy(*emptySpot->image, 0, 0, emptySpot->rectangle);

	pushImage("emptySpot", emptySpotImage);

	// generate the highlight spot
	newAnimationFrameNameList("highlightSpot");

	Gaza::Frame * highlightSpot = getFrame("highlightSpot");

	sf::Image * highlightSpotImage;

	int highlightFrameCount = 20;
	for(int i = highlightFrameCount - 1; i >= 0; i--)
	{
		int alphaDifference = 255 - (int)Gaza::Utility::round((255 / (float)(highlightFrameCount - 1)) * i);

		highlightSpotImage = new sf::Image();
		highlightSpotImage->Create(highlightSpot->rectangle.Width, highlightSpot->rectangle.Height);

		if(alphaDifference != 255)
		{
			highlightSpotImage->Copy(*highlightSpot->image, 0, 0, highlightSpot->rectangle);
			
			if(alphaDifference > 0)
			{
				for(unsigned int x = 0; x < highlightSpotImage->GetWidth(); x++)
				{
					for(unsigned int y = 0; y < highlightSpotImage->GetHeight(); y++)
					{
						// maintain the color, decrease the alpha
						sf::Color pixel = highlightSpotImage->GetPixel(x, y);
						int newAlpha = pixel.a - alphaDifference;
						if(newAlpha < 0)
						{
							newAlpha = 0;
						}
						pixel.a = newAlpha;

						highlightSpotImage->SetPixel(x, y, pixel);
					}
				}
			}
		}

		std::string highlightSpotFrameName = "highlightSpot"+Gaza::Utility::intToString(i);

		pushImage(highlightSpotFrameName, highlightSpotImage);
		addAnimationFrameName("highlightSpot", highlightSpotFrameName);
	}


	// Generate the individual images
	std::pair<std::string, sf::Color> cardColors[3];
	cardColors[0] = std::pair<std::string, sf::Color>("green", sf::Color(0, 127, 0));
	cardColors[1] = std::pair<std::string, sf::Color>("purple", sf::Color(127, 0, 127));
	cardColors[2] = std::pair<std::string, sf::Color>("red", sf::Color(255, 0, 0));

	std::pair<std::string, int> cardNumbers[3];
	cardNumbers[0] = std::pair<std::string, int>("One", 1);
	cardNumbers[1] = std::pair<std::string, int>("Two", 2);
	cardNumbers[2] = std::pair<std::string, int>("Three", 3);

	std::pair<std::string, std::string> cardPatterns[3];
	cardPatterns[0] = std::pair<std::string, std::string>("Empty", "empty");
	cardPatterns[1] = std::pair<std::string, std::string>("Solid", "solid");
	cardPatterns[2] = std::pair<std::string, std::string>("Striped", "striped");

	std::pair<std::string, std::string> cardShapes[3];
	cardShapes[0] = std::pair<std::string, std::string>("Diamond", "Diamond");
	cardShapes[1] = std::pair<std::string, std::string>("Oval", "Oval");
	cardShapes[2] = std::pair<std::string, std::string>("Squiggly", "Squiggly");

	Gaza::Frame * unselectedCard = getFrame("unselectedCard");
	sf::Image unselectedImage;
	unselectedImage.Create(unselectedCard->rectangle.Width, unselectedCard->rectangle.Height);
	unselectedImage.Copy(*unselectedCard->image, 0, 0, unselectedCard->rectangle);
					
	Gaza::Frame * selectedCard = getFrame("selectedCard");
	sf::Image selectedImage;
	selectedImage.Create(selectedCard->rectangle.Width, selectedCard->rectangle.Height);
	selectedImage.Copy(*selectedCard->image, 0, 0, selectedCard->rectangle);

	bool renderImageMethod = false;

	sf::Clock clock;
	for(int p = 0; p < 3; p++) 
	{
		for(int s = 0; s < 3; s++)
		{
			Gaza::Frame * symbol = getFrame(cardPatterns[p].second+cardShapes[s].second);
			for(int c = 0; c < 3; c++)
			{
				sf::RenderImage symbolRenderImage;
				sf::Image symbolImage;
				if(renderImageMethod)
				{
					// This method is really slow
					sf::Sprite symbolSprite;
					symbolSprite.SetImage(*symbol->image);
					symbolSprite.SetSubRect(symbol->rectangle);
					symbolSprite.SetColor(cardColors[c].second);

					symbolRenderImage.Create(symbol->rectangle.Width, symbol->rectangle.Height);
					symbolRenderImage.Clear(sf::Color(0, 0, 0, 0));
					symbolRenderImage.Draw(symbolSprite);
					symbolRenderImage.Display();
				}
				else
				{
					symbolImage.Create(symbol->rectangle.Width, symbol->rectangle.Height);
					symbolImage.Copy(*symbol->image, 0, 0, symbol->rectangle);

					for(unsigned int x = 0; x < symbolImage.GetWidth(); x++)
					{
						for(unsigned int y = 0; y < symbolImage.GetHeight(); y++)
						{
							// maintain the alpha, but copy the color over
							sf::Color pixel = symbolImage.GetPixel(x, y);
							pixel.r = cardColors[c].second.r;
							pixel.g = cardColors[c].second.g;
							pixel.b = cardColors[c].second.b;
							symbolImage.SetPixel(x, y, pixel);
						}
					}
				}

				for(int n = 0; n < 3; n++)
				{
					sf::Image * currentUnselectedImage = new sf::Image(unselectedImage);
					sf::Image * currentSelectedImage = new sf::Image(selectedImage);

					int centerX = (unselectedCard->rectangle.Width - symbol->rectangle.Width) / 2;

					int spacingY = (unselectedCard->rectangle.Height - cardNumbers[n].second * symbol->rectangle.Height) / (cardNumbers[n].second + 1);
					int topY = spacingY;

					for (int i = 0; i < cardNumbers[n].second; i++)
					{
						if(renderImageMethod)
						{
							currentUnselectedImage->Copy(symbolRenderImage.GetImage(), centerX, topY, sf::IntRect(0, 0, 0, 0), true);
							currentSelectedImage->Copy(symbolRenderImage.GetImage(), centerX, topY, sf::IntRect(0, 0, 0, 0), true);
						}
						else
						{
							currentUnselectedImage->Copy(symbolImage, centerX, topY, sf::IntRect(0, 0, 0, 0), true);
							currentSelectedImage->Copy(symbolImage, centerX, topY, sf::IntRect(0, 0, 0, 0), true);
						}

						topY += spacingY + symbol->rectangle.Height;
					}

					std::string currentUnselectedName = cardColors[c].first+cardNumbers[n].first+cardPatterns[p].first+cardShapes[s].first+"Unselected";
					std::string currentSelectedName = cardColors[c].first+cardNumbers[n].first+cardPatterns[p].first+cardShapes[s].first+"Selected";

					pushImage(currentUnselectedName, currentUnselectedImage);
					pushImage(currentSelectedName, currentSelectedImage);
				}
			}
		}
	}
}