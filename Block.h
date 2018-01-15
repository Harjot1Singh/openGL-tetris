#pragma once

#include <array>

#include "IDisplay.h"

/* Displayable block */
class Block : public IDisplay
{
	private:
		std::array<float, 3> color;
		std::array<float, 3> outlineColor;
		bool isEmpty = true;
	public:
		inline bool getEmpty() { return isEmpty; };
		inline void setEmpty(bool e) { isEmpty = e; };
		void display();
		void setColor(std::array<float, 3> color);
		Block();
};
