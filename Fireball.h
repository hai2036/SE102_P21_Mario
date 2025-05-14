#pragma once
#include "AssetIDs.h"
#include "GameObject.h"

#define FIREBALL_BBOX_SIZE 8
#define FIREBALL_SPEED 0.05f
#define FIREBALL_DELETE_TIME 3000

class CFireball : public CGameObject
{
protected:
	bool isHostile;
	ULONGLONG delete_start;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 0; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CFireball(float x, float y);
	void SetIsHostile(bool isHostile) { this->isHostile = isHostile; }
	bool GetIsHostile() { return isHostile; }
};