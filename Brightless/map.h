#pragma once
// インクルード ---------------------------------------------
#include "light.h"
#include "player.h"

// 定数 ----------------------------------------------------
#define		MAPCHIP_H_MAX		(60)
#define		MAPCHIP_V_MAX		(34)
#define		SCREEN_CHIP_H_MAX	(30)
#define		SCREEN_CHIP_V_MAX	(17)
#define		MAPCHIP_SIZE		(64)

// クラス宣言 ----------------------------------------------
class MapData : public Sprite
{
public:
    void	init();
    void	update(Light* light, Player* obj);
    void	draw();

    float	calRelative();
    void	collMapChipWithPlayer(Player* obj);
    void    collMapChipWithLight(Light* light);
    void	drawMapChip();
private:
};

// プロトタイプ宣言 -----------------------------------------