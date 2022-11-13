#include "../Headers/Collider.h"

Collider::Collider(int left, int right, int top, int bottom)
{
	this->left = left;
	this->right = right;
	this->top = top;
	this->bottom = bottom;
}

void Collider::UpdateLocation(float newLeft, float newRight, float newTop, float newBottom)
{
	left = newLeft;
	right = newRight;
	top = newTop;
	bottom = newBottom;
}

bool Collider::IsInside(float value, float left, float right)
{
	return value >= left && value <= right;
}


bool Collider::IsIntersected(const Collider& c)
{
	bool x = IsInside(left, c.left, c.right) || IsInside(c.left, left, right);
	bool y = IsInside(top, c.bottom, c.top) || IsInside(c.top, bottom, top);
	bool t = IsInside(bottom, c.bottom, c.top) || IsInside(c.bottom, bottom, top);
	return x && y || x && t;
}

void Collider::CheckCollision(GameObject* obj1, GameObject* obj2)
{

	if (obj1 != obj2 && obj1 && obj2 &&
		obj1->GetCollider()->IsIntersected(*obj2->GetCollider()))
	{
		obj1->OnCollision(obj2);

		if (obj2 && obj1)
		{
			obj2->OnCollision(obj1);
		}
			
	}

	for (auto obj3 : obj1->GetSubObjects())
	{
		if (obj3 && obj2)
			Collider::CheckCollision(obj3, obj2);
		for (auto obj4 : obj2->GetSubObjects())
		{
			if (obj4)
			{
				Collider::CheckCollision(obj3, obj4);
				Collider::CheckCollision(obj4, obj2);
			}
		}
	}
}



