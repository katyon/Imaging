// インクルード ----------------------------------------------------------------------------------
#include "DxLib.h"
#include <math.h>

#include "common.h"
#include "input.h"
#include "light.h"
#include "relative_position.h"
#include "vec2.h"

// 関数 ----------------------------------------------------------------------------------------
void Light::init()
{
    width = 6000;
    height = 200;
    angle = 0;
    rad = 0;
    pos.set(0, 200);
    posM.set(pos.x, pos.y);
    posA.set(0, 0);
    posB.set(0, 0);
    posC.set(0, 0);
    posD.set(0, 0);
    after_posA.set(0, 0);
    after_posB.set(0, 0);
    after_posC.set(0, 0);
    after_posD.set(0, 0);
    //handle = LoadGraph("Data\\Images\\Light\\light.png");
    col_over = Not;
    black = GetColor(0, 0, 0);
}

void Light::update()
{
    angleManager();
    collisionManager();
}

void Light::beforeDraw()
{
    //DrawRectRotaGraph2F(pos.x + getScrollAmountX(), pos.y + getScrollAmountY(), 0, 0, width, height, 0, height / 2, 1.0, -rad, handle, true, false, false);
    drawFreeSquareF(posA, posB, posC, posD, black, true);
    //DrawBox(0, 0, 1920, 1080, GetColor(0, 0, 0),true);
}

void Light::afterDraw()
{
    drawFreeSquareF(after_posA, after_posB, after_posC, after_posD, black, true);

    //drawFreeSquareF(posA, posB, posC, posD, GetColor(255, 0, 0), false);
}

void Light::end()
{
    DeleteGraph(handle);
}

void Light::angleManager()
{
    // キーボード
    if (Input::GetInstance()->GetKey(KEY_INPUT_F)) pos.x -= LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetKey(KEY_INPUT_H)) pos.x += LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetKey(KEY_INPUT_T)) pos.y -= LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetKey(KEY_INPUT_G)) pos.y += LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetKey(KEY_INPUT_Z)) angle -= LIGHT_ANGLE_SPEED;
    if (Input::GetInstance()->GetKey(KEY_INPUT_X)) angle += LIGHT_ANGLE_SPEED;
    // 箱コン
    if (Input::GetInstance()->GetRightThumb(PL_1, Roughly_Left))    pos.x -= LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetRightThumb(PL_1, Roughly_Right))   pos.x += LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetRightThumb(PL_1, Roughly_Up))      pos.y -= LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetRightThumb(PL_1, Roughly_Down))    pos.y += LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetButton(PL_1, XINPUT_BUTTON_LEFT_SHOULDER))     angle -= LIGHT_ANGLE_SPEED;
    if (Input::GetInstance()->GetButton(PL_1, XINPUT_BUTTON_RIGHT_SHOULDER))    angle += LIGHT_ANGLE_SPEED;

    rad = angle * PI / 180;

    posM.set(pos.x + getScrollAmountX(), pos.y + getScrollAmountY());
    posA.set(posM.x + cos(rad + (90 * PI / 180)) * height / 2, posM.y - sin(rad + (90 * PI / 180)) * height / 2);
    posB.set(posA.x + cos(rad + (-90 * PI / 180)) * height, posA.y - sin(rad + (-90 * PI / 180)) * height);
    posC.set(posB.x + cos(rad) * width, posB.y - sin(rad) * width);
    posD.set(posC.x + cos(rad + (90 * PI / 180)) * height, posC.y - sin(rad + (90 * PI / 180)) * height);
}

void Light::collisionManager()
{
    switch (col_over)
    {
    case Not:

        break;
    case Wall:

        break;
    case Corner:

        break;
    default: break;
    }
}

void Light::calculateAngle(vec2<float> a, vec2<float> b)
{

}

float Light::getScrollAmountX()
{
    return Scroll::getInstance().getScrollAmountX();
}

float Light::getScrollAmountY()
{
    return Scroll::getInstance().getScrollAmountY();
}

// 四角形同士の接触判定(重なっていたらtrue)
bool Light::judgeCollSquare(vec2<float> a1, vec2<float> b1, vec2<float> c1, vec2<float> d1, vec2<float> a2, vec2<float> b2, vec2<float> c2, vec2<float> d2)
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
bool Light::judgeIentersectLine(vec2<float> a1, vec2<float> b1, vec2<float> a2, vec2<float> b2)
{
    float ta = (a2.x - b2.x) * (a1.y - a2.y) + (a2.y - b2.y) * (a2.x - a1.x);
    float tb = (a2.x - b2.x) * (b1.y - a2.y) + (a2.y - b2.y) * (a2.x - b1.x);
    float tc = (a1.x - b1.x) * (a2.y - a1.y) + (a1.y - b1.y) * (a1.x - a2.x);
    float td = (a1.x - b1.x) * (b2.y - a1.y) + (a1.y - b1.y) * (a1.x - b2.x);

    if (tc * td < 0 && ta * tb < 0) return true;
    return false;
};

// 点と三角形の内外判定(内側ならtrue)
bool Light::judgeInsidePointWithTriangle(vec2<float> p, vec2<float> ta, vec2<float> tb, vec2<float> tc)
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
bool Light::judgeCollTriangle(vec2<float> a1, vec2<float> b1, vec2<float> c1, vec2<float> a2, vec2<float> b2, vec2<float> c2)
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

// 自由四角形描画
void Light::drawFreeSquareF(vec2<float> a, vec2<float> b, vec2<float> c, vec2<float> d, unsigned int cr, bool fill)
{
    if (fill)
    {
        DrawTriangle(a.x, a.y, b.x, b.y, c.x, c.y, cr, true);
        DrawTriangle(a.x, a.y, d.x, d.y, c.x, c.y, cr, true);
    }
    else
    {
        DrawTriangle(a.x, a.y, b.x, b.y, c.x, c.y, cr, false);
        DrawTriangle(a.x, a.y, d.x, d.y, c.x, c.y, cr, false);
    }
}

void Mask::init()
{
    handle = MakeScreen(GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT, true);
    CreateMaskScreen();
    SetMaskScreenGraph(handle);
    SetMaskReverseEffectFlag(true);
}

void Mask::draw(Light* light)
{
    SetDrawScreen(handle);
    ClearDrawScreen();
    light->beforeDraw();
    SetDrawScreen(DX_SCREEN_BACK);
    ClearDrawScreen();
    SetUseMaskScreenFlag(true);
}

void Mask::end()
{
    DeleteMask(handle);
    DeleteMaskScreen();
}