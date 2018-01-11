#pragma once

#include "IDisplay.h"

/* Displayable block */
class Block : public IDisplay
{
	private:
		void renderBlock();
	public:
		bool isEmpty = true;
		void display();
		inline void setVisible(bool isVisible) { isEmpty = !isVisible; };
		Block();
};
