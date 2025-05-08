#include "BackgroundBush.h"

void CBackgroundBush::Render()
{
	CSprites* sprites = CSprites::GetInstance();
	float xx = x;

	for (int i = 0; i < length; i++)
	{
		sprites->Get(ID_SPRITE_BACKGROUND_BUSH)->Draw(xx, y);
		xx += UNIT_SIZE;
	}
}