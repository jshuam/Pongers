#include "Game.h"

void Game::Start(void)
{
	if (_gameState != Game::Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Pongers");

	//_mainWindow.SetFramerateLimit(60);

	PlayerPaddle* player1 = new PlayerPaddle();
	player1->SetPosition((SCREEN_WIDTH/2),700);

	GameBall* ball = new GameBall();
	ball->SetPosition((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2) - 15);

	_gameObjectManager.Add("Paddle1", player1);
	_gameObjectManager.Add("Ball", ball);

	_gameState = Game::ShowingSplash;

	while (!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.close();
}

bool Game::IsExiting()
{
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

sf::Clock& Game::GetClock()
{
	return _clock;
}

void Game::GameLoop()
{
	sf::Event event;
	_mainWindow.pollEvent(event);

	switch (_gameState)
	{
		case Game::ShowingMenu:
		{
			ShowMenu();
			break;
		}
		case Game::ShowingSplash:
		{
			ShowSplashScreen();
			break;
		}
		case Game::Playing:
		{
			_mainWindow.clear(sf::Color(0, 0, 0));

			_gameObjectManager.UpdateAll();
			_gameObjectManager.DrawAll(_mainWindow);

			_mainWindow.display();

			if (event.type == sf::Event::Closed) _gameState = Game::Exiting;

			if (event.type == sf::Event::EventType::KeyPressed && event.key.code == sf::Keyboard::Escape) ShowMenu();

			break;
		}
	}
}

void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch (result)
	{
		case MainMenu::Exit:
			_gameState = Game::Exiting;
			break;
		case MainMenu::Play:
			_gameState = Game::Playing;
			break;
	}
}

Game::GameState Game::_gameState = GameState::Uninitialized;
sf::RenderWindow Game::_mainWindow;
sf::Clock Game::_clock;
GameObjectManager Game::_gameObjectManager;

