#pragma once
#include "Koopa.h"

class CRedKoopa: public CKoopa
{
public:
	CRedKoopa(float x, float y) :CKoopa(x, y){};
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

