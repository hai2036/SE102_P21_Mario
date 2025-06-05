#pragma once
#include "AssetIDs.h"
#include "GameObject.h"
#include "HUDText.h"
#include "SpeedBar.h"

#define HUD_WIDTH 250
#define HUD_HEIGHT 36

#define COIN_POSITION_OFFSET_X (141- HUD_WIDTH/2)
#define COIN_POSITION_OFFSET_Y (14- HUD_HEIGHT/2)
#define SCORE_POSITION_OFFSET_X (61 - HUD_WIDTH /2)
#define SCORE_POSITION_OFFSET_Y (22 - HUD_HEIGHT /2)
#define LIFE_POSITION_OFFSET_X (38 - HUD_WIDTH /2)
#define LIFE_POSITION_OFFSET_Y (22 - HUD_HEIGHT /2)
#define WORLD_POSITION_OFFSET_X (46 - HUD_WIDTH /2)
#define WORLD_POSITION_OFFSET_Y (14 - HUD_HEIGHT /2)
#define TIMER_POSITION_OFFSET_X (133 - HUD_WIDTH /2)
#define TIMER_POSITION_OFFSET_Y (22 - HUD_HEIGHT /2)
#define SPEED_BAR_POSITION_OFFSET_X (61 - HUD_WIDTH/2)
#define SPEED_BAR_POSITION_OFFSET_Y (14 - HUD_HEIGHT /2)


#define TIME_LIMIT 300	// 300 seconds

class HUD : public CGameObject
{

	static HUD* __instance;
	ULONGLONG timer;
	int timeLimit;
	int currentTime;
	int life;
	int coin;
	int score;
	int world;
	
	
	BOOLEAN stopTimer;
	
	HUDText* timerText;
	HUDText* lifeText;
	HUDText* coinText;
	HUDText* scoreText;
	HUDText* worldText;

	SpeedBar* speedBar;

public:
	HUD(float x, float y);
	virtual int IsCollidable() { return 0; };
	virtual int IsBlocking() { return 0; }
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom) {};
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	static HUD* GetInstance();
	void SetPosition(float x, float y);
	void StartTimer();
	void StopTimer();
	void ResetTimer();
	void AddScore(int score);
	void AddCoin();
	void AddLife();
	void DecreaseLife();
	void SetWorld(int world);
};