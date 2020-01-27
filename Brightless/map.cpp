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
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

void MapData::init()
{
    posX = posY = rel_posX = rel_posY = 0;
    handle = LoadGraph("Data\\Images\\Map\\map_chip.png");
}

void MapData::update(Light* light, Player* obj)
{
    MapData::collMapChipWithPlayer(obj);
    MapData::collMapChipWithLight(light);
}

void MapData::draw()
{
    MapData::drawMapChip();
}


void MapData::collMapChipWithPlayer(Player* obj)
{
    obj->setOnGround(false);

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

            if (test_map[Ver][Hor] > 0)
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
                                if (test_map[Ver - 1][Hor] == 0 && Ver != 0)
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
                                if (test_map[Ver + 1][Hor] == 0 && Ver != (MAPCHIP_V_MAX - 1))
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
                            if (test_map[Ver][Hor - 1] == 0 && Hor != 0)
                            {
                                obj->setPosX(chip_left - PLAYER_WIDTH);
                            }
                        }
                        if (obj->getSpeedX() < 0)
                        {
                            //判定のあったチップの右方向にチップが存在しなければ処理を行う
                            if (test_map[Ver][Hor + 1] == 0 && Hor != (MAPCHIP_H_MAX - 1))
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

    for (int Ver = 0 + MAP_MOVE_AMOUNT_Y; Ver < SCREEN_CHIP_V_MAX + MAP_MOVE_AMOUNT_Y + 1; Ver++)
    {
        for (int Hor = 0 + MAP_MOVE_AMOUNT_X; Hor < SCREEN_CHIP_H_MAX + MAP_MOVE_AMOUNT_X + 1; Hor++)
        {
            DrawRectGraphF(rel_posX + (Hor * MAPCHIP_SIZE), rel_posY + (Ver * MAPCHIP_SIZE), (test_map[Ver][Hor] * MAPCHIP_SIZE), 0, MAPCHIP_SIZE, MAPCHIP_SIZE, handle, TRUE);
        }
    }
}