#pragma once
#include "AssetIDs.h"
#include "GameObject.h"

class CParticle : public CGameObject
{
protected:
	ULONGLONG timer;
	int aniId;
public:
	CParticle(float x, float y, int aniId);
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& left, float& top, float& right, float& bottom) {}
};
