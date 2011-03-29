#ifndef CARD_HPP
#define CARD_HPP

#include "Common.hpp"

#include "GazaFrame.hpp"
#include "GazaFrameSheetCollection.hpp"
#include "GazaLogger.hpp"
#include "GazaSprite.hpp"

#include <string>

class Card : public Gaza::Sprite
{
public:
	Card(CardColor cardColor, CardNumber cardNumber, CardPattern cardPattern, CardShape cardShape, Gaza::FrameSheetCollection * cardSprites);
	~Card();

	CardColor getCardColor();
	CardNumber getCardNumber();
	CardPattern getCardPattern();
	CardShape getCardShape();

	bool getSelected();
	void setSelected(bool selected);
	void toggleSelected();

	void click();

private:
	static std::string getSpriteName(CardColor cardColor, CardNumber cardNumber, CardPattern cardPattern, CardShape cardShape);

	bool selected;

	CardColor cardColor;
	CardNumber cardNumber;
	CardPattern cardPattern;
	CardShape cardShape;

	Gaza::Frame * unselectedFrame;
	Gaza::Frame * selectedFrame;
};

#endif