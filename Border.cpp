#include "Border.h"

void CBorder::Render()
{
	RenderBoundingBox();
}

void CBorder::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - this->border_width / 2;
	t = y - this->border_height / 2;
	r = l + this->border_width;
	b = t + this->border_height;
}