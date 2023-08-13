#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Collidable
{
public:
	FloatRect virtual getCollisionBox() = 0;
};