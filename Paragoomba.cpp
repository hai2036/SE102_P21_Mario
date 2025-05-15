#include "debug.h"

#include "Paragoomba.h"

CParagoomba::CParagoomba(float x, float y) :CGoomba(x, y)
{
	this->ax = 0;
	this->ay = GOOMBA_GRAVITY;
	
	isHostile = true;
	isOnPlatform = false;
	bounceCount = 0;

	die_start = -1;
	SetState(PARAGOOMBA_STATE_WING);
}

void CParagoomba::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state == GOOMBA_STATE_DIE)
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

	if ((!isHostile) && (tick - unhostile_start >= PARAGOOMBA_UNHOSTILE_COOLDOWN))
	{
		isHostile = true;
	}

	if ((isOnPlatform) && (state == PARAGOOMBA_STATE_WING)) // Automatically bounce & fly
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
	int aniId = ID_ANI_PARAGOOMBA_WING_WALK;
	float oy = PARAGOOMBA_SPRITE_OFFSET_WING_WALK_Y;
	if (state == GOOMBA_STATE_DIE)
	{
		aniId = ID_ANI_PARAGOOMBA_DIE;
	}
	else if (state == GOOMBA_STATE_FOOT)
	{
		aniId = ID_ANI_PARAGOOMBA_FOOT_WALK;
		oy = 0;
	}
	else if (!isOnPlatform)
	{
		aniId = ID_ANI_PARAGOOMBA_WING_FLY;
		oy = PARAGOOMBA_SPRITE_OFFSET_WING_FLY_Y;
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x, y - oy);
	//RenderBoundingBox();
}

void CParagoomba::SetState(int state)
{
	ULONGLONG tick = GetTickCount64();

	CGameObject::SetState(state);
	switch (state)
	{
	case GOOMBA_STATE_DIE:
		die_start = tick;
		y += (GOOMBA_BBOX_HEIGHT - GOOMBA_BBOX_HEIGHT_DIE) / 2;
		vx = 0;
		vy = 0;
		ay = 0;
		break;
	case GOOMBA_STATE_FOOT:
		isHostile = false;
		unhostile_start = tick;
		vx = -GOOMBA_WALKING_SPEED;
		break;
	case PARAGOOMBA_STATE_WING:
		vx = -GOOMBA_WALKING_SPEED;
		break;
	}
}
