#include "Visuals.h"

void spawnParticle(int x, int y, int aniId)
{
	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	scene->AddObject(new CParticle(x, y, aniId), 3);
}

void spawnScoreParticle(int x, int y, int score)
{
	if (score ==0)
	{
		return;
	}
	score = score / 100;
	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	scene->AddObject(new CParticle(x, y - UNIT_SIZE/2, ID_ANI_PARTICLE_SCORE + score, 0, -UNIT_SIZE*2, 1000), 3);
}