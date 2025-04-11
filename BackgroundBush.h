#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define UNIT_SIZE 16

#define ID_SPRITE_BACKGROUND_BUSH 1010000

class CBackgroundBush : public CGameObject {
	int length;
public:
	CBackgroundBush(float x, float y, int length) : CGameObject(x, y)
	{
		this->length = length;
	}
	void Render();
	void Update(DWORD dt) {};
	void GetBoundingBox(float& l, float& t, float& r, float& b) {};
};