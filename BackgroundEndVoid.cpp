#include "BackgroundEndVoid.h"

void CBackgroundEndVoid::Render()
{
	CSprites* sprites = CSprites::GetInstance();

	float yy = y;

	for (int i = 0; i < height; i++)
	{
		sprites->Get(ID_SPRITE_BACKGROUND_END_VOID_EDGE)->Draw(x, yy);
		float xx = x + UNIT_SIZE;

		for (int j = 0; j < width; j++)
		{
			sprites->Get(ID_SPRITE_BACKGROUND_END_VOID_BODY)->Draw(xx, yy);
			xx += UNIT_SIZE;
		}

		yy += UNIT_SIZE;
	}
}