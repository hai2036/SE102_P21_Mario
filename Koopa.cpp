#include "Koopa.h"
#include "Goomba.h"
#include "PrizeBlock.h"
#include "Mario.h"
#include "Game.h"
#include "PiranhaPlant.h"
#include "debug.h"
CKoopa::CKoopa(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = KOOPA_GRAVITY;
	die_start = -1;
	hide_start = -1;
	wake_up_start = -1;
	tail_hit_start = -1;
	isUpSideDown = false;
	SetState(KOOPA_STATE_WALKING);
}

void CKoopa::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state == KOOPA_STATE_WALKING)
	{
		left = x - KOOPA_BBOX_WIDTH / 2;
		top = y - KOOPA_BBOX_HEIGHT / 2;
		right = left + KOOPA_BBOX_WIDTH;
		bottom = top + KOOPA_BBOX_HEIGHT;
	}
	else
	{
		left = x - UNIT_SIZE / 2;
		top = y - UNIT_SIZE / 2;
		right = left + UNIT_SIZE;
		bottom = top + UNIT_SIZE;
	}
}

void CKoopa::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CKoopa::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (e->obj->IsBlocking()) {
		if (e->ny != 0)
		{
			vy = 0;
		}
		else if (e->nx != 0)
		{
			vx = -vx;
		}
	}

	

	if (state== KOOPA_STATE_KICKED)
	{
		if (dynamic_cast<CGoomba*>(e->obj))
			OnCollisionWithGoomba(e);			
		else if (dynamic_cast<CKoopa*>(e->obj))
			OnCollisionWithKoopa(e);
		else if (dynamic_cast<CPrizeBlock*>(e->obj))
			OnCollisionWithPrizeBlock(e);
		else if (dynamic_cast<CPiranhaPlant*>(e->obj))
			OnCollisionWithPiranhaPlant(e);
	}
}



void CKoopa::OnCollisionWithGoomba(LPCOLLISIONEVENT e) {
	CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);
	if (goomba->GetState() != GOOMBA_STATE_DIE)
	{
		goomba->SetState(GOOMBA_STATE_DIE);
	}
}

void CKoopa::OnCollisionWithKoopa(LPCOLLISIONEVENT e) {
	CKoopa* koopa = dynamic_cast<CKoopa*>(e->obj);
	if (koopa->GetState() != KOOPA_STATE_DIE)
	{
		koopa->SetState(KOOPA_STATE_DIE);
	}

}

void CKoopa::OnCollisionWithPrizeBlock(LPCOLLISIONEVENT e) {
	CPrizeBlock* prizeBlock = dynamic_cast<CPrizeBlock*>(e->obj);

	prizeBlock->SetState(STATE_HIT);
}

void CKoopa::OnCollisionWithPiranhaPlant(LPCOLLISIONEVENT e) {
	CPiranhaPlant* PiranhaPlant = dynamic_cast<CPiranhaPlant*>(e->obj);
	
	PiranhaPlant->Damage();
	
}


void CKoopa::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	if ((state == KOOPA_STATE_DIE) && (GetTickCount64() - die_start > KOOPA_DIE_TIMEOUT))
	{
		isDeleted = true;
		return;
	}

	if ((state == KOOPA_STATE_HIDE || state == KOOPA_STATE_HOLDED) && (GetTickCount64() - hide_start > KOOPA_HIDE_TIMEOUT))
	{
		SetState(KOOPA_STATE_WAKE_UP);
	}

	if ((state == KOOPA_STATE_WAKE_UP) && (GetTickCount64() - wake_up_start > KOOPA_WAKE_UP_TIMEOUT))
	{
		// Adjust position to avoid falling off platform

		this->y -= ((KOOPA_BBOX_HEIGHT - UNIT_SIZE) / 2)+2;
		this->isUpSideDown = false;
		SetState(KOOPA_STATE_WALKING);
	}

	if ((state == KOOPA_STATE_TAIL_HIT) && (GetTickCount64() - hide_start > KOOPA_TAIL_HIT_TIMEOUT))
	{
		SetState(KOOPA_STATE_HIDE);
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CKoopa::Render()
{
	int aniId = -1;
	aniId = GetAniID();
	if (aniId == -1)
	{
		return;
	}
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CKoopa::SetState(int state)
{
	CMario* mario = dynamic_cast<CMario*>(CGame::GetInstance()->GetCurrentScene()->GetPlayer());
	CGameObject::SetState(state);
	switch (state)
	{
	case KOOPA_STATE_DIE:
		die_start = GetTickCount64();
		y += (KOOPA_BBOX_HEIGHT - KOOPA_BBOX_HEIGHT_DIE) / 2;
		vx = 0;
		vy = 0;
		ay = 0;
		break;
	case KOOPA_STATE_WALKING:
		vx = -KOOPA_WALKING_SPEED;
		ay = KOOPA_GRAVITY;
		break;
	case KOOPA_STATE_HIDE:
		vx = 0;
		vy = 0;
		ay = KOOPA_GRAVITY;
		hide_start = GetTickCount64();
		break;
	case KOOPA_STATE_WAKE_UP:
	{
		vx = 0;
		vy = 0;
		ay = KOOPA_GRAVITY;
		wake_up_start = GetTickCount64();
		break;
	}
		
	case KOOPA_STATE_KICKED:
	{
		if (mario->Getnx() == 1)
		{
			vx = KOOPA_SPINNING_SPEED;
		}
		else
		{
			vx = -KOOPA_SPINNING_SPEED;

		}
		ay = KOOPA_GRAVITY;
		break;
	}
	case KOOPA_STATE_HOLDED:
	{
		vx = 0;
		vy = 0;
		ay = 0;
		break;
	}
	case KOOPA_STATE_TAIL_HIT:
	{
		if (mario->Getnx() == 1)
		{
			vx = TAIL_HIT_SPEED_X;

		}
		else
		{
			vx = -TAIL_HIT_SPEED_X;
		}
		vy = TAIL_HIT_SPEED_Y;
		ax = 0;
		ay = KOOPA_GRAVITY;
		isUpSideDown = true;
		tail_hit_start = GetTickCount64();
		break;
	}
	default:
		break;
	}
}