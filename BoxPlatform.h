#pragma once
#include "AssetIDs.h"
#include "GameObject.h"

#define COLOR_WHITE 0
#define COLOR_GREEN 1
#define COLOR_PINK 2
#define COLOR_BLUE 3



class CBoxPlatform : public CGameObject
{
	void RenderBox(int spriteIds[9]);
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
