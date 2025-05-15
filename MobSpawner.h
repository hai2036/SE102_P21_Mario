#pragma once
#include "GameObject.h"

enum SpawnerType {
    SPAWNER_GOOMBA,
    SPAWNER_PARAGOOMBA,
    SPAWNER_KOOPA_RED,
    SPAWNER_PIRANHAPLANT_RED
};

class CMobSpawner : public CGameObject {
protected:
    SpawnerType type;
    LPGAMEOBJECT mob = nullptr;
public:
    CMobSpawner(float x, float y, SpawnerType type);

    void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) override;
    void Render() override {}
};
