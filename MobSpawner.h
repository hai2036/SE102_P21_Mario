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
    LPGAMEOBJECT mob;

    bool isRespawnable;

    virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom) {};
    virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
    virtual void Render() {};

    virtual int IsCollidable() { return 0; };
    virtual int IsBlocking() { return 0; }
    virtual void OnNoCollision(DWORD dt) {};
public:
    CMobSpawner(float x, float y, SpawnerType type);
};
