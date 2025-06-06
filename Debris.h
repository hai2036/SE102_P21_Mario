#pragma once
#include "GameObject.h"

#define DEBRIS_GRAVITY 0.001f
#define DEBRIS_LAUNCH_SPEED 0.3f

class CDebris : public CGameObject
{
protected:
	float ax, ay;

	int aniId;
	int duration;

	ULONGLONG timer;
public:
	CDebris(float x, float y, float dx, float dy, int aniId, int duration = 0);
	virtual void Render();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom) {}
};