#include "GazaSubImage.hpp"

namespace Gaza
{
	SubImage::SubImage()
	{

	}

	SubImage::SubImage(const sf::IntRect &rectangle, sf::Image * image)
	{
		this->rectangle = rectangle;
		this->image = image;
	}


}