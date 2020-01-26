// インクルード ----------------------------------------------------------------------------------
#include "DxLib.h"
#include <math.h>

#include "common.h"
#include "input.h"
#include "light.h"
#include "map.h"
#include "relative_position.h"

// 関数 ----------------------------------------------------------------------------------------
void Light::init()
{
    black = GetColor(0, 0, 0);
    posX = 0;
    posY = 200;
    width = 6000;
    height = 200;
    angle = 0;
    handle = LoadGraph("Data\\Images\\Light\\light.png");
    col_over = Not;
    vec.set(0, 200);
}

void Light::update()
{
    collisionManager();
    formManager();
    angleManager();
}

void Light::beforeDraw()
{
    DrawRectRotaGraph2F(posX+getScrollAmountX(), posY+getScrollAmountY(), 0, 0, width, height, 0, height / 2, 1.0, angle * PI / 180, handle, true, false, false);
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
    if (Input::GetInstance()->GetKey(KEY_INPUT_F)) posX -= LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetKey(KEY_INPUT_H)) posX += LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetKey(KEY_INPUT_T)) posY -= LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetKey(KEY_INPUT_G)) posY += LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetKey(KEY_INPUT_Z)) angle -= LIGHT_ANGLE_SPEED;
    if (Input::GetInstance()->GetKey(KEY_INPUT_X)) angle += LIGHT_ANGLE_SPEED;
    // 箱コン
    if (Input::GetInstance()->GetRightThumb(PL_1, Roughly_Left))    posX -= LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetRightThumb(PL_1, Roughly_Right))   posX += LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetRightThumb(PL_1, Roughly_Up))      posY -= LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetRightThumb(PL_1, Roughly_Down))    posY += LIGHT_MOVE_SPEED;
    if (Input::GetInstance()->GetButton(PL_1, XINPUT_BUTTON_LEFT_SHOULDER))     angle -= LIGHT_ANGLE_SPEED;
    if (Input::GetInstance()->GetButton(PL_1, XINPUT_BUTTON_RIGHT_SHOULDER))    angle += LIGHT_ANGLE_SPEED;
}

void Light::formManager()
{

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

void Light::calculateAngle(float x1, float y1, float x2, float y2)
{

}

void Light::drawFreeFillBlackSquareF(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    DrawTriangle(x1, y1, x2, y2, x3, y3, black, true);
    DrawTriangle(x1, y1, x4, y4, x3, y3, black, true);
}

void Light::drawFreeFillBlackSquareFVec2(vec2<float> vec, float x2, float y2, float x3, float y3, float x4, float y4)
{
    DrawTriangle(vec.x,vec.y, x2, y2, x3, y3, black, true);
    DrawTriangle(vec.x, vec.y, x4, y4, x3, y3, black, true);
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
    SetUseMaskScreenFlag(false);
}

void Mask::end()
{
    DeleteMask(handle);
    DeleteMaskScreen();
}