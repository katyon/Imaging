// インクルード ----------------------------------------------------------------------------------
#include "DxLib.h"

#include "input.h"
#include "scene_game.h"
#include "relative_position.h"

// 関数 ----------------------------------------------------------------------------------------
void Game_Bg::init()
{
    posX = posY = rel_posX = rel_posY = 0;
    handle = LoadGraph("Data\\Images\\Bg\\CenterBg.png");
    top_bg_handle = LoadGraph("Data\\Images\\Bg\\TopBg.png");
    bottom_bg_handle = LoadGraph("Data\\Images\\Bg\\BottomBg.png");
}

void Game_Bg::update()
{
    
}

void Game_Bg::draw()
{
    DrawExtendGraphF(posX, posY, posX+1920, posY+1080, handle, true);
    DrawExtendGraphF(0, 0 + Scroll::getInstance().getScrollAmountY(), 1920, 1080 + Scroll::getInstance().getScrollAmountY(), top_bg_handle, true);
    //DrawExtendGraphF(0, 0 + Scroll::getInstance().getScrollAmountY(), 1920, 1080 + Scroll::getInstance().getScrollAmountY(), bottom_bg_handle, true);
}

void Game_Bg::end()
{
    DeleteGraph(handle);
}

void Game_Conduct::updateDebug(Usable* usable)
{
    if (Input::GetInstance()->GetKeyDown(KEY_INPUT_1)) usable->changeSceneStateInit(Title);
    if (Input::GetInstance()->GetKeyDown(KEY_INPUT_2)) usable->changeSceneStateInit(Choice);
    if (Input::GetInstance()->GetKeyDown(KEY_INPUT_3)) usable->changeSceneStateInit(Game);
}

void Game_Flag::init()
{
    start_flag = false;
    end_flag = false;
    start_timer = 0;
    end_timer = 0;
}

void Game_Flag::update(Usable* usable)
{
    //if (Input::GetInstance()->GetKeyDown(KEY_INPUT_9)) start_flag = true;
    if (Input::GetInstance()->GetKeyDown(KEY_INPUT_0)) end_flag = true;

    if (start_flag == false) { start_timer++; }
    if (start_timer > 325) { start_flag = true; }
    if (end_flag == true)
    {
        if (start_timer > 325) { start_timer = 325; }
        start_timer--;
    }
    
    if (end_flag == true && start_timer < 0)
    {
        usable->changeSceneStateInit(Title);
    }
}

void Game_Flag::end()
{
   
}