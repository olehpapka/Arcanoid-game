#pragma once
#include "Framework.h"

class Mouse
{
private:
	Sprite* sprite;
public:
	Mouse();
	Sprite* GetSprite();
	void draw(int, int);
};