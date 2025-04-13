#include "Border.h"

void CBorder::Render()
{
	//RenderBoundingBox();
}

void CBorder::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - UNIT_SIZE / 2;
	t = y - UNIT_SIZE / 2;
	r = l + UNIT_SIZE * width;
	b = t + UNIT_SIZE * height;
}