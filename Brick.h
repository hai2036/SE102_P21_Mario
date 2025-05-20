#pragma once

#include "GameObject.h"
#include "AssetIDs.h"
#include "Mario.h"
#include "LifeMushroom.h"
#include "Game.h"
#define ID_ANI_BRICK 10000
#define ID_ANI_BRICK_EMPTY	10001
#define ID_ANI_BRICK_BREAK	10001

#define BRICK_STATE_NORMAL	1
#define BRICK_STATE_HIT		2
#define BRICK_STATE_BREAK	3
#define BRICK_STATE_EMPTY	4

#define BRICK_BREAKING_TIMEOUT	1000

class CBrick : public CGameObject {
	LPGAMEOBJECT prize;
	int prizeID;
	ULONGLONG breaking_start;
public:
	CBrick(float x, float y, int prizeID) : CGameObject(x, y) 
	{
		this->prize = nullptr;
		this->prizeID = prizeID;
		this->state = BRICK_STATE_NORMAL;
		breaking_start = -1;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);

	void SetState(int state);
};