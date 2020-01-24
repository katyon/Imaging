#pragma once

// インクルード ---------------------------------------------------------
#include "common.h"
#include "main.h"
#include "player.h"

// 定数 ----------------------------------------------------------------
#define SCREEN_WIDTH    (1920)
#define SCREEN_HEIGHT   (1080)

// クラス --------------------------------------------------------------
class System
{
public:
    void drawDebugString(Player* player);

private:
    unsigned int cr = 0;
};


bool judgeCollPointAndLine(float line_start_x, float line_start_y, float line_end_x, float line_end_y, float point_x, float point_y);