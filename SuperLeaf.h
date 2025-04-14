#pragma once
#include "GameObject.h"

#define ID_SPRITE_SUPER_LEAF 210001


#define SUPER_LEAF_STATE_ALIVE 1
#define SUPER_LEAF_STATE_DIE 0

class CSuperLeaf : public CGameObject
{
	void OnCollisionWithMario(LPCOLLISIONEVENT e);
protected:

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


