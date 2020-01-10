#pragma once

// インクルード ---------------------------------------------
#include "common.h"

// 定数 ----------------------------------------------------
#define PLAYER_SPEED	(10)

// クラス宣言 ----------------------------------------------
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

// プロトタイプ宣言 -----------------------------------------