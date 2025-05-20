#pragma once
#include "GameObject.h"

#define ID_SPRITE_LIFE_MUSHROOM 200002
#define LIFE_MUSHROOM_GRAVITY 0.002f
#define LIFE_MUSHROOM_WALKING_SPEED 0.05f

#define LIFE_MUSHROOM_STATE_RISE_UP 2
#define LIFE_MUSHROOM_STATE_WALKING 1
#define LIFE_MUSHROOM_STATE_DIE 0

#define LIFE_MUSHROOM_RISE_UP_SPEED -0.02f

class CLifeMushroom : public CGameObject
{
protected:
	int dx;
	float ax;
	float ay;
	float old_y;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CLifeMushroom(float x, float y, int dx);
	virtual void SetState(int state);

};



