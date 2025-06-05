#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

class CPipe	: public CGameObject {
	int height;
	bool isUpSideDown;
	int spriteID;
public:
	CPipe(float x, float y, int height, BOOLEAN isUpSideDown, int spriteID) : CGameObject(x, y)
	{
		this->height = height;
		this->isUpSideDown = isUpSideDown;
		this->spriteID = spriteID;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};

