#include "MovingPlatform.h"
#include "Border.h"
#include "debug.h"
#include "Game.h"

void CMovingPlatform::Render()
{
	CSprites* s = CSprites::GetInstance();

	float xx = x;

	for (int k = 1; k <= MOVING_PLATFORM_LENGTH; k++)
	{
		s->Get(ID_SPRITE_WOODEN_MOVING_PLATFORM+k)->Draw(xx, y);
		xx += UNIT_SIZE;
	}

	//RenderBoundingBox();
}

void CMovingPlatform::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	vy += ay * dt;

	x += vx * dt;
	y += vy * dt;

	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CMovingPlatform::OnCollisionWith(LPCOLLISIONEVENT e) {
	if (dynamic_cast<CBorder*>(e->obj))
		OnCollisionWithBorder(e);
}

void CMovingPlatform::OnCollisionWithBorder(LPCOLLISIONEVENT e) {
	CBorder* b = (CBorder*)e->obj;
	
	SetState(MOVING_PLATFORM_STATE_DIE);
	
}


void CMovingPlatform::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - UNIT_SIZE / 2;
	t = y - UNIT_SIZE / 2;
	r = l + UNIT_SIZE * 3;
	b = t + UNIT_SIZE;
}

void CMovingPlatform::SetState(int state) {
	if (this->state == MOVING_PLATFORM_STATE_DIE)
	{
		return;
	}
	this->state = state;
	switch (state)
	{
	case MOVING_PLATFORM_STATE_DROP: {
		this->ay = MOVING_PLATFORM_GRAVITY;
		this->vx = 0;
		break;
	}
	case MOVING_PLATFORM_STATE_DIE: {
		this->vx = 0;
		this->vy = 0;
		this->ay = 0;
		this->Delete();
		break;
	}
	default:
		break;
	}
}
