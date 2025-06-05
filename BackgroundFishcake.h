#pragma once

#include "AssetIDs.h"
#include "GameObject.h"

class CBackgroundFishcake : public CGameObject {
	bool isBig;

	void Render();
	void Update(DWORD dt) {};
	void GetBoundingBox(float& l, float& t, float& r, float& b) {};
public:
	CBackgroundFishcake(float x, float y, bool isBig) : CGameObject(x, y)
	{
		this->isBig = isBig;
	}
};