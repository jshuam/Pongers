#include "SplashScreen.h"
#include <chrono>
#include <thread>

void SplashScreen::Show(sf::RenderWindow& window)
{
	sf::Texture texture;
	if (texture.loadFromFile("assets/SplashScreen.png") != true)
		return;

	sf::Sprite sprite(texture);

	window.draw(sprite);
	window.display();

	/*sf::Event event;
	while (true)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed)
				return;
		}
	}*/
	std::this_thread::sleep_for(std::chrono::milliseconds(1250));
}
