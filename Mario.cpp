#include <algorithm>
#include "debug.h"

#include "Mario.h"
#include "Game.h"

#include "Goomba.h"
#include "Paragoomba.h"
#include "Coin.h"
#include "Portal.h"
#include "Border.h"
#include "PrizeBlock.h"
#include "SuperMushroom.h"
#include "SuperLeaf.h"
#include "PiranhaPlant.h"
#include "PiranhaClamp.h"
#include "BoomerangBro.h"
#include "Fireball.h"
#include "Collision.h"
#include "Koopa.h"
#include "GreenKoopa.h"
#include "LifeMushroom.h"
#include "Brick.h"
#include "SwitchBlock.h"
#include "MovingPlatform.h"
#include "HUD.h"

#include "Visuals.h"

void CMario::Restart() {
	this->x = -UNIT_SIZE;
	this->y = -UNIT_SIZE;

	isSitting = false;
	isFlying = false;
	isTailAttacking = false;
	isWagging = false;
	isKicking = false;
	isHolding = false;
	maxVx = 0.0f;
	ax = 0.0f;
	ay = MARIO_GRAVITY;

	level = MARIO_LEVEL_SMALL;
	untouchable = 0;
	untouchable_start = -1;
	tail_attacking_start = -1;
	kicking_start = -1;
	isOnPlatform = false;
	tailHitBox = nullptr;
	holdingObject = nullptr;
}

int CMario::ComboPrize() {
	int score = 0;
	switch (this->combo)
	{
	case 0:
	{
		score = 100;
		break;
	}
	case 1:
	{
		score = 200;
		break;
	}
	case 2:
	{
		score = 400;
		break;
	}
	case 3:
	{
		score = 800;
		break;
	}
	case 4:
	{
		score = 1000;
		break;
	}
	case 5:
	{
		score = 2000;
		break;
	}
	case 6:
	{
		score = 4000;
		break;
	}
	case 7:
	{
		score = 8000;
		break;
	}
	case 8:
	{
		this->lives += 1;
		HUD::GetInstance()->AddLife();
		break;
	}
	default:
		break;
	}
	return score;
}

void CMario::ComboScoreAni(float x, float y) {
	int score = ComboPrize();
	AddCombo();
	HUD::GetInstance()->AddScore(score);
	spawnScoreParticle(x, y, score);
}

void CMario::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	if (this->isFlying)
	{
		ay = 0;
	}
	else
	{
		ay = MARIO_GRAVITY;
	}

	if (this->level == MARIO_LEVEL_RACOON && this->tailHitBox !=nullptr)
	{
		if (this->nx >0)
		{
			tailHitBox->SetPosition(x + MARIO_BIG_BBOX_WIDTH/2 + UNIT_SIZE/2, y);
		}
		else
		{
			tailHitBox->SetPosition(x - (MARIO_BIG_BBOX_WIDTH/2 + UNIT_SIZE/2), y);
		}
	}
	
	vy += ay * dt;
	vx += ax * dt;

	if (abs(vx) > abs(maxVx)) vx = maxVx; 
	// reset untouchable timer if untouchable time has passed
	if (untouchable == 1 && GetTickCount64() - untouchable_start > MARIO_UNTOUCHABLE_TIME)
	{
		untouchable = 0;
	}

	// reset flying timer if flying time has passed
	if (isFlying && GetTickCount64() - flying_start > MARIO_FLYING_TIMEOUT)
	{
		isFlying = false;
	}

	if (combo > 0 && GetTickCount64() - combo_start > MARIO_COMBO_TIMEOUT)
	{
		combo = 0;
	}

	// reset tail attacking timmer if tail attacking time has passed
	if (isTailAttacking && GetTickCount64() - tail_attacking_start > MARIO_TAIL_ATTACKING_TIME)
	{
		isTailAttacking = false;
		if (tailHitBox != nullptr)
		{
			tailHitBox->Delete();
			tailHitBox = nullptr;
		}
	}

	// reset kicking timmer if kicking time has passed
	if (isKicking && GetTickCount64() - kicking_start > MARIO_KICKING_TIME)
	{
		isKicking = false;
	}

	if (isHolding)
	{
		if (holdingObject != nullptr)
		{
		
			holdingObject->SetPosition(x + UNIT_SIZE*nx, y);
			if (holdingObject->GetState() != KOOPA_STATE_HOLDED)
			{
				isHolding = false;
				this->holdingObject = nullptr;
				GetHitByEnemy();
			}
		}
	}
	isOnPlatform = false;
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CMario::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
	isOnPlatform = false;
}

