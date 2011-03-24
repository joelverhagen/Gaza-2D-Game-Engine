#ifndef GAZASCOTTPACKER_HPP
#define GAZASCOTTPACKER_HPP

#include "Gaza.hpp"
#include "GazaBaseHandler.hpp"

namespace Gaza
{
	namespace RectanglePacking
	{
		class ScottHandler : public BaseHandler
		{
		public:
			ScottHandler();
			~ScottHandler();

			void initialize(unsigned int width, unsigned int height);
			bool addRectangle(sf::IntRect * inputRectangle);

		private:
			class ScottPackerNode
			{
			public:
				ScottPackerNode(const sf::IntRect &rectangle);
				~ScottPackerNode();

				bool addRectangle(sf::IntRect * inputRectangle);

				sf::IntRect rectangle;
				ScottPackerNode * leftChild;
				ScottPackerNode * rightChild;
				bool filled;			
			};

			ScottPackerNode * rootNode;
		};
	}
}


#endif