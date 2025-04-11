#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define UNIT_SIZE 16

#define	ID_SPRITE_PIPE1	80001
#define	ID_SPRITE_PIPE2	80002
#define	ID_SPRITE_PIPE3	80003
#define	ID_SPRITE_PIPE4	80004

class CPipe	: public CGameObject {
	int pipe_height;
public:
	CPipe(float x, float y, int pipe_height) : CGameObject(x, y) 
	{
		this->pipe_height = pipe_height;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};

