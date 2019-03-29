#include "player.h"

player::player()
{
	move_cycle.addFrame(sf::IntRect(0, 0, 95, 58));
	move_cycle.addFrame(sf::IntRect(98, 0, 95, 58));
	move_cycle.addFrame(sf::IntRect(195, 0, 95, 58));
	move_cycle.addFrame(sf::IntRect(292, 0, 95, 58));
	move_cycle.setFrameSpeed(1.f / 100.f);
}


player::~player()
{
}

void player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		velocity.x += -100 * dt;
	}
	else if (input->isKeyDown(sf::Keyboard::Right))
	{
		velocity.x += 100 * dt;
	}
	else if (input->isKeyDown(sf::Keyboard::Up))
	{
		velocity.y += -100 * dt;
	}
	else if (input->isKeyDown(sf::Keyboard::Down))
	{
		velocity.y += 100 * dt;
	}
	else
	{
		velocity.x = 0;
		velocity.y = 0;
	}

}

void player::update(float dt)
{
	move(velocity*dt);
	setTextureRect(move_cycle.getCurrentFrame());
	
	if (velocity.x > 0.0)
	{
		move_cycle.setFlipped(false);
		move_cycle.animate(dt);
		setTextureRect(move_cycle.getCurrentFrame());
	}
	else if (velocity.x < 0.0)
	{
		move_cycle.setFlipped(true);
		move_cycle.animate(dt);
		setTextureRect(move_cycle.getCurrentFrame());
	}
	else
	{
		move_cycle.reset();
		setTextureRect(move_cycle.getCurrentFrame());
	}
	if (velocity.x > 500.0f)
	{
		velocity.x = 500.0f;
	}


}

void player::collisionResponse(GameObject * collider)
{
	velocity.y = 0;
	setPosition(getPosition().x, collider->getPosition().y - getSize().y);
}
