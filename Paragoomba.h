#pragma once
#include "AssetIDs.h"
#include "Goomba.h"

#define PARAGOOMBA_FLY_SPEED 0.25f
#define PARAGOOMBA_BOUNCE_SPEED 0.1f

#define PARAGOOMBA_STATE_WING 300
#define PARAGOOMBA_STATE_FOOT 200
#define PARAGOOMBA_STATE_DIE 100

#define PARAGOOMBA_FLY_COOLDOWN 1500
#define PARAGOOMBA_BOUNCE_THRESHOLD 3

class CParagoomba : public CGoomba
{
protected:
	ULONGLONG walk_start;

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
	bool HasWing() { return state == PARAGOOMBA_STATE_WING; }
};