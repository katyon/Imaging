#pragma once
// インクルード ---------------------------------------------
#include "light.h"
#include "player.h"
#include "scene_game.h"

// 定数 ----------------------------------------------------
#define		MAPCHIP_H_MAX		(60)
#define		MAPCHIP_V_MAX		(34)
#define		SCREEN_CHIP_H_MAX	(30)
#define		SCREEN_CHIP_V_MAX	(17)
#define		MAPCHIP_SIZE		(64)
#define		ELEVATOR_WIDTH		(64*3)
#define		ELEVATOR_HEIGHT		(64*4)

// クラス宣言 ----------------------------------------------
enum CHIP_DATA { Void, Floor, CatWalk, HandRail, HandRail_R, HandRail_L, Floor_Coner, CatWalk_Corner, PlayerSpawner, GoalSpawner };
class MapData : public Sprite
{
public:
	void	init(Player* player);
	void	draw(Game_Flag* game_flag);
	void	update(Player* obj,Game_Flag* game_flag);

	float	calRelative();
	void	collMapChipWithPlayer(Player* obj,Game_Flag* game_flag);
    void    collMapChipWithLight(Light* light);
	void	drawMapChip();
	void	drawElevator();
	void	drawElevatorFrame(Game_Flag* game_flag);
	void	drawElevatorDoor(Game_Flag* game_flag);

	void	judgeGoal();

	int		get_GoalHandle() { return goal_handle; }
	void	set_GoalHandle(int g) { goal_handle = g; }

private:
	int		goal_handle;
	int		goal_frame_handle;
	int		goal_door_handle;
};

// プロトタイプ宣言 -----------------------------------------