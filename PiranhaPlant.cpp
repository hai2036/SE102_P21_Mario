#include "debug.h"
#include "PiranhaPlant.h"

#include "Visuals.h"

#include "Mario.h"
#include "Fireball.h"

const int chompAniIds[4] = {
	ID_ANI_PIRANHAPLANT_CHOMP_RED_UP_LEFT,
	ID_ANI_PIRANHAPLANT_CHOMP_RED_UP_RIGHT,
	ID_ANI_PIRANHAPLANT_CHOMP_RED_DOWN_LEFT,
	ID_ANI_PIRANHAPLANT_CHOMP_RED_DOWN_RIGHT
};

const int openSpriteIds[4] = {
	ID_SPRITE_PIRANHAPLANT_RED_OPEN_UP_LEFT,
	ID_SPRITE_PIRANHAPLANT_RED_OPEN_UP_RIGHT,
	ID_SPRITE_PIRANHAPLANT_RED_OPEN_DOWN_LEFT,
	ID_SPRITE_PIRANHAPLANT_RED_OPEN_DOWN_RIGHT
};

CPiranhaPlant::CPiranhaPlant(float x, float y, bool isGreen) :CGameObject(x, y)
{
	isHostile = false;
	isRising = false;
	isOutside = false;
	this->isGreen = isGreen;
	canShoot = false;
	rise_start = -1;
	cooldown_start = -1;
	shoot_start = -1;

	y0 = y;
	y1 = isGreen ? y0 - (PIRANHAPLANT_BBOX_HEIGHT - 8) : y0 - PIRANHAPLANT_BBOX_HEIGHT;

	lookDirection = UP_LEFT;
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
		ULONGLONG timeTaken = tick - rise_start;
		if (timeTaken < PIRANHAPLANT_RISE_TIME)
		{
			float t = (float) timeTaken / PIRANHAPLANT_RISE_TIME;
			if (isOutside)
			{
				y = y1 + (y0 - y1) * t;
			}
			else
			{
				y = y0 + (y1 - y0) * t;
			}
		}
		else
		{
			y = isOutside ? y0 : y1;
			isOutside = !isOutside;
			isHostile = isOutside ? true : false;
			cooldown_start = tick;
			shoot_start = isOutside ? tick : -1;
			canShoot = true;
			isRising = false;
		}
	}

	if ((isOutside) && (canShoot))
	{
		if (tick - shoot_start >= PIRANHAPLANT_SHOOT_TIME)
		{
			float dx = 0.0f;
			float dy = 0.0f;

			switch (lookDirection)
			{
			case PiranhaPlantLookDirection::UP_LEFT:
				dx = -1.0f; dy = -1.0f;
				break;
			case PiranhaPlantLookDirection::UP_RIGHT:
				dx = 1.0f; dy = -1.0f;
				break;
			case PiranhaPlantLookDirection::DOWN_LEFT:
				dx = -1.0f; dy = 1.0f;
				break;
			case PiranhaPlantLookDirection::DOWN_RIGHT:
				dx = 1.0f; dy = 1.0f;
				break;
			}

			LPGAMEOBJECT fireball = new CFireball(x, y - UNIT_SIZE / 2, dx, dy, true);
			CGame::GetInstance()->GetCurrentScene()->AddObject(fireball, 3);
			canShoot = false;
		}
	}

	lookDirection = static_cast<PiranhaPlantLookDirection>(
		(marioY > y ? DOWN_LEFT : UP_LEFT) + (marioX > x + UNIT_SIZE / 2 ? 1 : 0)
	);

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CPiranhaPlant::Render()
{
	if (isRising)
	{
		int aniId = isGreen ? chompAniIds[lookDirection] + 1000 : chompAniIds[lookDirection];
		CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	}
	else
	{
		int spriteId = isGreen ? openSpriteIds[lookDirection] + 1000 : openSpriteIds[lookDirection];
		CSprites::GetInstance()->Get(spriteId)->Draw(x, y);
	}
	RenderBoundingBox();
}

void CPiranhaPlant::Damage()
{
	this->Delete();
	spawnParticle(x, y, ID_ANI_PARTICLE_SMOKE);
}