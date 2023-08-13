#include "Engine.h"

Engine::Engine()
{
	m_window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Lights Out", Style::None);
	m_mainView.setSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	if (sf::Shader::isAvailable())
	{
 		m_lightShader.loadFromFile("shaders/vertex_shader.vert", "shaders/fragment_shader.frag");
	}
	else
	{
		m_window.close();
	}
}

void Engine::run()
{
	Clock clock;

	while (m_window.isOpen())
	{
		float dtAsSeconds = clock.restart().asSeconds();

		input();
		update(dtAsSeconds);
		draw();
	}
}