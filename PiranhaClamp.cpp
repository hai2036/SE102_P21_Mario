#include "debug.h"
#include "PiranhaClamp.h"

#include "Visuals.h"

CPiranhaClamp::CPiranhaClamp(float x, float y) :CGameObject(x, y)
{
	y0 = y;
	y1 = y - PIRANHACLAMP_BBOX_HEIGHT;

	isHostile = false;
	isRising = false;
	isOutside = false;
	rise_start = -1;
	cooldown_start = -1;
}

void CPiranhaClamp::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{

	left = x - PIRANHACLAMP_BBOX_WIDTH / 2;
	top = y - PIRANHACLAMP_BBOX_HEIGHT / 2;
	right = left + PIRANHACLAMP_BBOX_WIDTH;
	bottom = top + PIRANHACLAMP_BBOX_HEIGHT;
}

void CPiranhaClamp::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CPiranhaClamp::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CPiranhaClamp*>(e->obj)) return;
}

void CPiranhaClamp::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	ULONGLONG tick = GetTickCount64();
	if (!isRising)
	{
		if (tick - cooldown_start >= PIRANHACLAMP_RISE_COOLDOWN)
		{
			rise_start = tick;
			isRising = true;
			isHostile = true;
		}
	}
	else
	{
		ULONGLONG timetaken = tick - rise_start;
		if (timetaken < PIRANHACLAMP_RISE_TIME)
		{
			// Su dung cong thuc Lerp (1 - t) * a + t * b
			float t = (float)timetaken / PIRANHACLAMP_RISE_TIME;
			if (isOutside)
			{
				y = (1 - t) * y1 + t * y0;
			}
			else
			{
				y = (1 - t) * y0 + t * y1;
			}
		}
		else
		{
			y = isOutside ? y0 : y1;
			isOutside = !isOutside;
			isHostile = isOutside ? true : false;
			cooldown_start = tick;
			isRising = false;
		}
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CPiranhaClamp::Render()
{
	CAnimations::GetInstance()->Get(ID_ANI_PIRANHACLAMP_CHOMP)->Render(x, y);
	RenderBoundingBox();
}

void CPiranhaClamp::Damage()
{
	this->Delete();

	spawnParticle(x, y, ID_ANI_PARTICLE_SMOKE);
}