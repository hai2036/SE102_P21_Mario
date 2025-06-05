#include "Particle.h"

CParticle::CParticle(float x, float y, int aniId) :CGameObject(x, y)
{
	timer = GetTickCount64();
	this->aniId = aniId;
}

void CParticle::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (GetTickCount64() - timer >= CAnimations::GetInstance()->Get(aniId)->GetAniTime())
	{
		this->Delete();
	}
}

void CParticle::Render()
{
	if (aniId != 0 && !this->isDeleted)
		CAnimations::GetInstance()->Get(aniId)->Render(x, y);
}