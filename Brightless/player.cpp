#include "DxLib.h"
#include "player.h"
#include "input.h"

void Player::init()
{
	posX = posY = 0;
	flip = 0;
	onground = 1;
	isjump = 0;
}

void Player::update()
{
	
}

void Player::draw()
{

}

void Player::setSpeed(float speedX)
{
	this->speedX = speedX;
}

void Player::setSpeed(float speedX, float speedY)
{
	this->speedX = speedX;
	this->speedY = speedY;
}

void movePlayer(Player* obj)
{
	switch (Input::GetInstance()->GetLeftThumb(PL_1, XINPUT_BUTTON_LEFT_THUMB))
	{
	case Before_Upper_Right:
	case Upper_Right:
	case After_Upper_Right:
	case Right:
	case Before_Lower_Right:
	case Lower_Right:
	case After_Lower_Right:
		obj->setSpeed(PLAYER_SPEED);
	case Down:
	case Before_Lower_Left:
	case Lower_Left:
	case After_Lower_Left:
	case Left:
	case Before_Upper_Left:
	case Upper_Left:
	case After_Upper_Left:
		obj->setSpeed(-PLAYER_SPEED);
	default:
		obj->setSpeed(0);
	}
}