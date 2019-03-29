#include "enemy.h"



enemy::enemy()
{
	health = 1;
}


enemy::~enemy()
{
}

void enemy::update(float dt)
{
	move(velocity*dt);
}

void enemy::collisionResponse(GameObject * collider)
{
	//setHealth(0);//If this runs the collision response activates across all the entities
	setVelocity(200, 0);//If this runs, then the enemies will only interact if hit by the player
}

void enemy::setHealth(int h)
{
	health = h;
}

int enemy::getHealth()
{
	return health;
}

