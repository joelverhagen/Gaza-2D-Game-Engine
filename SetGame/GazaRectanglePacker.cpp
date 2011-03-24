#include "GazaRectanglePacker.hpp"

namespace Gaza
{
	namespace Utility
	{
		RectanglePackerNode::RectanglePackerNode(const sf::IntRect &rectangle)
		{
			this->rectangle = rectangle;
			leftChild = 0;
			rightChild = 0;
			filled = false;
		}

		RectanglePackerNode::~RectanglePackerNode()
		{
			if(leftChild != 0)
			{
				delete leftChild;
			}
			if(rightChild != 0)
			{
				delete rightChild;
			}
		}

		sf::IntRect RectanglePackerNode::insert(const sf::IntRect &inputRectangle)
		{
			if(leftChild != 0 || rightChild != 0)
			{
				sf::IntRect leftRectangle = leftChild->insert(inputRectangle);
				if(isZero(leftRectangle))
				{
					return rightChild->insert(inputRectangle);
				}
				return leftRectangle;
			}
			else
			{
				if(filled || inputRectangle.Width > rectangle.Width || inputRectangle.Height > rectangle.Height)
				{
					return zeroIntRect;
				}

				if(inputRectangle.Width == rectangle.Width && inputRectangle.Height == rectangle.Height)
				{
					filled = true;
					return rectangle;
				}

				int widthDifference = rectangle.Width - inputRectangle.Width;
				int heightDifference = rectangle.Height - inputRectangle.Height;

				sf::IntRect leftRectangle(rectangle);
				sf::IntRect rightRectangle(rectangle);

				if(widthDifference > heightDifference)
				{
					leftRectangle.Width = inputRectangle.Width;
					rightRectangle.Left += inputRectangle.Width;
					rightRectangle.Width -= inputRectangle.Width;
				}
				else
				{
					leftRectangle.Height = inputRectangle.Height;
					rightRectangle.Top += inputRectangle.Height;
					rightRectangle.Height -= inputRectangle.Height;
				}

				leftChild = new RectanglePackerNode(leftRectangle);
				rightChild = new RectanglePackerNode(rightRectangle);

				return leftChild->insert(inputRectangle);
			}
		}

		RectanglePacker::RectanglePacker(int width, int height)
		{
			rootNode = new RectanglePackerNode(sf::IntRect(0, 0, width, height));
		}

		RectanglePacker::~RectanglePacker()
		{
			delete rootNode;
		}

		sf::IntRect RectanglePacker::addRectangle(const sf::IntRect &rectangle)
		{
			return rootNode->insert(rectangle);
		}
	}
}