#pragma once
// �C���N���[�h ---------------------------------------------------------


// �萔 ----------------------------------------------------------------

// �N���X --------------------------------------------------------------
class Choice_Bg : public Sprite
{
public:
    void init(Choice_Bg* choice_bg);
    void update(Choice_Bg* choice_bg,Usable* usable);
    void draw(Choice_Bg* choice_bg);
    void end(Choice_Bg* choice_bg);

private:
    int timer = 0;
};

class Choice_Conduct
{
public:
    void updateDebug(Choice_Conduct* choice_conduct, Usable* usable);   // �f�o�b�O�p�̍X�V����

};