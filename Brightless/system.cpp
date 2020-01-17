// �C���N���[�h -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "system.h"
#include "relative_position.h"
#include "input.h"

// �֐� ----------------------------------------------------------------------------------------
// �f�o�b�N������`��
void System::drawDebugString(Player* player)
{
    SetFontSize(25);
    cr = GetColor(0, 200, 200);


    DrawFormatString(0, 0, cr, "Title:1");
    DrawFormatString(0, 20, cr, "Choice:2");
    DrawFormatString(0, 40, cr, "Game:3");
    DrawFormatString(0, 60, cr, "�X�N���[���ړ���X:%f,Y:%f", Scroll::getInstance().getScrollAmountX(), Scroll::getInstance().getScrollAmountY());
    DrawFormatString(0, 80, cr, "�v���C���[���WX:%f,Y:%f", player->getPosX(), player->getPosY());
    DrawFormatString(0, 100, cr, "�v���C���[���΍��WX:%f,Y:%f", player->getRelPosX(), player->getRelPosY());
}