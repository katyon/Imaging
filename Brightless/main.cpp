#include "main.h"
#include "DxLib.h"

//////////////////////////////////////////////////////////////////////////
//	�e�Q�[���Ŏg�p����N���X�C���X�^���X��O���[�o���ϐ��͂����ɋL�q
//
GAME_SCENE scene;

//
// ��`�����܂�
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	��������Q�[���̏���
//

// �Q�[���J�n�O����
void AfterInit(void)
{
	scene = Title;
}
//�^�C�g���X�V����
void UpdateTitle(int GameTime)
{

}

// �Q�[���`�揈��
void TitleDraw(int GameTime)
{

}

// �Q�[���X�V����
void UpdateGame(int GameTime)
{

}

// �Q�[���`�揈��
void GameDraw(int GameTime)
{

}

// �Q�[���I������
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
//	�Q�[���̏��������܂�
//////////////////////////////////////////////////////////////////////////

// DirectX�������O����
void BeforeInit(void)
{
	//int mbResult;
	int win_mode = TRUE;
	//
	//// �t���X�N���[���ɂ��邩�I������
	//mbResult = MessageBox(NULL, STR_MSG_ASKFS, STR_MSGTTL_ASKFS, MB_YESNO);
	//if (mbResult == IDYES) win_mode = FALSE;
	ChangeWindowMode(win_mode);
	// �E�B���h�E�^�C�g����ݒ肷��
	SetMainWindowText(STR_WINTTL);
}

// �Q�[�����C�����[�v
void MainLoop(void)
{
	unsigned int gameTime = 0;			// �O���[�o���Q�[���J�E���^

	while (ProcessMessage() == 0)		// ProcessMessage������ɏ�������Ă���Ԃ̓��[�v
	{
		switch (scene)
		{
		case Title:
			UpdateTitle(gameTime);			// �^�C�g���X�V����
			ClearDrawScreen;				// ����ʂ��폜
			TitleDraw(gameTime);			// �^�C�g���`�揈��
			ScreenFlip();					// VSYNC��҂�
			break;
		case Game:
			UpdateGame(gameTime);			// �Q�[���X�V����
			ClearDrawScreen;				// ����ʂ��폜
			GameDraw(gameTime);				// �Q�[���`�揈��
			ScreenFlip();					// VSYNC��҂�
			break;
		case Clear:
			UpdateClear(gameTime);			// �N���A��ʍX�V����
			ClearDrawScreen;				// ����ʂ��폜
			ScreenFlip();					// VSYNC��҂�
			break;
		case GameOver:
			UpdateGameOver(gameTime);		// �Q�[���I�[�o�[��ʍX�V����
			ClearDrawScreen;				// ����ʂ��폜
			ScreenFlip();					// VSYNC��҂�
			break;
		case Reset:
			ResetGame;
			ClearDrawScreen;				// ����ʂ��폜
			ScreenFlip();					// VSYNC��҂�
			break;
		}
		// ESC�L�[�����͏�ɊĎ��B�����ꂽ�璼���ɏI��
		int stick = CheckHitKey(KEY_INPUT_ESCAPE);
		if (stick == 1) break;
		gameTime++;						// �Q�[���J�E���^��i�߂�
	}
}

// WinMain�֐�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	BeforeInit();						// DirectX�������O����
	if (DxLib_Init() == -1) return -1;	// �G���[���N�����璼���ɏI��

	SetGraphMode(1920, 1080, 32);
	SetDrawScreen(DX_SCREEN_BACK);		// �`��X�N���[���𗠑��Ɏw��
	SetWaitVSyncFlag(TRUE);				// VSYNC��L���ɂ���
	AfterInit();						// DirectX�������㏈��
	MainLoop();							// �Q�[���{��(���C�����[�v)
	DxLib_End();						// �c�w���C�u�����g�p�̏I������
	return 0;							// �\�t�g�̏I��
}
