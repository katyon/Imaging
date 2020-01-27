#pragma once
#include "light.h"
#include "player.h"

// ’è” ----------------------------------------------------------------
#define SCREEN_WIDTH    (1920)
#define SCREEN_HEIGHT   (1080)

// ƒNƒ‰ƒX --------------------------------------------------------------
class System
{
public:
    void    drawDebugString(Light* light, Player* player);

private:
    unsigned int cr = 0;

};


bool judgeCollPointAndLine(float line_start_x, float line_start_y, float line_end_x, float line_end_y, float point_x, float point_y);