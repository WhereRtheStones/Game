#include "Menu.h"



Menu::Menu(sf::RenderWindow* hwnd, Input* in, GameState *state)
{
	window = hwnd;
	input = in;
	gameState = state;

	// render text
	if (!font.loadFromFile("font/zrnic rg.ttf"))
	{
		std::cout << "Error loading font/n";
	}

	text.setFont(font);
	text.setString("Nacht Der Untoten");
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::Red);
	text.setPosition(400, 0);
}

Menu::~Menu()
{
}

void Menu::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		gameState->setCurrentState(State::LEVEL);
	}
}

void Menu::update(float dt)
{

}

void Menu::render()
{
	beginDraw();
	window->draw(text);
	endDraw();
}

void Menu::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

void Menu::endDraw()
{
	window->display();
}
