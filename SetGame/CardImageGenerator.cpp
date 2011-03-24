#include "CardImageGenerator.h"

void  CardImageGenerator::generateIndividualImages()
{
	sf::Color cardColors[3];
	cardColors[0] = sf::Color(0, 128, 0); // green
	cardColors[1] = sf::Color(128, 0, 128); // purple
	cardColors[2] = sf::Color(255, 0, 0); // red

	string cardPatterns[3];
	cardPatterns[0] = "empty";
	cardPatterns[1] = "solid";
	cardPatterns[2] = "striped";

	string cardShapes[3];
	cardShapes[0] = "Diamond";
	cardShapes[1] = "Oval";
	cardShapes[2] = "Squiggly";

	SpriteSheet * cardSpriteSheet = getInputSpriteSheet("cardSprites");
	sf::Image * cardSpritesImage = cardSpriteSheet->getImage();

	sf::IntRect unselectedCard = cardSpriteSheet->getRectangle("unselectedCard");
	sf::IntRect selectedCard = cardSpriteSheet->getRectangle("selectedCard");

	sf::Image unselectedImage;
	unselectedImage.Create(unselectedCard.Width, unselectedCard.Height);
	unselectedImage.Copy(*cardSpritesImage, 0, 0, unselectedCard);
					
	sf::Image selectedImage;
	selectedImage.Create(selectedCard.Width, selectedCard.Height);
	selectedImage.Copy(*cardSpritesImage, 0, 0, selectedCard);

	for(int p = 0; p < 3; p++) 
	{
		for(int s = 0; s < 3; s++)
		{
			for(int c = 0; c < 3; c++)
			{
				sf::IntRect symbol = cardSpriteSheet->getRectangle(cardPatterns[p]+cardShapes[s]);
				sf::Image * symbolImage = new sf::Image();

				symbolImage->Create(symbol.Width, symbol.Height);

				symbolImage->Copy(*cardSpritesImage, 0, 0, symbol);

				for(int n = 1; n <= 3; n++)
				{
					sf::Image * currentUnselectedImage = new sf::Image(unselectedImage);
					
					sf::Image * currentSelectedImage = new sf::Image(selectedImage);

					int centerX = (unselectedCard.Width - symbol.Width) / 2;

					int spacingY = (unselectedCard.Height - n * symbol.Height) / (n + 1);
					int topY = spacingY;

					for (int i = 0; i < n; i++)
					{
						currentUnselectedImage->Copy(*symbolImage, centerX, topY, sf::IntRect(0, 0, 0, 0), true);
						currentSelectedImage->Copy(*symbolImage, centerX, topY, sf::IntRect(0, 0, 0, 0), true);

						topY += spacingY + symbol.Height;
					}

					individualImages.push_back(currentUnselectedImage);
					individualImages.push_back(currentSelectedImage);
				}

				delete symbolImage;
			}
		}
	}

	sf::IntRect emptySpot = cardSpriteSheet->getRectangle("emptySpot");

	sf::Image * emptySpotImage = new sf::Image();
	emptySpotImage->Create(emptySpot.Width, emptySpot.Height);
	emptySpotImage->Copy(*cardSpritesImage, 0, 0, emptySpot);

	individualImages.push_back(emptySpotImage);
}

CardImageGenerator::CardImageGenerator(SpriteSheet * spriteSheet)
{
	addInputSpriteSheet("cardSprites", spriteSheet);
}