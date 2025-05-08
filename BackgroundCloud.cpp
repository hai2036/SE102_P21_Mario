#include "BackgroundCloud.h"

void CBackgroundCloud::Render()
{
	CSprites* sprites = CSprites::GetInstance();

	
	sprites->Get(ID_SPRITE_BACKGROUND_CLOUD_LEFT_TOP)->Draw(x, y);
	sprites->Get(ID_SPRITE_BACKGROUND_CLOUD_LEFT_BOTTOM)->Draw(x, y + UNIT_SIZE);

	float xx = x + UNIT_SIZE;

	for (int i = 0; i < length; i++)
	{
		sprites->Get(ID_SPRITE_BACKGROUND_CLOUD_MIDDLE_TOP)->Draw(xx, y);
		sprites->Get(ID_SPRITE_BACKGROUND_CLOUD_MIDDLE_BOTTOM)->Draw(xx, y + UNIT_SIZE);
		xx += UNIT_SIZE;
	}

	sprites->Get(ID_SPRITE_BACKGROUND_CLOUD_RIGHT_TOP)->Draw(xx, y);
	sprites->Get(ID_SPRITE_BACKGROUND_CLOUD_RIGHT_BOTTOM)->Draw(xx, y + UNIT_SIZE);
}