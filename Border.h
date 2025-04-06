#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

class CBorder : public CGameObject {
	int border_width;
	int border_height;
public:
	CBorder(float x, float y, int border_width=0, int border_height=0) : CGameObject(x, y) {
		this->border_width = border_width;
		this->border_height = border_height;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};

