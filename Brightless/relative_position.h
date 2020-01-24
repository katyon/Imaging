#pragma once
#include "map.h"
#include "player.h"
#include "system.h"
#include "scene_game.h"

#define	ABSOLUTE_SCROLL_DESTINATION_L		(400)
#define	ABSOLUTE_SCROLL_DESTINATION_R		(SCREEN_WIDTH - 400)
#define ABSOLUTE_SCROLL_DESTINATION_V		(660)

class Scroll
{
public:
	Scroll(const Scroll&) = delete;
	Scroll& operator=(const Scroll&) = delete;
	Scroll(Scroll&&) = delete;
	Scroll& operator=(Scroll&&) = delete;

	static Scroll& getInstance()
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

	float getScrollSpeedX() { return scroll_speed_x; }
	float getScrollSpeedY() { return scroll_speed_y; }
	void setScrollSpeedX(float s) { scroll_speed_x = s; }
	void setScrollSpeedY(float s) { scroll_speed_y = s; }

	float getScrollDestPosX() { return scroll_dest_posX; }
	void setScrollDestPosX(float d) { scroll_dest_posX = d; }
	float getScrollDestPosY() { return scroll_dest_posY; }
	void setScrollDestPosY(float d) { scroll_dest_posY = d; }

	void autoScroll(Player* player);

	void debugScroll();

private:
	Scroll() = default;
	~Scroll() = default;
	float scroll_amountX;
	float scroll_amountY;

	float scroll_speed_x;
	float scroll_speed_y;

	float scroll_dest_posX;
	float scroll_dest_posY;
};