void CMario::OnCollisionWith(LPCOLLISIONEVENT e)
{	
	if (e->ny != 0 && e->obj->IsBlocking())
	{
		vy = 0;
		if (e->ny < 0) isOnPlatform = true;
	}
	else 
	if (e->nx != 0 && e->obj->IsBlocking())
	{
		vx = 0;
	}

	if (dynamic_cast<CParagoomba*>(e->obj))
		OnCollisionWithParagoomba(e);
	else if (dynamic_cast<CGoomba*>(e->obj))
		OnCollisionWithGoomba(e);
	else if (dynamic_cast<CCoin*>(e->obj))
		OnCollisionWithCoin(e);
	else if (dynamic_cast<CBrick*>(e->obj))
		OnCollisionWithBrick(e);
	else if (dynamic_cast<CPortal*>(e->obj))
		OnCollisionWithPortal(e);
	else if (dynamic_cast<CBorder*>(e->obj))
		OnCollisionWithBorder(e);
	else if (dynamic_cast<CPrizeBlock*>(e->obj))
		OnCollisionWithPrizeBlock(e);
	else if (dynamic_cast<CSuperMushroom*>(e->obj))
		OnCollisionWithSuperMushroom(e);
	else if (dynamic_cast<CLifeMushroom*>(e->obj))
		OnCollisionWithLifeMushroom(e);
	else if (dynamic_cast<CSuperLeaf*>(e->obj))
		OnCollisionWithSuperLeaf(e);
	else if (dynamic_cast<CPiranhaPlant*>(e->obj))
		OnCollisionWithPiranhaPlant(e);
	else if (dynamic_cast<CPiranhaClamp*>(e->obj))
		OnCollisionWithPiranhaClamp(e);
	else if (dynamic_cast<CBoomerangBro*>(e->obj))
		OnCollisionWithBoomerangBro(e);
	else if (dynamic_cast<CFireball*>(e->obj))
		OnCollisionWithFireball(e);
	else if (dynamic_cast<CKoopa*>(e->obj))
		OnCollisionWithKoopa(e);
	else if (dynamic_cast<CSwitchBlock*>(e->obj))
		OnCollisionWithSwitchBlock(e);
	else if (dynamic_cast<CMovingPlatform*>(e->obj))
		OnCollisionWithMovingPlatform(e);
}

void CMario::OnCollisionWithParagoomba(LPCOLLISIONEVENT e)
{
	CParagoomba* goomba = dynamic_cast<CParagoomba*>(e->obj);

	// jump on top >> kill Goomba and deflect a bit 
	if (e->ny < 0)
	{
		if (goomba->GetState() != GOOMBA_STATE_DIE)
		{
			y -= 16;
			vy = -MARIO_JUMP_DEFLECT_SPEED;
			ComboScoreAni(x,y);

			if (goomba->GetState() == PARAGOOMBA_STATE_WING)
			{
				goomba->SetState(GOOMBA_STATE_FOOT);
				return;
			}
			goomba->SetState(GOOMBA_STATE_DIE);
		}
	}
	else // hit by Goomba
	{
		if (untouchable == 0 && goomba->GetIsHostile() == true)
		{
			if (goomba->GetState() != GOOMBA_STATE_DIE)
			{
				if (level > MARIO_LEVEL_SMALL)
				{
					level -= 1;
					StartUntouchable();
				}
				else
				{
					DebugOut(L">>> Mario DIE >>> \n");
					SetState(MARIO_STATE_DIE);
				}
			}
		}
	}
}

void CMario::GetHitByEnemy() {
	if (untouchable == 0)
	{
		if (level > MARIO_LEVEL_SMALL)
		{
			level -= 1;
			StartUntouchable();
		}
		else
		{
			DebugOut(L">>> Mario DIE >>> \n");
			SetState(MARIO_STATE_DIE);
		}
	}
}

