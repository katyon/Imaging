#pragma once
// �C���N���[�h ---------------------------------------------------------
#include "common.h"
#include "system.h"

// �萔 ----------------------------------------------------------------

// �N���X --------------------------------------------------------------
class Title_Bg : public Sprite
{
public:
    void init(Title_Bg* title_bg);
    void update(Title_Bg* title_bg);
    void draw(Title_Bg* title_bg);
    void end(Title_Bg* title_bg);

};

class Title_Conduct
{
public:
    void updateDebug(Title_Conduct* title_conduct, Usable* usable);   // �f�o�b�O�p�̍X�V����

};