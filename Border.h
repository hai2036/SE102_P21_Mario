#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

class CBorder : public CGameObject {
	int width;
	int height;
	int type;	// Border type | 0: blocking border ( this border only block player) | 1: death border (if player touch this border, player will die)
public:
	CBorder(float x, float y, int width, int height, int type) : CGameObject(x, y) {
		this->width = width;
		this->height = height;
		this->type = type;
	}
	int GetType() { return this->type; };
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};

