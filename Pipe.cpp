#include "Pipe.h"

void CPipe::Render()
{
	CSprites* sprites = CSprites::GetInstance();
	
	if (isUpSideDown)
	{
		float yy = y;

		for (int i = 0; i < height - 1; i++)
		{
			sprites->Get(this->spriteID +3)->Draw(x, yy);
			sprites->Get(this->spriteID + 4)->Draw(x + UNIT_SIZE, yy);
			yy += UNIT_SIZE;
		}

		sprites->Get(this->spriteID + 1)->Draw(x, yy);
		sprites->Get(this->spriteID + 2)->Draw(x + UNIT_SIZE, yy);

		
	}
	else
	{
		float yy = y;

		sprites->Get(this->spriteID + 1)->Draw(x, yy);
		sprites->Get(this->spriteID + 2)->Draw(x + UNIT_SIZE, yy);

		for (int i = 0; i < height - 1; i++)
		{
			yy += UNIT_SIZE;
			sprites->Get(this->spriteID + 3)->Draw(x, yy);
			sprites->Get(this->spriteID + 4)->Draw(x + UNIT_SIZE, yy);
		}
	}
	//RenderBoundingBox();
}

void CPipe::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - UNIT_SIZE / 2;
	t = y - UNIT_SIZE / 2;
	r = l + UNIT_SIZE * 2;
	b = t + UNIT_SIZE * height;
}