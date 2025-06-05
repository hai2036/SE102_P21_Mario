#include "HUD.h"

#include "Game.h"
#include "Mario.h"

HUD* HUD::__instance = NULL;

HUD::HUD(float x, float y) :CGameObject(x, y)
{
	timer = 0;
	life = 1;
	coin = 0;
	score = 0;
	world = 1;
	currentTime = 0;
	stopTimer = false;
	timeLimit = TIME_LIMIT;

	timerText = new HUDText(x, y, 3,true);
	timerText->SetValue(TIME_LIMIT);
	lifeText = new HUDText(x, y, 2,false);
	lifeText->SetValue(this->life);
	coinText = new HUDText(x, y, 2,false);
	coinText->SetValue(this->coin);
	scoreText = new HUDText(x, y, 7,true);
	scoreText->SetValue(this->score);
	worldText = new HUDText(x, y, 1,false);
	worldText->SetValue(this->world);

	speedBar = new SpeedBar(x, y);
}

HUD* HUD::GetInstance()
{
	if (__instance == NULL)
		__instance = new HUD(0, 0);
	return HUD::__instance;
}

void HUD::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	speedBar->Update(dt, coObjects);
	if (!stopTimer)
	{
		int timerNum = timeLimit - ((GetTickCount64() - timer) / 1000);
		currentTime = timerNum;
		if (currentTime <=0)
		{
			StopTimer();
			currentTime = 0;
			CGame::GetInstance()->GetPlayer()->SetState(MARIO_STATE_DIE);

		}
	}
	timerText->SetValue(currentTime);
}

void HUD::StartTimer() {
	timer = GetTickCount64();
	stopTimer = false;
}


void HUD::StopTimer() {
	stopTimer = true;
	timeLimit = currentTime;
}

void HUD::ResetTimer() {
	stopTimer = false;
	timeLimit = TIME_LIMIT;
	StartTimer();
}

void HUD::Render()
{
	CSprites::GetInstance()->Get(ID_SPRITE_HUD_BASE)->Draw(x, y);
	timerText->Render();
	lifeText->Render();
	coinText->Render();
	scoreText->Render();
	worldText->Render();
	speedBar->Render();
}

void HUD::SetPosition(float x, float y) {
	this->x = x;
	this->y = y;
	timerText->SetPosition(x + TIMER_POSITION_OFFSET_X, y + TIMER_POSITION_OFFSET_Y);
	lifeText->SetPosition(x + LIFE_POSITION_OFFSET_X, y + LIFE_POSITION_OFFSET_Y);
	coinText->SetPosition(x + COIN_POSITION_OFFSET_X, y + COIN_POSITION_OFFSET_Y);
	scoreText->SetPosition(x + SCORE_POSITION_OFFSET_X, y + SCORE_POSITION_OFFSET_Y);
	worldText->SetPosition(x + WORLD_POSITION_OFFSET_X, y + WORLD_POSITION_OFFSET_Y);
	speedBar->SetPosition(x + SPEED_BAR_POSITION_OFFSET_X, y + SPEED_BAR_POSITION_OFFSET_Y);
}

void HUD::AddScore(int score) {
	this->score += score;
	scoreText->SetValue(this->score);

}

void HUD::AddCoin() {
	this->coin += 1;
	coinText->SetValue(this->coin);
}

void HUD::SetWorld(int world) {
	this->world = world;
	worldText->SetValue(this->world);
}

void HUD::AddLife() {
	this->life += 1;
	lifeText->SetValue(this->life);
}

void HUD::DecreaseLife() {
	this->life -= 1;
	if (this->life == -1)
	{
		this->life = 0;
	}
	lifeText->SetValue(this->life);
}