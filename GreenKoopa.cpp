#include "GreenKoopa.h"
#include "Game.h"
#include "debug.h"

CGreenKoopa::CGreenKoopa(float x, float y, BOOLEAN wing) : CKoopa(x, y)
{
	this->wing = wing;
}

int CGreenKoopa::GetAniID()
{
	int aniId = -1;
	switch (this->state)
	{
	case KOOPA_STATE_WALKING:
	{
		if (vx > 0)
		{
			aniId = ID_ANI_GREEN_KOOPA_WALKING_RIGHT;
			if (wing)
			{
				aniId = ID_ANI_GREEN_KOOPA_WING_WALKING_RIGHT;

			}
		}
		else
		{
			aniId = ID_ANI_GREEN_KOOPA_WALKING_LEFT;
			if (wing)
			{
				aniId = ID_ANI_GREEN_KOOPA_WING_WALKING_LEFT;

			}
		}
		break;
	}
	case KOOPA_STATE_DIE:
	{

		aniId = ID_ANI_GREEN_KOOPA_DIE;
		break;
	}
	case KOOPA_STATE_HIDE:
	{
		if (isUpSideDown)
		{
			aniId = ID_ANI_GREEN_KOOPA_UPSIDE_DOWN_HIDE;
		}
		else
		{
			aniId = ID_ANI_GREEN_KOOPA_HIDE;
		}
		break;
	}
	case KOOPA_STATE_WAKE_UP:
	{
		if (isUpSideDown)
		{
			aniId = ID_ANI_GREEN_KOOPA_UPSIDE_DOWN_WAKE_UP;
		}
		else
		{
			aniId = ID_ANI_GREEN_KOOPA_WAKE_UP;
		}
		break;
	}
	case KOOPA_STATE_KICKED:
	{
		if (isUpSideDown)
		{
			aniId = ID_ANI_GREEN_KOOPA_UPSIDE_DOWN_SPINNING;
		}
		else
		{
			aniId = ID_ANI_GREEN_KOOPA_SPINNING;
		}
		break;
	}
	case KOOPA_STATE_HOLDED:
	{
		if (isUpSideDown)
		{
			aniId = ID_ANI_GREEN_KOOPA_UPSIDE_DOWN_HIDE;
		}
		else
		{
			aniId = ID_ANI_GREEN_KOOPA_HIDE;
		}
		break;
	}
	case KOOPA_STATE_TAIL_HIT:
		aniId = ID_ANI_GREEN_KOOPA_UPSIDE_DOWN_HIDE;
		break;
	default:
		break;
	}
	return aniId;
}

void CGreenKoopa::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {

	
	CKoopa::Update(dt, coObjects);
}