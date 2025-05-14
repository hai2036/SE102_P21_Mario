#include "Fireball.h"

CFireball::CFireball(float x, float y, float dx, float dy, bool isHostile) :CGameObject(x, y)
{
	vx = FIREBALL_SPEED * dx;
	vy = FIREBALL_SPEED * dy;

	this->isHostile = isHostile;
	this->delete_start = GetTickCount64();
}

void CFireball::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{

	left = x - FIREBALL_BBOX_SIZE / 2;
	top = y - FIREBALL_BBOX_SIZE / 2;
	right = left + FIREBALL_BBOX_SIZE;
	bottom = top + FIREBALL_BBOX_SIZE;
}

void CFireball::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CFireball::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CFireball*>(e->obj)) return;
}

void CFireball::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	ULONGLONG tick = GetTickCount64();

	if (tick - delete_start >= FIREBALL_DELETE_TIME)
	{
		Delete();
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CFireball::Render()
{
	CAnimations::GetInstance()->Get(ID_ANI_FIREBALL)->Render(x, y);
	//RenderBoundingBox();
}
