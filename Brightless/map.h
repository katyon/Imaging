#pragma once
// �C���N���[�h ---------------------------------------------
#include "common.h"
#include "Player.h"

// �萔 ----------------------------------------------------
#define		MAPCHIP_H_MAX		(60)
#define		MAPCHIP_V_MAX		(34)
#define		SCREEN_CHIP_H_MAX	(30)
#define		SCREEN_CHIP_V_MAX	(17)
#define		MAPCHIP_SIZE		(64)

// �N���X�錾 ----------------------------------------------
class MapData : public Sprite
{
public:
	void	init();
	void	update(Player* obj);
	void	draw();

	float	calRelative();
	void	collMapChipWithPlayer(Player* obj);
	void	drawMapChip();
private:
};

// �v���g�^�C�v�錾 -----------------------------------------