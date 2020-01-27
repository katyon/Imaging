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
    DrawFormatString(0, 120, cr, "交点座標X:%f,Y:%f", player->getCorrectX(), player->getCorrectY());
    DrawFormatString(0, 140, cr, "ジャンプフラグ:%d", player->getOnGround());
    DrawFormatString(0, 160, cr, "移動可能フラグ:%d", player->getMovementPass());
    DrawFormatString(0, 180, cr, "移動力X:%f,移動力Y:%f", player->getSpeedX(),player->getSpeedY());
}

//線分と点の接触判定
bool judgeCollPointAndLine(float line_start_x, float line_start_y, float line_end_x, float line_end_y, float point_x,float point_y,Player* player)
{
    float line_vector_x = line_end_x - line_start_x;
    float line_vector_y = line_end_y - line_start_y;
    float point_vector_x = point_x - line_start_x;
    float point_vector_y = point_y - line_start_y;

    float length_line = sqrtf(line_vector_x * line_vector_x + line_vector_y * line_vector_y);
    float length_point = sqrtf(point_vector_x * point_vector_x + point_vector_y * point_vector_y);

    //※floorfは浮動小数点計算の誤差修正(整数単位での判定)
    if (floorf((line_vector_x * point_vector_x + line_vector_y * point_vector_y)) == floorf((length_line * length_point))
        && length_line >= length_point)
    {
        return true;
    }
    return false;
}

//bool judgePenetrateLine(Player player, float line_start_x, float line_start_y, float line_end_x, float line_end_y)
//{
//    if (((line_start_y - line_end_y) * (player.getPosX() - line_start_x) + (line_start_x - line_end_x) * (line_start_y - player.getPosY())) *
//        ((line_start_y - line_end_y) * ((player.getPosX() + player.getSpeedX()) - line_start_x) + (line_start_x - line_end_x) * (line_start_y - (player.getPosY() + player.getSpeedY()))) < 0)
//    {
//        if(((player.getPosY()-(player.getPosY()+player.getSpeedY()))+(line_start_x-player.getPosX())+(player.getPosX()-(player.getPosX()+player.getSpeedX()))*(player.getPosY()-line_start_y)) *
//            ((player.getPosY() - (player.getPosY() + player.getSpeedY())) * (line_end_x - player.getPosY()) + (player.getPosX() - (player.getPosX() + player.getPosX())) * (player.getPosY() - line_end_y))<0)
//        {
//            return true;
//        }
//    }
//    return false;
//}

//bool judgePenetrateLine(Player player, float line_start_x, float line_start_y, float line_end_x, float line_end_y)
//{
//    if (((line_start_y - line_end_y) * (player.getPosX() - line_start_x) + (line_start_x - line_end_x) * (line_start_y - player.getPosY())) *
//        ((line_start_y - line_end_y) * ((player.getPosX() + player.getSpeedX()) - line_start_x) + (line_start_x - line_end_x) * (line_start_y - (player.getPosY() + player.getSpeedY()))) < 0)
//    {
//        if (((player.getPosY() - (player.getPosY() + player.getSpeedY())) + (line_start_x - player.getPosX()) + (player.getPosX() - (player.getPosX() + player.getSpeedX())) * (player.getPosY() - line_start_y)) *
//            ((player.getPosY() - (player.getPosY() + player.getSpeedY())) * (line_end_x - player.getPosY()) + (player.getPosX() - (player.getPosX() + player.getPosX())) * (player.getPosY() - line_end_y)) < 0)
//        {
//            return true;
//        }
//    }
//    return false;
//}
//
//bool judgePenetrateLine(float player_x, float player_y, float player_move_x, float player_move_y, float line_start_x, float line_start_y, float line_end_x, float line_end_y)
//{
//    if (((line_start_y - line_end_y) * (player_x - line_start_x) + (line_start_x - line_end_x) * (line_start_y - player_y)) *
//        ((line_start_y - line_end_y) * ((player_move_x) - line_start_x) + (line_start_x - line_end_x) * (line_start_y - (player_move_y))) < 0)
//    {
//        if (((player_y - (player_move_y)) + (line_start_x - player_x) + (player_x - (player_move_x)) * (player_y - line_start_y)) *
//            ((player_y - (player_move_y)) * (line_end_x - player_y) + (player_x - (player_move_x)) * (player_y - line_end_y)) < 0)
//        {
//            return true;
//        }
//    }
//    return false;
//}

