#include "PrizeBlock.h"
#include "Mario.h"
#include "SuperMushroom.h"
#include "SuperLeaf.h"
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

void CPrizeBlock::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CPrizeBlock::OnCollisionWithMario(LPCOLLISIONEVENT e) {
	CMario* mario = dynamic_cast<CMario*>(e->obj);
	if ((e->ny < 0 || (e->nx != 0 && mario->IsTailAttacking())) && this->state == STATE_NORMAL)
	{
		switch (this->prizeID)
		{
		case OBJECT_TYPE_COIN:
			mario->AddCoin(1);
			break;
		case OBJECT_TYPE_SUPER_MUSHROOM:
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
			this->prize = new CSuperMushroom(x, y - UNIT_SIZE, dx);
			break;
		}
		case OBJECT_TYPE_SUPER_LEAF:
		{
			this->prize = new CSuperLeaf(x, y - UNIT_SIZE);
			break;
		}
		default:
			break;
		}
		this->state = STATE_EMPTY;
		if (this->prize != nullptr)
		{
			CGame::GetInstance()->GetCurrentScene()->AddObject(this->prize);
		}
	}
	
}

void CPrizeBlock::OnCollisionWith(LPCOLLISIONEVENT e) {
	if (dynamic_cast<CMario*>(e->obj))
		OnCollisionWithMario(e);
}

void CPrizeBlock::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - UNIT_SIZE / 2;
	t = y - UNIT_SIZE / 2;
	r = l + UNIT_SIZE;
	b = t + UNIT_SIZE;
}
