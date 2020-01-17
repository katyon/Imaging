#include "DxLib.h"
#include "player.h"
#include "input.h"

void Player::init()
{
	posX = posY = rel_posX = rel_posY = 0;
	flip = 0;
	onground = 1;
	isjump = 0;
	state = None;
	handle = LoadGraph("Data\\Images\\Player\\pl_material.png");
}

void Player::update()
{
	Player::inputMovement();
	Player::affectGravity();

	Player::movePlayer();
}

void Player::draw()
{
	DrawGraphF(rel_posX, rel_posY, handle, TRUE);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Player::inputMovement()
{
	speedX = 0;

	//コントローラー入力
	{
		//左右移動
		if (Input::GetInstance()->GetLeftThumb(PL_1, Roughly_Right))
		{
			speedX = PLAYER_SPEED;
			state = Walk;
			flip = false;
		}
		if (Input::GetInstance()->GetLeftThumb(PL_1, Roughly_Left))
		{
			speedX = -PLAYER_SPEED;
			state = Walk;
			flip = true;
		}

		//ジャンプ
	}

	//キーボード入力
	{
		//左右移動
		if (Input::GetInstance()->GetKey(KEY_INPUT_RIGHT))
		{
			speedX = PLAYER_SPEED;
			state = Walk;
			flip = false;
		}

		if (Input::GetInstance()->GetKey(KEY_INPUT_LEFT))
		{
			speedX = -PLAYER_SPEED;
			state = Walk;
			flip = true;
		}


		//ジャンプ
		if (Input::GetInstance()->GetKeyDown(KEY_INPUT_SPACE))
		{
			if (onground && !isjump)
			{
				speedY = JUMP_POW;
				isjump = true;
				onground = false;
			}
		}
	}
}

void Player::movePlayer()
{
	posX += speedX;
	posY += speedY;

	// プレイヤーキャラクターの向き反転処理
	//if (speedX > 0) { flip = false; }
	//else { flip = true; }

	// ジャンプから降下への切替
	if (speedY > 0) { isjump = false; }

}

void Player::affectGravity()
{
	if (onground == false)
	{
		speedY += GRAVITY;
	}

	if (speedY > PLAYER_SPEED_MAX)
	{
		speedY = PLAYER_SPEED_MAX;
	}

	if (onground == true)
	{
		speedY = 0;
	}
}

float Player::getPosX()
{
	return posX;
}

float Player::getPosY()
{
	return posY;
}

void Player::setPosX(float x)
{
	posX = x;
}

void Player::setPosY(float y)
{
	posY = y;
}

float Player::getSpeedX()
{
	return speedX;
}

float Player::getSpeedY()
{
	return speedY;
}

void Player::setSpeedX(float x)
{
	speedX = x;
}

void Player::setSpeedY(float y)
{
	speedY = y;
}

void Player::setOnGround(bool g)
{
	onground = g;
}
