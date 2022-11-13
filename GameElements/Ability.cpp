#include "../Headers/Ability.h"
#include "../Headers/Platform.h"
#include "../Headers/Game.h"

Ability::Ability(const char* spritePath, int x, int y, int w, int h)
	: GameObject(spritePath, x, y, w, h)
{}

void Ability::Update()
{
	this->Move();
}

void Ability::Move()
{
	GameObject::Move(0, 1);
}