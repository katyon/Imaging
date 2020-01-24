#pragma once
// インクルード ---------------------------------------------------------
#include "vec2.h"
// 定数 -----------------------------------------------------------------
#define LIGHT_ANGLE_SPEED   (2)
#define LIGHT_MOVE_SPEED    (8)
// クラス --------------------------------------------------------------
class Light
{
public:
    void    init();
    void    update();
    void    beforeDraw();
    void    afterDraw();
    void    end();

    void    angleManager();
    void    formManager();
    void    collisionManager();
    void    calculateAngle(float x1, float y1, float x2, float y2);
    void    drawFreeFillBlackSquareF(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
    void    drawFreeFillBlackSquareFVec2(vec2<float> vec, float x2, float y2, float x3, float y3, float x4, float y4);

    enum CollisionState { Not, Wall, Corner};
    CollisionState  col_over;

private:
    float   getScrollAmountX();
    float   getScrollAmountY();

    unsigned int black = 0;
    float   posX = 0;
    float   posY = 0;
    int     width = 0;
    int     height = 0;
    float   angle = 0;
    int     handle = 0;
    vec2<float> vec;

};

class Mask
{
public:
    void    init();
    void    draw(Light* light);
    void    end();

private:
    int handle = 0;
};