#include "../Headers/BrickManager.h"
#include "../Headers/Game.h"

BrickManager::BrickManager(int w, int h, int screenWidth, int screenHeight) : GameObject(nullptr, 0, 0, 0, 0)
{
	dy = 1;
	lastMovedTime = 1;

	int brickWidth = screenWidth / w;
	int brickHeight = 45;
	for (int j = 0; j < h; j++)
		for (int i = 0; i < w; i++)
		{
			int type = rand() % 3 + 1;
			if (type == 3) type = INT_MAX;
			else blocksToDestroy++;
			auto brick = Brick::MakeBrick(static_cast<BrickType>(type), brickWidth * i,
				brickHeight * j, brickWidth, brickHeight);
			AddSubObject(brick);
		}
}

void BrickManager::Update()
{
	int time = Game::GetInstance()->GetSeconds();
	if (time > lastMovedTime && time % 1 == 0)
	{
		MoveDown();
		lastMovedTime = time;
	}
}

void BrickManager::MoveDown()
{
	for (auto brick : subObjects)
	{
		brick->Move(0, dy);
	}
}

void BrickManager::RemoveSubObject(GameObject* obj)
{
	blocksToDestroy--;
	GameObject::RemoveSubObject(obj);

	if (blocksToDestroy == 0)
		Game::GetInstance()->SetGameOver(true);
}