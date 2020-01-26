#include "DxLib.h"
#include "map.h"
#include "relative_position.h"


static int test_map[MAPCHIP_V_MAX][MAPCHIP_H_MAX]
{
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,3,3,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,2,2,2,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,3,3,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,2,2,2,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,1,1,1,1,1,10,1,1,1,1,6,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,1,1,1,1,1,1,1,1,6,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,1,1,1,1,1,1,6,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,0,0,0,0,0,0,0,6,1,1,1,1,6,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,6,1,1,6,0,0,0,0,0,0,0,6,1,1,6,0,0,0,0,0,0,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,6,1,1,1,1,6,0,0,0,0,0,0,0,6,6,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,6,1,1,1,1,1,1,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,6,1,1,1,1,1,1,1,1,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

void MapData::init(Player* player)
{
    posX = posY = rel_posX = rel_posY = 0;
    handle = LoadGraph("Data\\Images\\Map\\map_chip.png");
	goal_handle = LoadGraph("Data\\Images\\Map\\elevator.png");
	goal_frame_handle = LoadGraph("Data\\Images\\Map\\elevator_frame.png");
	goal_door_handle = LoadGraph("Data\\Images\\Map\\elevator_door.png");

	for (int Ver = 0; Ver < MAPCHIP_V_MAX; Ver++)
	{
		for (int Hor = 0; Hor < MAPCHIP_H_MAX; Hor++)
		{
			if (test_map[Ver][Hor] == PlayerSpawner)
			{
				player->setPosX((Hor * MAPCHIP_SIZE)- (PLAYER_WIDTH/2));
				player->setPosY((Ver * MAPCHIP_SIZE) - PLAYER_HEIGHT);
			}
		}
	}
}

void MapData::update(Player* obj)
{
    MapData::collMapChipWithPlayer(obj);
}

void MapData::draw()
{
    MapData::drawMapChip();
	MapData::drawElevatorFrame();
}



void MapData::collMapChipWithPlayer(Player* obj)
{
	if (obj->getMovementPass())
	{
		obj->setOnGround(false);
	}

	//チップ当たり判定処理
	for (int Ver = 0; Ver < MAPCHIP_V_MAX; Ver++)
	{
		for (int Hor = 0; Hor < MAPCHIP_H_MAX; Hor++)
		{
			int chip_left;
			int chip_right;
			int chip_top;
			int chip_bottom;
			int player_coll_left;
			int player_coll_right;
			int player_coll_top;
			int player_coll_bottom;

			if (test_map[Ver][Hor] > 0 && (test_map[Ver][Hor] != 3) && (test_map[Ver][Hor] != 4) && (test_map[Ver][Hor] != 5))
			{
				//マップチップ4点座標
				chip_left = Hor * MAPCHIP_SIZE;
				chip_right = (Hor + 1) * MAPCHIP_SIZE;
				chip_top = Ver * MAPCHIP_SIZE;
				chip_bottom = (Ver + 1) * MAPCHIP_SIZE;
				//プレイヤー当たり判定部4点座標
				player_coll_left = obj->getPosX();
				player_coll_right = obj->getPosX() + PLAYER_WIDTH;
				player_coll_top = obj->getPosY();
				player_coll_bottom = obj->getPosY() + PLAYER_HEIGHT;

				if (player_coll_left + 15 < chip_right && player_coll_right - 15 > chip_left&& player_coll_top < chip_bottom && player_coll_bottom > chip_top)
				{
					//縦方向の押し戻し
					if (obj->getSpeedY() != 0)
					{
						if (obj->getSpeedY() > 0)
						{
							if (player_coll_left + 15 < chip_right && player_coll_right - 15 > chip_left&& player_coll_top + 199 < chip_bottom && player_coll_bottom > chip_top)
							{
								//判定のあったチップの上方向にチップが存在しなければ処理を行う
								if ((test_map[Ver - 1][Hor] == 0 || test_map[Ver - 1][Hor] == 3 || test_map[Ver - 1][Hor] == 4 || test_map[Ver - 1][Hor] == 5) && Ver != 0)
								{
									obj->setPosY(chip_top - PLAYER_HEIGHT);
									obj->setSpeedY(0);
								}
							}
						}
						if (obj->getSpeedY() < 0)
						{
							if (player_coll_left + 15 < chip_right && player_coll_right - 15 > chip_left&& player_coll_top < chip_bottom && player_coll_bottom - 195 > chip_top)
							{
								//判定のあったチップの下方向にチップが存在しなければ処理を行う
								if ((test_map[Ver + 1][Hor] == 0 || test_map[Ver + 1][Hor] == 3 || test_map[Ver + 1][Hor] == 4 || test_map[Ver + 1][Hor] == 5) && Ver != (MAPCHIP_V_MAX-1))
								{
									obj->setPosY(chip_bottom);
									obj->setSpeedY(0);
									//Player->y = chip_bottom - PLAYER_COLL_TOP;
									//Player->speed_y = 0;
								}
							}
						}
					}
				}
				//押し戻し後のプレイヤー座標を再取得
				player_coll_left = obj->getPosX();
				player_coll_right = obj->getPosX() + PLAYER_WIDTH;
				player_coll_top = obj->getPosY();
				player_coll_bottom = obj->getPosY() + PLAYER_HEIGHT;

				if (player_coll_left < chip_right && player_coll_right > chip_left&& player_coll_top+15 < chip_bottom && player_coll_bottom-15 > chip_top)
				{
					//横方向の押し戻し処理
					if (obj->getSpeedX() != 0)
					{
						if (obj->getSpeedX() > 0)
						{
							//判定のあったチップの左方向にチップが存在しなければ処理を行う
							if ((test_map[Ver][Hor-1] == 0 || test_map[Ver][Hor - 1] == 3 || test_map[Ver][Hor - 1] == 4 || test_map[Ver][Hor - 1] == 5) && Hor != 0)
							{
								obj->setPosX(chip_left - PLAYER_WIDTH);
							}
						}
						if (obj->getSpeedX() < 0)
						{
							//判定のあったチップの右方向にチップが存在しなければ処理を行う
							if ((test_map[Ver][Hor + 1] == 0 || test_map[Ver][Hor + 1] == 3 || test_map[Ver][Hor + 1] == 4 || test_map[Ver][Hor + 1] == 5) && Hor != (MAPCHIP_H_MAX-1))
							{
								obj->setPosX(chip_right);
							}
						}
					}
				}
				//押し戻し後のプレイヤー座標を再取得
				player_coll_left = obj->getPosX();
				player_coll_right = obj->getPosX() + PLAYER_WIDTH;
				player_coll_top = obj->getPosY();
				player_coll_bottom = obj->getPosY() + PLAYER_HEIGHT;

				//接地判定
				if (player_coll_bottom == chip_top && player_coll_right > chip_left&& player_coll_left < chip_right)
				{
					obj->setOnGround(true);
				}
			}
		}
	}
}

void MapData::collMapChipWithLight(Light* light)
{
    //チップ当たり判定処理
    for (int Ver = 0; Ver < MAPCHIP_V_MAX; Ver++)
    {
        for (int Hor = 0; Hor < MAPCHIP_H_MAX; Hor++)
        {
            
        }
    }
}

void MapData::drawMapChip()
{
    int MAP_MOVE_AMOUNT_X = -(Scroll::getInstance().getScrollAmountX() / 64);
    if (MAP_MOVE_AMOUNT_X < 0) { MAP_MOVE_AMOUNT_X = 0; }
    if ((MAP_MOVE_AMOUNT_X + SCREEN_CHIP_H_MAX) >= MAPCHIP_H_MAX) { MAP_MOVE_AMOUNT_X = MAPCHIP_H_MAX - SCREEN_CHIP_H_MAX - 1; }

    int MAP_MOVE_AMOUNT_Y = -(Scroll::getInstance().getScrollAmountY() / 64);
	if (MAP_MOVE_AMOUNT_Y < 0) { MAP_MOVE_AMOUNT_Y = 0; }
	if ((MAP_MOVE_AMOUNT_Y + SCREEN_CHIP_V_MAX) >= MAPCHIP_V_MAX) { MAP_MOVE_AMOUNT_Y = MAPCHIP_V_MAX - SCREEN_CHIP_V_MAX - 1; }

    for (int Ver = 0 + MAP_MOVE_AMOUNT_Y; Ver < SCREEN_CHIP_V_MAX + MAP_MOVE_AMOUNT_Y + 1; Ver++)
    {
        for (int Hor = 0 + MAP_MOVE_AMOUNT_X; Hor < SCREEN_CHIP_H_MAX + MAP_MOVE_AMOUNT_X + 1; Hor++)
        {
			if (test_map[Ver][Hor] == 6 || test_map[Ver][Hor] >= 8)
			{
				DrawRectGraphF(rel_posX + (Hor * MAPCHIP_SIZE), rel_posY + (Ver * MAPCHIP_SIZE), (Floor * MAPCHIP_SIZE), 0, MAPCHIP_SIZE, MAPCHIP_SIZE, handle, TRUE);
			}
			else if (test_map[Ver][Hor] == 7)
			{
				DrawRectGraphF(rel_posX + (Hor * MAPCHIP_SIZE), rel_posY + (Ver * MAPCHIP_SIZE), (CatWalk * MAPCHIP_SIZE), 0, MAPCHIP_SIZE, MAPCHIP_SIZE, handle, TRUE);
			}
			else
			{
				DrawRectGraphF(rel_posX + (Hor * MAPCHIP_SIZE), rel_posY + (Ver * MAPCHIP_SIZE), (test_map[Ver][Hor] * MAPCHIP_SIZE), 0, MAPCHIP_SIZE, MAPCHIP_SIZE, handle, TRUE);
			}
        }
    }
}

void MapData::drawElevator()
{
	for (int Ver = 0; Ver < MAPCHIP_V_MAX; Ver++)
	{
		for (int Hor = 0; Hor < MAPCHIP_H_MAX; Hor++)
		{
			if (test_map[Ver][Hor] == PlayerSpawner || test_map[Ver][Hor] == GoalSpawner)
			{
				DrawRectGraphF(((Hor * MAPCHIP_SIZE) - (ELEVATOR_WIDTH / 2))+rel_posX, ((Ver * MAPCHIP_SIZE) - ELEVATOR_HEIGHT)+rel_posY, ELEVATOR_WIDTH * 0, 0, ELEVATOR_WIDTH, ELEVATOR_HEIGHT, goal_handle,TRUE);
			}
		}
	}
}

void MapData::drawElevatorFrame()
{
	for (int Ver = 0; Ver < MAPCHIP_V_MAX; Ver++)
	{
		for (int Hor = 0; Hor < MAPCHIP_H_MAX; Hor++)
		{
			if (test_map[Ver][Hor] == PlayerSpawner || test_map[Ver][Hor] == GoalSpawner)
			{
				DrawRectGraphF(((Hor * MAPCHIP_SIZE) - (ELEVATOR_WIDTH / 2)) + rel_posX, ((Ver * MAPCHIP_SIZE) - ELEVATOR_HEIGHT) + rel_posY, ELEVATOR_WIDTH * 0, 0, ELEVATOR_WIDTH, ELEVATOR_HEIGHT, goal_frame_handle, TRUE);
			}
		}
	}
}

void MapData::drawElevatorDoor()
{
	for (int Ver = 0; Ver < MAPCHIP_V_MAX; Ver++)
	{
		for (int Hor = 0; Hor < MAPCHIP_H_MAX; Hor++)
		{
			if (test_map[Ver][Hor] == PlayerSpawner || test_map[Ver][Hor] == GoalSpawner)
			{
				DrawRectGraphF(((Hor * MAPCHIP_SIZE) - (ELEVATOR_WIDTH / 2)) + rel_posX, ((Ver * MAPCHIP_SIZE) - ELEVATOR_HEIGHT) + rel_posY, ELEVATOR_WIDTH * 0, 0, ELEVATOR_WIDTH, ELEVATOR_HEIGHT, goal_door_handle, TRUE);
			}
		}
	}
}