// �C���N���[�h -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "system.h"

#include "input.h"

// �֐� ----------------------------------------------------------------------------------------
// �f�o�b�N������`��
void System::drawDebugString()
{
    cr = GetColor(255, 255, 255);

    if (Input::GetInstance()->GetKey(KEY_INPUT_1))
        DrawFormatString(10, 10, cr, "GetKey");
    if (Input::GetInstance()->GetKeyDown(KEY_INPUT_2))
        DrawFormatString(10, 30, cr, "GetKeyDown");
    if (Input::GetInstance()->GetKeyDownAll())
        DrawFormatString(10, 50, cr, "GetKeyDownAll");
    if (Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_A))
        DrawFormatString(10, 70, cr, "GetButtonDown");

    DrawFormatString(10, 90, cr, "KEY_INPUT_3:%d", Input::GetInstance()->GetKeyDebug(KEY_INPUT_3));
    DrawFormatString(10, 110, cr, "XINPUT_BUTTON_B:%d", Input::GetInstance()->GetButtonDebug(XINPUT_BUTTON_B));
}

// �V�[���J�ڏ���
void System::changeSceneStateInit(int state, Scene_State scene_num, Scene_Title* title, Scene_Choice* choice, Scene_Game* game)
{
    // ���݂̃V�[���̏I������
    switch (state)
    {
    case Title:
        title->end();
        break;
    case Choice:
        choice->end();
        break;
    case Game:
        game->end();
        break;
    }

    // �V�[���J�ڎ��ɏ�����
    switch (scene_num)
    {
    case Title:
        title->init();
        break;
    case Choice:
        choice->init();
        break;
    case Game:
        game->init();
        break;
    }

    state = scene_num;
}