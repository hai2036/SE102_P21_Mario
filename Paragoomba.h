#pragma once
#include "AssetIDs.h"
#include "Goomba.h"

#define PARAGOOMBA_FLY_SPEED 0.25f
#define PARAGOOMBA_BOUNCE_SPEED 0.08f

#define PARAGOOMBA_STATE_WING 300


#define PARAGOOMBA_UNHOSTILE_COOLDOWN 17
#define PARAGOOMBA_FLY_COOLDOWN 1500
#define PARAGOOMBA_BOUNCE_THRESHOLD 3

#define PARAGOOMBA_SPRITE_OFFSET_WING_WALK_Y 2.0f
#define PARAGOOMBA_SPRITE_OFFSET_WING_FLY_Y 4.0f

class CParagoomba : public CGoomba
{
protected:
	ULONGLONG walk_start;
	ULONGLONG unhostile_start;

	bool isHostile;
	bool isOnPlatform;
	int bounceCount;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CParagoomba(float x, float y);
	virtual void SetState(int state);
	bool GetIsHostile() { return isHostile; }
};