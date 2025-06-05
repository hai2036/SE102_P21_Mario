#include "HUDText.h"
#include "Game.h"
#include "Mario.h"

HUDText::HUDText(float x, float y, int charCount, BOOLEAN fillUp) :CGameObject(x, y)
{
	this->charCount = charCount;
	this->fillUp = fillUp;
}

void HUDText::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);
}


void HUDText::SetValue(int value) {
	this->list.clear();
	int numCount = 0;
	while (value != 0)
	{
		numCount += 1;
		list.push_back(value%10);
		value /= 10;
	}

	if (fillUp)
	{
		for (int i = 0; i < this->charCount - numCount; i++)
		{
			list.push_back(0);
		}
	}
	else
	{
		if (list.size()==0)
		{
			list.push_back(0);
		}
	}
}


void HUDText::Render()
{
	for (int i = 0; i < list.size(); i++)
	{
		CSprites::GetInstance()->Get(ID_SPRITE_HUD_NUMBER + list[i])->Draw(x + HUD_TEXT_WIDTH * (this->charCount -1-i), y);
	}
}

void HUDText::SetPosition(float x, float y) {
	this->x = x;
	this->y = y;
}
