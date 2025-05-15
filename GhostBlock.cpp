#include "GhostBlock.h"
#include "Mario.h"
void CGhostBlock::Render()
{
	RenderBoundingBox();
}

void CGhostBlock::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - GHOST_BLOCK_WIDTH / 2;
	t = y - GHOST_BLOCK_HEIGHT / 2;
	r = l + GHOST_BLOCK_WIDTH;
	b = t + GHOST_BLOCK_HEIGHT;
}

void CGhostBlock::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;

	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CGhostBlock::OnNoCollision(DWORD dt)
{
	y += vy * dt;
	isOnPlatform = false;
}

void CGhostBlock::OnCollisionWith(LPCOLLISIONEVENT e)
{
	
	if (e->obj->IsBlocking())
	{
		if (e->ny < 0)
		{
			if (dynamic_cast<CMario*>(e->obj))
			{
				isOnPlatform = false;
			}
			else
			{
				isOnPlatform = true;
				vy = 0;
			}
			
		}
		
		
	}
	else
	{
		if (e->ny < 0)
		{
			isOnPlatform = false;
		}
	}

}