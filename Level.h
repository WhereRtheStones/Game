#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Framework/GameObject.h"
#include <string>
#include <iostream>
#include "player.h"
#include "Framework/TileMap.h"
#include "Framework/Collision.h"
#include "manageEnemies.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in, GameState *state);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;
	AudioManager audio;

	//Level objekts The k is for a e s t h e t i c purposes
	player Rover;
	sf::Texture roverTexture;
	TileMap tileMap;
	manageEnemies Enemies;
};