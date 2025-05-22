#include "SwitchBlock.h"
#include "Brick.h"
#include "Coin.h"
void CSwitchBlock::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;
	switch (state)
	{
	case SWITCH_BLOCK_STATE_NORMAL:
	{
		aniId = ID_ANI_SWITCH_BLOCK;
		break;
	}
	case SWITCH_BLOCK_STATE_PRESSED:
	{
		aniId = ID_ANI_SWITCH_BLOCK_PRESSED;
		break;
	}
	default:
		break;
	}
	if (aniId == -1)
	{
		return;
	}
	animations->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}

void CSwitchBlock::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	if (this->state != SWITCH_BLOCK_STATE_PRESSED)
	{
		l = x - UNIT_SIZE / 2;
		t = y - UNIT_SIZE / 2;
		r = l + UNIT_SIZE;
		b = t + UNIT_SIZE;
	}

}

void CSwitchBlock::SetState(int state)
{
	if (this->state == SWITCH_BLOCK_STATE_PRESSED)
	{
		return;
	}
	if (state == SWITCH_BLOCK_STATE_PRESSED)
	{
		vector<vector<LPGAMEOBJECT>> objects = CGame::GetInstance()->GetCurrentScene()->GetObjects();
		int lastLayer = objects.size() -1;
		for (int i = 0; i < objects[lastLayer].size(); i++)
		{
			if (dynamic_cast<CBrick*>(objects[lastLayer][i]))
			{
				CBrick* brick = dynamic_cast<CBrick*>(objects[lastLayer][i]);
				if (brick->GetPrizeID() == -1)
				{
					float tempX, tempY;
					brick->GetPosition(tempX, tempY);
					brick->Delete();
					CCoin* coin = new CCoin(tempX, tempY);
					CGame::GetInstance()->GetCurrentScene()->AddObject(coin, 1);
				}
				
			}
		}
	}
	CGameObject::SetState(state);
}