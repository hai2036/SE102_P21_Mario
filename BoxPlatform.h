#pragma once
#include "GameObject.h"


#define COLOR_WHITE 0
#define COLOR_GREEN 1
#define COLOR_PINK 2
#define COLOR_BLUE 3

#define ID_SPRITE_WHITE_BOX1 70001
#define ID_SPRITE_WHITE_BOX2 70002
#define ID_SPRITE_WHITE_BOX3 70003
#define ID_SPRITE_WHITE_BOX4 70004
#define ID_SPRITE_WHITE_BOX5 70005
#define ID_SPRITE_WHITE_BOX6 70006
#define ID_SPRITE_WHITE_BOX7 70007
#define ID_SPRITE_WHITE_BOX8 70008
#define ID_SPRITE_WHITE_BOX9 70009

#define ID_SPRITE_GREEN_BOX1 71001
#define ID_SPRITE_GREEN_BOX2 71002
#define ID_SPRITE_GREEN_BOX3 71003
#define ID_SPRITE_GREEN_BOX4 71004
#define ID_SPRITE_GREEN_BOX5 71005
#define ID_SPRITE_GREEN_BOX6 71006
#define ID_SPRITE_GREEN_BOX7 71007
#define ID_SPRITE_GREEN_BOX8 71008
#define ID_SPRITE_GREEN_BOX9 71009

#define ID_SPRITE_PINK_BOX1 72001
#define ID_SPRITE_PINK_BOX2 72002
#define ID_SPRITE_PINK_BOX3 72003
#define ID_SPRITE_PINK_BOX4 72004
#define ID_SPRITE_PINK_BOX5 72005
#define ID_SPRITE_PINK_BOX6 72006
#define ID_SPRITE_PINK_BOX7 72007
#define ID_SPRITE_PINK_BOX8 72008
#define ID_SPRITE_PINK_BOX9 72009

#define ID_SPRITE_BLUE_BOX1 73001
#define ID_SPRITE_BLUE_BOX2 73002
#define ID_SPRITE_BLUE_BOX3 73003
#define ID_SPRITE_BLUE_BOX4 73004
#define ID_SPRITE_BLUE_BOX5 73005
#define ID_SPRITE_BLUE_BOX6 73006
#define ID_SPRITE_BLUE_BOX7 73007
#define ID_SPRITE_BLUE_BOX8 73008
#define ID_SPRITE_BLUE_BOX9 73009

class CBoxPlatform : public CGameObject
{
	void RenderWhiteBox();
	void RenderGreenBox();
	void RenderPinkBox();
	void RenderBlueBox();
protected:
	int boxWidth;
	int boxHeight;
	int color; // 0: white, 1: green, 2: pink, 3: blue
public:
	CBoxPlatform(float x, float y, int boxWidth, int boxHeight, int color) :CGameObject(x, y)
	{
		this->boxWidth = boxWidth;
		this->boxHeight = boxHeight;
		this->color = color;
	}

	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	int IsDirectionColliable(float nx, float ny);
};
typedef CBoxPlatform* LPBOXPLATFORM;
