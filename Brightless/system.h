#pragma once

// �C���N���[�h ---------------------------------------------------------
#include "common.h"
#include "main.h"

// �萔 ----------------------------------------------------------------

// �N���X --------------------------------------------------------------
class System
{
public:
    void drawDebugString();
    void changeSceneStateInit(int state, Scene_State scene_num, Scene_Title* title, Scene_Choice* choice, Scene_Game* game);

private:
    unsigned int cr = 0;
};