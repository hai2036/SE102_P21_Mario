#include "Blocks.h"

#include "Sprite.h"
#include "Sprites.h"

#include "Textures.h"
#include "Game.h"

void CBlocks::Render()
{
	if (this->length <= 0) return;
	CSprites* s = CSprites::GetInstance();

	float xx = 0;
	float yy = 0;
	for (int i = 0; i < this->height; i++)
	{
		yy = y + UNIT_SIZE * i;
		for (int k = 0; k < this->length; k++)
		{
			xx = x + UNIT_SIZE * k;
			s->Get(this->spriteId)->Draw(xx, yy);
		}
	}
	//RenderBoundingBox();
}

void CBlocks::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - UNIT_SIZE / 2;
	t = y - UNIT_SIZE / 2;
	r = l + UNIT_SIZE * this->length;
	b = t + UNIT_SIZE* this->height;
}

