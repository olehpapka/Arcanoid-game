#pragma once
#include "Framework.h"
#include "Game.h"
#include <iostream>

class Ball : public GameObject
{
private:
	float dx;
	float dy;
	float speed;
	bool isInitialState;
public:
	Ball(const char* spritePath, int x, int y, int w, int);
	void Move();

	void Update() override;
	void OnCollision(GameObject*) override;
	void OnMouseButtonClicked(FRMouseButton button, bool isReleased) override;

	~Ball();
};