void CMario::OnCollisionWithGoomba(LPCOLLISIONEVENT e)
{
	CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);

	// jump on top >> kill Goomba and deflect a bit 
	if (e->ny < 0)
	{
		if (goomba->GetState() != GOOMBA_STATE_DIE)
		{
			goomba->SetState(GOOMBA_STATE_DIE);
			vy = -MARIO_JUMP_DEFLECT_SPEED;
			ComboScoreAni(x, y);
		}
	}
	else // hit by Goomba
	{
		
		if (goomba->GetState() != GOOMBA_STATE_DIE)
		{
			GetHitByEnemy();
		}
		
	}
}

void CMario::OnCollisionWithKoopa(LPCOLLISIONEVENT e)
{
	CKoopa* koopa = dynamic_cast<CKoopa*>(e->obj);

	// jump on top >> kill koopa and deflect a bit 
	if (e->ny < 0)
	{
		if (koopa->GetState() != KOOPA_STATE_DIE && koopa->GetState() != KOOPA_STATE_HIDE)
		{
			if (koopa->GetState() == KOOPA_STATE_KICKED)
			{
				isKicking = true;
				kicking_start = GetTickCount64();
			}
			
			if (koopa->IsWing())
			{
				koopa->Damage();
				vy = -MARIO_JUMP_DEFLECT_SPEED;
				koopa->SetState(KOOPA_STATE_WALKING);
				StartUntouchable();
				ComboScoreAni(x, y);
				return;
			}

			koopa->SetState(KOOPA_STATE_HIDE);
			vy = -MARIO_JUMP_DEFLECT_SPEED;
			ComboScoreAni(x, y);
			
			return;
		}
	}

	if (koopa->GetState() != KOOPA_STATE_DIE)
	{
		if (koopa->GetState() == KOOPA_STATE_HIDE || koopa->GetState() == KOOPA_STATE_HOLDED)
		{

			if (isHolding == false && (this->state == MARIO_STATE_RUNNING_LEFT || this->state == MARIO_STATE_RUNNING_RIGHT))
			{
				isHolding = true;
				this->holdingObject = koopa;
				koopa->SetState(KOOPA_STATE_HOLDED);
			}
			else
			{
				if (isHolding == true && holdingObject == koopa)
				{
					return;
				}

				if (koopa->GetState() == KOOPA_STATE_HOLDED)
				{
					this->holdingObject = nullptr;
				}
				if (isKicking == false)
				{
					isKicking = true;
					kicking_start = GetTickCount64();
					StartUntouchable();
					koopa->SetState(KOOPA_STATE_KICKED);
					ComboScoreAni(x, y);

				}
			}
		}
		else // hit by koopa
		{
			if (koopa->GetState() != KOOPA_STATE_DIE)
			{
				GetHitByEnemy();

			}
		}
	}

	
}

void CMario::OnCollisionWithCoin(LPCOLLISIONEVENT e)
{
	e->obj->Delete();
	coin++;
	HUD::GetInstance()->AddCoin();
	HUD::GetInstance()->AddScore(50);
}

void CMario::OnCollisionWithPortal(LPCOLLISIONEVENT e)
{
	CPortal* p = (CPortal*)e->obj;
	p->GetTelePosition(this->x,this->y);
	HUD::GetInstance()->StopTimer();
	if (p->GetSceneId() == 3)
	{
		HUD::GetInstance()->ResetTimer();
	}
	CGame::GetInstance()->InitiateSwitchScene(p->GetSceneId());
}

void CMario::OnCollisionWithBorder(LPCOLLISIONEVENT e)
{
	CBorder* b = (CBorder*)e->obj;
	if (b->GetType() == 1)
	{
		DebugOut(L">>> Mario DIE >>> \n");
		SetState(MARIO_STATE_DIE);
	}
}

void CMario::OnCollisionWithPrizeBlock(LPCOLLISIONEVENT e)
{
	CPrizeBlock* prizeblock = dynamic_cast<CPrizeBlock*>(e->obj);

	// hit the prize block from below
	if (e->ny > 0)
	{
		prizeblock->SetState(STATE_HIT);
	}
}

