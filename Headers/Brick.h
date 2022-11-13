#pragma once
#include "GameObject.h"

class Ball;
class Platform;

enum BrickType
{
	REGULAR = 1,
	HARDENED = 2,
	UNBREAKABLE = INT_MAX
};

class Brick : public GameObject
{
protected:
	bool destroyed;
	unsigned int hp;
public:
	Brick(unsigned int hp, const char* spritePath, int x, int y, int w, int h);

	void Hit();
	void OnCollision(GameObject*);
	void Move(float, float) override;

	static Brick* MakeBrick(BrickType, int, int, int, int);
};