#include "BackgroundFishcake.h"

void CBackgroundFishcake::Render()
{
	CSprites* sprites = CSprites::GetInstance();

	if (isBig) {
		sprites->Get(ID_SPRITE_BACKGROUND_FISHCAKE_BIG_LEFT)->Draw(x, y);
		sprites->Get(ID_SPRITE_BACKGROUND_FISHCAKE_BIG_RIGHT)->Draw(x + UNIT_SIZE, y);
	}
	else {
		sprites->Get(ID_SPRITE_BACKGROUND_FISHCAKE_SMALL)->Draw(x, y);
	}
}