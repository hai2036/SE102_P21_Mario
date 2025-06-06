#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"
#include "TailHitBox.h"

#define MARIO_WALKING_SPEED		0.1f
#define MARIO_RUNNING_SPEED		0.2f

#define MARIO_ACCEL_WALK_X	0.0005f
#define MARIO_ACCEL_RUN_X	0.0007f

#define MARIO_JUMP_SPEED_Y		0.5f
#define MARIO_JUMP_RUN_SPEED_Y	0.6f
#define MARIO_FLY_SPEED_Y		0.20f
#define MARIO_WAGGING_FALL_SPEED_Y	0.1f

#define MARIO_GRAVITY			0.002f
#define MARIO_FLYING_GRAVITY	0.0002f

#define MARIO_JUMP_DEFLECT_SPEED  0.4f

#define MARIO_STATE_DIE				-10
#define MARIO_STATE_IDLE			0
#define MARIO_STATE_WALKING_RIGHT	100
#define MARIO_STATE_WALKING_LEFT	200

#define MARIO_STATE_JUMP			300
#define MARIO_STATE_RELEASE_JUMP    301

#define MARIO_STATE_RUNNING_RIGHT	400
#define MARIO_STATE_RUNNING_LEFT	500

#define MARIO_STATE_SIT				600
#define MARIO_STATE_SIT_RELEASE		601

#define MARIO_STATE_TAIL_ATTACKING	700

#define MARIO_STATE_RELEASE_HOLD	800
#define MARIO_STATE_HOLDING_RUNNING_RIGHT	801
#define MARIO_STATE_HOLDING_RUNNING_LEFT	802

#pragma region ANIMATION_ID

#define ID_ANI_MARIO_IDLE_RIGHT 400
#define ID_ANI_MARIO_IDLE_LEFT 401
#define ID_ANI_MARIO_IDLE_HOLD_RIGHT 402
#define ID_ANI_MARIO_IDLE_HOLD_LEFT 403

#define ID_ANI_MARIO_KICKING_RIGHT	411
#define ID_ANI_MARIO_KICKING_LEFT	412

#define ID_ANI_MARIO_WALKING_RIGHT 500
#define ID_ANI_MARIO_WALKING_LEFT 501

#define ID_ANI_MARIO_RUNNING_RIGHT 600
#define ID_ANI_MARIO_RUNNING_LEFT 601
#define ID_ANI_MARIO_RUNNING_HOLD_RIGHT 602
#define ID_ANI_MARIO_RUNNING_HOLD_LEFT 603

#define ID_ANI_MARIO_JUMP_WALK_RIGHT 700
#define ID_ANI_MARIO_JUMP_WALK_LEFT 701

#define ID_ANI_MARIO_JUMP_RUN_RIGHT 800
#define ID_ANI_MARIO_JUMP_RUN_LEFT 801

#define ID_ANI_MARIO_SIT_RIGHT 900
#define ID_ANI_MARIO_SIT_LEFT 901

#define ID_ANI_MARIO_BRACE_RIGHT 1000
#define ID_ANI_MARIO_BRACE_LEFT 1001

#define ID_ANI_MARIO_DIE 999

// SMALL MARIO
#define ID_ANI_MARIO_SMALL_IDLE_RIGHT 1100
#define ID_ANI_MARIO_SMALL_IDLE_LEFT 1102
#define ID_ANI_MARIO_SMALL_IDLE_HOLD_RIGHT 1103
#define ID_ANI_MARIO_SMALL_IDLE_HOLD_LEFT 1104

#define ID_ANI_MARIO_SMALL_KICKING_RIGHT 1105
#define ID_ANI_MARIO_SMALL_KICKING_LEFT 1106

#define ID_ANI_MARIO_SMALL_WALKING_RIGHT 1200
#define ID_ANI_MARIO_SMALL_WALKING_LEFT 1201

