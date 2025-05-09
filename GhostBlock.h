#pragma once
#include "GameObject.h"
#include "Koopa.h"

#define GHOST_BLOCK_WIDTH 4
#define GHOST_BLOCK_HEIGHT 16

class CGhostBlock : public CGameObject
{
	BOOLEAN isOnPlatform;
	float ay;
public:
	CGhostBlock(float x, float y) : CGameObject(x, y) 
	{
		ay = KOOPA_GRAVITY;
		isOnPlatform = false;
	};
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	
	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

	BOOLEAN IsOnPlatform() { return this->isOnPlatform; };

};

