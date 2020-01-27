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
private:
    int     top_bg_handle;;
    int     bottom_bg_handle;
};

class Game_Conduct
{
public:
    void updateDebug(Usable* usable);   // �f�o�b�O�p�̍X�V����
};

class Game_Flag
{
public :
    void init();
    void update(Usable* usable);
    void end();
    int     getStartTimer() { return start_timer; }
    int     getEndTimer() { return end_timer; }
    bool    getStartFlag() { return start_flag; }
    bool    getEndFlag() { return end_flag; }
    void    setEndFlag(bool e) { end_flag = e; }

private:
    bool    start_flag;
    bool    end_flag;
    int     start_timer;
    int     end_timer;

};