#include "RedKoopa.h"
#include "Game.h"
#include "debug.h"

CRedKoopa::CRedKoopa(float x, float y) :CKoopa(x, y)
{
	this->ghostBlock = new CGhostBlock(x + UNIT_SIZE, y);
	CGame::GetInstance()->GetCurrentScene()->AddObject(this->ghostBlock);
}
void CRedKoopa::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	CKoopa::Update(dt, coObjects);
	CGhostBlock* ghostblock = dynamic_cast<CGhostBlock*>(this->ghostBlock);

	if (this->state == KOOPA_STATE_WALKING)
	{
		float temp_x, temp_y;
		ghostBlock->GetPosition(temp_x, temp_y);
		if (ghostblock->IsOnPlatform() == false)
		{
			vx = -vx;
			temp_y = y;
		}

		if (vx >0)
		{
			ghostblock->SetPosition(x + KOOPA_BBOX_WIDTH/2 + GHOST_BLOCK_WIDTH /2, temp_y);

		}
		else
		{
			ghostblock->SetPosition(x - (KOOPA_BBOX_WIDTH / 2 + GHOST_BLOCK_WIDTH / 2), temp_y);

		}

		
	}
}