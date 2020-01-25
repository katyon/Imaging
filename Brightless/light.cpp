// インクルード ----------------------------------------------------------------------------------
#include "DxLib.h"
#include <math.h>

#include "common.h"
#include "input.h"
#include "light.h"
#include "map.h"
#include "relative_position.h"
#include "system.h"
#include "vec2.h"

// 関数 ----------------------------------------------------------------------------------------
void Light::init()
{
    posA.set(0, 200);
    width = 6000;
    height = 200;
    angle = 0;
    handle = LoadGraph("Data\\Images\\Light\\light.png");
    col_over = Not;
}

void Light::update()
{
    collisionManager();
    angleManager();
}

void Light::beforeDraw()
{
    DrawRectRotaGraph2F(posA.x + getScrollAmountX(), posA.y + getScrollAmountY(), 0, 0, width, height, 0, height / 2, 1.0, angle * PI / 180, handle, true, false, false);
}

void Light::afterDraw()
{
    //DrawBox(900, 500, 1920, 1080, black, true);
}

void Light::end()
{
    DeleteGraph(handle);
}

void Light::angleManager()
{
    // キーボード
    if (Input::GetInstance()->GetKey(KEY_INPUT_F)) posA.x -= LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetKey(KEY_INPUT_H)) posA.x += LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetKey(KEY_INPUT_T)) posA.y -= LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetKey(KEY_INPUT_G)) posA.y += LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetKey(KEY_INPUT_Z)) angle -= LIGHT_ANGLE_SPEED;
    if (Input::GetInstance()->GetKey(KEY_INPUT_X)) angle += LIGHT_ANGLE_SPEED;
    // 箱コン
    if (Input::GetInstance()->GetRightThumb(PL_1, Roughly_Left))    posA.x -= LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetRightThumb(PL_1, Roughly_Right))   posA.x += LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetRightThumb(PL_1, Roughly_Up))      posA.y -= LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetRightThumb(PL_1, Roughly_Down))    posA.y += LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetButton(PL_1, XINPUT_BUTTON_LEFT_SHOULDER))     angle -= LIGHT_ANGLE_SPEED;
    if (Input::GetInstance()->GetButton(PL_1, XINPUT_BUTTON_RIGHT_SHOULDER))    angle += LIGHT_ANGLE_SPEED;
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