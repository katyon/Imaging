#pragma once

// インクルード
#include <windows.h>
#include <DxLib.h>

// 定数 ----------------------------------------------------
#define STR_WINTTL				"Brightless"    // ウィンドウタイトル（任意に設定）
#define STR_MSGTTL_ASKFS		"起動処理"
#define STR_MSG_ASKFS			"フルスクリーンで起動しますか？"

#define SPR_MAX     (64)

enum sprHandle_Num
{
    Title_Bg, Choice_Bg, Game_BG,
    Player
};
// クラス --------------------------------------------------
class Usable
{
public:
    void BeforeInit(void);
    void AfterInit(void);
    void MainLoop(void);
};

// メインループ用の親クラス
class Scene
{
public:
    virtual void init(void) = 0;
    virtual void update(int GameTime) = 0;
    virtual void draw(int GameTime) = 0;
    virtual void end(void) = 0;
};

class Scene_Title :public Scene
{
public:
    void init(void);
    void update(int GameTime);
    void draw(int GameTime);
    void end(void);
private:

};

class Scene_Choice :public Scene
{
public:
    void init(void);
    void update(int GameTime);
    void draw(int GameTime);
    void end(void);
private:

};

class Scene_Game :public Scene
{
public:
    void init(void);
    void update(int GameTime);
    void draw(int GameTime);
    void end(void);
private:

};