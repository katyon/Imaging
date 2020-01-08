// インクルード -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "main.h"
#include "system.h"

// 関数 ----------------------------------------------------------------------------------------

// デバック文字を描画
void System::drawDebugString()
{
    cr = GetColor(255, 255, 255);

    DrawFormatString(10, 10, cr, "abcde");

}

// シーン遷移処理
void System::changeSceneStateInit(int state, Scene_State scene_num, Scene_Title* title, Scene_Choice* choice, Scene_Game* game)
{
    // 現在のシーンの終了処理
    switch (state)
    {
    case Title:
        title->end();
        break;
    case Choice:
        choice->end();
        break;
    case Game:
        game->end();
        break;
    }

    // シーン遷移時に初期化
    switch (scene_num)
    {
    case Title:
        title->init();
        break;
    case Choice:
        choice->init();
        break;
    case Game:
        game->init();
        break;
    }

    state = scene_num;
}