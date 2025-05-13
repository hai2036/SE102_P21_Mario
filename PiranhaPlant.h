#pragma once
#include "AssetIDs.h"
#include "GameObject.h"

#define PIRANHAPLANT_RISE_TIME 1000

#define PIRANHAPLANT_BBOX_WIDTH UNIT_SIZE
#define PIRANHAPLANT_BBOX_HEIGHT UNIT_SIZE * 2

class CPiranhaPlant : public CGameObject
{
protected:
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 1; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CPiranhaPlant(float x, float y);
	virtual void Damage();
};