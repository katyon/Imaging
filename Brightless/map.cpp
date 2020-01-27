#include "DxLib.h"
#include "common.h"
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
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,1,1,1,1,1,9,1,1,1,1,6,0,0,0,
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


void MapData::update(Player* obj,Game_Flag* game_flag)
{
    MapData::collMapChipWithPlayer(obj,game_flag);
}

void MapData::draw(Game_Flag* game_flag)
{
    MapData::drawMapChip();
	MapData::drawElevatorFrame(game_flag);
}

void MapData::collMapChipWithPlayer(Player* obj, Game_Flag* game_flag)
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
								if ((test_map[Ver + 1][Hor] == 0 || test_map[Ver + 1][Hor] == 3 || test_map[Ver + 1][Hor] == 4 || test_map[Ver + 1][Hor] == 5) && Ver != (MAPCHIP_V_MAX - 1))
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

				if (player_coll_left < chip_right && player_coll_right > chip_left&& player_coll_top + 15 < chip_bottom && player_coll_bottom - 15 > chip_top)
				{
					//横方向の押し戻し処理
					if (obj->getSpeedX() != 0)
					{
						if (obj->getSpeedX() > 0)
						{
							//判定のあったチップの左方向にチップが存在しなければ処理を行う
							if ((test_map[Ver][Hor - 1] == 0 || test_map[Ver][Hor - 1] == 3 || test_map[Ver][Hor - 1] == 4 || test_map[Ver][Hor - 1] == 5) && Hor != 0)
							{
								obj->setPosX(chip_left - PLAYER_WIDTH);
							}
						}
						if (obj->getSpeedX() < 0)
						{
							//判定のあったチップの右方向にチップが存在しなければ処理を行う
							if ((test_map[Ver][Hor + 1] == 0 || test_map[Ver][Hor + 1] == 3 || test_map[Ver][Hor + 1] == 4 || test_map[Ver][Hor + 1] == 5) && Hor != (MAPCHIP_H_MAX - 1))
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
			//ゴール判定
			if (test_map[Ver][Hor] == GoalSpawner)
			{
				if (player_coll_bottom == chip_top && abs((obj->getPosX() + (PLAYER_WIDTH / 2)) - Hor * MAPCHIP_SIZE) < 5)
				{
					game_flag->setEndFlag(true);
				}

			}
		}
	}
}

