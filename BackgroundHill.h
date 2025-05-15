#pragma once
#include "AssetIDs.h"
#include "GameObject.h"

class CBackgroundHill : public CGameObject
{
protected:
	int type;

	virtual void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b) {};
public:
	CBackgroundHill(float x, float y, int type) : CGameObject(x, y)
	{
		this->type = type;
	}
};