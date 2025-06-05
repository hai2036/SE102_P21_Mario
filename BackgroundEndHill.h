#pragma once
#pragma once
#include "AssetIDs.h"
#include "GameObject.h"

const

class CBackgroundEndHill : public CGameObject
{
protected:
	int height;
	bool leftOutline;
	bool rightOutline;

	virtual void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b) {};
public:
	CBackgroundEndHill(float x, float y, int height, bool leftOutline, bool rightOutline) : CGameObject(x, y)
	{
		this->height = height;
		this->leftOutline = leftOutline;
		this->rightOutline = rightOutline;
	}
};