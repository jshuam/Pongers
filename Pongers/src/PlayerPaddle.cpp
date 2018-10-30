#include <cassert>

#include "PlayerPaddle.h"
#include "Game.h"

PlayerPaddle::PlayerPaddle() : _velocity(0), _maxVelocity(600.0f)
{
	Load("assets/Paddle.png");
	assert(IsLoaded());

	GetSprite().setOrigin(GetSprite().getGlobalBounds().width / 2, GetSprite().getGlobalBounds().height / 2);
}

PlayerPaddle::~PlayerPaddle()
{}

void PlayerPaddle::Draw(sf::RenderWindow& window)
{
	VisibleGameObject::Draw(window);
}

float PlayerPaddle::GetVelocity() const
{
	return _velocity;
}

void PlayerPaddle::Update(sf::Time elapsedTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		_velocity -= 3.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		_velocity += 3.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		_velocity = 3.0f;
	}
	if (_velocity > _maxVelocity)
		_velocity = _maxVelocity;
	if (_velocity < -_maxVelocity)
		_velocity = -_maxVelocity;

	sf::Vector2f pos = this->GetPosition();

	if (pos.x < GetSprite().getGlobalBounds().width / 2 || pos.x > Game::SCREEN_WIDTH - GetSprite().getGlobalBounds().width / 2)
	{
		_velocity = -_velocity;
	}
	
	GetSprite().move(_velocity * (elapsedTime.asSeconds()), 0);
}
