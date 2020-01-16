#include "relative_position.h"
#include "input.h"

void Scroll::init()
{
	Scroll::get_instance().setScrollAmountX(0);
	Scroll::get_instance().setScrollAmountY(0);
}

void Scroll::update(Player* player,MapData* map,Game_Bg* bg)
{
	Scroll::updateRelPosX(player, map, bg);
	Scroll::updateRelPosY(player, map, bg);
	Scroll::debugScroll();
}

void Scroll::updateRelPosX(Player* player, MapData* map, Game_Bg* bg)
{
	player->setRelPosX(player->getPosX() + Scroll::get_instance().getScrollAmountX());
	map->setRelPosX(map->getPosX() + Scroll::get_instance().getScrollAmountX());
	bg->setRelPosX(bg->getPosX() + Scroll::get_instance().getScrollAmountX());
}

void Scroll::updateRelPosY(Player* player, MapData* map, Game_Bg* bg)
{
	player->setRelPosY(player->getPosY() + Scroll::get_instance().getScrollAmountY());
	map->setRelPosY(map->getPosY() + Scroll::get_instance().getScrollAmountY());
	bg->setRelPosY(bg->getPosY() + Scroll::get_instance().getScrollAmountY());
}

void Scroll::debugScroll()
{
	if (Input::GetInstance()->GetKey(KEY_INPUT_D)) { Scroll::get_instance().setScrollAmountX(Scroll::get_instance().getScrollAmountX() + 5); }
	if (Input::GetInstance()->GetKey(KEY_INPUT_S)) { Scroll::get_instance().setScrollAmountY(Scroll::get_instance().getScrollAmountY() + 5); }

	if (Input::GetInstance()->GetKey(KEY_INPUT_A)) { Scroll::get_instance().setScrollAmountX(Scroll::get_instance().getScrollAmountX() - 5); }
	if (Input::GetInstance()->GetKey(KEY_INPUT_W)) { Scroll::get_instance().setScrollAmountY(Scroll::get_instance().getScrollAmountY() - 5); }

	if (Input::GetInstance()->GetKey(KEY_INPUT_R)) { Scroll::get_instance().setScrollAmountX(0); }
	if (Input::GetInstance()->GetKey(KEY_INPUT_R)) { Scroll::get_instance().setScrollAmountY(0); }
}