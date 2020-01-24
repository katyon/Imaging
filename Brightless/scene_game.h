#pragma once
// インクルード ---------------------------------------------------------
#include "common.h"
#include "main.h"

// 定数 ----------------------------------------------------------------

// クラス --------------------------------------------------------------
class Game_Bg : public Sprite
{
public:
    void init();
    void update();
    void draw();
    void end();
};

class Game_Conduct
{
public:
    void updateDebug(Usable* usable);   // デバッグ用の更新処理

};