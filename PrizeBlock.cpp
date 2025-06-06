#include "PrizeBlock.h"
#include "Mario.h"
#include "SuperMushroom.h"
#include "SuperLeaf.h"
#include "PrizeCoin.h"
#include "Game.h"

void CPrizeBlock::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	CSprites* sprites = CSprites::GetInstance();
	switch (this->state)
	{
	case STATE_NORMAL:
		animations->Get(ID_ANI_PRIZE_BLOCK)->Render(x, y);
		break;
	case STATE_EMPTY:
		sprites->Get(ID_SPRITE_EMPTY_PRIZE_BLOCK)->Draw(x, y);
		break;
	default:
		break;
	}
	//RenderBoundingBox();
}

void CPrizeBlock::SetState(int state) {
	if (this->state == STATE_EMPTY)
	{
		return;
	}
	LPGAMEOBJECT player = CGame::GetInstance()->GetCurrentScene()->GetPlayer();
	CMario* mario = dynamic_cast<CMario*>(player);
	if (state == STATE_HIT)
	{
		switch (this->prizeID)
		{
		case OBJECT_TYPE_COIN:
			this->prize = new CPrizeCoin(x, y);
			break;
		case OBEJECT_TYPE_LEVEL_UP:
		{
			int dx = 0;
			float mario_X = 0;
			float mario_Y = 0; 
			mario->GetPosition(mario_X, mario_Y);
			
			if (mario_X > x + UNIT_SIZE/2)
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
		default:
			break;
		}
		this->state = STATE_EMPTY;
		if (this->prize != nullptr)
		{
			CGame::GetInstance()->GetCurrentScene()->AddObject(this->prize, 1);
		}
	}
}

void CPrizeBlock::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - UNIT_SIZE / 2;
	t = y - UNIT_SIZE / 2;
	r = l + UNIT_SIZE;
	b = t + UNIT_SIZE;
}
