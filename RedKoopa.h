#pragma once
#include "Koopa.h"
#include "GhostBlock.h"

#define ID_ANI_RED_KOOPA_WALKING_LEFT 6000
#define ID_ANI_RED_KOOPA_WALKING_RIGHT 6001
#define ID_ANI_RED_KOOPA_WING_WALKING_LEFT 6100
#define ID_ANI_RED_KOOPA_DIE 6002

#define ID_ANI_RED_KOOPA_HIDE 6003
#define ID_ANI_RED_KOOPA_WAKE_UP 6004
#define ID_ANI_RED_KOOPA_SPINNING 6005

#define ID_ANI_RED_KOOPA_UPSIDE_DOWN_HIDE 6013
#define ID_ANI_RED_KOOPA_UPSIDE_DOWN_WAKE_UP 6014
#define ID_ANI_RED_KOOPA_UPSIDE_DOWN_SPINNING 6015

#define RED_KOOPA_WING_FLY_SPEED 0.075f

class CRedKoopa: public CKoopa
{
	LPGAMEOBJECT ghostBlock;
	virtual int GetAniID();
public:
	CRedKoopa(float x, float y, BOOLEAN wing);
	virtual void OnNoCollision(DWORD dt);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

