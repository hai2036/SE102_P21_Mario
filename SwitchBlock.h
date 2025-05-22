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


class CSwitchBlock : public CGameObject {
public:
	CSwitchBlock(float x, float y) : CGameObject(x, y)
	{
		this->state = SWITCH_BLOCK_STATE_NORMAL;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	void SetState(int state);
};