//交点：Intersection
//void calIntersectionPoint(Player player, float line_start_x, float line_start_y, float line_end_x, float line_end_y)
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
//    player.setCorrectX = correctPosX;
//    player.setCorrectY = correctPosY;
//}
//
//void calIntersectionPoint(Player player, float player_x, float player_y, float player_move_x, float player_move_y, float line_start_x, float line_start_y, float line_end_x, float line_end_y)
//{
//    float s1 = (((line_end_x - line_start_x) * (player_y- line_start_y) - (line_end_y - line_start_y) * (player_x- line_start_x)) / 2);
//    float s2 = ((line_end_x - line_start_x) * (line_start_y - (player_move_y)) - (line_end_y - line_start_y) * (line_start_x - (player_move_x)) / 2);
//
//    float intersectionX = player_x+ ((player_move_x) - player_x) * s1 / (s1 + s2);
//    float intersectionY = player_y+ ((player_move_y) - player_y) * s1 / (s1 + s2);
//
//    float correctPosX = intersectionX + (line_end_x - line_start_x) * (((player_move_x)
//        - intersectionX) * (line_start_x - line_start_x) + ((player_move_y) - intersectionY) * (line_end_y - line_start_y)) / ((line_end_x - line_start_x) * (line_end_x - line_start_x) + (line_end_y - line_start_y) * (line_end_y - line_start_y));
//    float correctPosY = intersectionY + (line_end_x - line_start_x) * (((player_move_x)
//        - intersectionX) * (line_start_x - line_start_x) + ((player_move_y) - intersectionY) * (line_end_y - line_start_y)) / ((line_end_x - line_start_x) * (line_end_x - line_start_x) + (line_end_y - line_start_y) * (line_end_y - line_start_y));
//
//    player.setPosX = correctPosX;
//    player.setPosY = correctPosY;
//}

void judgePenetrateLine(Player player, float line_start_x, float line_start_y, float line_end_x, float line_end_y)
{
    if (((line_start_y - line_end_y) * (player.getPosX() - line_start_x) + (line_start_x - line_end_x) * (line_start_y - player.getPosY())) *
        ((line_start_y - line_end_y) * ((player.getPosX() + player.getSpeedX()) - line_start_x) + (line_start_x - line_end_x) * (line_start_y - (player.getPosY() + player.getSpeedY()))) < 0)
    {
        if (((player.getPosY() - (player.getPosY() + player.getSpeedY())) + (line_start_x - player.getPosX()) + (player.getPosX() - (player.getPosX() + player.getSpeedX())) * (player.getPosY() - line_start_y)) *
            ((player.getPosY() - (player.getPosY() + player.getSpeedY())) * (line_end_x - player.getPosY()) + (player.getPosX() - (player.getPosX() + player.getPosX())) * (player.getPosY() - line_end_y)) < 0)
        {
            float s1 = (((line_end_x - line_start_x) * (player.getPosY() - line_start_y) - (line_end_y - line_start_y) * (player.getPosX() - line_start_x)) / 2);
            float s2 = ((line_end_x - line_start_x) * (line_start_y - (player.getPosY() + player.getSpeedY())) - (line_end_y - line_start_y) * (line_start_x - (player.getPosX() + player.getSpeedX())) / 2);

            float intersectionX = player.getPosX() + ((player.getPosX() + player.getSpeedX()) - player.getPosX()) * s1 / (s1 + s2);
            float intersectionY = player.getPosY() + ((player.getPosY() + player.getSpeedY()) - player.getPosY()) * s1 / (s1 + s2);

            float correctPosX = intersectionX + (line_end_x - line_start_x) * (((player.getPosX() + player.getSpeedX())
                - intersectionX) * (line_start_x - line_start_x) + ((player.getPosY() + player.getSpeedY()) - intersectionY) * (line_end_y - line_start_y)) / ((line_end_x - line_start_x) * (line_end_x - line_start_x) + (line_end_y - line_start_y) * (line_end_y - line_start_y));
            float correctPosY = intersectionY + (line_end_x - line_start_x) * (((player.getPosX() + player.getSpeedX())
                - intersectionX) * (line_start_x - line_start_x) + ((player.getPosY() + player.getSpeedY()) - intersectionY) * (line_end_y - line_start_y)) / ((line_end_x - line_start_x) * (line_end_x - line_start_x) + (line_end_y - line_start_y) * (line_end_y - line_start_y));

            player.setCorrectX(correctPosX);
            player.setCorrectY(correctPosY);

            if (((line_start_y - line_end_y) * (player.getPosX() - line_start_x) + (line_start_x - line_end_x) * (line_start_y - player.getPosY()))*
                ((line_start_y - line_end_y) * ((player.getCorrectX()) - line_start_x) + (line_start_x - line_end_x) * (line_start_y - (player.getCorrectY()))) < 0)
            {
                if (((player.getPosY() - (player.getCorrectY())) + (line_start_x - player.getPosX()) + (player.getPosX() - (player.getCorrectX())) * (player.getPosY() - line_start_y)) *
                    ((player.getPosY() - (player.getCorrectY())) * (line_end_x - player.getPosY()) + (player.getPosX() - (player.getPosX() + player.getPosX())) * (player.getPosY() - line_end_y)) < 0)
                {
                    s1 = (((line_end_x - line_start_x) * (player.getPosY() - line_start_y) - (line_end_y - line_start_y) * (player.getPosX() - line_start_x)) / 2);
                    s2 = ((line_end_x - line_start_x) * (line_start_y - (player.getCorrectY())) - (line_end_y - line_start_y) * (line_start_x - (player.getCorrectX())) / 2);

                    intersectionX = player.getPosX() + ((player.getCorrectX()) - player.getPosX()) * s1 / (s1 + s2);
                    intersectionY = player.getPosY() + ((player.getCorrectY()) - player.getPosY()) * s1 / (s1 + s2);

                    player.setCorrectX(intersectionX);
                    player.setCorrectY(intersectionY);
                }
            }

            player.setPosX(player.getCorrectX());
            player.setPosY(player.getCorrectY());
        }
    }
}

