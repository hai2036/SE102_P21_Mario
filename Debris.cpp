#include "Debris.h"

CDebris::CDebris(float x, float y, float dx, float dy, int aniId, int duration) :CGameObject(x, y)
{
	vx = DEBRIS_LAUNCH_SPEED * dx;
	vy = -DEBRIS_LAUNCH_SPEED * dy;
	ax = 0;
	ay = DEBRIS_GRAVITY;

	this->aniId = aniId;
	this->duration = duration == 0 ? CAnimations::GetInstance()->Get(aniId)->GetAniTime() : duration;
	timer = GetTickCount64();
}

void CDebris::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	x += vx * dt;
	y += vy * dt;

	ULONGLONG timeTaken = GetTickCount64() - timer;

	if (timeTaken >= duration) {
		this->Delete();
	}
}

void CDebris::Render()
{
	if (!isDeleted)
		CAnimations::GetInstance()->Get(aniId)->Render(x, y);
}