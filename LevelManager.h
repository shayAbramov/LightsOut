#pragma once
#include <SFML/Graphics.hpp>

#define VERTICES_IN_TILE	6
#define TILE_SIZE			16

using namespace sf;
using namespace std;

class LevelManager
{
private:
	int m_levelWidth;
	int m_levelHeight;
	Vector2f m_playerSpawnPosition;

public:
	int** loadLevel(VertexArray& vertecis);
	int getLevelWidth();
	int getLevelHeight();
	Vector2f getPlayerSpawnPoint();
};