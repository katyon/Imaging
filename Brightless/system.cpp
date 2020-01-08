// �C���N���[�h -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "main.h"
#include "system.h"

// �֐� ----------------------------------------------------------------------------------------

// �f�o�b�N������`��
void System::drawDebugString()
{
    cr = GetColor(255, 255, 255);

    DrawFormatString(10, 10, cr, "abcde");

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