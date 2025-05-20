#pragma once
#include "GameObject.h"

#define TAIL_SPEED 0.2f
class CTailHitBox : public CGameObject
{

	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithPrizeBlock(LPCOLLISIONEVENT e);
	void OnCollisionWithBrick(LPCOLLISIONEVENT e);
	void OnCollisionWithKoopa(LPCOLLISIONEVENT e);
	void OnCollisionWithPiranhaPlant(LPCOLLISIONEVENT e);

public:
	CTailHitBox(float x, float y) :CGameObject(x, y) { this->vx = TAIL_SPEED; };
	
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);

	int IsCollidable() { return 1; };
	int IsBlocking() { return 0; }
	void OnNoCollision(DWORD dt);

	void OnCollisionWith(LPCOLLISIONEVENT e);
};

