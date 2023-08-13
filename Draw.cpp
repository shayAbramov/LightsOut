#include "Engine.h"

void Engine::draw()
{
	m_window.clear(Color::Black);

	m_lightShader.setUniform("lightPos", Vector2f(320, 240));

	if (m_levelIsLoaded)
	{
		m_window.setView(m_mainView);

		m_window.draw(m_VertexArrayLevel, &m_lightShader);

		m_window.draw(m_player.getSprite());

		VertexArray tmpVA;
		tmpVA.setPrimitiveType(LineStrip);
		tmpVA.resize(5);
		tmpVA[0].position = Vector2f(m_player.getCollisionBox().left, m_player.getCollisionBox().top);
		tmpVA[1].position = Vector2f(m_player.getCollisionBox().left + m_player.getCollisionBox().width, m_player.getCollisionBox().top);
		tmpVA[2].position = Vector2f(m_player.getCollisionBox().left + m_player.getCollisionBox().width, m_player.getCollisionBox().top + m_player.getCollisionBox().height);
		tmpVA[3].position = Vector2f(m_player.getCollisionBox().left, m_player.getCollisionBox().top + m_player.getCollisionBox().height);
		tmpVA[4].position = Vector2f(m_player.getCollisionBox().left, m_player.getCollisionBox().top);


		tmpVA[0].color = Color::Green;
		tmpVA[1].color = Color::Green;
		tmpVA[2].color = Color::Green;
		tmpVA[3].color = Color::Green;
		tmpVA[4].color = Color::Green;

		m_window.draw(tmpVA, &m_lightShader);
	}

	m_window.display();
}