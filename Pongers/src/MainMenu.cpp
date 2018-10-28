#include "MainMenu.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{
	sf::Texture texture;
	texture.loadFromFile("assets/MainMenu.png");
	sf::Sprite sprite(texture);

	MenuItem playButton;
	playButton.rect = sf::Rect<int>(0, 145, 1023, 235);
	playButton.action = MenuResult::Play;

	MenuItem exitButton;
	exitButton.rect = sf::Rect<int>(0, 383, 1023, 177);
	exitButton.action = MenuResult::Exit;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);

	window.draw(sprite);
	window.display();

	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	for (auto& menuItem : _menuItems)
	{
		if (menuItem.rect.contains(x, y))
		{
			return menuItem.action;
		}
	}

	return MenuResult::Nothing;
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event event;

	while (true)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
				return HandleClick(event.mouseButton.x, event.mouseButton.y);
			if (event.type == sf::Event::Closed)
				return MenuResult::Exit;
		}
	}
}
