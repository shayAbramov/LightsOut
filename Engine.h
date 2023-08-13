#pragma once
#include <SFML/Graphics.hpp>
#include "TextureLoader.h"
#include "LevelManager.h"
#include "Player.h"

using namespace sf;

#define SCREEN_WIDTH	640
#define SCREEN_HEIGHT	480

class Engine
{
	enum state { START, PLAYING, GAME_OVER };

private:
	RenderWindow m_window;

	TextureLoader m_textureLoader;

	LevelManager m_levelManager;

	Shader m_lightShader;

	Player m_player;

	View m_mainView;

	state m_gameState;
	bool m_levelIsLoaded;
	int** m_ArrayLevel = NULL;
	VertexArray m_VertexArrayLevel;

	void input();
	void update(float dtAsSeconds);
	void draw();

	void detectCollisions();

public:
	Engine();
	void loadLevel();
	void run();
};