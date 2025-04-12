#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

class CPipe	: public CGameObject {
	int height;
public:
	CPipe(float x, float y, int height) : CGameObject(x, y) 
	{
		this->height = height;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};

