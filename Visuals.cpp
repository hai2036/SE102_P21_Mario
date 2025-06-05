#include "Visuals.h"

#include "Particle.h"
#include "Debris.h"

void spawnParticle(int x, int y, int aniId)
{
	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	scene->AddObject(new CParticle(x, y, aniId), 3);
}

void spawnScoreParticle(int x, int y)
{
	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	scene->AddObject(new CParticle(x, y - UNIT_SIZE/2, ID_ANI_PARTICLE_SCORE + 1, 0, -UNIT_SIZE*2, 1000), 3);
}

void spawnDebris(int x, int y, int aniId)
{
	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	scene->AddObject(new CDebris(x, y, -0.5, 0.6, aniId, 1000), 3);
	scene->AddObject(new CDebris(x, y, -0.25, 1, aniId, 1000), 3);
	scene->AddObject(new CDebris(x, y, 0.25, 1, aniId, 1000), 3);
	scene->AddObject(new CDebris(x, y, 0.5, 0.6, aniId, 1000), 3);
}