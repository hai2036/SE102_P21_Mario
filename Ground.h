#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"


class CGround : public CGameObject {
	int ground_width;
	int ground_height;
	int ground_spriteID;
public:
	CGround(float x, float y, int ground_width, int ground_height, int ground_spriteID) : CGameObject(x, y) {
		this->ground_width = ground_width;
		this->ground_height = ground_height;
		this->ground_spriteID = ground_spriteID;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};
