#pragma once
// �C���N���[�h ---------------------------------------------------------
#include "common.h"
#include "main.h"

// �萔 ----------------------------------------------------------------

// �N���X --------------------------------------------------------------
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
    void updateDebug(Usable* usable);   // �f�o�b�O�p�̍X�V����

};