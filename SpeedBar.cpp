#include "SpeedBar.h"
#include "Game.h"
#include "Mario.h"


SpeedBar::SpeedBar(float x, float y) :CGameObject(x, y)
{
	this->arrowFill = 0;
	this->timer = -1;
}

void SpeedBar::DecreaseStart() {

	timer = GetTickCount64();
	
}

void SpeedBar::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (arrowFill > 0 && GetTickCount64() - timer >= SPEED_BAR_DECREASE_TIMEOUT)
	{
		arrowFill -= 1;
		DecreaseStart();
	}

	CMario* mario = dynamic_cast<CMario*>(CGame::GetInstance()->GetPlayer());
	float vx, vy;
	mario->GetSpeed(vx,vy);
	if (abs(vx) > MARIO_WALKING_SPEED)	// Linear interpolation
	{
		int temp = (((abs(vx) - MARIO_WALKING_SPEED) / (MARIO_RUNNING_SPEED - MARIO_WALKING_SPEED)) * SPEED_BAR_ARROW_COUNT);
		if (temp < arrowFill)
		{
			DecreaseStart();
		}
		else
		{
			arrowFill = temp;
		}
	}
}


void SpeedBar::Render()
{

	for (size_t i = 0; i < SPEED_BAR_ARROW_COUNT; i++)
	{
		if (i < arrowFill)
		{
			CSprites::GetInstance()->Get(ID_SPRITE_HUD_SPEED +1)->Draw(x + i * SPEED_BAR_ARROW_WIDTH, y);

		}
		else
		{
			CSprites::GetInstance()->Get(ID_SPRITE_HUD_SPEED)->Draw(x + i * SPEED_BAR_ARROW_WIDTH, y);

		}
	}
	if (arrowFill == SPEED_BAR_ARROW_COUNT)	// max speed
	{
		CAnimations::GetInstance()->Get(ID_ANI_HUD_PSIGN)->Render(x + SPEED_BAR_ARROW_COUNT * SPEED_BAR_ARROW_WIDTH + 6, y);

	}
	else
	{
		CSprites::GetInstance()->Get(ID_SPRITE_HUD_PSIGN)->Draw(x + SPEED_BAR_ARROW_COUNT * SPEED_BAR_ARROW_WIDTH + 6, y);
	}
}

void SpeedBar::SetPosition(float x, float y) {
	this->x = x;
	this->y = y;
}
