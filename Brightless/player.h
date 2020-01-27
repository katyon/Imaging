#pragma once

// インクルード ---------------------------------------------
#include "common.h"
#include "scene_game.h"

// 定数 ----------------------------------------------------
#define PLAYER_WIDTH		(100.0f)
#define PLAYER_HEIGHT		(200.0f)

#define PLAYER_SPEED		(10.0f)
#define PLAYER_SPEED_MAX	(20.0f)
#define JUMP_POW			(-20.0f)
#define GRAVITY				(0.7f)

// クラス宣言 ----------------------------------------------

enum PlayerState { None, Walk };

class Player : public Sprite
{
private:
	float		speedX, speedY;
	bool		flip;
	bool		onground;
	bool		isjump;
	PlayerState state;
	int			anime_timer;

	float		correctX, correctY;
	bool		movement_pass;
	float		move_angle;

public:
	void		init();
	void		update(Game_Flag* game_flag);
	void		draw();

	void		inputMovement(Game_Flag* game_flag);
	void		movePlayer();
	void		affectGravity();

	float		getPosX() { return posX; }
	float		getPosY() { return posY; }
	void		setPosX(float x) { posX = x; }
	void		setPosY(float y) { posY = y; }

	float		getSpeedX() { return speedX; }
	float		getSpeedY() { return speedY; }
	void		setSpeedX(float x) { speedX = x; }
	void		setSpeedY(float y) { speedY = y; }

	float		getCorrectX() { return correctX; }
	float		getCorrectY() { return correctY; }
	void		setCorrectX(float x) { correctX = x; }
	void		setCorrectY(float y) { correctY = y; }

	bool		getMovementPass() { return movement_pass; }
	void		setMovementPass(bool m) { movement_pass = m; }

	float		getMoveAngle() { return move_angle; }
	void		setMoveAngle(float a) { move_angle = a; }


	bool		getFlip() { return flip; }

	bool		getOnGround() { return onground; }
	void		setOnGround(bool g) { onground = g; };

};

// プロトタイプ宣言 -----------------------------------------