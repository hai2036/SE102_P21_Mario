#include "Pipe.h"

void CPipe::Render()
{
	CSprites* sprites = CSprites::GetInstance();
	float yy = y;

	sprites->Get(ID_SPRITE_PIPE_HEAD_LEFT)->Draw(x, yy);
	sprites->Get(ID_SPRITE_PIPE_HEAD_RIGHT)->Draw(x + UNIT_SIZE, yy);

	for (int i = 0; i < height - 1; i++)
	{
		yy += UNIT_SIZE;
		sprites->Get(ID_SPRITE_PIPE_BODY_LEFT)->Draw(x, yy);
		sprites->Get(ID_SPRITE_PIPE_BODY_RIGHT)->Draw(x + UNIT_SIZE, yy);
	}

	RenderBoundingBox();
}

void CPipe::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - UNIT_SIZE / 2;
	t = y - UNIT_SIZE / 2;
	r = l + UNIT_SIZE * 2;
	b = t + UNIT_SIZE * height;
}