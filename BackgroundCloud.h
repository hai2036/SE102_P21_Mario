#pragma once

#include "AssetIDs.h"
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

class CBackgroundCloud : public CGameObject {
	int length;
public:
	CBackgroundCloud(float x, float y, int length) : CGameObject(x, y)
	{
		this->length = length;
	}
	void Render();
	void Update(DWORD dt) {};
	void GetBoundingBox(float& l, float& t, float& r, float& b) {};
};