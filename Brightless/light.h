#pragma once
// インクルード ---------------------------------------------------------

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
    
private:
    void    angleManager();
    void    collisionManager();
    void    calculateAngle(vec2<float> a,vec2<float> b);
    float   getScrollAmountX();
    float   getScrollAmountY();

    vec2<float> posA;
    enum CollisionState { Not, Wall, Corner};
    CollisionState  col_over;
    int     width = 0;
    int     height = 0;
    float   angle = 0;
    int     handle = 0;

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