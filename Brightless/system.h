#pragma once

// �C���N���[�h ---------------------------------------------------------
#include "common.h"
#include "light.h"
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