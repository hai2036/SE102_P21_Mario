#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define BRICK_WIDTH 16

#define GROUND_TILE_SIZE 16

#define	ID_SPRITE_GROUND1	60001
#define	ID_SPRITE_GROUND2	60002
#define	ID_SPRITE_GROUND3	60003
#define	ID_SPRITE_GROUND4	60004
#define	ID_SPRITE_GROUND5	60005
#define	ID_SPRITE_GROUND6	60006
#define	ID_SPRITE_GROUND7	60007
#define	ID_SPRITE_GROUND8	60008
#define	ID_SPRITE_GROUND9	60009


class CGround : public CGameObject {
	int ground_width;
	int ground_height;
public:
	CGround(float x, float y, int ground_width, int ground_height) : CGameObject(x, y) {
		this->ground_width = ground_width;
		this->ground_height = ground_height;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};
