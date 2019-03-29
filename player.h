#pragma once
#include "Framework/Vector.h"
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class player : public GameObject
{
public:
	player();
	~player();
	void handleInput(float dt);
	void update(float dt);
	void collisionResponse(GameObject * collider);

private:
	float scale;
	bool clicked;
	int health;

	Animation move_cycle;

};