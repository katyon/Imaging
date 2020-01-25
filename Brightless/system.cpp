// インクルード -------------------------------------------------------------------------------------
#include "DxLib.h"
#include <math.h>

#include "common.h"
#include "light.h"
#include "main.h"
#include "player.h"
#include "relative_position.h"
#include "system.h"
#include "vec2.h"

// 関数 ----------------------------------------------------------------------------------------
// デバック文字を描画
void System::drawDebugString(Light* light, Player* player)
{
    SetFontSize(25);
    cr = GetColor(0, 200, 200);

    DrawFormatString(0, 0, cr, "Title:1");
    DrawFormatString(0, 20, cr, "Choice:2");
    DrawFormatString(0, 40, cr, "Game:3");
    DrawFormatString(0, 60, cr, "スクロール移動量X:%f,Y:%f", Scroll::getInstance().getScrollAmountX(), Scroll::getInstance().getScrollAmountY());
    DrawFormatString(0, 80, cr, "プレイヤー座標X:%f,Y:%f", player->getPosX(), player->getPosY());
    DrawFormatString(0, 100, cr, "プレイヤー相対座標X:%f,Y:%f", player->getRelPosX(), player->getRelPosY());
    //DrawFormatString(0, 120, cr, "ライトとチップの接触判定:%d", judgeCollSquare());

}

// 自由四角形描画
void System::drawFreeFillBlackSquareF(vec2<float> a, vec2<float> b, vec2<float> c, vec2<float> d)
{
    black = GetColor(0, 0, 0);
    DrawTriangle(a.x, a.y, b.x, b.y, c.x, c.y, black, true);
    DrawTriangle(a.x, a.y, d.x, d.y, c.x, c.y, black, true);
}

// 四角形同士の接触判定(重なっていたらtrue)
bool System::judgeCollSquare(vec2<float> a1, vec2<float> b1, vec2<float> c1, vec2<float> d1, vec2<float> a2, vec2<float> b2, vec2<float> c2, vec2<float> d2)
{
    bool judge[4] = { false };
    if (judgeCollTriangle(a1, b1, c1, a2, b2, c2)) judge[0] = true;
    if (judgeCollTriangle(a1, b1, c1, a2, d2, c2)) judge[1] = true;
    if (judgeCollTriangle(a1, d1, c1, a2, b2, c2)) judge[2] = true;
    if (judgeCollTriangle(a1, d1, c1, a2, d2, c2)) judge[3] = true;

    if (judge[0] || judge[1] || judge[2] || judge[3]) return true;
    return false;
}

// 線同士の接触判定(重なっていたらtrue)
bool System::judgeIentersectLine(vec2<float> a1, vec2<float> b1, vec2<float> a2, vec2<float> b2)
{
    float ta = (a2.x - b2.x) * (a1.y - a2.y) + (a2.y - b2.y) * (a2.x - a1.x);
    float tb = (a2.x - b2.x) * (b1.y - a2.y) + (a2.y - b2.y) * (a2.x - b1.x);
    float tc = (a1.x - b1.x) * (a2.y - a1.y) + (a1.y - b1.y) * (a1.x - a2.x);
    float td = (a1.x - b1.x) * (b2.y - a1.y) + (a1.y - b1.y) * (a1.x - b2.x);

    if (tc * td < 0 && ta * tb < 0) return true;
    return false;
};

// 点と三角形の内外判定(内側ならtrue)
bool System::judgeInsidePointWithTriangle(vec2<float> p, vec2<float> ta, vec2<float> tb, vec2<float> tc)
{
    vec2<float> AB;
    vec2<float> BP;

    vec2<float> BC;
    vec2<float> CP;

    vec2<float> CA;
    vec2<float> AP;

    AB.set(tb.x - ta.x, tb.y - ta.y);
    BP.set(p.x - tb.x, p.y - tb.y);
    BC.set(tc.x - tb.x, tc.y - tb.y);
    CP.set(p.x - tc.x, p.y - tc.y);
    CA.set(ta.x - tc.x, ta.y - tc.y);
    AP.set(p.x - ta.x, p.y - ta.y);

    float c1 = AB.x * BP.y - AB.y * BP.x;
    float c2 = BC.x * CP.y - BC.y * CP.x;
    float c3 = CA.x * AP.y - CA.y * AP.x;

    if ((c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0)) return true;
    return false;
}

// 三角形同士の接触判定(重なっていたらtrue)
bool System::judgeCollTriangle(vec2<float> a1, vec2<float> b1, vec2<float> c1, vec2<float> a2, vec2<float> b2, vec2<float> c2)
{
    bool judge[11] = { false };
    if (judgeIentersectLine(a1, b1, a2, b2)) judge[0] = true;
    if (judgeIentersectLine(a1, b1, b2, c2)) judge[1] = true;
    if (judgeIentersectLine(a1, b1, c2, a2)) judge[2] = true;
    if (judgeIentersectLine(b1, c1, a2, b2)) judge[3] = true;
    if (judgeIentersectLine(b1, c1, b2, c2)) judge[4] = true;
    if (judgeIentersectLine(b1, c1, c2, a2)) judge[5] = true;
    if (judgeIentersectLine(c1, a1, a2, b2)) judge[6] = true;
    if (judgeIentersectLine(c1, a1, b2, c2)) judge[7] = true;
    if (judgeIentersectLine(c1, a1, c2, a2)) judge[8] = true;
    if (judgeInsidePointWithTriangle(a1, a2, b2, c2) && judgeInsidePointWithTriangle(b1, a2, b2, c2) && judgeInsidePointWithTriangle(c1, a2, b2, c2)) judge[9] = true;
    if (judgeInsidePointWithTriangle(a2, a1, b1, c1) && judgeInsidePointWithTriangle(b2, a1, b1, c1) && judgeInsidePointWithTriangle(c2, a1, b1, c1)) judge[10] = true;

    if (judge[0] || judge[1] || judge[2] || judge[3] || judge[4] || judge[5] || judge[6] || judge[7] || judge[8] || judge[9] || judge[10]) return true;
    return false;
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