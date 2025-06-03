#pragma once
#include "GameObject.h"
#include "AssetIDs.h"
#include "Mario.h"
#include "LifeMushroom.h"
#include "Game.h"
#define ID_ANI_SWITCH_BLOCK 21000	
#define ID_ANI_SWITCH_BLOCK_PRESSED	21001

#define SWITCH_BLOCK_STATE_NORMAL	1
#define SWITCH_BLOCK_STATE_PRESSED	2

#define  SWITCH_BLOCK_AOE_WIDTH	5*UNIT_SIZE	
#define	 SWITCH_BLOCK_AOE_HEIGHT	5*UNIT_SIZE	

#define SWITCH_TIME_OUT	10000

class CSwitchBlock : public CGameObject {
	float width;	// area of affect
	float height;
	ULONGLONG timer;

	void Switch();
public:
	CSwitchBlock(float x, float y) : CGameObject(x, y)
	{
		this->state = SWITCH_BLOCK_STATE_NORMAL;
		this->width = SWITCH_BLOCK_AOE_WIDTH;
		this->height = SWITCH_BLOCK_AOE_HEIGHT;
		this->timer = -1;
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	void SetState(int state);
};
