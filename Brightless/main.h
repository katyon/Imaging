#pragma once

// インクルード
#include <windows.h>
#include <DxLib.h>

// 定数定義
#define STR_WINTTL				"Brightless"    // ウィンドウタイトル（任意に設定）
#define STR_MSGTTL_ASKFS		"起動処理"
#define STR_MSG_ASKFS			"フルスクリーンで起動しますか？"

enum GAME_STATE { Title, Choice, Game };

// クラス定義
// メインループ用の親クラス
class SCENE
{
public:
    virtual void init(void) = 0;
    virtual void update(int GameTime) = 0;
    virtual void draw(int GameTime) = 0;
    virtual void end(void) = 0;
};

class TITLE :public SCENE
{
public:
    void init(void);
    void update(int GameTime);
    void draw(int GameTime);
    void end(void);
private:

};

class CHOICE :public SCENE
{
public:
    void init(void);
    void update(int GameTime);
    void draw(int GameTime);
    void end(void);
private:

};

class GAME :public SCENE
{
public:
    void init(void);
    void update(int GameTime);
    void draw(int GameTime);
    void end(void);
private:

};