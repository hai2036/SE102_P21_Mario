#include "Boomerang.h"

CBoomerang::CBoomerang(float x, float y, float dx, float dy, bool isHostile) :CFireball(x, y, dx, dy, isHostile)
{
	ULONGLONG tick = GetTickCount64();

	vx = BOOMERANG_SPEED_X * dx;
	vy = BOOMERANG_SPEED_Y * dy;
	
	ax = BOOMERANG_GRAVITY_X * dx;
	ay = BOOMERANG_GRAVITY_Y;

	y0 = y + UNIT_SIZE / 2;

	returning = false;
	this->isHostile = isHostile;
	flight_start = tick;
	delete_start = tick;
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
	y += y <= y0 ? vy * dt : 0;
};

void CBoomerang::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	ULONGLONG tick = GetTickCount64();

	if (tick - delete_start >= BOOMERANG_DELETE_TIME)
	{
		Delete();
	}

	vx += ax * dt;
	vy += ay * dt;

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CBoomerang::Render()
{
	CAnimations::GetInstance()->Get(ID_ANI_BOOMERANG)->Render(x, y);
	//RenderBoundingBox();
}
