#include "../Headers/GameObject.h"
#include "../Headers/Collider.h"

GameObject::GameObject(const char* spritePath, int x, int y, int w, int h)
{
    this->x = x;
    this->y = y;
    this->width = w;
    this->height = h;

    if (spritePath)
    {
        this->sprite = createSprite(spritePath);
        setSpriteSize(sprite, width, height);
    }
 
    this->collider = new Collider(x, x + width, y, y + height);
}

int GameObject::GetX()
{
    return x;
}

int GameObject::GetY()
{
    return y;
}

int GameObject::GetWidth()
{
    return width;
}

int GameObject::GetHeight()
{
    return height;
}

Collider* GameObject::GetCollider()
{
    return collider;
}

Sprite* GameObject::GetSprite()
{
    return sprite;
}

void GameObject::Move(float dx, float dy)
{
    x += dx;
    y += dy;

    if (collider)
        collider->UpdateLocation(x, x + width, y + height, y);

    for (auto obj : subObjects)
        obj->Move(dx, dy);
}

void GameObject::Draw()
{
    if (sprite)
        drawSprite(sprite, x, y);

    for (auto obj : subObjects)
        obj->Draw();
}

void GameObject::AddSubObject(GameObject* obj)
{
    obj->parent = this;
    subObjects.emplace_back(obj);
}

void GameObject::RemoveSubObject(GameObject* obj)
{
    auto position = std::find(subObjects.begin(), subObjects.end(), obj);
    if (position != subObjects.end())
        subObjects.erase(position);
}

std::vector<GameObject*> GameObject::GetSubObjects()
{
    return subObjects;
}

void GameObject::UpdateSprite(const char* path)
{
    destroySprite(sprite);
    sprite = createSprite(path);
    setSpriteSize(sprite, width, height);
}


GameObject::~GameObject()
{
    delete collider;

    if (sprite)
        destroySprite(sprite);

    for (auto obj : subObjects)
        delete obj;
}