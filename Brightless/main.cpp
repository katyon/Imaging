#include "main.h"
#include "DxLib.h"

#include "common.h"

//////////////////////////////////////////////////////////////////////////
//	�e�Q�[���Ŏg�p����N���X�C���X�^���X��O���[�o���ϐ��͂����ɋL�q
//
GAME_STATE  state;
TITLE       title;
CHOICE      choice;
GAME        game;

//
// ��`�����܂�
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// �Q�[���J�n�O����
void AfterInit(void)
{
    state = Title;
}
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	��������^�C�g���̏���
//

// �^�C�g������������
void TITLE::init(void)
{

}

// �^�C�g���X�V����
void TITLE::update(int GameTime)
{

}

// �^�C�g���`�揈��
void TITLE::draw(int GameTime)
{

}

// �^�C�g���I������
void TITLE::end(void)
{

}

//
//	�^�C�g���̏��������܂�
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	��������X�e�[�W�I���̏���
//

// �X�e�[�W�I������������
void CHOICE::init(void)
{

}

// �X�e�[�W�I���X�V����
void CHOICE::update(int GameTime)
{

}

// �X�e�[�W�I��`�揈��
void CHOICE::draw(int GameTime)
{

}

// �X�e�[�W�I���I������
void CHOICE::end(void)
{

}

//
//	�X�e�[�W�I���̏��������܂�
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	��������Q�[���̏���
//

// �Q�[������������
void GAME::init(void)
{

}

// �Q�[���X�V����
void GAME::update(int GameTime)
{

}

// �Q�[���`�揈��
void GAME::draw(int GameTime)
{

}

// �Q�[���I������
void GAME::end(void)
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
        ClearDrawScreen;				// ����ʂ��폜

		switch (state)
		{
		case Title:
			title.update(gameTime);         // �^�C�g���X�V����
			title.draw(gameTime);           // �^�C�g���`�揈��
			break;
        case Choice:
            choice.update(gameTime);        // �X�e�[�W�I���X�V����
            choice.draw(gameTime);          // �X�e�[�W�I��`�揈��
            break;
		case Game:
			game.update(gameTime);          // �Q�[���X�V����
			game.draw(gameTime);            // �Q�[���`�揈��
			break;
		}
        ScreenFlip();// VSYNC��҂�
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

	SetGraphMode(GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT, 32);
	SetDrawScreen(DX_SCREEN_BACK);		// �`��X�N���[���𗠑��Ɏw��
	SetWaitVSyncFlag(TRUE);				// VSYNC��L���ɂ���
	AfterInit();						// DirectX�������㏈��
	MainLoop();							// �Q�[���{��(���C�����[�v)
	DxLib_End();						// �c�w���C�u�����g�p�̏I������
	return 0;							// �\�t�g�̏I��
}
