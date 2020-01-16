#pragma once
#include "map.h"
#include "player.h"
#include "system.h"
#include "scene_game.h"

#define	ABSOLUTE_SCROLL_DESTINATION_L		(400)
#define	ABSOLUTE_SCROLL_DESTINATION_R		(SCREEN_WIDTH - 400)

class Scroll
{
public:
	Scroll(const Scroll&) = delete;
	Scroll& operator=(const Scroll&) = delete;
	Scroll(Scroll&&) = delete;
	Scroll& operator=(Scroll&&) = delete;

	static Scroll& get_instance()
	{
		static Scroll instance;
		return instance;
	}

	void init();
	void update(Player* player, MapData* map, Game_Bg* bg);

	void updateRelPosX(Player* player,MapData* map,Game_Bg* bg);
	void updateRelPosY(Player* player, MapData* map, Game_Bg* bg);

	float getScrollAmountX() { return scroll_amountX; }
	float getScrollAmountY() { return scroll_amountY; }
	void setScrollAmountX(float a) { scroll_amountX = a; }
	void setScrollAmountY(float a) { scroll_amountY = a; }

	void debugScroll();

private:
	Scroll() = default;
	~Scroll() = default;
	float scroll_amountX;
	float scroll_amountY;
};