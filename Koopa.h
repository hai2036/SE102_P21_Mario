#pragma once
#include "GameObject.h"

#define KOOPA_GRAVITY 0.002f
#define KOOPA_WALKING_SPEED 0.05f
#define KOOPA_SPINNING_SPEED 0.2f

#define KOOPA_BBOX_WIDTH 16
#define KOOPA_BBOX_HEIGHT 27
#define KOOPA_BBOX_HEIGHT_DIE 8

#define KOOPA_DIE_TIMEOUT 500
#define KOOPA_HIDE_TIMEOUT 5000
#define KOOPA_WAKE_UP_TIMEOUT 200

#define KOOPA_STATE_WALKING 100
#define KOOPA_STATE_DIE 200
#define KOOPA_STATE_HIDE 300
#define KOOPA_STATE_WAKE_UP 400
#define KOOPA_STATE_KICKED 500

#define ID_ANI_KOOPA_WALKING_LEFT 6000
#define ID_ANI_KOOPA_WALKING_RIGHT 6001
#define ID_ANI_KOOPA_DIE 6002
#define ID_ANI_KOOPA_HIDE 6003
#define ID_ANI_KOOPA_WAKE_UP 6003


class CKoopa : public CGameObject
{

	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithPrizeBlock(LPCOLLISIONEVENT e);
	void OnCollisionWithKoopa(LPCOLLISIONEVENT e);
protected:
	float ax;
	float ay;

	ULONGLONG die_start;
	ULONGLONG hide_start;
	ULONGLONG wake_up_start;


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
};