#define ID_ANI_MARIO_SMALL_RUNNING_RIGHT 1300
#define ID_ANI_MARIO_SMALL_RUNNING_LEFT 1301
#define ID_ANI_MARIO_SMALL_RUNNING_HOLD_RIGHT 1302
#define ID_ANI_MARIO_SMALL_RUNNING_HOLD_LEFT 1303

#define ID_ANI_MARIO_SMALL_BRACE_RIGHT 1400
#define ID_ANI_MARIO_SMALL_BRACE_LEFT 1401

#define ID_ANI_MARIO_SMALL_JUMP_WALK_RIGHT 1500
#define ID_ANI_MARIO_SMALL_JUMP_WALK_LEFT 1501

#define ID_ANI_MARIO_SMALL_JUMP_RUN_RIGHT 1600
#define ID_ANI_MARIO_SMALL_JUMP_RUN_LEFT 1601

// RACCOON MARIO
#define ID_ANI_MARIO_RACCOON_IDLE_RIGHT 1700
#define ID_ANI_MARIO_RACCOON_IDLE_LEFT 1701
#define ID_ANI_MARIO_RACCOON_IDLE_HOLD_RIGHT 1702
#define ID_ANI_MARIO_RACCOON_IDLE_HOLD_LEFT 1703

#define ID_ANI_MARIO_RACCOON_KICKING_RIGHT 1704
#define ID_ANI_MARIO_RACCOON_KICKING_LEFT 1705

#define ID_ANI_MARIO_RACCOON_WALKING_RIGHT 1800
#define ID_ANI_MARIO_RACCOON_WALKING_LEFT 1801

#define ID_ANI_MARIO_RACCOON_RUNNING_RIGHT 1900
#define ID_ANI_MARIO_RACCOON_RUNNING_LEFT 1901
#define ID_ANI_MARIO_RACCOON_RUNNING_HOLD_RIGHT 1902
#define ID_ANI_MARIO_RACCOON_RUNNING_HOLD_LEFT 1903

#define ID_ANI_MARIO_RACCOON_JUMP_WALK_RIGHT 2000
#define ID_ANI_MARIO_RACCOON_JUMP_WALK_LEFT 2001
#define ID_ANI_MARIO_RACCOON_TAIL_WAGGING_RIGHT 2020
#define ID_ANI_MARIO_RACCOON_TAIL_WAGGING_LEFT 2021

#define ID_ANI_MARIO_RACCOON_JUMP_RUN_RIGHT 2100
#define ID_ANI_MARIO_RACCOON_JUMP_RUN_LEFT 2101
#define ID_ANI_MARIO_RACCOON_FLY_TAIL_WAGGING_RIGHT 2110
#define ID_ANI_MARIO_RACCOON_FLY_TAIL_WAGGING_LEFT 2111

#define ID_ANI_MARIO_RACCOON_SIT_RIGHT 2200
#define ID_ANI_MARIO_RACCOON_SIT_LEFT 2201

#define ID_ANI_MARIO_RACCOON_BRACE_RIGHT 2300
#define ID_ANI_MARIO_RACCOON_BRACE_LEFT 2301

#define ID_ANI_MARIO_RACCOON_TAIL_ATTACKING_LEFT 2401
#define ID_ANI_MARIO_RACCOON_TAIL_ATTACKING_RIGHT 2402

#pragma endregion

#define GROUND_Y 160.0f




#define	MARIO_LEVEL_SMALL	1
#define	MARIO_LEVEL_BIG		2
#define MARIO_LEVEL_RACOON	3

#define MARIO_BIG_BBOX_WIDTH  14
#define MARIO_BIG_BBOX_HEIGHT 24
#define MARIO_BIG_SITTING_BBOX_WIDTH  14
#define MARIO_BIG_SITTING_BBOX_HEIGHT 16

#define MARIO_SIT_HEIGHT_ADJUST ((MARIO_BIG_BBOX_HEIGHT-MARIO_BIG_SITTING_BBOX_HEIGHT)/2)