void CMario::OnCollisionWithSuperMushroom(LPCOLLISIONEVENT e)
{
	CSuperMushroom* superMushroom = (CSuperMushroom*)e->obj;
	superMushroom->SetState(SUPER_MUSHROOM_STATE_DIE);
	SetLevel(this->level+1);
	HUD::GetInstance()->AddScore(1000);
	spawnScoreParticle(x, y, 1000);
}

void CMario::OnCollisionWithSuperLeaf(LPCOLLISIONEVENT e)
{
	CSuperLeaf* superLeaf = (CSuperLeaf*)e->obj;
	superLeaf->SetState(SUPER_LEAF_STATE_DIE);
	SetLevel(this->level + 1);
	HUD::GetInstance()->AddScore(1000);
	spawnScoreParticle(x, y, 1000);
}

void CMario::OnCollisionWithLifeMushroom(LPCOLLISIONEVENT e)
{
	CLifeMushroom* lifeMushroom = (CLifeMushroom*)e->obj;
	lifeMushroom->SetState(SUPER_MUSHROOM_STATE_DIE);
	this->lives += 1;
	HUD::GetInstance()->AddLife();
}

void CMario::OnCollisionWithBrick(LPCOLLISIONEVENT e)
{
	CBrick* brick = dynamic_cast<CBrick*>(e->obj);

	// hit the prize block from below
	if (e->ny > 0)
	{
		brick->SetState(BRICK_STATE_HIT);

		HUD::GetInstance()->AddScore(50);
	}
}

void CMario::OnCollisionWithSwitchBlock(LPCOLLISIONEVENT e)
{
	CSwitchBlock* switchBlock = dynamic_cast<CSwitchBlock*>(e->obj);

	// hit the switch block from above
	if (e->ny < 0)
	{
		switchBlock->SetState(SWITCH_BLOCK_STATE_PRESSED);
	}
}

void CMario::OnCollisionWithMovingPlatform(LPCOLLISIONEVENT e)
{
	CMovingPlatform* movingPlatform = dynamic_cast<CMovingPlatform*>(e->obj);

	// hit the movingPlatform from above
	if (e->ny < 0)
	{
		movingPlatform->SetState(MOVING_PLATFORM_STATE_DROP);
	}
}

void CMario::OnCollisionWithPiranhaPlant(LPCOLLISIONEVENT e)
{
	CPiranhaPlant* piranhaPlant = dynamic_cast<CPiranhaPlant*>(e->obj);

	if (untouchable == 0 && piranhaPlant->GetIsHostile() == true)
	{
		if (level > MARIO_LEVEL_SMALL)
		{
			level -= 1;
			StartUntouchable();
		}
		else
		{
			DebugOut(L">>> Mario DIE >>> \n");
			SetState(MARIO_STATE_DIE);
		}
	}
}

void CMario::OnCollisionWithPiranhaClamp(LPCOLLISIONEVENT e)
{
	CPiranhaClamp* piranhaClamp = dynamic_cast<CPiranhaClamp*>(e->obj);

	if (untouchable == 0 && piranhaClamp->GetIsHostile() == true)
	{
		if (level > MARIO_LEVEL_SMALL)
		{
			level -= 1;
			StartUntouchable();
		}
		else
		{
			DebugOut(L">>> Mario DIE >>> \n");
			SetState(MARIO_STATE_DIE);
		}
	}
}

void CMario::OnCollisionWithBoomerangBro(LPCOLLISIONEVENT e)
{
	CBoomerangBro* boomerangBro = dynamic_cast<CBoomerangBro*>(e->obj);

	// jump on top >> kill Goomba and deflect a bit 
	if (e->ny < 0)
	{
		if (boomerangBro->GetState() != BOOMERANGBRO_STATE_DIE)
		{
			boomerangBro->SetState(BOOMERANGBRO_STATE_DIE);
			vy = -MARIO_JUMP_DEFLECT_SPEED;
			ComboScoreAni(x, y);
		}
	}
	else // hit by Goomba
	{

		if (boomerangBro->GetState() != BOOMERANGBRO_STATE_DIE)
		{
			GetHitByEnemy();
		}

	}
}

