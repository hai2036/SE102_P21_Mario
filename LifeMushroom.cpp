#include "LifeMushroom.h"
#include "debug.h"
CLifeMushroom::CLifeMushroom(float x, float y, int dx) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = 0;
	this->state = LIFE_MUSHROOM_STATE_RISE_UP;
	this->dx = dx;
	this->vy = LIFE_MUSHROOM_RISE_UP_SPEED;
	this->old_y = y;
}

void CLifeMushroom::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - UNIT_SIZE / 2;
	top = y - UNIT_SIZE / 2;
	right = left + UNIT_SIZE;
	bottom = top + UNIT_SIZE;
}

void CLifeMushroom::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CLifeMushroom::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CLifeMushroom*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CLifeMushroom::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{


	if (this->state == LIFE_MUSHROOM_STATE_RISE_UP)
	{
		y += vy * dt;
	}
	else
	{
		vy += ay * dt;
		vx += ax * dt;
		CCollision::GetInstance()->Process(this, dt, coObjects);
	}

	if (old_y - y >= UNIT_SIZE && this->state == LIFE_MUSHROOM_STATE_RISE_UP)
	{
		SetState(LIFE_MUSHROOM_STATE_WALKING);
	}
}


void CLifeMushroom::Render()
{
	CSprites* sprites = CSprites::GetInstance();
	sprites->Get(ID_SPRITE_LIFE_MUSHROOM)->Draw(x, y);
}

void CLifeMushroom::SetState(int state)
{
	CGameObject::SetState(state);
	switch (this->state)
	{
	case LIFE_MUSHROOM_STATE_DIE:
	{
		vx = 0;
		vy = 0;
		this->Delete();
		break;
	}

	case LIFE_MUSHROOM_STATE_WALKING:
	{
		this->ay = LIFE_MUSHROOM_GRAVITY;
		this->dx = dx;
		this->vx = LIFE_MUSHROOM_WALKING_SPEED * this->dx;
		break;
	}

	default:
		break;
	}
}
