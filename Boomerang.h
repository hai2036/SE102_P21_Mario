#pragma once
#include "AssetIDs.h"
#include "GameObject.h"
#include "Fireball.h"

#define BOOMERANG_BBOX_SIZE UNIT_SIZE
#define BOOMERANG_SPEED 0.05f
#define BOOMERANG_DELETE_TIME 3000

class CBoomerang : public CFireball
{
protected:
	bool isHostile;
	ULONGLONG delete_start;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual void OnNoCollision(DWORD dt);

public:
	CBoomerang(float x, float y, float dx, float dy, bool isHostile);
	void SetIsHostile(bool isHostile) { this->isHostile = isHostile; }
	bool GetIsHostile() { return isHostile; }
};