#include "../Headers/Platform.h"
#include "../Headers/Game.h"

Platform::Platform(const char* spritePath, int x, int y, int w, int h) 
	: GameObject(spritePath, x, y, w, h)
{

}

void Platform::HandleKeyInput(FRKey k)
{
	int dx{};
	if (k == FRKey::RIGHT && x < Game::GetInstance()->GetScreenWidth() - width)
	{
		dx = 30;
		Move(dx);
		GetCollider()->UpdateLocation(x, x + width, y + height, y);
	}
	if (k == FRKey::LEFT && x > 0)
	{
		dx = -30;
		Move(dx);
		collider->UpdateLocation(x, x + width,y + height, y);
	}
}

void Platform::OnCollision(GameObject *obj)
{
	if (auto it = dynamic_cast<Ability*>(obj))
	{
		Game::GetInstance()->DestroyAbility();
	}
}
