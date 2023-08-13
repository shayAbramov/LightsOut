#include "Engine.h"

void Engine::input()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		m_window.close();
	}

	if (m_gameState == state::START)
	{
		Event event;

		while (m_window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
			{
				m_gameState = state::PLAYING;
			}
		}
	}

	if (m_gameState == state::PLAYING)
	{
		m_player.handleInput();
	}
}