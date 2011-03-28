#include "GazaFrame.hpp"

namespace Gaza
{
	Frame::Frame()
	{

	}

	Frame::Frame(const sf::IntRect &rectangle, sf::Image * image)
	{
		this->rectangle = rectangle;
		this->image = image;
	}


}