#define MARIO_SMALL_BBOX_WIDTH  13
#define MARIO_SMALL_BBOX_HEIGHT 12


#define MARIO_UNTOUCHABLE_TIME 2500
#define MARIO_TAIL_ATTACKING_TIME	200
#define MARIO_KICKING_TIME 200
#define MARIO_FLYING_TIMEOUT 400
#define MARIO_COMBO_TIMEOUT 2000

class CMario : public CGameObject
{
	bool isSitting;
	bool isFlying;
	bool isTailAttacking;
	bool isWagging;
	bool isKicking;
	bool isHolding;
	float maxVx;
	float ax;				// acceleration on x 
	float ay;				// acceleration on y 

	int lives;
	int combo;
	int level; 
	int untouchable; 
	ULONGLONG untouchable_start;
	ULONGLONG tail_attacking_start;
	ULONGLONG kicking_start;
	ULONGLONG flying_start;
	ULONGLONG combo_start;

	bool isOnPlatform;
	int coin;
	LPGAMEOBJECT tailHitBox;
	LPGAMEOBJECT holdingObject;

	void OnCollisionWithParagoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithBrick(LPCOLLISIONEVENT e);
	void OnCollisionWithCoin(LPCOLLISIONEVENT e);
	void OnCollisionWithPortal(LPCOLLISIONEVENT e);
	void OnCollisionWithBorder(LPCOLLISIONEVENT e);
	void OnCollisionWithPrizeBlock(LPCOLLISIONEVENT e);
	void OnCollisionWithSuperMushroom(LPCOLLISIONEVENT e);
	void OnCollisionWithLifeMushroom(LPCOLLISIONEVENT e);
	void OnCollisionWithSuperLeaf(LPCOLLISIONEVENT e);
	void OnCollisionWithPiranhaPlant(LPCOLLISIONEVENT e);
	void OnCollisionWithPiranhaClamp(LPCOLLISIONEVENT e);
	void OnCollisionWithBoomerangBro(LPCOLLISIONEVENT e);
	void OnCollisionWithFireball(LPCOLLISIONEVENT e);
	void OnCollisionWithKoopa(LPCOLLISIONEVENT e);
	void OnCollisionWithSwitchBlock(LPCOLLISIONEVENT e);
	void OnCollisionWithMovingPlatform(LPCOLLISIONEVENT e);




	int GetAniIdRacoon();
	int GetAniIdBig();
	int GetAniIdSmall();
	
	void GetHitByEnemy();
public:
	CMario(float x, float y) : CGameObject(x, y)
	{
		isSitting = false;
		isFlying = false;
		isTailAttacking = false;
		isWagging = false;
		isKicking = false;
		isHolding = false;
		maxVx = 0.0f;
		ax = 0.0f;
		ay = MARIO_GRAVITY; 

		combo = 0;
		lives = 1;
		level = MARIO_LEVEL_SMALL;
		untouchable = 0;
		untouchable_start = -1;
		tail_attacking_start = -1;
		kicking_start = -1;
		flying_start = -1;
		combo_start = -1;
		isOnPlatform = false;
		coin = 0;
		tailHitBox = nullptr;
		holdingObject = nullptr;
	}
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void SetState(int state);

	int IsCollidable()
	{ 
		return (state != MARIO_STATE_DIE);
	}

	int IsBlocking() { return (state != MARIO_STATE_DIE && untouchable==0); }

	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);

	void SetLevel(int l);
	int GetLevel() { return this->level; };
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount64(); }

	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void AddCoin(int Coin) { this->coin += Coin; };
	bool IsTailAttacking() { return this->isTailAttacking; };
	bool IsHolding() { return this->isHolding; };
	bool IsFlying() { return this->isFlying; };
	int Getnx() { return this->nx; };
	void Restart();
	int GetCombo() { return this->combo; };
	void AddCombo() { this->combo += 1; this->combo_start = GetTickCount64(); };
	int ComboPrize();
	void ComboScoreAni(float x, float y);
};