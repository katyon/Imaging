#pragma once
// �C���N���[�h ---------------------------------------------------------
#include "common.h"
#include "main.h"

// �萔 ----------------------------------------------------------------

// �N���X --------------------------------------------------------------
class Choice_Bg : public Sprite
{
public:
    void init(Choice_Bg* choice_bg);
    void update(Choice_Bg* choice_bg);
    void draw(Choice_Bg* choice_bg);
    void end(Choice_Bg* choice_bg);

private:

};

class Choice_Conduct
{
public:
    void updateDebug(Choice_Conduct* choice_conduct, Usable* usable);   // �f�o�b�O�p�̍X�V����

};