#pragma once

#include "VisibleGameObject.h"

class PlayerPaddle : public VisibleGameObject
{
public:
	PlayerPaddle();
	~PlayerPaddle();

	void Update(sf::Time elapsedTime);
	void Draw(sf::RenderWindow& window);

	float GetVelocity() const;

private:
	float _velocity;
	float _maxVelocity;
};