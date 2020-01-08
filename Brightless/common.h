#pragma once

// ’è”’è‹`
#define GAME_SCREEN_WIDTH	(1920)      // ƒQ[ƒ€‰æ–Ê‚Ì•
#define GAME_SCREEN_HEIGHT	(1080)      // ƒQ[ƒ€‰æ–Ê‚Ì‚‚³
#define PI          (3.1415926535f)     // ‰~ü—¦
#define ROOT2       (1.41421356f)       // ã2
#define ROOT5       (2.2360679f)        // ã5

enum PL_Num { PL_1, PL_2 };
enum Scene_State { Title, Choice, Game };

class Sprite
{
public:
    virtual void update() = 0;
    virtual void draw() = 0;

protected:
    int posX = 0;
    int posY = 0;
    float posXF = 0;
    float posYF = 0;
    int width = 0;
    int height = 0;
};