#include "TailHitBox.h"
#include "Mario.h"
#include "Game.h"

#include "Goomba.h"
#include "PrizeBlock.h"
#include "Koopa.h"

#include "debug.h"
#include "Collision.h"


void CTailHitBox::Render() {
	RenderBoundingBox();
}

void CTailHitBox::GetBoundingBox(float& l, float& t, float& r, float& b) {
	l = x - UNIT_SIZE / 2;
	t = y - UNIT_SIZE / 2;
	r = l + UNIT_SIZE;
	b = t + UNIT_SIZE;
}

void CTailHitBox::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	CCollision::GetInstance()->Process(this, dt, coObjects);

}


void CTailHitBox::OnNoCollision(DWORD dt) {

}

void CTailHitBox::OnCollisionWith(LPCOLLISIONEVENT e) {
	
	if (e->nx !=0.0f && e->ny !=0.0f) // Only when overlap nx and ny !=0 at the same time
	{
		LPGAMEOBJECT player = CGame::GetInstance()->GetCurrentScene()->GetPlayer();
		CMario* mario = dynamic_cast<CMario*>(player);
		if (mario->IsTailAttacking())
		{
			if (dynamic_cast<CGoomba*>(e->obj))
				OnCollisionWithGoomba(e);
			else if (dynamic_cast<CPrizeBlock*>(e->obj))
				OnCollisionWithPrizeBlock(e);
			else if (dynamic_cast<CKoopa*>(e->obj))
				OnCollisionWithKoopa(e);
		}
	}
}

void CTailHitBox::OnCollisionWithGoomba(LPCOLLISIONEVENT e)
{
	CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);

	if (goomba->GetState() != GOOMBA_STATE_DIE)
	{
		goomba->SetState(GOOMBA_STATE_DIE);
	}
}

void CTailHitBox::OnCollisionWithPrizeBlock(LPCOLLISIONEVENT e)
{
	CPrizeBlock* prizeblock = dynamic_cast<CPrizeBlock*>(e->obj);

	prizeblock->SetState(STATE_HIT);

	
}

void CTailHitBox::OnCollisionWithKoopa(LPCOLLISIONEVENT e)
{
	CKoopa* koopa = dynamic_cast<CKoopa*>(e->obj);

	if (koopa->GetState() != KOOPA_STATE_DIE)
	{
		koopa->SetState(KOOPA_STATE_TAIL_HIT);
	}
}