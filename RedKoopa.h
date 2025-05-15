#pragma once
#include "Koopa.h"
#include "GhostBlock.h"

#define ID_ANI_RED_KOOPA_WALKING_LEFT 6000
#define ID_ANI_RED_KOOPA_WALKING_RIGHT 6001
#define ID_ANI_RED_KOOPA_DIE 6002

#define ID_ANI_RED_KOOPA_HIDE 6003
#define ID_ANI_RED_KOOPA_WAKE_UP 6004
#define ID_ANI_RED_KOOPA_SPINNING 6005

#define ID_ANI_RED_KOOPA_UPSIDE_DOWN_HIDE 6013
#define ID_ANI_RED_KOOPA_UPSIDE_DOWN_WAKE_UP 6014
#define ID_ANI_RED_KOOPA_UPSIDE_DOWN_SPINNING 6015

class CRedKoopa: public CKoopa
{
	LPGAMEOBJECT ghostBlock;
	virtual int GetAniID();
public:
	CRedKoopa(float x, float y);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

