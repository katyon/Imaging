#pragma once

// �萔��`
#define GAME_SCREEN_WIDTH	(1920)      // �Q�[����ʂ̕�
#define GAME_SCREEN_HEIGHT	(1080)      // �Q�[����ʂ̍���
#define PI          (3.1415926535f)     // �~����
#define ROOT2       (1.41421356f)       // ��2
#define ROOT5       (2.2360679f)        // ��5

enum PL_Num { PL_1, PL_2 };

class Sprite
{
public:
    virtual void init(void) {};
    virtual void update(void) {};
    virtual void draw(void) {};
    virtual void end(void) {};

protected:
    float posX = 0;
    float posY = 0;
    int width = 0;
    int height = 0;
    int handle = 0;
};