void CMario::OnCollisionWithFireball(LPCOLLISIONEVENT e)
{
	CFireball* fireball = dynamic_cast<CFireball*>(e->obj);

	if (untouchable == 0 && fireball->GetIsHostile() == true)
	{
		if (level > MARIO_LEVEL_SMALL)
		{
			level -= 1;
			StartUntouchable();
		}
		else
		{
			DebugOut(L">>> Mario DIE >>> \n");
			SetState(MARIO_STATE_DIE);
		}
	}
}

//
// Get animation ID for small Mario
//
int CMario::GetAniIdSmall()
{
	int aniId = -1;
	if (isKicking)
	{
		if (nx > 0)
		{
			aniId = ID_ANI_MARIO_SMALL_KICKING_RIGHT;
		}
		else
		{
			aniId = ID_ANI_MARIO_SMALL_KICKING_LEFT;

		}
	}
	else
	{
		if (!isOnPlatform)
		{
			if (abs(ax) == MARIO_ACCEL_RUN_X)
			{
				if (nx >= 0)
					aniId = ID_ANI_MARIO_SMALL_JUMP_RUN_RIGHT;
				else
					aniId = ID_ANI_MARIO_SMALL_JUMP_RUN_LEFT;
			}
			else
			{
				if (nx >= 0)
					aniId = ID_ANI_MARIO_SMALL_JUMP_WALK_RIGHT;
				else
					aniId = ID_ANI_MARIO_SMALL_JUMP_WALK_LEFT;
			}
		}
		else
			if (isSitting)
			{
				if (nx > 0)
					aniId = ID_ANI_MARIO_SIT_RIGHT;
				else
					aniId = ID_ANI_MARIO_SIT_LEFT;
			}
			else
				if (vx == 0)
				{
					if (isHolding)
					{
						if (nx > 0) aniId = ID_ANI_MARIO_SMALL_IDLE_HOLD_RIGHT;
						else aniId = ID_ANI_MARIO_SMALL_IDLE_HOLD_LEFT;
					}
					else
					{
						if (nx > 0) aniId = ID_ANI_MARIO_SMALL_IDLE_RIGHT;
						else aniId = ID_ANI_MARIO_SMALL_IDLE_LEFT;
					}

				}
				else if (vx > 0)
				{
					if (ax < 0)
						aniId = ID_ANI_MARIO_SMALL_BRACE_RIGHT;
					else if (ax == MARIO_ACCEL_RUN_X)
					{
						aniId = ID_ANI_MARIO_SMALL_RUNNING_RIGHT;
						if (isHolding)
						{
							aniId = ID_ANI_MARIO_SMALL_RUNNING_HOLD_RIGHT;
						}
					}
					else if (ax == MARIO_ACCEL_WALK_X)
						aniId = ID_ANI_MARIO_SMALL_WALKING_RIGHT;
				}
				else // vx < 0
				{
					if (ax > 0)
						aniId = ID_ANI_MARIO_SMALL_BRACE_LEFT;
					else if (ax == -MARIO_ACCEL_RUN_X)
					{
						aniId = ID_ANI_MARIO_SMALL_RUNNING_LEFT;
						if (isHolding)
						{
							aniId = ID_ANI_MARIO_SMALL_RUNNING_HOLD_LEFT;
						}
					}
					else if (ax == -MARIO_ACCEL_WALK_X)
						aniId = ID_ANI_MARIO_SMALL_WALKING_LEFT;
				}
	}
	if (aniId == -1) aniId = ID_ANI_MARIO_SMALL_IDLE_RIGHT;

	return aniId;
}


