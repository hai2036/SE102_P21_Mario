#include "TailHitBox.h"
#include "Mario.h"
#include "Game.h"

#include "Goomba.h"
#include "PrizeBlock.h"
#include "Koopa.h"
#include "PiranhaPlant.h"
#include "PiranhaClamp.h"
#include "BoomerangBro.h"
#include "GreenKoopa.h"
#include "Brick.h"

#include "Visuals.h"

#include "debug.h"
#include "Collision.h"
#include "HUD.h"

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
		if (mario->IsTailAttacking() && this->hit == 1)
		{
			if (dynamic_cast<CGoomba*>(e->obj))
				OnCollisionWithGoomba(e);
			else if (dynamic_cast<CPrizeBlock*>(e->obj))
				OnCollisionWithPrizeBlock(e);
			else if (dynamic_cast<CBrick*>(e->obj))
				OnCollisionWithBrick(e);
			else if (dynamic_cast<CKoopa*>(e->obj))
				OnCollisionWithKoopa(e);
			else if (dynamic_cast<CPiranhaPlant*>(e->obj))
				OnCollisionWithPiranhaPlant(e);
			else if (dynamic_cast<CPiranhaClamp*>(e->obj))
				OnCollisionWithPiranhaClamp(e);
			else if (dynamic_cast<CBoomerangBro*>(e->obj))
				OnCollisionWithBoomerangBro(e);
		}
	}
}

void CTailHitBox::OnCollisionWithGoomba(LPCOLLISIONEVENT e)
{
	CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);

	if (goomba->GetState() != GOOMBA_STATE_DIE)
	{
		goomba->SetState(GOOMBA_STATE_DIE);

		spawnParticle(x, y, ID_ANI_PARTICLE_HIT);
		CMario* mario = dynamic_cast<CMario*>(CGame::GetInstance()->GetPlayer());
		int score = mario->ComboPrize();
		mario->AddCombo();
		HUD::GetInstance()->AddScore(score);
		spawnScoreParticle(x, y, score);
	}
	this->hit -= 1;
}

void CTailHitBox::OnCollisionWithPrizeBlock(LPCOLLISIONEVENT e)
{
	CPrizeBlock* prizeblock = dynamic_cast<CPrizeBlock*>(e->obj);

	int state = prizeblock->GetState();
	if (state != STATE_HIT && state != STATE_EMPTY)
	{
		prizeblock->SetState(STATE_HIT);

		spawnParticle(x, y, ID_ANI_PARTICLE_HIT);
	}
	this->hit -= 1;
}

void CTailHitBox::OnCollisionWithBrick(LPCOLLISIONEVENT e)
{
	CBrick* brick = dynamic_cast<CBrick*>(e->obj);

	int state = brick->GetState();
	if (state != BRICK_STATE_HIT && state != BRICK_STATE_EMPTY)
	{
		brick->SetState(BRICK_STATE_HIT);

		spawnParticle(x, y, ID_ANI_PARTICLE_HIT);
		HUD::GetInstance()->AddScore(50);
	}
	this->hit -= 1;
}

void CTailHitBox::OnCollisionWithKoopa(LPCOLLISIONEVENT e)
{
	CKoopa* koopa = dynamic_cast<CKoopa*>(e->obj);

	if (koopa->GetState() != KOOPA_STATE_DIE)
	{
		if (dynamic_cast<CGreenKoopa*>(koopa))
		{
			CGreenKoopa* greenKoopa = dynamic_cast<CGreenKoopa*>(koopa);
			if (greenKoopa->IsWing())
			{
				greenKoopa->Damage();
			}

		}
		koopa->SetState(KOOPA_STATE_TAIL_HIT);

		spawnParticle(x, y, ID_ANI_PARTICLE_HIT);
		CMario* mario = dynamic_cast<CMario*>(CGame::GetInstance()->GetPlayer());
		int score = mario->ComboPrize();
		mario->AddCombo();
		HUD::GetInstance()->AddScore(score);
		spawnScoreParticle(x, y, score);
	}
	this->hit -= 1;
}

void CTailHitBox::OnCollisionWithPiranhaPlant(LPCOLLISIONEVENT e) {
	CPiranhaPlant* PiranhaPlant = dynamic_cast<CPiranhaPlant*>(e->obj);

	PiranhaPlant->Damage();
	
	spawnParticle(x, y, ID_ANI_PARTICLE_HIT);
	CMario* mario = dynamic_cast<CMario*>(CGame::GetInstance()->GetPlayer());
	int score = mario->ComboPrize();
	mario->AddCombo();
	HUD::GetInstance()->AddScore(score);
	spawnScoreParticle(x, y, score);
	this->hit -= 1;
}

void CTailHitBox::OnCollisionWithPiranhaClamp(LPCOLLISIONEVENT e) {
	CPiranhaClamp* PiranhaClamp = dynamic_cast<CPiranhaClamp*>(e->obj);

	PiranhaClamp->Damage();

	spawnParticle(x, y, ID_ANI_PARTICLE_HIT);
	CMario* mario = dynamic_cast<CMario*>(CGame::GetInstance()->GetPlayer());
	int score = mario->ComboPrize();
	mario->AddCombo();
	HUD::GetInstance()->AddScore(score);
	spawnScoreParticle(x, y, score);
	this->hit -= 1;
}

void CTailHitBox::OnCollisionWithBoomerangBro(LPCOLLISIONEVENT e)
{
	CBoomerangBro* boomerangBro = dynamic_cast<CBoomerangBro*>(e->obj);

	if (boomerangBro->GetState() != BOOMERANGBRO_STATE_DIE)
	{
		boomerangBro->SetState(BOOMERANGBRO_STATE_DIE);

		spawnParticle(x, y, ID_ANI_PARTICLE_HIT);
		CMario* mario = dynamic_cast<CMario*>(CGame::GetInstance()->GetPlayer());
    int score = mario->ComboPrize();
    mario->AddCombo();
    HUD::GetInstance()->AddScore(score);
    spawnScoreParticle(x, y, score);
    this->hit -= 1;
	}
}