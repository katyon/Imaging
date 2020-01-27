#include "DxLib.h"
#include "player.h"
#include "input.h"
#include "system.h"
#include <math.h>

void Player::init()
{
	posX = posY = rel_posX = rel_posY = correctX = correctY = 0;
	flip = 0;
	onground = 1;
	isjump = 0;
	state = PlayerState::None;
	handle = LoadGraph("Data\\Images\\Player\\Player.png");
	movement_pass = true;
	move_angle = 0;
	anime_timer = 0;
}

void Player::update(Game_Flag* game_flag)
{
	Player::inputMovement(game_flag);
	Player::affectGravity();

	Player::movePlayer();
	anime_timer++;
}

void Player::draw()
{
	if (speedX != 0 && onground == true)
	{
		if (flip == false) { DrawRectGraphF(rel_posX, rel_posY, PLAYER_WIDTH * ((anime_timer % 30) / 10), PLAYER_HEIGHT * 1, PLAYER_WIDTH, PLAYER_HEIGHT, handle, TRUE, FALSE); }
		if (flip == true) { DrawRectGraphF(rel_posX, rel_posY, PLAYER_WIDTH * ((anime_timer % 30) / 10), PLAYER_HEIGHT * 1, PLAYER_WIDTH, PLAYER_HEIGHT, handle, TRUE, TRUE); }
	}
	if (speedY < 0 && onground == false)
	{
		if (flip == false) { DrawRectGraphF(rel_posX, rel_posY, PLAYER_WIDTH*0, PLAYER_HEIGHT * 2, PLAYER_WIDTH, PLAYER_HEIGHT, handle, TRUE, FALSE); }
		if (flip == true) { DrawRectGraphF(rel_posX, rel_posY, PLAYER_WIDTH*0, PLAYER_HEIGHT * 2, PLAYER_WIDTH, PLAYER_HEIGHT, handle, TRUE, TRUE); }
	}
	if (speedY >= 0 && onground == false)
	{
		if (flip == false) { DrawRectGraphF(rel_posX, rel_posY, PLAYER_WIDTH, PLAYER_HEIGHT * 2, PLAYER_WIDTH, PLAYER_HEIGHT, handle, TRUE, FALSE); }
		if (flip == true) { DrawRectGraphF(rel_posX, rel_posY, PLAYER_WIDTH, PLAYER_HEIGHT * 2, PLAYER_WIDTH, PLAYER_HEIGHT, handle, TRUE, TRUE); }
	}
	if (speedX == 0 && speedY == 0 && (onground==true || movement_pass==false))
	{
		if (flip == false) { DrawRectGraphF(rel_posX, rel_posY, PLAYER_WIDTH * ((anime_timer % 30) / 10), PLAYER_HEIGHT * 0, PLAYER_WIDTH, PLAYER_HEIGHT, handle, TRUE, FALSE); }
		if (flip == true) { DrawRectGraphF(rel_posX, rel_posY, PLAYER_WIDTH * ((anime_timer % 30) / 10), PLAYER_HEIGHT * 0, PLAYER_WIDTH, PLAYER_HEIGHT, handle, TRUE, TRUE); }
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Player::inputMovement(Game_Flag* game_flag)
{
	speedX = 0;

	//コントローラー入力
	if (game_flag->getStartFlag() == true && game_flag->getEndFlag() == false)
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
		if (Input::GetInstance()->GetButton(PL_1, XINPUT_BUTTON_A))
		{
			if (onground && !isjump)
			{
				speedY = JUMP_POW;
				isjump = true;
				onground = false;
				movement_pass = true;
			}
		}
	}

	//キーボード入力
	if (game_flag->getStartFlag() == true && game_flag->getEndFlag() == false) {
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
				movement_pass = true;
			}
		}
	}
}

void Player::movePlayer()
{
	if (movement_pass)
	{
		posX += speedX;
		posY += speedY;
	}
	else if (speedX > 0)
	{
		posX += cos(move_angle) * (PLAYER_SPEED);
		posY += sin(move_angle) * (PLAYER_SPEED);
	}
	else if (speedX < 0)
	{
		posX -= cos(move_angle) * (PLAYER_SPEED);
		posY -= sin(move_angle) * (PLAYER_SPEED);
	}

	// ジャンプから降下への切替
	if (speedY >= 0) { isjump = false; }


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
