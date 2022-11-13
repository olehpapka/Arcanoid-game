#pragma once
#include "GameObject.h"

class Collider;

class Platform : public GameObject
{
public:
	Platform(const char* spritePath, int x, int y, int w, int h);
	void HandleKeyInput(FRKey) override;
	void OnCollision(GameObject*) override;
};