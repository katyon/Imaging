#pragma once
// インクルード ---------------------------------------------------------


// 定数 ----------------------------------------------------------------

// クラス --------------------------------------------------------------
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
    void updateDebug(Choice_Conduct* choice_conduct, Usable* usable);   // デバッグ用の更新処理

};