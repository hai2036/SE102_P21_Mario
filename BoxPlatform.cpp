#include "BoxPlatform.h"
#include "Sprite.h"
#include "Sprites.h"

#include "Textures.h"
#include "Game.h"

void CBoxPlatform::RenderWhiteBox() {
	CSprites* sprites = CSprites::GetInstance();
	float xx = 0;
	float yy = 0;
	for (int i = 0; i < this->boxHeight; i++)
	{
		yy = y + UNIT_SIZE * i;
		for (int k = 0; k < this->boxWidth; k++)
		{
			xx = x + UNIT_SIZE * k;
			if (i == 0)
			{
				if (k == 0)
				{
					sprites->Get(ID_SPRITE_WHITE_BOX1)->Draw(xx, yy);
				}
				else if (k == this->boxWidth - 1)
				{
					sprites->Get(ID_SPRITE_WHITE_BOX3)->Draw(xx, yy);
				}
				else
				{
					sprites->Get(ID_SPRITE_WHITE_BOX2)->Draw(xx, yy);
				}
			}
			else if (i == this->boxHeight - 1)
			{
				if (k == 0)
				{
					sprites->Get(ID_SPRITE_WHITE_BOX7)->Draw(xx, yy);
				}
				else if (k == this->boxWidth - 1)
				{
					sprites->Get(ID_SPRITE_WHITE_BOX9)->Draw(xx, yy);
				}
				else
				{
					sprites->Get(ID_SPRITE_WHITE_BOX8)->Draw(xx, yy);
				}
			}
			else
			{
				if (k == 0)
				{
					sprites->Get(ID_SPRITE_WHITE_BOX4)->Draw(xx, yy);
				}
				else if (k == this->boxWidth - 1)
				{
					sprites->Get(ID_SPRITE_WHITE_BOX6)->Draw(xx, yy);
				}
				else
				{
					sprites->Get(ID_SPRITE_WHITE_BOX5)->Draw(xx, yy);
				}
			}
		}
	}
}

void CBoxPlatform::RenderGreenBox() {
	CSprites* sprites = CSprites::GetInstance();
	float xx = 0;
	float yy = 0;
	for (int i = 0; i < this->boxHeight; i++)
	{
		yy = y + UNIT_SIZE * i;
		for (int k = 0; k < this->boxWidth; k++)
		{
			xx = x + UNIT_SIZE * k;
			if (i == 0)
			{
				if (k == 0)
				{
					sprites->Get(ID_SPRITE_GREEN_BOX1)->Draw(xx, yy);
				}
				else if (k == this->boxWidth - 1)
				{
					sprites->Get(ID_SPRITE_GREEN_BOX3)->Draw(xx, yy);
				}
				else
				{
					sprites->Get(ID_SPRITE_GREEN_BOX2)->Draw(xx, yy);
				}
			}
			else if (i == this->boxHeight - 1)
			{
				if (k == 0)
				{
					sprites->Get(ID_SPRITE_GREEN_BOX7)->Draw(xx, yy);
				}
				else if (k == this->boxWidth - 1)
				{
					sprites->Get(ID_SPRITE_GREEN_BOX9)->Draw(xx, yy);
				}
				else
				{
					sprites->Get(ID_SPRITE_GREEN_BOX8)->Draw(xx, yy);
				}
			}
			else
			{
				if (k == 0)
				{
					sprites->Get(ID_SPRITE_GREEN_BOX4)->Draw(xx, yy);
				}
				else if (k == this->boxWidth - 1)
				{
					sprites->Get(ID_SPRITE_GREEN_BOX6)->Draw(xx, yy);
				}
				else
				{
					sprites->Get(ID_SPRITE_GREEN_BOX5)->Draw(xx, yy);
				}
			}
		}
	}
}

