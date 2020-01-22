#pragma once

// インクルード ---------------------------------------------------------
#include "common.h"
#include "light.h"
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