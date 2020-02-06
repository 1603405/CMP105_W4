#include "Level.h"


Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	texturgoomba.loadFromFile("gfx/Goomba.png");
	texturemushroom.loadFromFile("gfx/Mushroom.png");

	goomba.setTexture(&texturgoomba);
	goomba.setSize(sf::Vector2f(100, 100));
	goomba.setPosition(500, 500);
	goomba.setVelocity(500.0, 500.0);

	mushroom.setTexture(&texturemushroom);
	mushroom.setSize(sf::Vector2f(100, 100));
	mushroom.setPosition(100, 100);
	mushroom.setVelocity(500.0, 500.0);
	mushroom.setInput(input);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	mushroom.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(goomba);
	window->draw(mushroom);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}