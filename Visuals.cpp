#include "Visuals.h"

void spawnParticle(int x, int y, int aniId)
{
	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	scene->AddObject(new CParticle(x, y, aniId), 3);
}

void spawnScoreParticle(int x, int y)
{
	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	scene->AddObject(new CParticle(x, y, ID_ANI_PARTICLE_SCORE + 1, 0, -UNIT_SIZE), 3);
}