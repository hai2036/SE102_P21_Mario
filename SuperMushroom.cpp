#include "SuperMushroom.h"
CSuperMushroom::CSuperMushroom(float x, float y, int dx) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = SUPER_MUSHROOM_GRAVITY;
	this->state = SUPER_MUSHROOM_STATE_ALIVE;
	this->dx = dx;
	this->vx = SUPER_MUSHROOM_WALKING_SPEED* this->dx;
	
}

void CSuperMushroom::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - UNIT_SIZE / 2;
	top = y - UNIT_SIZE / 2;
	right = left + UNIT_SIZE;
	bottom = top + UNIT_SIZE;
}

void CSuperMushroom::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CSuperMushroom::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CSuperMushroom*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CSuperMushroom::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CSuperMushroom::Render()
{
	CSprites* sprites = CSprites::GetInstance();
	sprites->Get(ID_SPRITE_SUPER_MUSHROOM)->Draw(x, y);
}

void CSuperMushroom::SetState(int state)
{
	CGameObject::SetState(state);
	switch (this->state)
	{
	case SUPER_MUSHROOM_STATE_DIE:
		this->Delete();
		break;
	default:
		break;
	}
}
