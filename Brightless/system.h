#pragma once

// インクルード ---------------------------------------------------------
#include "common.h"
#include "main.h"

// 定数 ----------------------------------------------------------------

// クラス --------------------------------------------------------------
class System
{
public:
    void drawDebugString();
    void changeSceneStateInit(int state, Scene_State scene_num, Scene_Title* title, Scene_Choice* choice, Scene_Game* game);

private:
    unsigned int cr = 0;
};