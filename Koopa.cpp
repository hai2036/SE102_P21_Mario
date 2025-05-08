#include "Koopa.h"
#include "Goomba.h"
#include "PrizeBlock.h"
#include "debug.h"
CKoopa::CKoopa(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = KOOPA_GRAVITY;
	die_start = -1;
	hide_start = -1;
	wake_up_start = -1;
	SetState(KOOPA_STATE_WALKING);
}

void CKoopa::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state != KOOPA_STATE_WALKING)
	{
		left = x - UNIT_SIZE / 2;
		top = y - UNIT_SIZE / 2;
		right = left + UNIT_SIZE;
		bottom = top + UNIT_SIZE;
	}
	else
	{
		left = x - KOOPA_BBOX_WIDTH / 2;
		top = y - KOOPA_BBOX_HEIGHT / 2;
		right = left + KOOPA_BBOX_WIDTH;
		bottom = top + KOOPA_BBOX_HEIGHT;
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


void CKoopa::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	if ((state == KOOPA_STATE_DIE) && (GetTickCount64() - die_start > KOOPA_DIE_TIMEOUT))
	{
		isDeleted = true;
		return;
	}

	if ((state == KOOPA_STATE_HIDE) && (GetTickCount64() - hide_start > KOOPA_HIDE_TIMEOUT))
	{
		SetState(KOOPA_STATE_WAKE_UP);
	}

	if ((state == KOOPA_STATE_WAKE_UP) && (GetTickCount64() - wake_up_start > KOOPA_WAKE_UP_TIMEOUT))
	{
		// Adjust position to avoid falling off platform

		this->y -= ((KOOPA_BBOX_HEIGHT - UNIT_SIZE) / 2)+2;
		SetState(KOOPA_STATE_WALKING);
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CKoopa::Render()
{
	int aniId = ID_ANI_KOOPA_WALKING_LEFT;
	switch (state)
	{
	case KOOPA_STATE_DIE:
	{
		aniId = ID_ANI_KOOPA_DIE;
		break;
	}
	case KOOPA_STATE_WALKING:
	{
		aniId = (this->vx > 0) ? ID_ANI_KOOPA_WALKING_RIGHT : ID_ANI_KOOPA_WALKING_LEFT;
		break;
	}
	case KOOPA_STATE_HIDE:
	{
		aniId = ID_ANI_KOOPA_HIDE;
		break;
	}
	case KOOPA_STATE_WAKE_UP:
	{
		aniId = ID_ANI_KOOPA_WAKE_UP;
		break;
	}
	case KOOPA_STATE_KICKED:
	{
		aniId = ID_ANI_KOOPA_HIDE;
		break;
	}
	default:
		break;
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CKoopa::SetState(int state)
{
	
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
		break;
	case KOOPA_STATE_HIDE:
		vx = 0;
		hide_start = GetTickCount64();
		break;
	case KOOPA_STATE_WAKE_UP:
		wake_up_start = GetTickCount64();
	case KOOPA_STATE_KICKED:
	{
		vx = KOOPA_SPINNING_SPEED;
		break;
	}
	default:
		break;
	}
	CGameObject::SetState(state);
}