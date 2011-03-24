#include "GazaScottHandler.hpp"

namespace Gaza
{
	namespace RectanglePacking
	{
		ScottHandler::ScottPackerNode::ScottPackerNode(const sf::IntRect &rectangle)
		{
			this->rectangle = rectangle;
			leftChild = 0;
			rightChild = 0;
			filled = false;
		}

		ScottHandler::ScottPackerNode::~ScottPackerNode()
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

		bool ScottHandler::ScottPackerNode::addRectangle(sf::IntRect * inputRectangle)
		{
			if(leftChild != 0 || rightChild != 0)
			{
				bool leftSuccess = leftChild->addRectangle(inputRectangle);
				if(!leftSuccess)
				{
					return rightChild->addRectangle(inputRectangle);
				}
				return leftSuccess;
			}
			else
			{
				if(filled || inputRectangle->Width > rectangle.Width || inputRectangle->Height > rectangle.Height)
				{
					return false;
				}

				if(inputRectangle->Width == rectangle.Width && inputRectangle->Height == rectangle.Height)
				{
					filled = true;
					inputRectangle->Left = rectangle.Left;
					inputRectangle->Top = rectangle.Top;
					inputRectangle->Width = rectangle.Width;
					inputRectangle->Height = rectangle.Height;

					return true;
				}

				int widthDifference = rectangle.Width - inputRectangle->Width;
				int heightDifference = rectangle.Height - inputRectangle->Height;

				sf::IntRect leftRectangle(rectangle);
				sf::IntRect rightRectangle(rectangle);

				if(widthDifference > heightDifference)
				{
					leftRectangle.Width = inputRectangle->Width;
					rightRectangle.Left += inputRectangle->Width;
					rightRectangle.Width -= inputRectangle->Width;
				}
				else
				{
					leftRectangle.Height = inputRectangle->Height;
					rightRectangle.Top += inputRectangle->Height;
					rightRectangle.Height -= inputRectangle->Height;
				}

				leftChild = new ScottPackerNode(leftRectangle);
				rightChild = new ScottPackerNode(rightRectangle);

				return leftChild->addRectangle(inputRectangle);
			}
		}

		ScottHandler::ScottHandler()
		{
			rootNode = 0;
		}

		ScottHandler::~ScottHandler()
		{
			if(rootNode != 0)
			{
				delete rootNode;
			}
		}

		void ScottHandler::initialize(unsigned int width, unsigned int height)
		{
			if(rootNode != 0)
			{
				delete rootNode;
			}
			rootNode = new ScottPackerNode(sf::IntRect(0, 0, width, height));
		}

		bool ScottHandler::addRectangle(sf::IntRect * inputRectangle)
		{
			return rootNode->addRectangle(inputRectangle);
		}
	}
}