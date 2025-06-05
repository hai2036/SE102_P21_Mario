#pragma once
#include "AssetIDs.h"
#include "GameObject.h"

#define PIRANHACLAMP_RISE_TIME 300
#define PIRANHACLAMP_RISE_COOLDOWN 2000

#define PIRANHACLAMP_BBOX_WIDTH UNIT_SIZE
#define PIRANHACLAMP_BBOX_HEIGHT (UNIT_SIZE * 1.5)

class CPiranhaClamp : public CGameObject
{
protected:
	float y0, y1;

	bool isHostile;
	bool isRising;
	bool isOutside;
	ULONGLONG rise_start;
	ULONGLONG cooldown_start;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CPiranhaClamp(float x, float y);
	bool GetIsHostile() { return isHostile; }
	virtual void Damage();
};