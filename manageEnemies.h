#pragma once
#include "enemy.h"
#include <math.h>
#include <vector>
#include "Framework/GameObject.h"
#include <iostream>

class manageEnemies
{
public:
	manageEnemies();
	~manageEnemies();
	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);
	void setSpawnX(int x);
	void setSpawnY(int y);

	std::vector <enemy> &getEnemies();
private:
	std::vector <enemy> enemies;
	sf::Texture sprite;

	int spawnX;
	int spawnY;
};

