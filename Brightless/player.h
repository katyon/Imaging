#pragma once

// �C���N���[�h ---------------------------------------------
#include "common.h"

// �萔 ----------------------------------------------------

// �N���X�錾 ----------------------------------------------
class Player : public Sprite
{
public:
	void init();
	void update();
	void draw();
private:
	float	speedX, speedY;
	bool	flip;
	bool	onground;
	bool	isjump;
};

// �v���g�^�C�v�錾 -----------------------------------------