#pragma once
#include "Brick.h"
#include <vector>
#include <algorithm>

class BrickManager : public GameObject
{
private:
	int dy;

	int lastMovedTime;

	int blocksToDestroy = 0;
public:
	BrickManager(int, int, int, int);
	void MoveDown();

	void RemoveSubObject(GameObject*) override;
	void Update() override;
};
