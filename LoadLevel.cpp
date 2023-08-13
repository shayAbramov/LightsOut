#include "Engine.h"

void Engine::loadLevel()
{
	for (int i = 0; i < m_levelManager.getLevelWidth(); i++)
	{
		delete[] m_ArrayLevel[i];
	}
	
	delete[] m_ArrayLevel;

	m_ArrayLevel = m_levelManager.loadLevel(m_VertexArrayLevel);

	// spawn here player
	m_player.spawn(m_levelManager.getPlayerSpawnPoint());

	// spawn here enemies

	// spawn here obstecles

	m_levelIsLoaded = true;
}