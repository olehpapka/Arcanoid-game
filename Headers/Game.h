#pragma once
#include <array>
#include <vector>
#include <time.h>
#include "Platform.h"
#include "Ball.h"
#include "Mouse.h"
#include "BrickManager.h"
#include "Collider.h"
#include "Ability.h"

class Game
{
private:
	std::vector<GameObject*> objects;
	Mouse* mouse;
	int screenWidth;
	int screenHeight;

	int mouseX;
	int mouseY;

	bool isGameOver = false;

	static Game* game;
	
	int lastSpawnAbilityTime;
	GameObject* ability;
	time_t time;

	Game();
public:
	static Game* GetInstance();
	void DrawObjects();
	Mouse* GetMouse();
	void MoveObjects();
	void GameLogic();
	int& SetScreenWidth();
	int& SetScreenHeight();
	int GetScreenWidth();
	int GetScreenHeight();
	bool GameOver();
	void CheckCollisions();

	void SetGameOver(bool);
	void OnKeyInputReceived(FRKey);
	void OnMouseMove(int, int, int, int);
	void OnMouseButtonClicked(FRMouseButton button, bool isReleased);
	int GetMouseX();
	int GetMouseY();
	void Restart();

	void SpawnAbility();
	void DestroyAbility();

	int GetSeconds();

	~Game();
	

};