#pragma once
// �C���N���[�h ---------------------------------------------------------
#include "common.h"
#include "main.h"

// �萔 ----------------------------------------------------------------

// �N���X --------------------------------------------------------------
class Game_Bg : public Sprite
{
public:
    void init(Game_Bg* game_bg);
    void update(Game_Bg* game_bg);
    void draw(Game_Bg* game_bg);
    void end(Game_Bg* game_bg);

private:

};

class Game_Conduct
{
public:
    void updateDebug(Game_Conduct* game_conduct, Usable* usable);   // �f�o�b�O�p�̍X�V����

};