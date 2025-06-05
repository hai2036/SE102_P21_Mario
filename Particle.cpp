#include "Particle.h"

CParticle::CParticle(float x, float y, int aniId, float xx, float yy) :CGameObject(x, y)
{
	x0 = x;
	y0 = y;
	x1 = x + xx;
	y1 = y + yy;
	this->aniId = aniId;
	duration = CAnimations::GetInstance()->Get(aniId)->GetAniTime();
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
		x = x0 + (x1 - x0) * et;
		y = y0 + (y1 - y0) * et;
	}
}

void CParticle::Render()
{
	if (aniId != 0 && !this->isDeleted)
		CAnimations::GetInstance()->Get(aniId)->Render(x, y);
}