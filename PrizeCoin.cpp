#include "PrizeCoin.h"

void CPrizeCoin::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_COIN)->Render(x, y);

	//RenderBoundingBox();
}

void CPrizeCoin::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	y += vy * dt;
	if (old_y - y >= COIN_RISE_UP_HEIGHT && this->state == COIN_STATE_RISE_UP)
	{
		vy = -vy;
		this->state = COIN_STATE_FALL_DOWN;
	}

	if (y >= old_y && this->state == COIN_STATE_FALL_DOWN)
	{
		vy = 0;
		LPGAMEOBJECT player = CGame::GetInstance()->GetCurrentScene()->GetPlayer();
		CMario* mario = dynamic_cast<CMario*>(player);
		mario->AddCoin(1);
		this->Delete();
	}
}

