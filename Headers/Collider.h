#pragma once
#include "GameObject.h"

enum ColliderLayers
{
	BRICK = 1,
	OTHER = 2
};

inline ColliderLayers operator|(ColliderLayers a, ColliderLayers b)
{
	return static_cast<ColliderLayers>(static_cast<int>(a) | static_cast<int>(b));
}

class Collider
{
private:
	float left;
	float right;
	float top;
	float bottom;

	bool isColliding = false;
public:
	Collider(int,int,int,int);
	bool IsInside(float, float, float);
	bool IsIntersected(const Collider&);
	void UpdateLocation(float, float, float, float);
	//virtual void SetCollisionFlags(ColliderLayers layers);

	static void CheckCollision(GameObject*, GameObject*);
};

