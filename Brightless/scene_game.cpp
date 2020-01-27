// インクルード ----------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "scene_game.h"

// 関数 ----------------------------------------------------------------------------------------
void Game_Bg::init()
{
    posX = posY = rel_posX = rel_posY = 0;
    handle = LoadGraph("Data\\Images\\Bg\\Game_Bg.png");
}

void Game_Bg::update()
{

}

void Game_Bg::draw()
{
    DrawGraphF(posX, posY, handle, true);
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