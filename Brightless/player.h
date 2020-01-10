#pragma once

// インクルード ---------------------------------------------
#include "common.h"

// 定数 ----------------------------------------------------

// クラス宣言 ----------------------------------------------
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

// プロトタイプ宣言 -----------------------------------------