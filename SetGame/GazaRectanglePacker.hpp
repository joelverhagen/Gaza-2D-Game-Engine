#ifndef GAZARECTANGLEPACKER_HPP
#define GAZARECTANGLEPACKER_HPP

#include "Gaza.hpp"
#include "GazaUtility.hpp"

namespace Gaza
{
	namespace Utility
	{
		class RectanglePackerNode
		{
		public:
			RectanglePackerNode(const sf::IntRect &rectangle);
			~RectanglePackerNode();

			sf::IntRect insert(const sf::IntRect &inputRectangle);

			sf::IntRect rectangle;
			RectanglePackerNode * leftChild;
			RectanglePackerNode * rightChild;
			bool filled;			
		};

		class RectanglePacker
		{
		public:
			RectanglePacker(int width, int height);
			~RectanglePacker();

			sf::IntRect addRectangle(const sf::IntRect &rectangle);

		private:
			RectanglePackerNode * rootNode;
		};
	}
}

#endif