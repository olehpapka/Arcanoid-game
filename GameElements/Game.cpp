#include "../Headers/Game.h"


Game* Game::game = nullptr;

Game::Game()
{
	screenHeight = 0;
	screenWidth = 0;

	time = std::time(0);
	lastSpawnAbilityTime = 1;
}

Game* Game::GetInstance()
{
	if (game == nullptr)
	{
		game = new Game();
	}
	return game;
}


void Game::DrawObjects()
{
	drawTestBackground();

	for (auto item : objects)
		item->Draw();

	mouse->draw(mouseX, mouseY);
}

Mouse* Game::GetMouse()
{
	return mouse;
}

void Game::MoveObjects()
{
	for (auto obj : objects)
	{
		obj->Update();
	}
}

void Game::GameLogic()
{
	MoveObjects();
	CheckCollisions();
	DrawObjects();
	
	if (GetSeconds() > lastSpawnAbilityTime && GetSeconds() % 5 == 0)
	{
		SpawnAbility();
		lastSpawnAbilityTime = GetSeconds();
	}
}

int Game::GetSeconds()
{
	return static_cast<int>(difftime(std::time(0), time));
}

void Game::CheckCollisions()
{
	for (auto obj1 : objects)
	{
		for (auto obj2 : objects)
		{
			if (obj1 != obj2)
			{
				Collider::CheckCollision(obj1, obj2);
			}
				
		}
	}
}

int& Game::SetScreenWidth()
{
	return screenWidth;
}

int& Game::SetScreenHeight()
{
	return screenHeight;
}

int Game::GetScreenWidth()
{
	return screenWidth;
}

int Game::GetScreenHeight()
{
	return screenHeight;
}

bool Game::GameOver()
{
	return isGameOver;
}

void Game::OnKeyInputReceived(FRKey k)
{
	for (auto item : objects)
	{
		item->HandleKeyInput(k);
	}
}

void Game::OnMouseMove(int x, int y, int relX, int relY)
{
	mouseX = x;
	mouseY = y;
}

void Game::OnMouseButtonClicked(FRMouseButton button, bool isReleased)
{
	for (auto item : objects)
		item->OnMouseButtonClicked(button, isReleased);
}

void Game::SetGameOver(bool state)
{
	isGameOver = state;
}

int Game::GetMouseX()
{
	return mouseX;
}

int Game::GetMouseY() 
{
	return mouseY;
}

void Game::Restart()
{
	for (auto item : objects)
	{
		if(item)
			delete item;
	}
		

	objects.clear();

	SetGameOver(false);

	mouse = new Mouse();

	int screenWidth = GetScreenWidth();
	int screenHeight = GetScreenHeight();

	int platformWidth = screenWidth / 5;
	int platformHeight = 45;
	int platformX = (screenWidth - platformWidth) / 2;
	int platformY = screenHeight - 2 * platformHeight;

	int ballDiametr = 40;

	auto platform = new Platform("data/56-Breakout-Tiles.png", platformX, platformY, platformWidth, platformHeight);
	auto ball = new Ball("data/62-Breakout-Tiles.png", (screenWidth - ballDiametr) / 2, platformY - ballDiametr - 5, ballDiametr, ballDiametr);
	auto brickManager = new BrickManager(5, 3, screenWidth, screenHeight);
	objects.emplace_back(platform);
	objects.emplace_back(ball);
	objects.emplace_back(brickManager);
}

void Game::SpawnAbility()
{
	int x = rand() % GetScreenWidth();
	int y = (rand() % GetScreenHeight()) / 2;

	ability = new Ability("data/60-Breakout-Tiles.png", x, y, 64, 64);
	objects.emplace_back(ability);
}

void Game::DestroyAbility()
{
	auto position = std::find(objects.begin(), objects.end(), ability);
	if (position != objects.end())
		objects.erase(position);
}

Game::~Game()
{
	for (auto item : objects)
		delete item;
}