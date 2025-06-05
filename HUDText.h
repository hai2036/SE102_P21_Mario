#pragma once
#include "AssetIDs.h"
#include "GameObject.h"
#include "string.h"


#define HUD_TEXT_WIDTH 8
#define HUD_TEXT_HEIGHT 8

class HUDText : public CGameObject
{
	int charCount;
	vector<int> list;
	BOOLEAN fillUp; // fill up empty with 0
public:
	HUDText(float x, float y, int charCount, BOOLEAN fillup);
	virtual int IsCollidable() { return 0; };
	virtual int IsBlocking() { return 0; }
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom) {};
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	void SetPosition(float x, float y);
	void SetValue(int value);
};

