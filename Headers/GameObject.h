#pragma once
#include "Framework.h"
#include <vector>

class Collider;

class GameObject
{
protected:
	Sprite* sprite;
	Collider* collider;
	std::vector<GameObject*> subObjects;
	GameObject* parent;
	float x;
	float y;
	float width;
	float height;
	bool isInitialState = true;
public:
	GameObject(const char* spritePath, int x, int y, int w, int h);
	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();
	void AddSubObject(GameObject*);
	virtual void RemoveSubObject(GameObject*);
	std::vector<GameObject*> GetSubObjects();
	Collider* GetCollider();
	Sprite* GetSprite();
	void UpdateSprite(const char*);
	virtual void Move(float dx, float dy = 0);

	virtual void Update() {}
	virtual void Draw();
	virtual void OnCollision(GameObject*) {}
	virtual void HandleKeyInput(FRKey) {}
	virtual void OnMouseButtonClicked(FRMouseButton button, bool isReleased) {}

	~GameObject();
};
