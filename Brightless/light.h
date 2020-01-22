#pragma once
// インクルード ---------------------------------------------------------

// 定数 -----------------------------------------------------------------
#define ANGLE_SPEED (5)

// クラス --------------------------------------------------------------
class Light
{
public:
    void    init();
    void    update();
    void    draw();
    void    end();

    void    angleManager();
    void    formManager();
    void    collisionManager();
    void    getAngle(float x1, float y1, float x2, float y2);
    void    drawFreeFillBlackSquareF(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);

    enum CollisionState { Not, Wall, Corner};

    float   posXA = 0;
    float   posYA = 0;
    float   posXB = 0;
    float   posYB = 0;
    float   posXC = 0;
    float   posYC = 0;
    float   posXD = 0;
    float   posYD = 0;
    float   angle = 0;
    CollisionState  col_over;

private:
    unsigned int black = 0;

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