//
// Get animdation ID for big Mario
//
int CMario::GetAniIdBig()
{
	int aniId = -1;
	if (isKicking)
	{
		if (nx > 0)
		{
			aniId = ID_ANI_MARIO_KICKING_RIGHT;
		}
		else
		{
			aniId = ID_ANI_MARIO_KICKING_LEFT;

		}
		return aniId;
	}
	if (!isOnPlatform)
	{
		if (abs(ax) == MARIO_ACCEL_RUN_X)
		{
			if (nx >= 0)
				aniId = ID_ANI_MARIO_JUMP_RUN_RIGHT;
			else
				aniId = ID_ANI_MARIO_JUMP_RUN_LEFT;
		}
		else
		{
			if (nx >= 0)
				aniId = ID_ANI_MARIO_JUMP_WALK_RIGHT;
			else
				aniId = ID_ANI_MARIO_JUMP_WALK_LEFT;
		}
	}
	else
		if (isSitting)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_SIT_RIGHT;
			else
				aniId = ID_ANI_MARIO_SIT_LEFT;
		}
		else
			if (vx == 0)
			{
				if (isHolding)
				{
					if (nx > 0) aniId = ID_ANI_MARIO_IDLE_HOLD_RIGHT;
					else aniId = ID_ANI_MARIO_IDLE_HOLD_LEFT;
				}
				else
				{
					if (nx > 0) aniId = ID_ANI_MARIO_IDLE_RIGHT;
					else aniId = ID_ANI_MARIO_IDLE_LEFT;
				}
				
			}
			else if (vx > 0)
			{
				if (ax < 0)
					aniId = ID_ANI_MARIO_BRACE_RIGHT;
				else if (ax == MARIO_ACCEL_RUN_X)
				{
					aniId = ID_ANI_MARIO_RUNNING_RIGHT;
					if (isHolding)
					{
						aniId = ID_ANI_MARIO_RUNNING_HOLD_RIGHT;

					}
				}
				else if (ax == MARIO_ACCEL_WALK_X)
					aniId = ID_ANI_MARIO_WALKING_RIGHT;
			}
			else // vx < 0
			{
				if (ax > 0)
					aniId = ID_ANI_MARIO_BRACE_LEFT;
				else if (ax == -MARIO_ACCEL_RUN_X)
				{
					aniId = ID_ANI_MARIO_RUNNING_LEFT;
					if (isHolding)
					{
						aniId = ID_ANI_MARIO_RUNNING_HOLD_LEFT;

					}
				}
				else if (ax == -MARIO_ACCEL_WALK_X)
					aniId = ID_ANI_MARIO_WALKING_LEFT;
			}

	if (aniId == -1) aniId = ID_ANI_MARIO_IDLE_RIGHT;

	return aniId;
}

//
// Get animdation ID for Racoon Mario
//
int CMario::GetAniIdRacoon()
{
	int aniId = -1;
	if (isKicking)
	{
		if (nx > 0)
		{
			aniId = ID_ANI_MARIO_RACCOON_KICKING_RIGHT;
		}
		else
		{
			aniId = ID_ANI_MARIO_RACCOON_KICKING_LEFT;

		}
		return aniId;
	}
	if (isTailAttacking)
	{
		if (nx > 0)
		{
			aniId = ID_ANI_MARIO_RACCOON_TAIL_ATTACKING_RIGHT;
		}
		else
		{
			aniId = ID_ANI_MARIO_RACCOON_TAIL_ATTACKING_LEFT;

		}
	}
	else
		if (!isOnPlatform)
		{
			if (isFlying)
			{
				if (nx >= 0)
					aniId = ID_ANI_MARIO_RACCOON_FLY_TAIL_WAGGING_RIGHT;
				else
					aniId = ID_ANI_MARIO_RACCOON_FLY_TAIL_WAGGING_LEFT;
			}
			else if (isWagging)
			{
				if (nx >= 0)
					aniId = ID_ANI_MARIO_RACCOON_TAIL_WAGGING_RIGHT;
				else
					aniId = ID_ANI_MARIO_RACCOON_TAIL_WAGGING_LEFT;
			}
			else
			{
				if (abs(ax) == MARIO_ACCEL_RUN_X)
				{

					if (nx >= 0)
						aniId = ID_ANI_MARIO_RACCOON_JUMP_RUN_RIGHT;
					else
						aniId = ID_ANI_MARIO_RACCOON_JUMP_RUN_LEFT;
				}
				else
				{
					if (nx >= 0)
						aniId = ID_ANI_MARIO_RACCOON_JUMP_WALK_RIGHT;
					else
						aniId = ID_ANI_MARIO_RACCOON_JUMP_WALK_LEFT;
				}
				
			}
			
		}
		else
			if (isSitting)
			{
				if (nx > 0)
					aniId = ID_ANI_MARIO_RACCOON_SIT_RIGHT;
				else
					aniId = ID_ANI_MARIO_RACCOON_SIT_LEFT;
			}
			else
				if (vx == 0)
				{
					if (isHolding)
					{
						if (nx > 0) aniId = ID_ANI_MARIO_RACCOON_IDLE_HOLD_RIGHT;
						else aniId = ID_ANI_MARIO_RACCOON_IDLE_HOLD_LEFT;
					}
					else
					{
						if (nx > 0) aniId = ID_ANI_MARIO_RACCOON_IDLE_RIGHT;
						else aniId = ID_ANI_MARIO_RACCOON_IDLE_LEFT;
					}
					
				}
				else if (vx > 0)
				{
					if (ax < 0)
						aniId = ID_ANI_MARIO_RACCOON_BRACE_RIGHT;
					else if (ax == MARIO_ACCEL_RUN_X)
					{
						aniId = ID_ANI_MARIO_RACCOON_RUNNING_RIGHT;
						if (isHolding)
						{
							aniId = ID_ANI_MARIO_RACCOON_RUNNING_HOLD_RIGHT;

						}
					}
					else if (ax == MARIO_ACCEL_WALK_X)
						aniId = ID_ANI_MARIO_RACCOON_WALKING_RIGHT;
				}
				else // vx < 0
				{
					if (ax > 0)
						aniId = ID_ANI_MARIO_RACCOON_BRACE_LEFT;
					else if (ax == -MARIO_ACCEL_RUN_X)
					{
						aniId = ID_ANI_MARIO_RACCOON_RUNNING_LEFT;
						if (isHolding)
						{
							aniId = ID_ANI_MARIO_RACCOON_RUNNING_HOLD_LEFT;

						}
					}
					else if (ax == -MARIO_ACCEL_WALK_X)
						aniId = ID_ANI_MARIO_RACCOON_WALKING_LEFT;
				}

	if (aniId == -1) aniId = ID_ANI_MARIO_RACCOON_IDLE_RIGHT;

	return aniId;
}