//線分AB(A:x1,x2)(B:x2,y2)と線分CD(C:x3,y3)(D:x4,y4)の判定
//A:プレイヤーの座標 B:移動後のプレイヤーの座標 C:線分の始点　D:線分の終点    (必ずC<Dが成り立つ状態で使用する)
void judgeIntersection(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, Player* player)
{
    if ((x1<x3 || x1>x4))
    {
        //player->setMovementPass(true);
    }

   if (((x1 - x2) * (y3 - y1) + (y1 - y2) * (x1 - x3)) *
       ((x1 - x2) * (y4 - y1) + (y1 - y2) * (x1 - x4)) < 0)
   {
       if (((x3 - x4) * (y1 - y3) + (y3 - y4) * (x3 - x1)) *
           ((x3 - x4) * (y2 - y3) + (y3 - y4) * (x3 - x2)) < 0)
       {
           float S1 = ( (x3 - x4) * (y1 - y4) - (y3 - y4) * (x1 - x4) ) / 2;
           float S2 = ( (x3 - x4) * (y4 - y2) - (y3 - y4) * (x4 - x2) ) / 2;
   
           float intersection_x = floorf(x1 + (x2 - x1) * S1 / (S1 + S2)+0.5f);
           float intersection_y = floorf(y1 + (y2 - y1) * S1 / (S1 + S2)+0.5f);
   
           player->setCorrectX(intersection_x);
           player->setCorrectY(intersection_y);
   
           if (((x1 - intersection_x) * (y3 - y1) + (y1 - intersection_y) * (x1 - x3)) *
               ((x1 - intersection_x) * (y4 - y1) + (y1 - intersection_y) * (x1 - x4)) < 0)
           {
               if (((x3 - x4) * (y1 - y3) + (y3 - y4) * (x3 - x1)) *
                   ((x3 - x4) * (intersection_y - y3) + (y3 - y4) * (x3 - intersection_x)) < 0)
               {
                   S1 = ((x3 - x4) * (y1 - y4) - (y3 - y4) * (x1 - x4)) / 2;
                   S2 = ((x3 - x4) * (y4 - intersection_y) - (y3 - y4) * (x4 - intersection_x)) / 2;
   
                   intersection_x = floorf(x1 + (intersection_x - x1) * S1 / (S1 + S2))+0.5f;
                   intersection_y = floorf(y1 + (intersection_y - y1) * S1 / (S1 + S2))+0.5f;
                   player->setCorrectX(intersection_x);
                   player->setCorrectY(intersection_y);
               }
           }

           player->setMoveAngle(atan2((y4-y3),(x4-x3)));
   
           player->setPosX(player->getCorrectX()-(PLAYER_WIDTH/2));
           player->setPosY(player->getCorrectY()-PLAYER_HEIGHT);

           player->setOnGround(true);
           player->setMovementPass(false);
       }
   }
}

bool judgeIntersectionY(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, Player* player)
{

    if (((x1 - x2) * (y3 - y1) + (y1 - y2) * (x1 - x3)) *
        ((x1 - x2) * (y4 - y1) + (y1 - y2) * (x1 - x4)) < 0)
    {
        if (((x3 - x4) * (y1 - y3) + (y3 - y4) * (x3 - x1)) *
            ((x3 - x4) * (y2 - y3) + (y3 - y4) * (x3 - x2)) < 0)
        {
            float S1 = ((x3 - x4) * (y1 - y4) - (y3 - y4) * (x1 - x4)) / 2;
            float S2 = ((x3 - x4) * (y4 - y2) - (y3 - y4) * (x4 - x2)) / 2;

            float intersection_x = floorf(x1 + (x2 - x1) * S1 / (S1 + S2) + 0.5f);
            float intersection_y = floorf(y1 + (y2 - y1) * S1 / (S1 + S2) + 0.5f);
            return true;
            
        }
    }
    //player->setMovementPass(true);
    return false;
}