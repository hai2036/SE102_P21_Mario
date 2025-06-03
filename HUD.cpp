#include "HUD.h"

#include "Game.h"
#include "Mario.h"

HUD::HUD(float x, float y) :CGameObject(x, y)
{
}

void HUD::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - HUD_WIDTH / 2;
	top = y - HUD_HEIGHT / 2;
	right = left + HUD_WIDTH;
	bottom = top + HUD_HEIGHT;
}

void HUD::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void HUD::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<HUD*>(e->obj)) return;
}

void HUD::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void HUD::Render()
{
	CMario* mario = dynamic_cast<CMario*>(CGame::GetInstance()->GetCurrentScene()->GetPlayer());

	CSprites::GetInstance()->Get(ID_SPRITE_HUD_BASE)->Draw(x, y);
}