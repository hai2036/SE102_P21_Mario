#include "BoomerangBro.h"
#include "Border.h"

#include "Game.h"
#include "Mario.h"

#include "Boomerang.h"

CBoomerangBro::CBoomerangBro(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = BOOMERANGBRO_WALK_GRAVITY;
	die_start = -1;
	lookRight = false;
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
	ULONGLONG tick = GetTickCount64();

	CMario* mario = dynamic_cast<CMario*>(CGame::GetInstance()->GetCurrentScene()->GetPlayer());
	float marioX, marioY;
	mario->GetPosition(marioX, marioY);

	if ((state == BOOMERANGBRO_STATE_DIE) && (tick - die_start > BOOMERANGBRO_DIE_TIMEOUT))
	{
		this->Delete();
		return;
	}

	if (state == BOOMERANGBRO_STATE_WALK) {
		if (isMoving) {
			if (tick - moving_start >= BOOMERANGBRO_MOVE_TIMEOUT) {
				isMoving = false;
				isForward = !isForward;
				moving_start = tick;
			}
			else {
				vx = isForward ? BOOMERANGBRO_WALK_SPEED : -BOOMERANGBRO_WALK_SPEED;
			}
		}
		else {
			vx = 0;
			if (tick - moving_start >= BOOMERANGBRO_MOVE_TIMEOUT) {
				isMoving = true;
				moving_start = tick;
			}
		}

		if (tick - jump_start >= BOOMERANGBRO_JUMP_COOLDOWN) {
			vy = -BOOMERANGBRO_JUMP_SPEED;
			jump_start = tick;
		}

		if (isReady) {
			if (tick - ready_start >= BOOMERANGBRO_THROW_COOLDOWN) {
				float dx = lookRight ? 1 : -1;
				LPGAMEOBJECT boomerang = new CBoomerang(x, y-8, dx, -1, true);
				CGame::GetInstance()->GetCurrentScene()->AddObject(boomerang, 3);

				isReady = false;
				ready_start = tick;
			}
		}
		else {
			if (tick - ready_start >= BOOMERANGBRO_READY_COOLDOWN) {
				isReady = true;
				ready_start = tick;
			}
		}
	}

	vy += ay * dt;
	vx += ax * dt;

	lookRight = marioX > x + BOOMERANGBRO_BBOX_WIDTH / 2 ? true : false ;

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CBoomerangBro::Render()
{
	int aniId = ID_ANI_BOOMERANGBRO_WALK_UNREADY_STAND_LEFT;
	int ox = 0;
	int oy = 0;

	if (state == BOOMERANGBRO_STATE_DIE)
		aniId = ID_ANI_BOOMERANGBRO_DIE;
	else {
		if (isReady) {
			aniId = isMoving ? ID_ANI_BOOMERANGBRO_WALK_READY_MOVE_LEFT : ID_ANI_BOOMERANGBRO_WALK_READY_STAND_LEFT;
			ox = RENDER_OFFSET_READY_X;
			oy = RENDER_OFFSET_READY_Y;
		}
		else
			aniId = isMoving ? ID_ANI_BOOMERANGBRO_WALK_UNREADY_MOVE_LEFT : ID_ANI_BOOMERANGBRO_WALK_UNREADY_STAND_LEFT;
		if (lookRight) {
			aniId += 10;
			ox = -ox;
		}
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x + ox, y + oy);
	RenderBoundingBox();
}

void CBoomerangBro::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case BOOMERANGBRO_STATE_DIE:
		vx = 0;
		vy = -BOOMERANGBRO_DIEHOP_SPEED;
		ax = 0;
		ay = BOOMERANGBRO_DIE_GRAVITY;
		die_start = GetTickCount64();
		break;
	case BOOMERANGBRO_STATE_WALK:
		isReady = true;
		isMoving = true;
		isForward = false;
		moving_start = GetTickCount64();
		jump_start = GetTickCount64();
		break;
	}
}
