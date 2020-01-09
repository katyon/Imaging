#include "main.h"
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "scene_choice.h"
#include "scene_game.h"
#include "scene_title.h"
#include "system.h"

//////////////////////////////////////////////////////////////////////////
//	�e�Q�[���Ŏg�p����N���X�C���X�^���X��O���[�o���ϐ��͂����ɋL�q
//

Usable          usable;
System          sys;
Scene_Title     title;
Title_Bg        title_bg;
Title_Conduct   title_conduct;
Scene_Choice    choice;
Choice_Bg       choice_bg;
Choice_Conduct  choice_conduct;
Scene_Game      game;
Game_Bg         game_bg;
Game_Conduct    game_conduct;

Scene_State     state;

//
// ��`�����܂�
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	��������^�C�g���̏���
//

// �^�C�g������������
void Scene_Title::init(void)
{
    title_bg.init(&title_bg);
}

// �^�C�g���X�V����
void Scene_Title::update(int GameTime)
{
    title_bg.update(&title_bg);
    title_conduct.updateDebug(&title_conduct, &usable);     // debug
}

// �^�C�g���`�揈��
void Scene_Title::draw(int GameTime)
{
    title_bg.draw(&title_bg);
    sys.drawDebugString();      // debug
}

// �^�C�g���I������
void Scene_Title::end(void)
{
    title_bg.end(&title_bg);
}

//
//	�^�C�g���̏��������܂�
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	��������X�e�[�W�I���̏���
//

// �X�e�[�W�I������������
void Scene_Choice::init(void)
{
    choice_bg.init(&choice_bg);
}

// �X�e�[�W�I���X�V����
void Scene_Choice::update(int GameTime)
{
    choice_bg.update(&choice_bg);
    choice_conduct.updateDebug(&choice_conduct, &usable);   // debug
}

// �X�e�[�W�I��`�揈��
void Scene_Choice::draw(int GameTime)
{
    choice_bg.draw(&choice_bg);
    sys.drawDebugString();              // debug
}

// �X�e�[�W�I���I������
void Scene_Choice::end(void)
{
    choice_bg.end(&choice_bg);
}

//
//	�X�e�[�W�I���̏��������܂�
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	��������Q�[���̏���
//

// �Q�[������������
void Scene_Game::init(void)
{
    game_bg.init(&game_bg);
}

// �Q�[���X�V����
void Scene_Game::update(int GameTime)
{
    game_bg.update(&game_bg);
    game_conduct.updateDebug(&game_conduct, &usable);   // debug
}

// �Q�[���`�揈��
void Scene_Game::draw(int GameTime)
{
    game_bg.draw(&game_bg);
    sys.drawDebugString();      // debug
}

// �Q�[���I������
void Scene_Game::end(void)
{
    game_bg.end(&game_bg);
}

//
//	�Q�[���̏��������܂�
//////////////////////////////////////////////////////////////////////////

// DirectX�������O����
void Usable::BeforeInit(void)
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

// �Q�[���J�n�O����
void Usable::AfterInit(void)
{
    // InputClass
    Input::Create();
    Input::GetInstance()->Init();

    state = Title;
    title.init();
}

// �Q�[���I���㏈��
void Usable::End(void)
{
    // InputClass�̏I������
    Input::Destroy();
    // �S�O���t�B�b�N�̍폜
    DxLib::InitGraph();
    // �S���f�[�^�̍폜
    InitSoundMem();
}

// �V�[���J�ڏ���
void Usable::changeSceneStateInit(Scene_State next_num)
{
    // ���݂̃V�[���̏I������
    switch (state)
    {
    case Title:
        title.end();
        break;
    case Choice:
        choice.end();
        break;
    case Game:
        game.end();
        break;
    }

    // �V�[���J�ڎ��ɏ�����
    switch (next_num)
    {
    case Title:
        title.init();
        break;
    case Choice:
        choice.init();
        break;
    case Game:
        game.init();
        break;
    }

    state = next_num;
}

// �Q�[�����C�����[�v
void Usable::MainLoop(void)
{
    unsigned int gameTime = 0;			// �O���[�o���Q�[���J�E���^

    usable.AfterInit();    // �Q�[���J�n�O����

    while (ProcessMessage() == 0)		    // ProcessMessage������ɏ�������Ă���Ԃ̓��[�v
    {
        ClearDrawScreen();  				// ����ʂ��폜

        Input::GetInstance()->Updata();     // ���͏�Ԃ̍X�V����

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

        ScreenFlip();   // VSYNC��҂�

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
    usable.BeforeInit();                // DirectX�������O����
    if (DxLib_Init() == -1) return -1;  // �G���[���N�����璼���ɏI��

    SetGraphMode(GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT, 32);
    SetDrawScreen(DX_SCREEN_BACK);      // �`��X�N���[���𗠑��Ɏw��
    SetWaitVSyncFlag(TRUE);             // VSYNC��L���ɂ���
    usable.AfterInit();                 // DirectX�������㏈��
    usable.MainLoop();                  // �Q�[���{��(���C�����[�v)
    usable.End();                       // �Q�[���I���㏈��
    DxLib_End();                        // �c�w���C�u�����g�p�̏I������
    return 0;                           // �\�t�g�̏I��
}
