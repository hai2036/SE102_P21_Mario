#include "SuperLeaf.h"
#include "Mario.h"
CSuperLeaf::CSuperLeaf(float x, float y) :CGameObject(x, y)
{
	this->state = SUPER_LEAF_STATE_ALIVE;
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
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CSuperLeaf*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}

	if (dynamic_cast<CMario*>(e->obj))
	{
		OnCollisionWithMario(e);
		SetState(SUPER_LEAF_STATE_DIE);
	}
}

void CSuperLeaf::OnCollisionWithMario(LPCOLLISIONEVENT e) {
	CMario* mario = dynamic_cast<CMario*>(e->obj);

	mario->SetLevel(MARIO_LEVEL_RACOON);
}

void CSuperLeaf::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
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
	default:
		break;
	}
}
