#include "MobSpawner.h"

#include "Game.h"
#include "Goomba.h"
#include "Paragoomba.h"
#include "RedKoopa.h"
#include "PiranhaPlant.h"
#include "PiranhaClamp.h"
#include "BoomerangBro.h"
#include "GreenKoopa.h"
#include "MovingPlatform.h"
#include "PlayScene.h"
#include "debug.h"

CMobSpawner::CMobSpawner(float x, float y, SpawnerType type, int option) {
    this->x = x;
    this->y = y;
    this->type = type;
    this->option = option;
    mob = nullptr;
    isRespawnable = true;
}

CMobSpawner::CMobSpawner(float x, float y, SpawnerType type) {
    this->x = x;
    this->y = y;
    this->type = type;
    this->option = 0;
    mob = nullptr;
    isRespawnable = true;
}

void CMobSpawner::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
    float cx, cy;
    CGame::GetInstance()->GetCamPos(cx, cy);
    
    int sw = CGame::GetInstance()->GetBackBufferWidth();
    int sh = CGame::GetInstance()->GetBackBufferHeight();

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
            mob = new CRedKoopa(x, y, this->option);
            break;
        case SPAWNER_KOOPA_GREEN:
            mob = new CGreenKoopa(x, y, this->option);
            break;
        case SPAWNER_PIRANHAPLANT:
            mob = new CPiranhaPlant(x, y, this->option);
            break;
        case SPAWNER_PIRANHACLAMP:
            mob = new CPiranhaClamp(x, y);
            break;
        case SPAWNER_BOOMERANGBRO:
            mob = new CBoomerangBro(x, y);
            break;
        case SPAWNER_MOVING_PLATFORM:
        {
            mob = new CMovingPlatform(x,y);
            break;
        }
        }

        if (mob) {
            CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
            mob->SetPosition(x, y);
            scene->AddObject(mob, 1);

            isRespawnable = false;
        }
    }
}
