#include "Engine.h"

void Engine::update(float dtAsSeconds)
{
	if (m_gameState == state::PLAYING)
	{
		if (!m_levelIsLoaded)
		{
			loadLevel();
		}

		m_player.update(dtAsSeconds);

		m_mainView.setCenter(m_player.getSprite().getPosition());

		detectCollisions();
	}
}