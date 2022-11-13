#include "../Headers/Ball.h"
#include "../Headers/Brick.h"
#include "../Headers/Platform.h"

Ball::Ball(const char* spritePath, int x, int y, int w, int h)
	: GameObject(spritePath, x, y, w, h)
{
	dx = 0;
	dy = 0;
	speed = 2;
	isInitialState = true;
}


void Ball::Move()
{
	int screenWidth = Game::GetInstance()->GetScreenWidth();
	int screenHeight = Game::GetInstance()->GetScreenHeight();

	float futureX = x + dx;
	float futureY = y + dy;

	if (futureX < 0 || futureX+width > screenWidth)
		dx *= -1;
	if (futureY < 0)
		dy *= -1;
	if (futureY + width > screenHeight)
		Game::GetInstance()->SetGameOver(true);
	
		

	GameObject::Move(dx * speed, dy * speed);
}

void Ball::Update()
{
	this->Move();
}

void Ball::OnCollision(GameObject* obj) 
{
	if (dynamic_cast<Platform*>(obj))
	{
		dy *= -1;
		Move();
	}
	else if (auto it = dynamic_cast<Brick*>(obj))
	{
		dy *= -1;
		Move();
	}
}

void Ball::OnMouseButtonClicked(FRMouseButton button, bool isReleased)
{
	if (button == FRMouseButton::LEFT && isInitialState)
	{
		int mouseX = Game::GetInstance()->GetMouseX();
		int mouseY = Game::GetInstance()->GetMouseY();

		int ballCenterX = x + width / 2;
		int ballCenterY = y + height / 2;
	
		int vecX = mouseX - ballCenterX;
		int vecY = mouseY - ballCenterY;
		float l = sqrt(pow(vecX, 2) + pow(vecY, 2));

		dx = vecX / l;
		dy = vecY / l;

		isInitialState = false;
	}
}



Ball::~Ball()
{
	delete collider;
}