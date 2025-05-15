#include "BackgroundHill.h"

void CBackgroundHill::Render()
{
	CSprites* sprites = CSprites::GetInstance();

	sprites->Get(ID_SPRITE_BACKGROUND_HILL_LEFT_CLIFF)->Draw(x, y);
	sprites->Get(ID_SPRITE_BACKGROUND_HILL_RIGHT_CLIFF)->Draw(x + UNIT_SIZE, y);

	float yy = y + UNIT_SIZE;

	for (int i = 0; i < height; i++)
	{
		if (leftOutline)
		{
			sprites->Get(ID_SPRITE_BACKGROUND_HILL_LEFT_EDGE)->Draw(x, yy);
		}
		else
		{
			sprites->Get(ID_SPRITE_BACKGROUND_HILL_BODY)->Draw(x, yy);
		}
		
		
		if (rightOutline)
		{
			sprites->Get(ID_SPRITE_BACKGROUND_HILL_RIGHT_EDGE)->Draw(x + UNIT_SIZE, yy);
		}
		else
		{
			sprites->Get(ID_SPRITE_BACKGROUND_HILL_BODY)->Draw(x + UNIT_SIZE, yy);
		}

		yy += UNIT_SIZE;
	}
}