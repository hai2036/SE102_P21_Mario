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

void CParagoomba::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state == PARAGOOMBA_STATE_DIE)
	{
		left = x - GOOMBA_BBOX_WIDTH / 2;
		top = y - GOOMBA_BBOX_HEIGHT_DIE / 2;
		right = left + GOOMBA_BBOX_WIDTH;
		bottom = top + GOOMBA_BBOX_HEIGHT_DIE;
	}
	else
	{
		left = x - GOOMBA_BBOX_WIDTH / 2;
		top = y - GOOMBA_BBOX_HEIGHT / 2;
		right = left + GOOMBA_BBOX_WIDTH;
		bottom = top + GOOMBA_BBOX_HEIGHT;
	}
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

	if ((state == PARAGOOMBA_STATE_WING) && (isOnPlatform)) // Automatically bounce & fly
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
	if ((state == PARAGOOMBA_STATE_DIE) && (tick - die_start > GOOMBA_DIE_TIMEOUT))
	{
		isDeleted = true;
		return;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CParagoomba::Render()
{
	int aniId = ID_ANI_PARAGOOMBA_WING_FLY;
	if (state == PARAGOOMBA_STATE_DIE)
	{
		aniId = ID_ANI_PARAGOOMBA_DIE;
	}
	else if (state == PARAGOOMBA_STATE_FOOT)
	{
		aniId = ID_ANI_PARAGOOMBA_FOOT_WALK;
	}
	else if (isOnPlatform)
	{
		aniId = ID_ANI_PARAGOOMBA_WING_WALK;
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CParagoomba::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case PARAGOOMBA_STATE_DIE:
		die_start = GetTickCount64();
		y += (GOOMBA_BBOX_HEIGHT - GOOMBA_BBOX_HEIGHT_DIE) / 2;
		vx = 0;
		vy = 0;
		ay = 0;
		break;
	default:
		vx = -GOOMBA_WALKING_SPEED;
	}
}
