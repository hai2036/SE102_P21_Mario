#pragma once
#include "GameObject.h"

// 
// The most popular type of object in Mario! 
// 
#define UNIT_SIZE 16

class CBlocks : public CGameObject
{
protected:
	int length;				// Unit: cell 
	int spriteId;

public:
	CBlocks(float x, float y, int length, int sprite_id) :CGameObject(x, y)
	{
		this->length = length;
		this->spriteId = sprite_id;
	}

	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);

};

typedef CBlocks* LPBLOCKS;

