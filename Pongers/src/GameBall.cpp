#include <cassert>

#include "GameBall.h"

GameBall::GameBall()
{
	Load("assets/Ball.png");
	assert(IsLoaded());

	GetSprite().setOrigin(15, 15);
}

GameBall::~GameBall()
{
}
