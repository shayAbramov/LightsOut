#include "LevelManager.h"
#include <fstream>

int** LevelManager::loadLevel(VertexArray& rVaLevel)
{
	string levelFileName = "levels/level1.txt";

	ifstream inputFile(levelFileName);
	string str;

	while (getline(inputFile, str))
	{
		m_levelHeight++;
	}

	m_levelWidth = str.length();

	inputFile.clear();
	inputFile.seekg(0, ios::beg);

	int** arrayLevel = new int* [m_levelHeight];
	for (int i = 0; i < m_levelHeight; i++)
	{
		arrayLevel[i] = new int[m_levelWidth];
	}

	for (int y = 0; inputFile >> str; y++)
	{
		for (int x = 0; x < m_levelWidth; x++)
		{
			const char value = str[x];
			arrayLevel[y][x] = atoi(&value);
		}
	}

	inputFile.close();

	rVaLevel.setPrimitiveType(Triangles);
	rVaLevel.resize(m_levelWidth * m_levelHeight * VERTICES_IN_TILE);

	int current_vertex = 0;
	for (int x = 0; x < m_levelWidth; x++)
	{
		for (int y = 0; y < m_levelHeight; y++)
		{
			int leftX = x * TILE_SIZE;
			int topY = y * TILE_SIZE;

			rVaLevel[current_vertex + 0].position = Vector2f(leftX				, topY);
			rVaLevel[current_vertex + 1].position = Vector2f(leftX + TILE_SIZE	, topY);
			rVaLevel[current_vertex + 2].position = Vector2f(leftX				, topY + TILE_SIZE);
			rVaLevel[current_vertex + 3].position = Vector2f(leftX				, topY + TILE_SIZE);
			rVaLevel[current_vertex + 4].position = Vector2f(leftX + TILE_SIZE	, topY);
			rVaLevel[current_vertex + 5].position = Vector2f(leftX + TILE_SIZE	, topY + TILE_SIZE);

			if (arrayLevel[y][x] == 1)
			{
				rVaLevel[current_vertex + 0].color = Color::Black;
				rVaLevel[current_vertex + 1].color = Color::Black;
				rVaLevel[current_vertex + 2].color = Color::Black;
				rVaLevel[current_vertex + 3].color = Color::Black;
				rVaLevel[current_vertex + 4].color = Color::Black;
				rVaLevel[current_vertex + 5].color = Color::Black;
			}
			else
			{
				if (arrayLevel[y][x] == 2)
				{
					m_playerSpawnPosition = Vector2f(leftX + 8, topY + 15); // why? think about it. what are these magic numbers?
				}

				rVaLevel[current_vertex + 0].color = Color::White;
				rVaLevel[current_vertex + 1].color = Color::White;
				rVaLevel[current_vertex + 2].color = Color::White;
				rVaLevel[current_vertex + 3].color = Color::White;
				rVaLevel[current_vertex + 4].color = Color::White;
				rVaLevel[current_vertex + 5].color = Color::White;
			}

			current_vertex = current_vertex + VERTICES_IN_TILE;
		}
	}

	return arrayLevel;
}

int LevelManager::getLevelWidth()
{
	return m_levelWidth;
}

int LevelManager::getLevelHeight()
{
	return m_levelHeight;
}

Vector2f LevelManager::getPlayerSpawnPoint()
{
	return m_playerSpawnPosition;
}