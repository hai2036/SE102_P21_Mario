#include "Brick.h"

void CBrick::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;
	switch (state)
	{
	case BRICK_STATE_NORMAL:
	{
		aniId = ID_ANI_BRICK;
		break;
	}
	case BRICK_STATE_BREAK:
	{
		aniId = ID_ANI_BRICK_BREAK;
		break;
	}
	case BRICK_STATE_EMPTY:
	{
		aniId = ID_ANI_BRICK_EMPTY;
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

void CBrick::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x - UNIT_SIZE/2;
	t = y - UNIT_SIZE /2;
	r = l + UNIT_SIZE;
	b = t + UNIT_SIZE;
}

void CBrick::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (this->state == BRICK_STATE_BREAK && GetTickCount64() - breaking_start > BRICK_BREAKING_TIMEOUT)
	{
		this->Delete();
	}
}


void CBrick::SetState(int state)
{
	if (this->state == BRICK_STATE_EMPTY)
	{
		return;
	}
	LPGAMEOBJECT player = CGame::GetInstance()->GetCurrentScene()->GetPlayer();
	CMario* mario = dynamic_cast<CMario*>(player);

	if (state == BRICK_STATE_HIT)
	{
		switch (this->prizeID)
		{
		case OBJECT_TYPE_LIFE_MUSHROOM:
		{
			int dx = 0;
			float mario_X = 0;
			float mario_Y = 0;
			mario->GetPosition(mario_X, mario_Y);

			if (mario_X > x + UNIT_SIZE / 2)
			{
				dx = -1;
			}
			else
			{
				dx = 1;
			}
			this->prize = new CLifeMushroom(x, y, dx);

			break;
		}
		default:
			break;
		}
		if (this->prize != nullptr)
		{
			CGame::GetInstance()->GetCurrentScene()->AddObject(this->prize, 1);
			this->state = BRICK_STATE_EMPTY;

		}
		else
		{
			this->state = BRICK_STATE_BREAK;
			this->breaking_start = GetTickCount64();
		}
	}
}