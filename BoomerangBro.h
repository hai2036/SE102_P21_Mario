#pragma once
#include "AssetIDs.h"
#include "GameObject.h"

#define BOOMERANGBRO_GRAVITY 0.0008f
#define BOOMERANGBRO_WALK_SPEED 0.03f
#define BOOMERANGBRO_JUMP_SPEED 0.03f

#define BOOMERANGBRO_BBOX_WIDTH 14
#define BOOMERANGBRO_BBOX_HEIGHT 22

#define BOOMERANGBRO_DIE_TIMEOUT 500
#define BOOMERANGBRO_MOVE_TIMEOUT 1000

#define BOOMERANGBRO_STATE_DIE 100
#define BOOMERANGBRO_STATE_WALK 200

class CBoomerangBro : public CGameObject
{
protected:
	float ax;
	float ay;

	bool isReady;
	bool isMoving;
	bool isForward;

	ULONGLONG moving_start;
	ULONGLONG die_start;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return state != BOOMERANGBRO_STATE_DIE; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CBoomerangBro(float x, float y);
	virtual void SetState(int state);
};