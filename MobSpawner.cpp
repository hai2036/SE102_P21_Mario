#include "MobSpawner.h"

#include "Game.h"
#include "Goomba.h"
#include "Paragoomba.h"
#include "RedKoopa.h"
#include "PiranhaPlant.h"
#include "PlayScene.h"

CMobSpawner::CMobSpawner(float x, float y, SpawnerType type) {
    this->x = x;
    this->y = y;
    this->type = type;

    mob = nullptr;
    isRespawnable = true;
}

void CMobSpawner::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
    float cx, cy;
    CGame::GetInstance()->GetCamPos(cx, cy);
    
    float sw = CGame::GetInstance()->GetBackBufferWidth();
    float sh = CGame::GetInstance()->GetBackBufferHeight();

    bool inSpawnzone = (x >= cx - UNIT_SIZE * 2 && x <= cx + sw + UNIT_SIZE * 2 &&
        y >= cy - UNIT_SIZE * 2 && y <= cy + sh + UNIT_SIZE * 2);

    if (!inSpawnzone && (!mob || mob->IsDeleted())) {
        isRespawnable = true;
        return;
    }

    if (isRespawnable && (!mob || mob->IsDeleted())) {
        switch (type) {
        case SPAWNER_GOOMBA:
            mob = new CGoomba(x, y);
            break;
        case SPAWNER_PARAGOOMBA:
            mob = new CParagoomba(x, y);
            break;
        case SPAWNER_KOOPA_RED:
            mob = new CRedKoopa(x, y);
            break;
        case SPAWNER_PIRANHAPLANT_RED:
            mob = new CPiranhaPlant(x, y);
            break;
        }

        if (mob) {
            CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
            mob->SetPosition(x, y);
            scene->AddObject(mob);

            isRespawnable = false;
        }
    }
}
