#include "../Headers/Mouse.h"


Mouse::Mouse()
{
	sprite = createSprite("data/59-Breakout-Tiles.png");
	if (sprite)
		setSpriteSize(sprite, 30, 30);
}

Sprite* Mouse::GetSprite()
{
	return sprite;
}

void Mouse::draw(int x, int y)
{
	if (sprite)
		drawSprite(sprite, x, y);
}