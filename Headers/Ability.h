#pragma once
#include "GameObject.h"

class Platform;

class Ability : public GameObject
{
public:
	Ability(const char* spritePath, int x, int y, int w, int h);
	
	void Update() override;
	void Move();
};