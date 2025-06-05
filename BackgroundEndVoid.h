#pragma once
#include "AssetIDs.h"
#include "GameObject.h"

const

class CBackgroundEndVoid : public CGameObject
{
protected:
	int width;
	int height;

	virtual void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b) {};
public:
	CBackgroundEndVoid(float x, float y, int width, int height) : CGameObject(x, y)
	{
		this->width = width;
		this->height = height;
	}
};