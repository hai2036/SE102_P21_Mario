#include "Ground.h"

void CGround::Render()
{
	CSprites* sprites = CSprites::GetInstance();
	float xx = 0;
	float yy = 0;
	for (int i = 0; i < this->ground_height; i++)
	{
		yy = y + UNIT_SIZE *i;
		for (int k = 0; k < this->ground_width; k++)
		{
			xx = x + UNIT_SIZE * k;
			if (i == 0)
			{
				if (k == 0)
				{
					sprites->Get(this->ground_spriteID +1)->Draw(xx, yy);
				}
				else if (k == this->ground_width - 1)
				{
					sprites->Get(this->ground_spriteID + 3)->Draw(xx, yy);
				}
				else
				{
					sprites->Get(this->ground_spriteID + 2)->Draw(xx, yy);
				}
			}
			else 
			{
				if (k == 0)
				{
					sprites->Get(this->ground_spriteID + 4)->Draw(xx, yy);
				}
				else if (k == this->ground_width - 1)
				{
					sprites->Get(this->ground_spriteID + 6)->Draw(xx, yy);
				}
				else
				{
					sprites->Get(this->ground_spriteID + 5)->Draw(xx, yy);
				}
			}
		}
	}
	//RenderBoundingBox();
}

void CGround::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - UNIT_SIZE / 2;
	t = y - UNIT_SIZE / 2;
	r = l + UNIT_SIZE * this->ground_width;
	b = t + UNIT_SIZE * this->ground_height;
}