void CMario::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;

	if (state == MARIO_STATE_DIE)
		aniId = ID_ANI_MARIO_DIE;
	else if (level == MARIO_LEVEL_RACOON)
		aniId = GetAniIdRacoon();
	else if (level == MARIO_LEVEL_BIG)
		aniId = GetAniIdBig();
	else if (level == MARIO_LEVEL_SMALL)
		aniId = GetAniIdSmall();

	animations->Get(aniId)->Render(x, y);

	RenderBoundingBox();
	
	//DebugOutTitle(L"Coins: %d | Lives: %d", coin,lives);
}

void CMario::SetState(int state)
{
	// DIE is the end state, cannot be changed! 
	if (this->state == MARIO_STATE_DIE && this->lives <0) return; 

	switch (state)
	{
	case MARIO_STATE_RUNNING_RIGHT:
		if (isSitting) break;
		maxVx = MARIO_RUNNING_SPEED;
		ax = MARIO_ACCEL_RUN_X;
		nx = 1;
		break;
	case MARIO_STATE_RUNNING_LEFT:
		if (isSitting) break;
		maxVx = -MARIO_RUNNING_SPEED;
		ax = -MARIO_ACCEL_RUN_X;
		nx = -1;
		break;
	case MARIO_STATE_WALKING_RIGHT:
		if (isSitting) break;
		maxVx = MARIO_WALKING_SPEED;
		ax = MARIO_ACCEL_WALK_X;
		nx = 1;
		break;
	case MARIO_STATE_WALKING_LEFT:
		if (isSitting) break;
		maxVx = -MARIO_WALKING_SPEED;
		ax = -MARIO_ACCEL_WALK_X;
		nx = -1;
		break;
	case MARIO_STATE_JUMP:
		if (isSitting) break;
		if (isOnPlatform)
		{
			if (abs(this->vx) == MARIO_RUNNING_SPEED)
				vy = -MARIO_JUMP_RUN_SPEED_Y;
			else 
				vy = -MARIO_JUMP_SPEED_Y;
		}
		else if (this->level == MARIO_LEVEL_RACOON)
		{
			if (abs(this->vx) == MARIO_RUNNING_SPEED)
			{
				this->isFlying = true;
				vy = -MARIO_FLY_SPEED_Y;
				flying_start = GetTickCount64();
			}
			else
			{
				this->isWagging = true;
				vy = -MARIO_WAGGING_FALL_SPEED_Y;
			}
		}
		break;

	case MARIO_STATE_RELEASE_JUMP:
		if (vy < 0 && isFlying) vy += MARIO_JUMP_SPEED_Y / 2;
		this->isFlying = false;
		this->isWagging = false;
		break;
	case MARIO_STATE_TAIL_ATTACKING:
	{
		if (isTailAttacking == true)
		{
			break;
		}
		
		if (tailHitBox == nullptr)
		{
			tailHitBox = new CTailHitBox(x + MARIO_BIG_BBOX_WIDTH+3, y);
			CGame::GetInstance()->GetCurrentScene()->AddObject(tailHitBox,1);
		}
		isTailAttacking = true;
		tail_attacking_start = GetTickCount64();
		break;
	}
	case MARIO_STATE_SIT:
		if (isOnPlatform && level != MARIO_LEVEL_SMALL)
		{
			state = MARIO_STATE_IDLE;
			isSitting = true;
			ax = 0;
			vx = 0; vy = 0.0f;
			y +=MARIO_SIT_HEIGHT_ADJUST;
		}
		break;

	case MARIO_STATE_SIT_RELEASE:
		if (isSitting)
		{
			isSitting = false;
			state = MARIO_STATE_IDLE;
			y -= MARIO_SIT_HEIGHT_ADJUST;
		}
		break;
	case MARIO_STATE_HOLDING_RUNNING_RIGHT:
	{
		if (isSitting) break;
		maxVx = MARIO_WALKING_SPEED;
		ax = MARIO_ACCEL_WALK_X;
		nx = 1;
		break;
	}
	case MARIO_STATE_HOLDING_RUNNING_LEFT:
	{
		if (isSitting) break;
		maxVx = -MARIO_RUNNING_SPEED;
		ax = -MARIO_ACCEL_RUN_X;
		nx = -1;
		break;
	}
	case MARIO_STATE_RELEASE_HOLD:
	{
		isHolding = false;
		isKicking = true;
		kicking_start = GetTickCount64();
		if (this->holdingObject != nullptr)
		{
			StartUntouchable();
			holdingObject->SetState(KOOPA_STATE_KICKED);
			ComboScoreAni(x, y);
		}
		
		break;
	}
	case MARIO_STATE_IDLE:
		ax = 0.0f;
		vx = 0.0f;
		break;

	case MARIO_STATE_DIE:
	{
		vy = -MARIO_JUMP_DEFLECT_SPEED;
		vx = 0;
		ax = 0;
		this->lives -= 1;
		HUD::GetInstance()->DecreaseLife();
		if (this->lives >= 0)
		{
			CGame::GetInstance()->InitiateRestartScene();
		}
		break;
	}
		
	}

	CGameObject::SetState(state);
}

