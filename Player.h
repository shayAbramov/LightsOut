#pragma once
#include <SFML/Graphics.hpp>

#define PLAYER_SPEED	50

using namespace sf;

class Player
{
private:
	Sprite m_sprite;

	Vector2f m_position;
	Vector2f m_destination;

	float m_speed = PLAYER_SPEED;

	bool m_movingUp;
	bool m_movingRight;
	bool m_movingDown;
	bool m_movingLeft;

public:
	Player();

	FloatRect getCollisionBox();

	void spawn(Vector2f position);

	void handleInput();

	void update(float dtAsSeconds);

	void stopUp(float position);
	void stopRight(float position);
	void stopDown(float position);
	void stopLeft(float position);

	bool isMovingUp();
	bool isMovingRight();
	bool isMovingDown();
	bool isMovingLeft();

	Sprite getSprite();
};