void MapData::collMapChipWithLight(Light* light)
{
    float chip_left;
    float chip_right;
    float chip_top;
    float chip_bottom;
    vec2<float> chip_posA;
    vec2<float> chip_posB;
    vec2<float> chip_posC;
    vec2<float> chip_posD;

    //チップ当たり判定処理
    for (int Ver = 0; Ver < MAPCHIP_V_MAX; Ver++)
    {
        for (int Hor = 0; Hor < MAPCHIP_H_MAX; Hor++)
        {
            if (test_map[Ver][Hor] == 4)
            {
                //マップチップ4点座標
                chip_left = Hor * MAPCHIP_SIZE;
                chip_right = (Hor + 1) * MAPCHIP_SIZE;
                chip_top = Ver * MAPCHIP_SIZE;
                chip_bottom = (Ver + 1) * MAPCHIP_SIZE;
                chip_posA.set(chip_left + Scroll::getInstance().getScrollAmountX(), chip_top + Scroll::getInstance().getScrollAmountY());
                chip_posB.set(chip_left + Scroll::getInstance().getScrollAmountX(), chip_bottom + Scroll::getInstance().getScrollAmountY());
                chip_posC.set(chip_right + Scroll::getInstance().getScrollAmountX(), chip_bottom + Scroll::getInstance().getScrollAmountY());
                chip_posD.set(chip_right + Scroll::getInstance().getScrollAmountX(), chip_top + Scroll::getInstance().getScrollAmountY());

                if (light->judgeCollSquare(light->posA, light->posB, light->posC, light->posD, chip_posA, chip_posB, chip_posC, chip_posD))
                {
                    //light->after_posA.set(0,0);
                    //light->after_posB.set(0, 1080);
                    //light->after_posC.set(1920, 1080);
                    //light->after_posD.set(1920, 0);
                    light->after_posA.set(chip_left, chip_top - 1000);
                    light->after_posB.set(chip_left, chip_bottom + 500);
                    light->after_posC.set(chip_right + 500, chip_bottom + 500);
                    light->after_posD.set(chip_right + 500, chip_top - 1000);
                    //light->after_posB.set(light->after_posA.x + cos(light->rad + (-90 * PI / 180)) * height, light->after_posA.y - sin(light->rad + (-90 * PI / 180)) * height);
                    //light->after_posC.set(light->after_posB.x + cos(light->rad) * width, light->after_posB.y - sin(light->rad) * width);
                    //light->after_posD.set(light->after_posC.x + cos(light->rad + (90 * PI / 180)) * height, light->after_posC.y - sin(light->rad + (90 * PI / 180)) * height);
                }
                else
                {
                    //light->after_posA.set(0, 0);
                    //light->after_posB.set(0, 0);
                    //light->after_posC.set(0, 0);
                    //light->after_posD.set(0, 0);
                }
            }
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

void MapData::drawElevatorFrame(Game_Flag* game_flag)
{
	int anime_frame = 0;
	if (game_flag->getStartTimer() < 100) { anime_frame = 0; }
	else if (game_flag->getStartTimer() >= 100 && game_flag->getStartTimer() < 213) { anime_frame = 1; }
	else if (game_flag->getStartTimer() >= 213 && game_flag->getStartTimer() < 216) { anime_frame = 2; }
	else if (game_flag->getStartTimer() >= 216 && game_flag->getStartTimer() < 219) { anime_frame = 3; }
	else if (game_flag->getStartTimer() >= 219 && game_flag->getStartTimer() < 222) { anime_frame = 4; }
	else if (game_flag->getStartTimer() >= 222 && game_flag->getStartTimer() < 225) { anime_frame = 5; }
	else if (game_flag->getStartTimer() >= 225) { anime_frame = 6; }

	for (int Ver = 0; Ver < MAPCHIP_V_MAX; Ver++)
	{
		for (int Hor = 0; Hor < MAPCHIP_H_MAX; Hor++)
		{
			if (test_map[Ver][Hor] == PlayerSpawner || test_map[Ver][Hor] == GoalSpawner)
			{
				DrawRectGraphF(((Hor * MAPCHIP_SIZE) - (ELEVATOR_WIDTH / 2)) + rel_posX, ((Ver * MAPCHIP_SIZE) - ELEVATOR_HEIGHT) + rel_posY, ELEVATOR_WIDTH * anime_frame, 0, ELEVATOR_WIDTH, ELEVATOR_HEIGHT, goal_frame_handle, TRUE);
			}
		}
	}
}

void MapData::drawElevatorDoor(Game_Flag* game_flag)
{
	int anime_frame = 0;
	if (game_flag->getStartTimer() < 100) { anime_frame = 0; }
	else if (game_flag->getStartTimer() >= 100 && game_flag->getStartTimer() < 213) { anime_frame = 1; }
	else if (game_flag->getStartTimer() >= 213 && game_flag->getStartTimer() < 216) { anime_frame = 2; }
	else if (game_flag->getStartTimer() >= 216 && game_flag->getStartTimer() < 219) { anime_frame = 3; }
	else if (game_flag->getStartTimer() >= 219 && game_flag->getStartTimer() < 222) { anime_frame = 4; }
	else if (game_flag->getStartTimer() >= 222 && game_flag->getStartTimer() < 225) { anime_frame = 5; }
	else if (game_flag->getStartTimer() >= 225) { anime_frame = 6; }

	for (int Ver = 0; Ver < MAPCHIP_V_MAX; Ver++)
	{
		for (int Hor = 0; Hor < MAPCHIP_H_MAX; Hor++)
		{
			if (test_map[Ver][Hor] == PlayerSpawner || test_map[Ver][Hor] == GoalSpawner)
			{
				DrawRectGraphF(((Hor * MAPCHIP_SIZE) - (ELEVATOR_WIDTH / 2)) + rel_posX, ((Ver * MAPCHIP_SIZE) - ELEVATOR_HEIGHT) + rel_posY, ELEVATOR_WIDTH * anime_frame, 0, ELEVATOR_WIDTH, ELEVATOR_HEIGHT, goal_door_handle, TRUE);
			}
		}
	}
}