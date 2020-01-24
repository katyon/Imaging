#pragma once

// �C���N���[�h ---------------------------------------------------------
#include "common.h"
#include "main.h"
#include "player.h"

// �萔 ----------------------------------------------------------------
#define SCREEN_WIDTH    (1920)
#define SCREEN_HEIGHT   (1080)

// �N���X --------------------------------------------------------------
class System
{
public:
    void drawDebugString(Player* player);

private:
    unsigned int cr = 0;
};


bool judgeCollPointAndLine(float line_start_x, float line_start_y, float line_end_x, float line_end_y, float point_x, float point_y);