void CBoxPlatform::RenderPinkBox() {
	CSprites* sprites = CSprites::GetInstance();
	float xx = 0;
	float yy = 0;
	for (int i = 0; i < this->boxHeight; i++)
	{
		yy = y + UNIT_SIZE * i;
		for (int k = 0; k < this->boxWidth; k++)
		{
			xx = x + UNIT_SIZE * k;
			if (i == 0)
			{
				if (k == 0)
				{
					sprites->Get(ID_SPRITE_PINK_BOX1)->Draw(xx, yy);
				}
				else if (k == this->boxWidth - 1)
				{
					sprites->Get(ID_SPRITE_PINK_BOX3)->Draw(xx, yy);
				}
				else
				{
					sprites->Get(ID_SPRITE_PINK_BOX2)->Draw(xx, yy);
				}
			}
			else if (i == this->boxHeight - 1)
			{
				if (k == 0)
				{
					sprites->Get(ID_SPRITE_PINK_BOX7)->Draw(xx, yy);
				}
				else if (k == this->boxWidth - 1)
				{
					sprites->Get(ID_SPRITE_PINK_BOX9)->Draw(xx, yy);
				}
				else
				{
					sprites->Get(ID_SPRITE_PINK_BOX8)->Draw(xx, yy);
				}
			}
			else
			{
				if (k == 0)
				{
					sprites->Get(ID_SPRITE_PINK_BOX4)->Draw(xx, yy);
				}
				else if (k == this->boxWidth - 1)
				{
					sprites->Get(ID_SPRITE_PINK_BOX6)->Draw(xx, yy);
				}
				else
				{
					sprites->Get(ID_SPRITE_PINK_BOX5)->Draw(xx, yy);
				}
			}
		}
	}
}

void CBoxPlatform::RenderBlueBox() {
	CSprites* sprites = CSprites::GetInstance();
	float xx = 0;
	float yy = 0;
	for (int i = 0; i < this->boxHeight; i++)
	{
		yy = y + UNIT_SIZE * i;
		for (int k = 0; k < this->boxWidth; k++)
		{
			xx = x + UNIT_SIZE * k;
			if (i == 0)
			{
				if (k == 0)
				{
					sprites->Get(ID_SPRITE_BLUE_BOX1)->Draw(xx, yy);
				}
				else if (k == this->boxWidth - 1)
				{
					sprites->Get(ID_SPRITE_BLUE_BOX3)->Draw(xx, yy);
				}
				else
				{
					sprites->Get(ID_SPRITE_BLUE_BOX2)->Draw(xx, yy);
				}
			}
			else if (i == this->boxHeight - 1)
			{
				if (k == 0)
				{
					sprites->Get(ID_SPRITE_BLUE_BOX7)->Draw(xx, yy);
				}
				else if (k == this->boxWidth - 1)
				{
					sprites->Get(ID_SPRITE_BLUE_BOX9)->Draw(xx, yy);
				}
				else
				{
					sprites->Get(ID_SPRITE_BLUE_BOX8)->Draw(xx, yy);
				}
			}
			else
			{
				if (k == 0)
				{
					sprites->Get(ID_SPRITE_BLUE_BOX4)->Draw(xx, yy);
				}
				else if (k == this->boxWidth - 1)
				{
					sprites->Get(ID_SPRITE_BLUE_BOX6)->Draw(xx, yy);
				}
				else
				{
					sprites->Get(ID_SPRITE_BLUE_BOX5)->Draw(xx, yy);
				}
			}
		}
	}
}

void CBoxPlatform::Render()
{
	
	switch (this->color)
	{
	case COLOR_WHITE:
		RenderWhiteBox();
		break;
	case COLOR_GREEN:
		RenderGreenBox();
		break;
	case COLOR_PINK:
		RenderPinkBox();
		break;
	case COLOR_BLUE:
		RenderBlueBox();
		break;

	default:
		break;
	}
	
	//RenderBoundingBox();
}

void CBoxPlatform::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - UNIT_SIZE / 2;
	t = y - UNIT_SIZE / 2;
	r = l + UNIT_SIZE * this->boxWidth;
	b = t + UNIT_SIZE * this->boxHeight;
}

int CBoxPlatform::IsDirectionColliable(float nx, float ny)
{
	if (nx == 0 && ny == -1) return 1;
	else return 0;
}