// �C���N���[�h -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "system.h"

#include "input.h"

// �֐� ----------------------------------------------------------------------------------------
// �f�o�b�N������`��
void System::drawDebugString()
{
    cr = GetColor(255, 255, 255);

    DrawFormatString(0, 0, cr, "Title:1");
    DrawFormatString(0, 20, cr, "Choice:2");
    DrawFormatString(0, 40, cr, "Game:3");
}