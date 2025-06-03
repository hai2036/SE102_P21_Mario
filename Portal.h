#pragma once

#include "GameObject.h"

/*
	Object that triggers scene switching
*/
class CPortal : public CGameObject
{
	int scene_id;	// target scene to switch to 

	float width;
	float height;

	float tele_x;	//x,y of mario on new scence | (-16,-16): is for take the mario playscence x,y 
	float tele_y;
public:
	CPortal(float l, float t, float r, float b, int scene_id, float tele_x, float tele_y);
	virtual void Render();
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);

	void RenderBoundingBox(void);
	
	void GetTelePosition(float& tele_x, float& tele_y);
	int GetSceneId() { return scene_id;  }
	int IsBlocking() { return 0; }

};