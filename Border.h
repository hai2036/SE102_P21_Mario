#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

class CBorder : public CGameObject {
	int border_width;
	int border_height;
	int type;	// Border type | 0: blocking border ( this border only block player) | 1: death border (if player touch this border, player will die)
public:
	CBorder(float x, float y, int border_width, int border_height, int type) : CGameObject(x, y) {
		this->border_width = border_width;
		this->border_height = border_height;
		this->type = type;
	}
	int GetType() { return this->type; };
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};

