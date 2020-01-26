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
	handle = LoadGraph("Data\\Images\\Player\\pl_material.png");
	movement_pass = true;
	move_angle = 0;
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

	//�R���g���[���[����
	{
		//���E�ړ�
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

		//�W�����v
	}

	//�L�[�{�[�h����
	{
		//���E�ړ�
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


		//�W�����v
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

	////�v���C���[�L�����N�^�[�̌������]����
	//if (speedX > 0) { flip = false; }
	//else { flip = true; }

	// �W�����v����~���ւ̐ؑ�
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
