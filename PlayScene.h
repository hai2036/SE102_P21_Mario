#pragma once
#include "Game.h"
#include "Textures.h"
#include "Scene.h"

#include "GameObject.h"

class CPlayScene: public CScene
{
protected: 
	vector<vector<LPGAMEOBJECT>> objects;
	int numberOfLayers;
	float playSceneLength;

	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);

	void _ParseSection_ASSETS(string line);
	void _ParseSection_LAYERS(string line);
	void _ParseSection_OBJECTS(string line);
	void _ParseSection_LENGTH(string line);

	void LoadAssets(LPCWSTR assetFile);
	
public: 
	CPlayScene(int id, LPCWSTR filePath);

	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();

	LPGAMEOBJECT GetPlayer() 
	{
		LPGAMEOBJECT player = CGame::GetInstance()->GetPlayer();
		return player; 
	}

	void AddObject(LPGAMEOBJECT obj, int layer);
	virtual vector<vector<LPGAMEOBJECT>> GetObjects() { return this->objects; };
	void Clear();
	void PurgeDeletedObjects();

	static bool IsGameObjectDeleted(const LPGAMEOBJECT& o);
};

typedef CPlayScene* LPPLAYSCENE;

