// インクルード ----------------------------------------------------------------------------------
#include "DxLib.h"
#include <math.h>

#include "common.h"
#include "input.h"
#include "light.h"

// 関数 ----------------------------------------------------------------------------------------
void Light::init()
{
    black   = GetColor(0, 0, 0);

    posXA  = 200;
    posYA  = 600;
    posXB  = 0;
    posYB  = 300;
    posXC  = GAME_SCREEN_WIDTH;
    posYC  = 300;
    posXD  = GAME_SCREEN_WIDTH;
    posYD  = 0;
    angle  = 0;
    col_over    = Not;
}

void Light::update()
{
    collisionManager();
    formManager();
    angleManager();
}

void Light::draw()
{
    DrawBox(posXA, posYA, 600, 900, black, true);
}

void Light::end()
{

}

void Light::angleManager()
{

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

void Light::drawFreeFillBlackSquareF(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    DrawTriangle(x1, y1, x2, y2, x3, y3, black, true);
    DrawTriangle(x1, y1, x4, y4, x3, y3, black, true);
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
    light->draw();
    SetDrawScreen(DX_SCREEN_BACK);
    ClearDrawScreen();
    SetUseMaskScreenFlag(true);
}

void Mask::end()
{
    DeleteMask(handle);
    DeleteMaskScreen();
}