void CMario::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	if (level == MARIO_LEVEL_BIG || level == MARIO_LEVEL_RACOON)
	{
		if (isSitting)
		{
			left = x - MARIO_BIG_SITTING_BBOX_WIDTH / 2;
			top = y - MARIO_BIG_SITTING_BBOX_HEIGHT / 2;
			right = left + MARIO_BIG_SITTING_BBOX_WIDTH;
			bottom = top + MARIO_BIG_SITTING_BBOX_HEIGHT;
		}
		else
		{
			left = x - MARIO_BIG_BBOX_WIDTH / 2;
			top = y - MARIO_BIG_BBOX_HEIGHT / 2;
			right = left + MARIO_BIG_BBOX_WIDTH;
			bottom = top + MARIO_BIG_BBOX_HEIGHT;
		}
	}
	else
	{
		left = x - MARIO_SMALL_BBOX_WIDTH / 2;
		top = y - MARIO_SMALL_BBOX_HEIGHT / 2;
		right = left + MARIO_SMALL_BBOX_WIDTH;
		bottom = top + MARIO_SMALL_BBOX_HEIGHT;
	}
}

void CMario::SetLevel(int l)
{
	if (l > MARIO_LEVEL_RACOON)
	{
		l = MARIO_LEVEL_RACOON;
	}
	// Adjust position to avoid falling off platform
	if (this->level == MARIO_LEVEL_SMALL)
	{
		y -= (MARIO_BIG_BBOX_HEIGHT - MARIO_SMALL_BBOX_HEIGHT) / 2;
	}
	level = l;
}

