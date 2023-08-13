#include "Player.h"
#include "TextureLoader.h"

Player::Player()
{
	m_sprite = Sprite(TextureLoader::getTexture("graphics/sprite_sheet.png"), IntRect(0, 0, 16, 16));
	m_sprite.setOrigin(8, 15); // expiriment
}

FloatRect Player::getCollisionBox()
{
	return FloatRect(m_position.x - 8, m_position.y - 15, 16, 16); // Why? what are these magic numbers?
}

void Player::spawn(Vector2f position)
{
	m_position = position;

	m_sprite.setPosition(m_position);
}

void Player::handleInput()
{
	if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
	{
		m_movingUp = false;
		m_movingRight = false;
		m_movingDown = false;
		m_movingLeft = false;

		m_movingUp = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
	{
		m_movingUp = false;
		m_movingRight = false;
		m_movingDown = false;
		m_movingLeft = false;

		m_movingRight = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
	{
		m_movingUp = false;
		m_movingRight = false;
		m_movingDown = false;
		m_movingLeft = false;

		m_movingDown = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
	{
		m_movingUp = false;
		m_movingRight = false;
		m_movingDown = false;
		m_movingLeft = false;

		m_movingLeft = true;
	}
}

void Player::update(float dtAsSeconds)
{
	if (m_movingUp)
	{
		m_position.y -= m_speed * dtAsSeconds;
		m_sprite.setPosition(m_position);
	}
	else if (m_movingRight) {
		m_position.x += m_speed * dtAsSeconds;
		m_sprite.setPosition(m_position);
	}
	else if (m_movingDown) {
		m_position.y += m_speed * dtAsSeconds;
		m_sprite.setPosition(m_position);
	}
	else if (m_movingLeft) {
		m_position.x -= m_speed * dtAsSeconds;
		m_sprite.setPosition(m_position);
	}
}


void Player::stopUp(float position)
{
	m_position.y += position;
	m_sprite.setPosition(m_position);
	m_movingUp = false;
}


void Player::stopRight(float position)
{
	m_position.x -= position;
	m_sprite.setPosition(m_position);
	m_movingRight = false;
}

void Player::stopDown(float position)
{
	m_position.y -= position;
	m_sprite.setPosition(m_position);
	m_movingDown = false;
}

void Player::stopLeft(float position)
{
	m_position.x += position;
	m_sprite.setPosition(m_position);
	m_movingLeft = false;
}

bool Player::isMovingUp()
{
	return m_movingUp;
}

bool Player::isMovingDown()
{
	return m_movingDown;
}

bool Player::isMovingRight()
{
	return m_movingRight;
}

bool Player::isMovingLeft()
{
	return m_movingLeft;
}

Sprite Player::getSprite()
{
	return m_sprite;
}