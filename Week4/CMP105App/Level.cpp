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
	speedx = 500.f;
	speedy = 500.f;

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
	goomba.move(speedx * dt, speedy * dt);
	sf::Vector2u winPos = window->getSize(); //Vector2u creating variable with two values (unsigned variable)
	sf::Vector2f objPos = goomba.getPosition();//Vector2f creating variable with two values (float variable)
	if (objPos.x + 100 > winPos.x)
	{
		speedx = speedx * -1;
	}

	if (objPos.y + 100 > winPos.y)
	{
		speedy = speedy * -1;
	}

	if (objPos.x < 0)
	{
		speedx = speedx * -1;
	}

	if (objPos.y < 0)
	{
		speedy = speedy * -1;
	}
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