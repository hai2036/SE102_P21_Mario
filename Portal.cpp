#include "Portal.h"
#include "Game.h"
#include "Textures.h"

CPortal::CPortal(float l, float t, float r, float b, int scene_id, float tele_x, float tele_y)
{
	this->scene_id = scene_id;
	x = l; 
	y = t;
	width = r - l;
	height = b - t;
	this->tele_x = tele_x;
	this->tele_y = tele_y;
}

void CPortal::RenderBoundingBox()
{
	D3DXVECTOR3 p(x, y, 0);
	RECT rect;

	LPTEXTURE bbox = CTextures::GetInstance()->Get(ID_TEX_BBOX);

	float l, t, r, b;

	GetBoundingBox(l, t, r, b);
	rect.left = 0;
	rect.top = 0;
	rect.right = (int)r - (int)l;
	rect.bottom = (int)b - (int)t;

	float cx, cy;
	CGame::GetInstance()->GetCamPos(cx, cy);

	CGame::GetInstance()->Draw(x - cx, y - cy, bbox, nullptr, BBOX_ALPHA, rect.right - 1, rect.bottom - 1);
}

void CPortal::Render()
{
	RenderBoundingBox();
}

void CPortal::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x - width/2;
	t = y - height/2;
	r = x + width/2;
	b = y + height/2;
}


void CPortal::GetTelePosition(float& tele_x, float& tele_y)
{
	tele_x = this->tele_x;
	tele_y = this->tele_y;
}
