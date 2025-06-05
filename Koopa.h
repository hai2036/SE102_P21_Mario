#pragma once
#include "GameObject.h"

#define KOOPA_GRAVITY 0.001f
#define KOOPA_WALKING_SPEED 0.05f
#define KOOPA_SPINNING_SPEED 0.2f
#define TAIL_HIT_SPEED_X 0.1f
#define TAIL_HIT_SPEED_Y -0.4f

#define KOOPA_BBOX_WIDTH 16
#define KOOPA_BBOX_HEIGHT 27
#define KOOPA_BBOX_HEIGHT_DIE 8

#define KOOPA_DIE_TIMEOUT 500
#define KOOPA_HIDE_TIMEOUT 5000
#define KOOPA_WAKE_UP_TIMEOUT 2000
#define KOOPA_TAIL_HIT_TIMEOUT 500

#define KOOPA_STATE_WALKING 100
#define KOOPA_STATE_DIE 200
#define KOOPA_STATE_HIDE 300
#define KOOPA_STATE_WAKE_UP 400
#define KOOPA_STATE_KICKED 500
#define KOOPA_STATE_HOLDED 600
#define KOOPA_STATE_TAIL_HIT	700





class CKoopa : public CGameObject
{
protected:
	float ax;
	float ay;
	bool isUpSideDown;
	bool wing;

	ULONGLONG die_start;
	ULONGLONG hide_start;
	ULONGLONG wake_up_start;
	ULONGLONG tail_hit_start;

	virtual int GetAniID() { return -1; };

	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithPrizeBlock(LPCOLLISIONEVENT e);
	void OnCollisionWithBrick(LPCOLLISIONEVENT e);
	void OnCollisionWithKoopa(LPCOLLISIONEVENT e);
	void OnCollisionWithPiranhaPlant(LPCOLLISIONEVENT e);

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CKoopa(float x, float y);
	virtual void SetState(int state);
	bool IsWing() { return this->wing; };
	void Damage();
};
