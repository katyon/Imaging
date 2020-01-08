#pragma once
// ’è” ----------------------------------------------------------------

// ƒNƒ‰ƒX --------------------------------------------------------------
class System
{
public:
    void drawDebugString();
    void changeSceneStateInit(int state, Scene_State scene_num, Scene_Title* title, Scene_Choice* choice, Scene_Game* game);

private:
    unsigned int cr = 0;
};