#pragma once
#include "AssetIDs.h"
#include "GameObject.h"

#define PIRANHAPLANT_RISE_TIME 1000
#define PIRANHAPLANT_RISE_COOLDOWN 3000

#define PIRANHAPLANT_BBOX_WIDTH UNIT_SIZE
#define PIRANHAPLANT_BBOX_HEIGHT UNIT_SIZE * 2

#define PIRANHAPLANT_LOOK_DIRECTION_UP_LEFT 1
#define PIRANHAPLANT_LOOK_DIRECTION_UP_RIGHT 2
#define PIRANHAPLANT_LOOK_DIRECTION_DOWN_LEFT 3
#define PIRANHAPLANT_LOOK_DIRECTION_DOWN_RIGHT 4

class CPiranhaPlant : public CGameObject
{
protected:
	float y0, y1;

	bool isHostile;
	bool isRising;
	bool isOutside;
	ULONGLONG rise_start;
	ULONGLONG cooldown_start;

	int lookDirection;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CPiranhaPlant(float x, float y);
	bool GetIsHostile() { return isHostile; }
	virtual void Damage();
};