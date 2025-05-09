#include "debug.h"

#include "Paragoomba.h"

CParagoomba::CParagoomba(float x, float y) :CGoomba(x, y)
{
	SetState(PARAGOOMBA_STATE_WING);

	this->ax = 0;
	this->ay = GOOMBA_GRAVITY;
	die_start = -1;

	isOnPlatform = false;
	bounceCount = 0;
}

void CParagoomba::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
	isOnPlatform = false;
};

void CParagoomba::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CParagoomba*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
		if (e->ny < 0) isOnPlatform = true;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CParagoomba::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;
	ULONGLONG tick = GetTickCount64();

	if (isOnPlatform)
	{
		if (tick - walk_start >= PARAGOOMBA_FLY_COOLDOWN) {
			if (bounceCount >= PARAGOOMBA_BOUNCE_THRESHOLD) {
				vy = -PARAGOOMBA_FLY_SPEED;
				walk_start = tick;
				bounceCount = 0;
			}
			else
			{
				vy = -PARAGOOMBA_BOUNCE_SPEED;
				bounceCount++;
			}
		}
	}
	if ((state == GOOMBA_STATE_DIE) && (tick - die_start > GOOMBA_DIE_TIMEOUT))
	{
		isDeleted = true;
		return;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CParagoomba::Render()
{
	int aniId = ID_ANI_GOOMBA_WALKING;
	if (state == GOOMBA_STATE_DIE)
	{
		aniId = ID_ANI_GOOMBA_DIE;
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CParagoomba::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case GOOMBA_STATE_DIE:
		die_start = GetTickCount64();
		y += (GOOMBA_BBOX_HEIGHT - GOOMBA_BBOX_HEIGHT_DIE) / 2;
		vx = 0;
		vy = 0;
		ay = 0;
		break;
	case GOOMBA_STATE_WALKING:
		vx = -GOOMBA_WALKING_SPEED;
		break;
	}
}
