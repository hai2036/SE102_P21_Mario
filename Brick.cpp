#include "Brick.h"
#include "SwitchBlock.h"
#include "SuperMushroom.h"
#include "SuperLeaf.h"
#include "PrizeCoin.h"

#include "Visuals.h"

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
	if (this->state != BRICK_STATE_BREAK)
	{
		l = x - UNIT_SIZE / 2;
		t = y - UNIT_SIZE / 2;
		r = l + UNIT_SIZE;
		b = t + UNIT_SIZE;
	}
	
}

void CBrick::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (this->breaking_start !=-1  &&GetTickCount64() - breaking_start > BRICK_MULTI_COIN_TIMEOUT)
	{
		this->state = BRICK_STATE_EMPTY;
	}
	else if (this->prizeID == OBJECT_TYPE_COIN)
	{
		this->state = BRICK_STATE_NORMAL;
	}

	
	


	
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
		case OBJECT_TYPE_COIN:
		{
			if (this->breaking_start == -1)
			{
				this->breaking_start = GetTickCount64();
			}
			this->prize = new CPrizeCoin(x, y);
			break;
		}
		case OBEJECT_TYPE_LEVEL_UP:
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

			if (mario->GetLevel() == MARIO_LEVEL_SMALL)
			{
				this->prize = new CSuperMushroom(x, y, dx);
			}
			else
			{
				this->prize = new CSuperLeaf(x, y);
			}
			break;
		}
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
		case OBJECT_TYPE_SWITCH_BLOCK:
		{
			this->prize = new CSwitchBlock(x, y-UNIT_SIZE);
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
			spawnDebris(x, y, ID_ANI_DEBRIS_BRICK);
		}
	}
}