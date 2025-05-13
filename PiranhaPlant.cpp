#include "debug.h"
#include "PiranhaPlant.h"

#include "Game.h"
#include "Mario.h"

CPiranhaPlant::CPiranhaPlant(float x, float y) :CGameObject(x, y)
{
	y0 = y;
	y1 = y - PIRANHAPLANT_BBOX_HEIGHT;
	
	isHostile = false;
	isRising = false;
	isOutside = false;
	rise_start = -1;
	cooldown_start = -1;
}

void CPiranhaPlant::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{

	left = x - PIRANHAPLANT_BBOX_WIDTH / 2;
	top = y - PIRANHAPLANT_BBOX_HEIGHT / 2;
	right = left + PIRANHAPLANT_BBOX_WIDTH;
	bottom = top + PIRANHAPLANT_BBOX_HEIGHT;
}

void CPiranhaPlant::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CPiranhaPlant::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CPiranhaPlant*>(e->obj)) return;
}

void CPiranhaPlant::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CMario* mario = dynamic_cast<CMario*>(CGame::GetInstance()->GetCurrentScene()->GetPlayer());
	float marioX, marioY;
	mario->GetPosition(marioX, marioY);
	ULONGLONG tick = GetTickCount64();
	if (!isRising)
	{
		if (tick - cooldown_start >= PIRANHAPLANT_RISE_COOLDOWN)
		{
			rise_start = tick;
			isRising = true;
			isHostile = true;
		}
	}
	else
	{
		ULONGLONG timetaken = tick - rise_start;
		if (timetaken < PIRANHAPLANT_RISE_TIME)
		{
			// Su dung cong thuc Lerp (1 - t) * a + t * b
			float t = (float) timetaken / PIRANHAPLANT_RISE_TIME;
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

	if (marioX > x + UNIT_SIZE / 2)
	{
		if (marioY > y + UNIT_SIZE / 2)
		{
			lookDirection = PIRANHAPLANT_LOOK_DIRECTION_DOWN_RIGHT;
		}
		else
		{
			lookDirection = PIRANHAPLANT_LOOK_DIRECTION_UP_RIGHT;
		}
	}
	else
	{
		if (marioY > y + UNIT_SIZE / 2)
		{
			lookDirection = PIRANHAPLANT_LOOK_DIRECTION_DOWN_LEFT;
		}
		else
		{
			lookDirection = PIRANHAPLANT_LOOK_DIRECTION_UP_LEFT;
		}
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CPiranhaPlant::Render()
{
	if (isRising)
	{
		int aniId = ID_ANI_PIRANHAPLANT_CHOMP_RED_DOWN_LEFT;
		if (lookDirection == PIRANHAPLANT_LOOK_DIRECTION_DOWN_LEFT)
		{
			aniId = ID_ANI_PIRANHAPLANT_CHOMP_RED_DOWN_LEFT;
		}
		else if (lookDirection == PIRANHAPLANT_LOOK_DIRECTION_DOWN_RIGHT)
		{
			aniId = ID_ANI_PIRANHAPLANT_CHOMP_RED_DOWN_RIGHT;
		}
		else if (lookDirection == PIRANHAPLANT_LOOK_DIRECTION_UP_LEFT)
		{
			aniId = ID_ANI_PIRANHAPLANT_CHOMP_RED_UP_LEFT;
		}
		else
		{
			aniId = ID_ANI_PIRANHAPLANT_CHOMP_RED_UP_RIGHT;
		}

		CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	}
	else
	{
		int spriteId = ID_SPRITE_PIRANHAPLANT_RED_CLOSE_DOWN_LEFT;
		if (lookDirection == PIRANHAPLANT_LOOK_DIRECTION_DOWN_LEFT)
		{
			spriteId = ID_SPRITE_PIRANHAPLANT_RED_CLOSE_DOWN_LEFT;
		}
		else if (lookDirection == PIRANHAPLANT_LOOK_DIRECTION_DOWN_RIGHT)
		{
			spriteId = ID_SPRITE_PIRANHAPLANT_RED_CLOSE_DOWN_RIGHT;
		}
		else if (lookDirection == PIRANHAPLANT_LOOK_DIRECTION_UP_LEFT)
		{
			spriteId = ID_SPRITE_PIRANHAPLANT_RED_CLOSE_UP_LEFT;
		}
		else
		{
			spriteId = ID_SPRITE_PIRANHAPLANT_RED_CLOSE_UP_RIGHT;
		}

		CSprites::GetInstance()->Get(spriteId)->Draw(x, y);
	}
	RenderBoundingBox();
}

void CPiranhaPlant::Damage()
{
	isDeleted = true;
}
