#pragma once
#include "light.h"
#include "player.h"

// íËêî ----------------------------------------------------------------
#define SCREEN_WIDTH    (1920)
#define SCREEN_HEIGHT   (1080)

// ÉNÉâÉX --------------------------------------------------------------
class System
{
public:
    void    drawDebugString(Light* light, Player* player);
    void    drawFreeFillBlackSquareF(vec2<float> a, vec2<float> b, vec2<float> c, vec2<float> d);
    bool    judgeCollSquare(vec2<float> a1, vec2<float> b1, vec2<float> c1, vec2<float> d1, vec2<float> a2, vec2<float> b2, vec2<float> c2, vec2<float> d2);

private:
    bool    judgeIentersectLine(vec2<float> a1, vec2<float> b1, vec2<float> a2, vec2<float> b2);
    bool    judgeInsidePointWithTriangle(vec2<float> p, vec2<float> ta, vec2<float> tb, vec2<float> tc);
    bool    judgeCollTriangle(vec2<float> a1, vec2<float> b1, vec2<float> c1, vec2<float> a2, vec2<float> b2, vec2<float> c2);

    unsigned int cr = 0;
    unsigned int black = 0;

};


bool judgeCollPointAndLine(float line_start_x, float line_start_y, float line_end_x, float line_end_y, float point_x, float point_y);