#include "Boomerang.h"

CBoomerang::CBoomerang(float x, float y, float dx, float dy, bool isHostile) :CFireball(x, y, dx, dy, isHostile)
{
	vx = BOOMERANG_SPEED * dx;
	vy = BOOMERANG_SPEED * dy;

	this->isHostile = isHostile;
	this->delete_start = GetTickCount64();
}

void CBoomerang::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{

	left = x - BOOMERANG_BBOX_SIZE / 2;
	top = y - BOOMERANG_BBOX_SIZE / 2;
	right = left + BOOMERANG_BBOX_SIZE;
	bottom = top + BOOMERANG_BBOX_SIZE;
}

void CBoomerang::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CBoomerang::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	ULONGLONG tick = GetTickCount64();

	if (tick - delete_start >= BOOMERANG_DELETE_TIME)
	{
		Delete();
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CBoomerang::Render()
{
	CAnimations::GetInstance()->Get(ID_ANI_BOOMERANG)->Render(x, y);
	//RenderBoundingBox();
}
