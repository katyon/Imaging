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
    bool    judgeCollSquare(vec2<float> a1, vec2<float> b1, vec2<float> c1, vec2<float> d1, vec2<float> a2, vec2<float> b2, vec2<float> c2, vec2<float> d2);

    vec2<float> pos;
    vec2<float> posM;
    vec2<float> posA;
    vec2<float> posB;
    vec2<float> posC;
    vec2<float> posD;
    vec2<float> after_posA;
    vec2<float> after_posB;
    vec2<float> after_posC;
    vec2<float> after_posD;
    int     width = 0;
    int     height = 0;
    float   rad = 0;
private:
    void    angleManager();
    void    collisionManager();
    void    calculateAngle(vec2<float> a, vec2<float> b);
    float   getScrollAmountX();
    float   getScrollAmountY();
    bool    judgeIentersectLine(vec2<float> a1, vec2<float> b1, vec2<float> a2, vec2<float> b2);
    bool    judgeInsidePointWithTriangle(vec2<float> p, vec2<float> ta, vec2<float> tb, vec2<float> tc);
    bool    judgeCollTriangle(vec2<float> a1, vec2<float> b1, vec2<float> c1, vec2<float> a2, vec2<float> b2, vec2<float> c2);
    void    drawFreeSquareF(vec2<float> a, vec2<float> b, vec2<float> c, vec2<float> d, unsigned int cr, bool fill);

    enum CollisionState { Not, Wall, Corner };
    CollisionState  col_over;
    float   angle = 0;

    int     handle = 0;
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