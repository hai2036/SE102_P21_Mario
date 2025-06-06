#include "BoomerangBro.h"
#include "Border.h"

CBoomerangBro::CBoomerangBro(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = BOOMERANGBRO_GRAVITY;
	isReady = true;
	isMoving = true;
	die_start = -1;
	SetState(BOOMERANGBRO_STATE_WALK);
}

void CBoomerangBro::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - BOOMERANGBRO_BBOX_WIDTH / 2;
	top = y - BOOMERANGBRO_BBOX_HEIGHT / 2;
	right = left + BOOMERANGBRO_BBOX_WIDTH;
	bottom = top + BOOMERANGBRO_BBOX_HEIGHT;
}

void CBoomerangBro::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CBoomerangBro::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CBoomerangBro*>(e->obj)) return;

	if (dynamic_cast<CBorder*>(e->obj)) {
		CBorder* b = (CBorder*)e->obj;
		if (b->GetType() == 1)
		{
			SetState(BOOMERANGBRO_STATE_DIE);
			return;
		}
	}

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CBoomerangBro::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	if ((state == BOOMERANGBRO_STATE_DIE) && (GetTickCount64() - die_start > BOOMERANGBRO_DIE_TIMEOUT))
	{
		this->Delete();
		return;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CBoomerangBro::Render()
{
	int aniId = ID_ANI_BOOMERANGBRO_WALK_UNREADY_MOVE;
	if (state == BOOMERANGBRO_STATE_DIE)
	{
		aniId = ID_ANI_BOOMERANGBRO_DIE;
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CBoomerangBro::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case BOOMERANGBRO_STATE_DIE:
		die_start = GetTickCount64();
		vx = 0;
		vy = 0;
		ax = 0;
		ay = 0;
		break;
	case BOOMERANGBRO_STATE_WALK:
		vx = -BOOMERANGBRO_WALK_SPEED;
		break;
	}
}
