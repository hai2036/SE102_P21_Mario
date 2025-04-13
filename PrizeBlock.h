#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#include "AssetIDs.h"


#define ID_ANI_PRIZE_BLOCK 20000
#define ID_SPRITE_EMPTY_PRIZE_BLOCK 100005

#define STATE_EMPTY	1
#define STATE_NORMAL	0

class CPrizeBlock : public CGameObject {
	LPGAMEOBJECT prize;
	int prizeID;
	void OnCollisionWithMario(LPCOLLISIONEVENT e);
public:
	CPrizeBlock(float x, float y, int prizeID) : CGameObject(x, y) 
	{
		this->state = STATE_NORMAL;
		this->prize = nullptr;
		this->prizeID = prizeID;
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsCollidable() { return 1; };
	void OnNoCollision(DWORD dt) {};

	void OnCollisionWith(LPCOLLISIONEVENT e);
};
