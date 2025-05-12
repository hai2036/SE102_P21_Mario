#pragma once
#include "Coin.h"
#include "Game.h"
#include "Mario.h"
#define COIN_RISE_UP_SPEED -0.2f
#define	COIN_RISE_UP_HEIGHT 80

#define COIN_STATE_RISE_UP 1
#define COIN_STATE_FALL_DOWN 2
class CPrizeCoin : public CCoin
{
	float old_y;
public:
	CPrizeCoin(float x, float y) : CCoin(x, y) 
	{
		this->vy = COIN_RISE_UP_SPEED;
		this->old_y = y;
		this->state = COIN_STATE_RISE_UP;
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b) {};
	int IsBlocking() { return 0; }
};

