// インクルード -------------------------------------------------------------------------------------
#include "DxLib.h"
#include <math.h>

#include "relative_position.h"
#include "input.h"
#include "system.h"

// 関数 ----------------------------------------------------------------------------------------
// デバック文字を描画
void System::drawDebugString(Player* player)
{
    SetFontSize(25);
    cr = GetColor(0, 200, 200);

    DrawFormatString(0, 0, cr, "Title:1");
    DrawFormatString(0, 20, cr, "Choice:2");
    DrawFormatString(0, 40, cr, "Game:3");
    DrawFormatString(0, 60, cr, "スクロール移動量X:%f,Y:%f", Scroll::getInstance().getScrollAmountX(), Scroll::getInstance().getScrollAmountY());
    DrawFormatString(0, 80, cr, "プレイヤー座標X:%f,Y:%f", player->getPosX(), player->getPosY());
    DrawFormatString(0, 100, cr, "プレイヤー相対座標X:%f,Y:%f", player->getRelPosX(), player->getRelPosY());
}

//線分と点の接触判定
bool judgeCollPointAndLine(float line_start_x, float line_start_y, float line_end_x, float line_end_y, float point_x,float point_y)
{
    float line_vector_x = line_end_x - line_start_x;
    float line_vector_y = line_end_y - line_start_y;
    float point_vector_x = point_x - line_start_x;
    float point_vector_y = point_y - line_start_y;

    float length_line = sqrtf(line_vector_x * line_vector_x + line_vector_y * line_vector_y);
    float length_point = sqrtf(point_vector_x * point_vector_x + point_vector_y * point_vector_y);

    //※floorfは浮動小数点計算の誤差修正(整数単位での判定)
    if (floorf(line_vector_x * point_vector_x + line_vector_y * point_vector_y) == floorf(length_line * length_point)
        && length_line >= length_point)
    {
        return true;
    }

    return false;
}

bool judgePenetrateLine(Player player, float line_start_x, float line_start_y, float line_end_x, float line_end_y)
{
    if (((line_start_y - line_end_y) * (player.getPosX() - line_start_x) + (line_start_x - line_end_x) * (line_start_y - player.getPosY())) *
        ((line_start_y - line_end_y) * ((player.getPosX() + player.getSpeedX()) - line_start_x) + (line_start_x - line_end_x) * (line_start_y - (player.getPosY() + player.getSpeedY()))) < 0)
    {
        if(((player.getPosY()-(player.getPosY()+player.getSpeedY()))+(line_start_x-player.getPosX())+(player.getPosX()-(player.getPosX()+player.getSpeedX()))*(player.getPosY()-line_start_y)) *
            ((player.getPosY() - (player.getPosY() + player.getSpeedY())) * (line_end_x - player.getPosY()) + (player.getPosX() - (player.getPosX() + player.getPosX())) * (player.getPosY() - line_end_y))<0)
        {
            return true;
        }
    }
    return false;
}

//交点：Intersection
//float calIntersectionPoint(Player player, float line_start_x, float line_start_y, float line_end_x, float line_end_y)
//{
//    float s1 = (((line_end_x - line_start_x) * (player.getPosY() - line_start_y) - (line_end_y - line_start_y) * (player.getPosX() - line_start_x)) / 2);
//    float s2 = ((line_end_x - line_start_x) * (line_start_y - (player.getPosY() + player.getSpeedY())) - (line_end_y - line_start_y) * (line_start_x - (player.getPosX() + player.getSpeedX())) / 2);
//
//    float intersectionX = player.getPosX() + ((player.getPosX() + player.getSpeedX()) - player.getPosX()) * s1 / (s1 + s2);
//    float intersectionY = player.getPosY() + ((player.getPosY() + player.getSpeedY()) - player.getPosY()) * s1 / (s1 + s2);
//
//    float correctPosX = intersectionX + (line_end_x - line_start_x) * (((player.getPosX() + player.getSpeedX())
//        - intersectionX) * (line_start_x - line_start_x) + ((player.getPosY() + player.getSpeedY()) - intersectionY) * (line_end_y - line_start_y)) / ((line_end_x - line_start_x) * (line_end_x - line_start_x) + (line_end_y - line_start_y) * (line_end_y - line_start_y));
//    float correctPosY = intersectionY + (line_end_x - line_start_x) * (((player.getPosX() + player.getSpeedX())
//        - intersectionX) * (line_start_x - line_start_x) + ((player.getPosY() + player.getSpeedY()) - intersectionY) * (line_end_y - line_start_y)) / ((line_end_x - line_start_x) * (line_end_x - line_start_x) + (line_end_y - line_start_y) * (line_end_y - line_start_y));
//
//}