#pragma once
#include "AssetIDs.h"
#include "GameObject.h"

#define SPEED_BAR_ARROW_COUNT 6

#define SPEED_BAR_ARROW_WIDTH 8
#define SPEED_BAR_DECREASE_TIMEOUT 500

class SpeedBar : public CGameObject
{
	ULONGLONG timer;
	int arrowFill;
public:
	SpeedBar(float x, float y);
	virtual int IsCollidable() { return 0; };
	virtual int IsBlocking() { return 0; }
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom) {};
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
	void SetPosition(float x, float y);

	void DecreaseStart();

};

