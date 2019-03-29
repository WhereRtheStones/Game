#include "manageEnemies.h"



manageEnemies::manageEnemies()
{
	sprite.loadFromFile("gfx/Beach_Ball.png");

	for (int i = 0; i < 20; i++)
	{
		enemies.push_back(enemy());
		enemies[i].setAlive(false);
		enemies[i].setTexture(&sprite);
		enemies[i].setSize(sf::Vector2f(100, 100));
		enemies[i].setCollisionBox(0, 0, 100, 100);
	}

}


manageEnemies::~manageEnemies()
{
}

void manageEnemies::spawn()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		if (!enemies[i].isAlive())
		{
			enemies[i].setAlive(true);
			enemies[i].setVelocity(0,0);
			enemies[i].setPosition(rand() % 800 - 100, rand() % 600 - 100);
			return;
		}
	}
}

void manageEnemies::update(float dt)
{
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].isAlive())
		{
			enemies[i].update(dt);
		}

	}
	deathCheck();
}

void manageEnemies::deathCheck()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].isAlive())
		{
			if (enemies[i].getHealth() == 0)
			{
				enemies[i].setVelocity(200,0);
			}
		}
	}
}

void manageEnemies::render(sf::RenderWindow * window)
{
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].isAlive())
		{
			window->draw(enemies[i]);
		}
	}
}

void manageEnemies::setSpawnX(int x)
{
	spawnX = x;
}

void manageEnemies::setSpawnY(int y)
{
	spawnY = y;
}

std::vector<enemy>& manageEnemies::getEnemies()
{
	return enemies;
}
