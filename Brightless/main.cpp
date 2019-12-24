#include "main.h"
#include "DxLib.h"

#include "common.h"

//////////////////////////////////////////////////////////////////////////
//	各ゲームで使用するクラスインスタンスやグローバル変数はここに記述
//
GAME_STATE  state;
TITLE       title;
CHOICE      choice;
GAME        game;

//
// 定義ここまで
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// ゲーム開始前処理
void AfterInit(void)
{
    state = Title;
}
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	ここからタイトルの処理
//

// タイトル初期化処理
void TITLE::init(void)
{

}

// タイトル更新処理
void TITLE::update(int GameTime)
{

}

// タイトル描画処理
void TITLE::draw(int GameTime)
{

}

// タイトル終了処理
void TITLE::end(void)
{

}

//
//	タイトルの処理ここまで
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	ここからステージ選択の処理
//

// ステージ選択初期化処理
void CHOICE::init(void)
{

}

// ステージ選択更新処理
void CHOICE::update(int GameTime)
{

}

// ステージ選択描画処理
void CHOICE::draw(int GameTime)
{

}

// ステージ選択終了処理
void CHOICE::end(void)
{

}

//
//	ステージ選択の処理ここまで
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	ここからゲームの処理
//

// ゲーム初期化処理
void GAME::init(void)
{

}

// ゲーム更新処理
void GAME::update(int GameTime)
{

}

// ゲーム描画処理
void GAME::draw(int GameTime)
{

}

// ゲーム終了処理
void GAME::end(void)
{

}

//
//	ゲームの処理ここまで
//////////////////////////////////////////////////////////////////////////

// DirectX初期化前処理
void BeforeInit(void)
{
	//int mbResult;
	int win_mode = TRUE;
	//
	//// フルスクリーンにするか選択する
	//mbResult = MessageBox(NULL, STR_MSG_ASKFS, STR_MSGTTL_ASKFS, MB_YESNO);
	//if (mbResult == IDYES) win_mode = FALSE;
	ChangeWindowMode(win_mode);
	// ウィンドウタイトルを設定する
	SetMainWindowText(STR_WINTTL);
}

// ゲームメインループ
void MainLoop(void)
{
	unsigned int gameTime = 0;			// グローバルゲームカウンタ

	while (ProcessMessage() == 0)		// ProcessMessageが正常に処理されている間はループ
	{
        ClearDrawScreen;				// 裏画面を削除

		switch (state)
		{
		case Title:
			title.update(gameTime);         // タイトル更新処理
			title.draw(gameTime);           // タイトル描画処理
			break;
        case Choice:
            choice.update(gameTime);        // ステージ選択更新処理
            choice.draw(gameTime);          // ステージ選択描画処理
            break;
		case Game:
			game.update(gameTime);          // ゲーム更新処理
			game.draw(gameTime);            // ゲーム描画処理
			break;
		}
        ScreenFlip();// VSYNCを待つ
		// ESCキーだけは常に監視。押されたら直ちに終了
		int stick = CheckHitKey(KEY_INPUT_ESCAPE);
		if (stick == 1) break;
		gameTime++;						// ゲームカウンタを進める
	}
}

// WinMain関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	BeforeInit();						// DirectX初期化前処理
	if (DxLib_Init() == -1) return -1;	// エラーが起きたら直ちに終了

	SetGraphMode(GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT, 32);
	SetDrawScreen(DX_SCREEN_BACK);		// 描画スクリーンを裏側に指定
	SetWaitVSyncFlag(TRUE);				// VSYNCを有効にする
	AfterInit();						// DirectX初期化後処理
	MainLoop();							// ゲーム本体(メインループ)
	DxLib_End();						// ＤＸライブラリ使用の終了処理
	return 0;							// ソフトの終了
}
