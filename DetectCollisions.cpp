#include "Engine.h"

void Engine::detectCollisions()
{
	int startX	= (int)(m_player.getCollisionBox().left / TILE_SIZE) - 1;
	int startY	= (int)(m_player.getCollisionBox().top / TILE_SIZE) - 1;
	int endX	= (int)(m_player.getCollisionBox().left / TILE_SIZE) + 2;
	int endY	= (int)(m_player.getCollisionBox().top / TILE_SIZE) + 2;

	if (startX < 0)
	{
		startX = 0;
	}
	
	if (startY < 0)
	{
		startY = 0;
	}

	if (endX > m_levelManager.getLevelWidth())
	{
		endX = m_levelManager.getLevelWidth();
	}

	if (endY > m_levelManager.getLevelHeight())
	{
		endY = m_levelManager.getLevelHeight();
	}

	FloatRect block;
	block.width = TILE_SIZE;
	block.height = TILE_SIZE;
	for (int x = startX; x < endX; x++)
	{
		for (int y = startY; y < endY; y++)
		{
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;

			if (m_ArrayLevel[y][x] == 1)
			{
				if (m_player.getCollisionBox().intersects(block))
				{
					if (m_player.isMovingUp() && m_player.getCollisionBox().top < block.top + block.height)
					{
						m_player.stopUp(block.top + block.height - m_player.getCollisionBox().top);
					}

					if (m_player.isMovingRight() && m_player.getCollisionBox().left + m_player.getCollisionBox().width > block.left)
					{
						m_player.stopRight(m_player.getCollisionBox().left + m_player.getCollisionBox().width - block.left);
					}

					if (m_player.isMovingDown() && m_player.getCollisionBox().top < block.top && m_player.getCollisionBox().top + m_player.getCollisionBox().height > block.top)
					{
						m_player.stopDown(m_player.getCollisionBox().top + m_player.getCollisionBox().height - block.top);
					}

					if (m_player.isMovingLeft() && m_player.getCollisionBox().left < block.left + block.width)
					{
						m_player.stopLeft(block.left + block.width - m_player.getCollisionBox().left);
					}
				}
			}
		}
	}
}