#include "RedKoopa.h"
#include "Game.h"
#include "debug.h"

CRedKoopa::CRedKoopa(float x, float y, BOOLEAN wing) :CKoopa(x, y)
{
	this->wing = wing;
	if (this->wing)
	{
		this->ay = 0;
		this->vx = 0;
		this->vy = RED_KOOPA_WING_FLY_SPEED;
	}
}

int CRedKoopa::GetAniID()
{
	int aniId = -1;
	switch (this->state)
	{
	case KOOPA_STATE_WALKING:
	{
		if (vx > 0)
		{
			aniId = ID_ANI_RED_KOOPA_WALKING_RIGHT;
		}
		else
		{
			aniId = ID_ANI_RED_KOOPA_WALKING_LEFT;
			if (this->wing)
			{
				aniId = ID_ANI_RED_KOOPA_WING_WALKING_LEFT;
			}
		}
		break;
	}
	case KOOPA_STATE_DIE:
	{
		aniId = ID_ANI_RED_KOOPA_DIE;
		break;
	}
	case KOOPA_STATE_HIDE:
	{
		if (isUpSideDown)
		{
			aniId = ID_ANI_RED_KOOPA_UPSIDE_DOWN_HIDE;
		}
		else
		{
			aniId = ID_ANI_RED_KOOPA_HIDE;
		}
		break;
	}
	case KOOPA_STATE_WAKE_UP:
	{
		if (isUpSideDown)
		{
			aniId = ID_ANI_RED_KOOPA_UPSIDE_DOWN_WAKE_UP;
		}
		else
		{
			aniId = ID_ANI_RED_KOOPA_WAKE_UP;
		}
		break;
	}
	case KOOPA_STATE_KICKED:
	{
		if (isUpSideDown)
		{
			aniId = ID_ANI_RED_KOOPA_UPSIDE_DOWN_SPINNING;
		}
		else
		{
			aniId = ID_ANI_RED_KOOPA_SPINNING;
		}
		break;
	}
	case KOOPA_STATE_HOLDED:
	{
		if (isUpSideDown)
		{
			aniId = ID_ANI_RED_KOOPA_UPSIDE_DOWN_HIDE;
		}
		else
		{
			aniId = ID_ANI_RED_KOOPA_HIDE;
		}
		break;
	}
	case KOOPA_STATE_TAIL_HIT:
		aniId = ID_ANI_RED_KOOPA_UPSIDE_DOWN_HIDE;
		break;
	default:
		break;
	}
	return aniId;
}

void CRedKoopa::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CRedKoopa::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (this->state == KOOPA_STATE_WALKING)
	{
		if (this->wing)
		{
			if (!(this->y >= UNIT_SIZE * 15 && this->y <= UNIT_SIZE * 26))
			{
				this->vy = -this->vy;
			}
		}
		else
		{
			if (this->ghostBlock == nullptr)
			{
				this->ghostBlock = new CGhostBlock(x + UNIT_SIZE, y);
				CGame::GetInstance()->GetCurrentScene()->AddObject(this->ghostBlock, 1);
			}
			CGhostBlock* ghostblock = dynamic_cast<CGhostBlock*>(this->ghostBlock);
			float temp_x, temp_y;
			ghostblock->GetPosition(temp_x, temp_y);
			if (ghostblock->IsOnPlatform() == false && this->vy ==0)
			{
				vx = -vx;
				temp_y = y;
			}

			if (vx > 0)
			{
				ghostblock->SetPosition(x + KOOPA_BBOX_WIDTH / 2 + GHOST_BLOCK_WIDTH / 2, temp_y);

			}
			else
			{
				ghostblock->SetPosition(x - (KOOPA_BBOX_WIDTH / 2 + GHOST_BLOCK_WIDTH / 2), temp_y);
			}
		}
	}
	else
	{
		if (this->ghostBlock != nullptr)
		{
			this->ghostBlock->Delete();
			this->ghostBlock = nullptr;
		}
	}
	CKoopa::Update(dt, coObjects);

}