#pragma once
#include "GameObject.h"
#include "AssetIDs.h"

#define MOVING_PLATFORM_LENGTH	3
#define MOVING_PLATFORM_SPEED	-0.05f
#define MOVING_PLATFORM_GRAVITY	0.00005f

#define MOVING_PLATFORM_STATE_DROP	2
#define MOVING_PLATFORM_STATE_NORMAL 0
#define MOVING_PLATFORM_STATE_DIE 1

class CMovingPlatform : public CGameObject
{
protected:
	float ay;				// acceleration on y 

	void OnCollisionWithBorder(LPCOLLISIONEVENT e);
public:
	CMovingPlatform(float x, float y) :CGameObject(x, y)
	{
		this->vx = MOVING_PLATFORM_SPEED;
		this->ay = 0;
		this->state = MOVING_PLATFORM_STATE_NORMAL;
	}
	
	void OnCollisionWith(LPCOLLISIONEVENT e);
	int IsCollidable() { return 1; };
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void SetState(int state);

};

