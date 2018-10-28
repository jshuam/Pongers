#include "Game.h"

void Game::Start(void)
{
	if (_gameState != Game::Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Pongers");

	PlayerPaddle* player1 = new PlayerPaddle();
	player1->Load("assets/Paddle.png");
	player1->SetPosition((1024/2)-60,700);

	_gameObjectManager.Add("Paddle1", player1);
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

void Game::GameLoop()
{
	sf::Event event;
	_mainWindow.pollEvent(event);

	switch (_gameState)
	{
		case Game::Uninitialized:
			break;
		case Game::ShowingSplash:
		{
			ShowSplashScreen();
			break;
		}
		case Game::Paused:
			break;
		case Game::ShowingMenu:
		{
			ShowMenu();
			break;
		}
		case Game::Playing:
		{
			_mainWindow.clear(sf::Color(0, 0, 0));
			_gameObjectManager.DrawAll(_mainWindow);
			_mainWindow.display();

			if (event.type == sf::Event::Closed) _gameState = Game::Exiting;

			if (event.type == sf::Event::EventType::KeyPressed && event.key.code == sf::Keyboard::Escape) ShowMenu();

			break;
		}
		case Game::Exiting:
			break;
		default:
			break;
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
		case MainMenu::Nothing:
			break;
		case MainMenu::Exit:
			_gameState = Game::Exiting;
			break;
		case MainMenu::Play:
			_gameState = Game::Playing;
			break;
		default:
			break;
	}
}

Game::GameState Game::_gameState = GameState::Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;
