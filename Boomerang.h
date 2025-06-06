#pragma once
#include "AssetIDs.h"
#include "GameObject.h"
#include "Fireball.h"

#define BOOMERANG_BBOX_SIZE UNIT_SIZE

#define BOOMERANG_SPEED_X 0.24f
#define BOOMERANG_SPEED_Y 0.24f

#define BOOMERANG_GRAVITY_X -0.0003f
#define BOOMERANG_GRAVITY_Y 0.00008f

#define BOOMERANG_DELETE_TIME 3000

class CBoomerang : public CFireball
{
protected:
	float ax;
	float ay;

	float y0;

	bool isHostile;
	bool returning = false;

	ULONGLONG flight_start;
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