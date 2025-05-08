#pragma once
#include "GameObject.h"
class CTailHitBox : public CGameObject
{

	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithPrizeBlock(LPCOLLISIONEVENT e);

public:
	CTailHitBox(float x, float y) :CGameObject(x, y) {};
	
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);

	int IsCollidable() { return 1; };
	int IsBlocking() { return 0; }
	void OnNoCollision(DWORD dt);

	void OnCollisionWith(LPCOLLISIONEVENT e);
};

