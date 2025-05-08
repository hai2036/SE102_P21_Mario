#pragma once
#include "GameObject.h"

#define ID_SPRITE_SUPER_MUSHROOM 200001
#define SUPER_MUSHROOM_GRAVITY 0.002f
#define SUPER_MUSHROOM_WALKING_SPEED 0.05f

#define SUPER_MUSHROOM_STATE_ALIVE 1
#define SUPER_MUSHROOM_STATE_DIE 0

class CSuperMushroom : public CGameObject
{
protected:
	int dx;
	float ax;
	float ay;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CSuperMushroom(float x, float y, int dx);
	virtual void SetState(int state);

};

