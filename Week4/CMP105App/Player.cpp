#include "Player.h"


void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		move(sf::Vector2f(velocity.x, 0) * dt);
	}

	if (input->isKeyDown(sf::Keyboard::Left))
	{
		move(sf::Vector2f(-velocity.x, 0) * dt);
	}

	if (input->isKeyDown(sf::Keyboard::Up))
	{
		move(sf::Vector2f( 0, -velocity.y) * dt);
	}

	if (input->isKeyDown(sf::Keyboard::Down))
	{
		move(sf::Vector2f( 0, velocity.y) * dt);
	}
};

//Player::Player()
//{
//
//}
//
//Player::~Player()
//{
//
//}