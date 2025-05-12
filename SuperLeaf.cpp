#include "SuperLeaf.h"
CSuperLeaf::CSuperLeaf(float x, float y) :CGameObject(x, y)
{
	this->state = SUPER_LEAF_STATE_RISE_UP;
	this->old_y = y;
	this->old_x = x;
	this->vy = SUPER_LEAF_RISE_UP_SPEED;
}

void CSuperLeaf::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - UNIT_SIZE / 2;
	top = y - UNIT_SIZE / 2;
	right = left + UNIT_SIZE;
	bottom = top + UNIT_SIZE;
}

void CSuperLeaf::OnNoCollision(DWORD dt)
{

};

void CSuperLeaf::OnCollisionWith(LPCOLLISIONEVENT e)
{

}

void CSuperLeaf::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (abs(old_x - x) >= UNIT_SIZE * 3 && this->state == SUPER_LEAF_STATE_FALL_DOWN)
	{
		vx = -vx;
		old_x = x;
	}

	y += vy * dt;
	x += vx * dt;
	
	
	if (old_y - y >= UNIT_SIZE*2 && this->state == SUPER_LEAF_STATE_RISE_UP)
	{
		SetState(SUPER_LEAF_STATE_FALL_DOWN);
	}
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CSuperLeaf::Render()
{
	CSprites* sprites = CSprites::GetInstance();
	sprites->Get(ID_SPRITE_SUPER_LEAF)->Draw(x, y);
}

void CSuperLeaf::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case SUPER_LEAF_STATE_DIE:
		this->Delete();
		break;
	case SUPER_LEAF_STATE_FALL_DOWN:
	{
		this->vx = SUPER_LEAF_FALL_DOWN_X_SPEED;
		this->vy = SUPER_LEAF_FALL_DOWN_Y_SPEED;
		break;
	}
	default:
		break;
	}
}
