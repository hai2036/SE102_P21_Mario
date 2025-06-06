#pragma once

#include "AssetIDs.h"
#include "GameObject.h"

class CBackgroundBush : public CGameObject {
	int length;

	void Render();
	void Update(DWORD dt) {};
	void GetBoundingBox(float& l, float& t, float& r, float& b) {};
public:
	CBackgroundBush(float x, float y, int length) : CGameObject(x, y)
	{
		this->length = length;
	}
};