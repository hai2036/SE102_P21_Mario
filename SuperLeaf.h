#pragma once
#include "GameObject.h"

#define ID_SPRITE_SUPER_LEAF 210001


#define SUPER_LEAF_STATE_RISE_UP 2
#define SUPER_LEAF_STATE_FALL_DOWN 1
#define SUPER_LEAF_STATE_DIE 0

#define SUPER_LEAF_RISE_UP_SPEED -0.2f
#define SUPER_LEAF_FALL_DOWN_Y_SPEED 0.02f
#define SUPER_LEAF_FALL_DOWN_X_SPEED 0.075f

class CSuperLeaf : public CGameObject
{
protected:

	float old_y;
	float old_x;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CSuperLeaf(float x, float y);
	virtual void SetState(int state);

};


