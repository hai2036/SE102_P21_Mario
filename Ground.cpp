#include "Ground.h"

void CGround::Render()
{
	CSprites* sprites = CSprites::GetInstance();
	float xx = 0;
	float yy = 0;
	for (int i = 0; i < this->ground_height; i++)
	{
		yy = y + GROUND_TILE_SIZE *i;
		for (int k = 0; k < this->ground_width; k++)
		{
			xx = x + GROUND_TILE_SIZE * k;
			if (i == 0)
			{
				if (k == 0)
				{
					sprites->Get(ID_SPRITE_GROUND1)->Draw(xx, yy);
				}
				else if (k == this->ground_width - 1)
				{
					sprites->Get(ID_SPRITE_GROUND3)->Draw(xx, yy);
				}
				else
				{
					sprites->Get(ID_SPRITE_GROUND2)->Draw(xx, yy);
				}
			}
			else if (i == this->ground_height - 1) 
			{
				if (k == 0)
				{
					sprites->Get(ID_SPRITE_GROUND7)->Draw(xx, yy);
				}
				else if (k == this->ground_width - 1)
				{
					sprites->Get(ID_SPRITE_GROUND9)->Draw(xx, yy);
				}
				else
				{
					sprites->Get(ID_SPRITE_GROUND8)->Draw(xx, yy);
				}
			}
			else 
			{
				if (k == 0)
				{
					sprites->Get(ID_SPRITE_GROUND4)->Draw(xx, yy);
				}
				else if (k == this->ground_width - 1)
				{
					sprites->Get(ID_SPRITE_GROUND6)->Draw(xx, yy);
				}
				else
				{
					sprites->Get(ID_SPRITE_GROUND5)->Draw(xx, yy);
				}
			}
		}
	}
	//RenderBoundingBox();
}

void CGround::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - GROUND_TILE_SIZE / 2;
	t = y - GROUND_TILE_SIZE / 2;
	r = l + GROUND_TILE_SIZE * this->ground_width;
	b = t + GROUND_TILE_SIZE * this->ground_height;
}
