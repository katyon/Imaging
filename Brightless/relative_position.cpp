#include "relative_position.h"
#include "input.h"

void Scroll::init()
{
	Scroll::getInstance().setScrollAmountX(0);
	Scroll::getInstance().setScrollAmountY(0);
}

void Scroll::update(Player* player,MapData* map,Game_Bg* bg)
{
	Scroll::updateRelPosX(player, map, bg);
	Scroll::updateRelPosY(player, map, bg);
	Scroll::debugScroll();
	Scroll::autoScroll(player);
}

void Scroll::updateRelPosX(Player* player, MapData* map, Game_Bg* bg)
{
	player->setRelPosX(player->getPosX() + Scroll::getInstance().getScrollAmountX());
	map->setRelPosX(map->getPosX() + Scroll::getInstance().getScrollAmountX());
	bg->setRelPosX(bg->getPosX() + Scroll::getInstance().getScrollAmountX());
}

void Scroll::updateRelPosY(Player* player, MapData* map, Game_Bg* bg)
{
	player->setRelPosY(player->getPosY() + Scroll::getInstance().getScrollAmountY());
	map->setRelPosY(map->getPosY() + Scroll::getInstance().getScrollAmountY());
	bg->setRelPosY(bg->getPosY() + Scroll::getInstance().getScrollAmountY());
}

void Scroll::debugScroll()
{
	if (Input::GetInstance()->GetKey(KEY_INPUT_D)) { Scroll::getInstance().setScrollAmountX(Scroll::getInstance().getScrollAmountX() + 5); }
	if (Input::GetInstance()->GetKey(KEY_INPUT_S)) { Scroll::getInstance().setScrollAmountY(Scroll::getInstance().getScrollAmountY() + 5); }

	if (Input::GetInstance()->GetKey(KEY_INPUT_A)) { Scroll::getInstance().setScrollAmountX(Scroll::getInstance().getScrollAmountX() - 5); }
	if (Input::GetInstance()->GetKey(KEY_INPUT_W)) { Scroll::getInstance().setScrollAmountY(Scroll::getInstance().getScrollAmountY() - 5); }

	if (Input::GetInstance()->GetKey(KEY_INPUT_R)) { Scroll::getInstance().setScrollAmountX(0); }
	if (Input::GetInstance()->GetKey(KEY_INPUT_R)) { Scroll::getInstance().setScrollAmountY(0); }
}

void Scroll:: autoScroll(Player* player)
{
	//プレイヤーが右向きのときのスクロール目標地点設定
	if (!player->getFlip())
	{
		Scroll::getInstance().setScrollDestPosX(ABSOLUTE_SCROLL_DESTINATION_L);
	}
	//プレイヤーが左向きのときのスクロール目標地点設定
	if (player->getFlip())
	{
		Scroll::getInstance().setScrollDestPosX(ABSOLUTE_SCROLL_DESTINATION_R);
	}
	//縦方向のスクロール目標地点設定
	Scroll::getInstance().setScrollDestPosY(ABSOLUTE_SCROLL_DESTINATION_V);

	////////// 横 //////////
	//スクロールスピードの設定
	Scroll::getInstance().setScrollSpeedX(((Scroll::getScrollDestPosX() - player->getRelPosX()) / 100) * 3);
	//スクロールの実行
	Scroll::getInstance().setScrollAmountX(Scroll::getInstance().getScrollAmountX() + Scroll::getInstance().getScrollSpeedX());

	////////// 縦 //////////
	//スクロールスピードの設定
	Scroll::getInstance().setScrollSpeedY(((Scroll::getScrollDestPosY() - player->getRelPosY()) / 80) * 2);
	//スクロールの実行
	Scroll::getInstance().setScrollAmountY(Scroll::getInstance().getScrollAmountY() + Scroll::getInstance().getScrollSpeedY());

	//スクロール限界地点の補正処理
	//画面左端
	if (Scroll::getInstance().getScrollAmountX() > 0)
	{
		Scroll::getInstance().setScrollAmountX(0);
	}
	//画面右端
	if (Scroll::getInstance().getScrollAmountX() < (-(MAPCHIP_H_MAX- SCREEN_CHIP_H_MAX)*MAPCHIP_SIZE) )
	{
		Scroll::getInstance().setScrollAmountX(-(MAPCHIP_H_MAX - SCREEN_CHIP_H_MAX) * MAPCHIP_SIZE);
	}
	//画面上端
	if (Scroll::getInstance().getScrollAmountY() > 0)
	{
		Scroll::getInstance().setScrollAmountY(0);
	}
	//画面下端
	if (Scroll::getInstance().getScrollAmountY() < (-(MAPCHIP_V_MAX - SCREEN_CHIP_V_MAX) * MAPCHIP_SIZE))
	{
		Scroll::getInstance().setScrollAmountY(-(MAPCHIP_V_MAX - SCREEN_CHIP_V_MAX) * MAPCHIP_SIZE);
	}
}