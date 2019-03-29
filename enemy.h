#pragma once
#include "Framework/Vector.h"
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class enemy : public GameObject
{
public:
	enemy();
	~enemy();

	void update(float dt);
	void collisionResponse(GameObject * collider); //Collision for taking damage
	void setHealth(int d);
	int getHealth();

private:
	int health;




};

