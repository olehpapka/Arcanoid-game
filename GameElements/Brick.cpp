#include "../Headers/Brick.h"
#include "../Headers/Ball.h"
#include "../Headers/Platform.h"

Brick::Brick(unsigned int hp, const char* spritePath, int x, int y, int w, int h)
	: GameObject(spritePath, x, y, w, h)
{
	this->hp = hp;
	this->destroyed = false;
}

void Brick::Hit()
{
	hp--;
}

void Brick::OnCollision(GameObject* obj)
{
	if (dynamic_cast<Platform*>(obj))
	{
		Game::GetInstance()->SetGameOver(true);
	}
	else if (dynamic_cast<Ball*>(obj))
	{
		Hit();

		if (hp == 1)
			UpdateSprite("data/06-Breakout-Tiles.png");
		else if (hp <= 0)
			parent->RemoveSubObject(this);
	}
}

void Brick::Move(float dx, float dy)
{
	GameObject::Move(dx, dy);

	int screenHeight = Game::GetInstance()->GetScreenHeight();

	if (y + height >= screenHeight)
		Game::GetInstance()->SetGameOver(true);

	
}

Brick* Brick::MakeBrick(BrickType type, int x, int y, int w, int h)
{
	const char* path = nullptr;
	switch (type)
	{
	case REGULAR:
		path = "data/01-Breakout-Tiles.png";
		break;
	case HARDENED:
		path = "data/05-Breakout-Tiles.png";
		break;
	case UNBREAKABLE:
		path = "data/13-Breakout-Tiles.png";
		break;
	}

	return new Brick(type, path, x, y, w, h);
}