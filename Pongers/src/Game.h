#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "SplashScreen.h"
#include "MainMenu.h"
#include "PlayerPaddle.h"
#include "GameObjectManager.h"
#include "GameBall.h"

class Game
{
public:
	static void Start();
	static sf::Clock& GetClock();
	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;

private:
	static bool IsExiting();
	static void GameLoop();

	static void ShowSplashScreen();
	static void ShowMenu();

	enum GameState
	{
		Uninitialized,
		ShowingSplash,
		Paused,
		ShowingMenu,
		Playing,
		Exiting
	};

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
	static sf::Clock _clock;
	static GameObjectManager _gameObjectManager;
};
