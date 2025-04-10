#include "Blocks.h"

#include "Sprite.h"
#include "Sprites.h"

#include "Textures.h"
#include "Game.h"

void CBlocks::Render()
{
	if (this->length <= 0) return;
	float xx = x;
	CSprites* s = CSprites::GetInstance();

	for (int i = 0; i < this->length; i++)
	{
		s->Get(this->spriteId)->Draw(xx, y);
		xx += UNIT_SIZE;
	}

	//RenderBoundingBox();
}

void CBlocks::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - UNIT_SIZE / 2;
	t = y - UNIT_SIZE / 2;
	r = l + UNIT_SIZE * this->length;
	b = t + UNIT_SIZE;
}

