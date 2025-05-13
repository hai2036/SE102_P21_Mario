#pragma once
#include "Game.h"
#include "Textures.h"
#include "Scene.h"

#include "GameObject.h"
#include "Mario.h"
#include "Portal.h"
#include "Coin.h"
#include "Platform.h"
#include "Border.h"
#include "Ground.h"
#include "BoxPlatform.h"
#include "Pipe.h"
#include "Blocks.h"
#include "BackgroundBush.h"
#include "BackgroundCloud.h"
#include "PrizeBlock.h"
#include "Brick.h"
#include "Goomba.h"
#include "Paragoomba.h"
#include "PiranhaPlant.h"
//#include "Koopas.h"


class CPlayScene: public CScene
{
protected: 
	// A play scene has to have player, right? 
	LPGAMEOBJECT player;					

	vector<LPGAMEOBJECT> objects;

	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);

	void _ParseSection_ASSETS(string line);
	void _ParseSection_OBJECTS(string line);

	void LoadAssets(LPCWSTR assetFile);
	
public: 
	CPlayScene(int id, LPCWSTR filePath);

	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();

	LPGAMEOBJECT GetPlayer() { return player; }

	void AddObject(LPGAMEOBJECT obj);
	void Clear();
	void PurgeDeletedObjects();

	static bool IsGameObjectDeleted(const LPGAMEOBJECT& o);
};

typedef CPlayScene* LPPLAYSCENE;

