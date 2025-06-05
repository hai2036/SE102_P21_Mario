#include "Particle.h"

CParticle::CParticle(float x, float y, int aniId, float xx, float yy, int duration) :CGameObject(x, y)
{
	x0 = x;
	y0 = y;
	x1 = x + xx;
	y1 = y + yy;
	this->aniId = aniId;
	this->duration = duration == 0 ? CAnimations::GetInstance()->Get(aniId)->GetAniTime() : duration;
	timer = GetTickCount64();
}

void CParticle::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	ULONGLONG timeTaken = GetTickCount64() - timer;
	
	if (timeTaken >= duration) {
		this->Delete();
	} else {
		float t = (float)timeTaken / duration;
		float et = 1.0f - (1.0f - t) * (1.0f - t); //Quadratic
		x = x0 + (x1 - x0) * t;
		y = y0 + (y1 - y0) * t;
	}
}

void CParticle::Render()
{
	if (aniId != 0 && !this->isDeleted)
		CAnimations::GetInstance()->Get(aniId)->Render(x, y);
}