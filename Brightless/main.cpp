#include "main.h"
#include "DxLib.h"

//////////////////////////////////////////////////////////////////////////
//	各ゲームで使用するクラスインスタンスやグローバル変数はここに記述
//
GAME_SCENE scene;

//
// 定義ここまで
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	ここからゲームの処理
//

// ゲーム開始前処理
void AfterInit(void)
{
	scene = Title;
}
//タイトル更新処理
void UpdateTitle(int GameTime)
{

}

// ゲーム描画処理
void TitleDraw(int GameTime)
{

}

// ゲーム更新処理
void UpdateGame(int GameTime)
{

}

// ゲーム描画処理
void GameDraw(int GameTime)
{

}

// ゲーム終了処理
void ResetGame(void)
{

}

void UpdateClear(int GameTime)
{

}

void UpdateGameOver(int GameTime)
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
		switch (scene)
		{
		case Title:
			UpdateTitle(gameTime);			// タイトル更新処理
			ClearDrawScreen;				// 裏画面を削除
			TitleDraw(gameTime);			// タイトル描画処理
			ScreenFlip();					// VSYNCを待つ
			break;
		case Game:
			UpdateGame(gameTime);			// ゲーム更新処理
			ClearDrawScreen;				// 裏画面を削除
			GameDraw(gameTime);				// ゲーム描画処理
			ScreenFlip();					// VSYNCを待つ
			break;
		case Clear:
			UpdateClear(gameTime);			// クリア画面更新処理
			ClearDrawScreen;				// 裏画面を削除
			ScreenFlip();					// VSYNCを待つ
			break;
		case GameOver:
			UpdateGameOver(gameTime);		// ゲームオーバー画面更新処理
			ClearDrawScreen;				// 裏画面を削除
			ScreenFlip();					// VSYNCを待つ
			break;
		case Reset:
			ResetGame;
			ClearDrawScreen;				// 裏画面を削除
			ScreenFlip();					// VSYNCを待つ
			break;
		}
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

	SetGraphMode(1920, 1080, 32);
	SetDrawScreen(DX_SCREEN_BACK);		// 描画スクリーンを裏側に指定
	SetWaitVSyncFlag(TRUE);				// VSYNCを有効にする
	AfterInit();						// DirectX初期化後処理
	MainLoop();							// ゲーム本体(メインループ)
	DxLib_End();						// ＤＸライブラリ使用の終了処理
	return 0;							// ソフトの終了
}
