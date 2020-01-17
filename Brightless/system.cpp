// インクルード -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "system.h"
#include "relative_position.h"
#include "input.h"

// 関数 ----------------------------------------------------------------------------------------
// デバック文字を描画
void System::drawDebugString(Player* player)
{
    SetFontSize(25);
    cr = GetColor(0, 200, 200);


    DrawFormatString(0, 0, cr, "Title:1");
    DrawFormatString(0, 20, cr, "Choice:2");
    DrawFormatString(0, 40, cr, "Game:3");
    DrawFormatString(0, 60, cr, "スクロール移動量X:%f,Y:%f", Scroll::getInstance().getScrollAmountX(), Scroll::getInstance().getScrollAmountY());
    DrawFormatString(0, 80, cr, "プレイヤー座標X:%f,Y:%f", player->getPosX(), player->getPosY());
    DrawFormatString(0, 100, cr, "プレイヤー相対座標X:%f,Y:%f", player->getRelPosX(), player->getRelPosY());
}