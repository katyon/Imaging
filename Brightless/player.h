#pragma once

// �C���N���[�h ---------------------------------------------
#include "common.h"

// �萔 ----------------------------------------------------
#define PLAYER_SPEED	(10)

// �N���X�錾 ----------------------------------------------
class Player : public Sprite
{
public:
	void	init();
	void	update();
	void	draw();
	void	setSpeed(float speedX);
	void	setSpeed(float speedX, float speedY);
private:
	float	speedX, speedY;
	bool	flip;
	bool	onground;
	bool	isjump;

};

// �v���g�^�C�v�錾 -----------------------------------------