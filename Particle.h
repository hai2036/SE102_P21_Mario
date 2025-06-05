#pragma once
#include "AssetIDs.h"
#include "GameObject.h"

class CParticle : public CGameObject
{
protected:
	float x0, y0, x1, y1;
	int aniId;
	int duration;

	ULONGLONG timer;
public:
	CParticle(float x, float y, int aniId, float xx = 0, float yy = 0);
	virtual void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom) {}
};
