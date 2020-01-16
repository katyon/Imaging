#pragma once

// �C���N���[�h ---------------------------------------------
#include "common.h"

// �萔 ----------------------------------------------------
#define PLAYER_WIDTH		(100)
#define PLAYER_HEIGHT		(200)

#define PLAYER_SPEED		(10)
#define PLAYER_SPEED_MAX	(20)
#define JUMP_POW			(-20)
#define GRAVITY				(0.7)

// �N���X�錾 ----------------------------------------------

enum PlayerState { None, Walk };

class Player : public Sprite
{
public:
	void		init();
	void		update();
	void		draw();

	void		inputMovement();
	void		movePlayer();
	void		affectGravity();

	float		getPosX();
	float		getPosY();
	void		setPosX(float x);
	void		setPosY(float y);

	float		getSpeedX();
	float		getSpeedY();
	void		setSpeedX(float x);
	void		setSpeedY(float y);

	void		setOnGround(bool g);

private:
	float		speedX, speedY;
	bool		flip;
	bool		onground;
	bool		isjump;
	PlayerState state;
};

// �v���g�^�C�v�錾 -----------------------------------------