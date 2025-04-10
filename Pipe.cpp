#include "Pipe.h"

void CPipe::Render()
{
	CSprites* sprites = CSprites::GetInstance();
	float yy = 0;
	if (this->pipe_height == 1)
	{
		sprites->Get(ID_SPRITE_PIPE1)->Draw(x, y);
		sprites->Get(ID_SPRITE_PIPE2)->Draw(x + UNIT_SIZE, y);
	}
	else
	{
		for (int i = 0; i < this->pipe_height - 1; i++)
		{
			yy = y - i * UNIT_SIZE;
			sprites->Get(ID_SPRITE_PIPE3)->Draw(x, yy);
			sprites->Get(ID_SPRITE_PIPE4)->Draw(x + UNIT_SIZE, yy);
		}
		yy -= UNIT_SIZE;
		sprites->Get(ID_SPRITE_PIPE1)->Draw(x, yy);
		sprites->Get(ID_SPRITE_PIPE2)->Draw(x + UNIT_SIZE, yy);
	}
	//RenderBoundingBox();
}

void CPipe::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - UNIT_SIZE / 2;
	t = y - ((UNIT_SIZE/2) + UNIT_SIZE*(this->pipe_height-1));
	r = l + UNIT_SIZE * 2;
	b = t + UNIT_SIZE * this->pipe_height;
}