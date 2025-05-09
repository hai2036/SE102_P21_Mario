#pragma once
#include "Koopa.h"
#include "GhostBlock.h"

class CRedKoopa: public CKoopa
{
	LPGAMEOBJECT ghostBlock;
public:
	CRedKoopa(float x, float y);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

