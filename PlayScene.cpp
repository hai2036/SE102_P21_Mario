#include <iostream>
#include <fstream>
#include "AssetIDs.h"

#include "PlayScene.h"
#include "Utils.h"
#include "Textures.h"
#include "Sprites.h"

#include "HUD.h"
#include "Mario.h"
#include "MobSpawner.h"
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
#include "BackgroundHill.h"
#include "BackgroundFishcake.h"
#include "BackgroundEndVoid.h"
#include "BackgroundEndHill.h"
#include "PrizeBlock.h"
#include "Brick.h"
#include "Goomba.h"
#include "Paragoomba.h"
#include "BoomerangBro.h"
#include "PiranhaPlant.h"
#include "PiranhaClamp.h"
#include "Koopa.h"
#include "RedKoopa.h"
#include "MovingPlatform.h"
#include "SampleKeyEventHandler.h"

using namespace std;

CPlayScene::CPlayScene(int id, LPCWSTR filePath):
	CScene(id, filePath)
{
	this->numberOfLayers = 0;
	this->playSceneLength = 0;
	key_handler = new CSampleKeyHandler(this);
}


#define SCENE_SECTION_UNKNOWN -1
#define SCENE_SECTION_ASSETS	1
#define SCENE_SECTION_OBJECTS	2
#define SCENE_SECTION_LAYERS	3
#define SCENE_SECTION_LENGTH	4

#define ASSETS_SECTION_UNKNOWN -1
#define ASSETS_SECTION_SPRITES 1
#define ASSETS_SECTION_ANIMATIONS 2

#define MAX_SCENE_LINE 1024

void CPlayScene::_ParseSection_SPRITES(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 6) return; // skip invalid lines

	int ID = atoi(tokens[0].c_str());
	int l = atoi(tokens[1].c_str());
	int t = atoi(tokens[2].c_str());
	int r = atoi(tokens[3].c_str());
	int b = atoi(tokens[4].c_str());
	int texID = atoi(tokens[5].c_str());

	LPTEXTURE tex = CTextures::GetInstance()->Get(texID);
	if (tex == NULL)
	{
		DebugOut(L"[ERROR] Texture ID %d not found!\n", texID);
		return; 
	}

	CSprites::GetInstance()->Add(ID, l, t, r, b, tex);
}

void CPlayScene::_ParseSection_ASSETS(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 1) return;

	wstring path = ToWSTR(tokens[0]);
	
	LoadAssets(path.c_str());
}

void CPlayScene::_ParseSection_LAYERS(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 1) return;

	this->numberOfLayers = atoi(tokens[0].c_str());

	for (int i = 0; i < this->numberOfLayers; i++)
	{
		vector<LPGAMEOBJECT> layers;
		objects.push_back(layers);
	}

}

void CPlayScene::_ParseSection_LENGTH(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 1) return;

	this->playSceneLength = atof(tokens[0].c_str())*UNIT_SIZE;

	

}

void CPlayScene::_ParseSection_ANIMATIONS(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 3) return; // skip invalid lines - an animation must at least has 1 frame and 1 frame time

	//DebugOut(L"--> %s\n",ToWSTR(line).c_str());

	LPANIMATION ani = new CAnimation();

	int ani_id = atoi(tokens[0].c_str());
	for (int i = 1; i < tokens.size(); i += 2)	// why i+=2 ?  sprite_id | frame_time  
	{
		int sprite_id = atoi(tokens[i].c_str());
		int frame_time = atoi(tokens[i+1].c_str());
		ani->Add(sprite_id, frame_time);
	}

	CAnimations::GetInstance()->Add(ani_id, ani);
}

/*
	Parse a line in section [OBJECTS] 
*/
void CPlayScene::_ParseSection_OBJECTS(string line)
{
	vector<string> tokens = split(line);

	// skip invalid lines - an object set must have at least id, x, y, z
	if (tokens.size() < 3) return;

	int object_type = atoi(tokens[0].c_str());
	float x = (float)atof(tokens[1].c_str()) * UNIT_SIZE;
	float y = (float)atof(tokens[2].c_str()) * UNIT_SIZE;
	int z = atoi(tokens[3].c_str());


	CGameObject *obj = NULL;

	switch (object_type)
	{
	case OBJECT_TYPE_BORDER:
	{
		int width = atoi(tokens[4].c_str());
		int height = atoi(tokens[5].c_str());
		int type = atoi(tokens[6].c_str());
		obj = new CBorder(x, y, width, height, type);
		break;
	}
	case OBJECT_TYPE_MARIO:
	{
		LPGAMEOBJECT player = GetPlayer();
		float tempX, tempY;
		if (player == nullptr) // If mario hasn't been created
		{
			player = new CMario(-1, -1);
			DebugOut(L"[INFO] Player object has been created!\n");
			
		}
		player->GetPosition(tempX, tempY);
		if (tempX == -UNIT_SIZE && tempY == -UNIT_SIZE)
		{
			player->SetPosition(x, y);
		}

		objects[z].push_back(player);

		return;
	}
		
	case OBJECT_TYPE_GOOMBA: obj = new CMobSpawner(x, y, SPAWNER_GOOMBA); break;
	case OBJECT_TYPE_PARAGOOMBA: obj = new CMobSpawner(x, y, SPAWNER_PARAGOOMBA); break;
	case OBJECT_TYPE_BOOMERANGBRO: obj = new CMobSpawner(x, y, SPAWNER_BOOMERANGBRO); break;
	case OBJECT_TYPE_PIRANHAPLANT:
	{
		x += UNIT_SIZE / 2;
		y += UNIT_SIZE / 2;

		bool isGreen = atoi(tokens[4].c_str());
		obj = new CMobSpawner(x, y, SPAWNER_PIRANHAPLANT, isGreen);
		obj->SetPosition(x, y);
		objects[z].push_back(obj);
		return;
	}
	case OBJECT_TYPE_PIRANHACLAMP:
	{
		x += UNIT_SIZE / 2;
		y += UNIT_SIZE / 3;
		obj = new CMobSpawner(x, y, SPAWNER_PIRANHACLAMP);
		obj->SetPosition(x, y);
		objects[z].push_back(obj);
		return;
	}
	case OBJECT_TYPE_KOOPAS:
	{
		int koopas_type = atoi(tokens[4].c_str());
		int wing = atoi(tokens[5].c_str());
		switch (koopas_type)
		{
		case KOOPA_TYPE_RED:
		{
			obj = new CMobSpawner(x, y, SPAWNER_KOOPA_RED, wing);
			break;
		}
		case KOOPA_TYPE_GREEN:
		{
			obj = new CMobSpawner(x, y, SPAWNER_KOOPA_GREEN, wing);
			break;
		}
			
		default:
			break;
		}
		 
		break; 
	}
	case OBJECT_TYPE_BRICK:
	{
		int prizeID = atoi(tokens[4].c_str());
		if (tokens.size() > 6) {
			int	length = atoi(tokens[5].c_str());
			int	height = atoi(tokens[6].c_str());

			for (int k = 0; k < height; k++)
			{
				float yy = y + UNIT_SIZE * k;
				for (int i = 0; i < length; i++)
				{
					float xx = x + UNIT_SIZE * i;
					obj = new CBrick(x, y, prizeID);
					obj->SetPosition(xx, yy);
					objects[z].push_back(obj);
				}
			}
			
			return;
		}
		else
		{
			obj = new CBrick(x, y, prizeID);
		}
		break;
	}

	case OBJECT_TYPE_COIN:
	{
		int columns = atoi(tokens[4].c_str());
		int rows = atoi(tokens[5].c_str());

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				float xx = x + UNIT_SIZE * j;
				float yy = y + UNIT_SIZE * i;
				obj = new CCoin(xx, yy);
				obj->SetPosition(xx, yy);
				objects[z].push_back(obj);
			}
		}
		return;
	}


	case OBJECT_TYPE_PLATFORM:
	{

		float cell_width = (float)atof(tokens[4].c_str());
		float cell_height = (float)atof(tokens[5].c_str());
		int length = atoi(tokens[6].c_str());
		int sprite_begin = atoi(tokens[7].c_str());
		int sprite_middle = atoi(tokens[8].c_str());
		int sprite_end = atoi(tokens[9].c_str());

		obj = new CPlatform(
			x, y,
			cell_width, cell_height, length,
			sprite_begin, sprite_middle, sprite_end
		);

		break;
	}
	case OBJECT_TYPE_MOVING_PLATFORM:
	{
		obj = new CMobSpawner(x, y, SPAWNER_MOVING_PLATFORM);
		break;
	}
	case OBJECT_TYPE_GROUND:
	{
		// for object with 6 different sprite
		int ground_width = atoi(tokens[4].c_str());
		int ground_height = atoi(tokens[5].c_str());
		int ground_spriteID = atoi(tokens[6].c_str());
		obj = new CGround(x, y, ground_width, ground_height, ground_spriteID);
		break;
	}
	case OBJECT_TYPE_BOX_PLATFORM:
	{
		int box_width = atoi(tokens[4].c_str());
		int box_height = atoi(tokens[5].c_str());
		int color = atoi(tokens[6].c_str());
		obj = new CBoxPlatform(x, y, box_width, box_height, color);
		break;
	}
	case OBJECT_TYPE_PIPE:
	{
		int height = atoi(tokens[4].c_str());
		int isUpSideDown = atoi(tokens[5].c_str());
		int spriteID = atoi(tokens[6].c_str());
		obj = new CPipe(x, y, height, isUpSideDown, spriteID);
		break;
	}
	case OBJECT_TYPE_BLOCKS:
	{
		int length = atoi(tokens[4].c_str());
		int height = atoi(tokens[5].c_str());
		int sprite_id = atoi(tokens[6].c_str());
		obj = new CBlocks(x, y, length, height, sprite_id);
		break;
	}
	case OBJECT_TYPE_PRIZE_BLOCK:
	{
		int prizeID = atoi(tokens[4].c_str());
		obj = new CPrizeBlock(x, y, prizeID);
		break;
	}
	case OBJECT_TYPE_PORTAL:
	{
		float r = (float)atof(tokens[4].c_str())*UNIT_SIZE;
		float b = (float)atof(tokens[5].c_str())* UNIT_SIZE;
		int scene_id = atoi(tokens[6].c_str());
		float tele_x = (float)atof(tokens[7].c_str()) * UNIT_SIZE;
		float tele_y = (float)atof(tokens[8].c_str()) * UNIT_SIZE;
		obj = new CPortal(x, y, r, b, scene_id, tele_x, tele_y);
		break;
	}
	case OBJECT_TYPE_BACKGROUND_BUSH:
	{
		int length = atoi(tokens[4].c_str());
		obj = new CBackgroundBush(x, y, length);
		break;
	}
	case OBJECT_TYPE_BACKGROUND_CLOUD:
	{
		int length = atoi(tokens[4].c_str());
		obj = new CBackgroundCloud(x, y, length);
		break;
	}
	case OBJECT_TYPE_BACKGROUND_HILL:
	{
		int height = atoi(tokens[4].c_str());
		bool leftOutline = atoi(tokens[5].c_str());
		bool rightOutline = atoi(tokens[6].c_str());
		obj = new CBackgroundHill(x, y, height, leftOutline, rightOutline);
		break;
	}
	case OBJECT_TYPE_BACKGROUND_FISHCAKE:
	{
		bool isBig = atoi(tokens[4].c_str());
		obj = new CBackgroundFishcake(x, y, isBig);
		break;
	};
	case OBJECT_TYPE_BACKGROUND_END_VOID:
	{
		int width = atoi(tokens[4].c_str());
		int height = atoi(tokens[5].c_str());
		obj = new CBackgroundEndVoid(x, y, width, height);
		break;
	}
	case OBJECT_TYPE_BACKGROUND_END_HILL:
	{
		int height = atoi(tokens[4].c_str());
		bool leftOutline = atoi(tokens[5].c_str());
		bool rightOutline = atoi(tokens[6].c_str());
		obj = new CBackgroundEndHill(x, y, height, leftOutline, rightOutline);
		break;
	}

	break;
	default:
		DebugOut(L"[ERROR] Invalid object type: %d\n", object_type);
		return;
	}

	// General object setup
	obj->SetPosition(x, y);


	objects[z].push_back(obj);
}

void CPlayScene::LoadAssets(LPCWSTR assetFile)
{
	DebugOut(L"[INFO] Start loading assets from : %s \n", assetFile);

	ifstream f;
	f.open(assetFile);

	int section = ASSETS_SECTION_UNKNOWN;

	char str[MAX_SCENE_LINE];
	while (f.getline(str, MAX_SCENE_LINE))
	{
		string line(str);

		if (line[0] == '#') continue;	// skip comment lines	

		if (line == "[SPRITES]") { section = ASSETS_SECTION_SPRITES; continue; };
		if (line == "[ANIMATIONS]") { section = ASSETS_SECTION_ANIMATIONS; continue; };
		if (line[0] == '[') { section = SCENE_SECTION_UNKNOWN; continue; }

		//
		// data section
		//
		switch (section)
		{
		case ASSETS_SECTION_SPRITES: _ParseSection_SPRITES(line); break;
		case ASSETS_SECTION_ANIMATIONS: _ParseSection_ANIMATIONS(line); break;
		}
	}

	f.close();

	DebugOut(L"[INFO] Done loading assets from %s\n", assetFile);
}

void CPlayScene::Load()
{
	DebugOut(L"[INFO] Start loading scene from : %s \n", sceneFilePath);

	ifstream f;
	f.open(sceneFilePath);

	// current resource section flag
	int section = SCENE_SECTION_UNKNOWN;					

	char str[MAX_SCENE_LINE];
	while (f.getline(str, MAX_SCENE_LINE))
	{
		string line(str);

		if (line[0] == '#') continue;	// skip comment lines	
		if (line == "[ASSETS]") { section = SCENE_SECTION_ASSETS; continue; };
		if (line == "[LAYERS]") { section = SCENE_SECTION_LAYERS; continue; };
		if (line == "[OBJECTS]") { section = SCENE_SECTION_OBJECTS; continue; };
		if (line == "[LENGTH]") { section = SCENE_SECTION_LENGTH; continue; };
		if (line[0] == '[') { section = SCENE_SECTION_UNKNOWN; continue; }	

		//
		// data section
		//
		switch (section)
		{ 
			case SCENE_SECTION_ASSETS: _ParseSection_ASSETS(line); break;
			case SCENE_SECTION_LAYERS: _ParseSection_LAYERS(line); break;
			case SCENE_SECTION_OBJECTS: _ParseSection_OBJECTS(line); break;
			case SCENE_SECTION_LENGTH: _ParseSection_LENGTH(line); break;
		}
	}

	f.close();
	HUD* hud = HUD::GetInstance();
	objects[numberOfLayers-1].push_back(LPGAMEOBJECT(hud));
	hud->StartTimer();
	DebugOut(L"[INFO] Done loading scene  %s\n", sceneFilePath);
}

void CPlayScene::Update(DWORD dt)
{
	// We know that Mario is the first object in the list hence we won't add him into the colliable object list
	// TO-DO: This is a "dirty" way, need a more organized way 
	vector<LPGAMEOBJECT> coObjects;
	for (int i = 0; i < this->numberOfLayers; i++)
	{
		for (size_t k = 0; k < objects[i].size(); k++)
		{
			coObjects.push_back(objects[i][k]);
		}
	}
	
	for (int i = 0; i < this->numberOfLayers; i++)
	{
		for (size_t k = 0; k < objects[i].size(); k++)
		{
			objects[i][k]->Update(dt, &coObjects);
		}
	}
	

	// skip the rest if scene was already unloaded (Mario::Update might trigger PlayScene::Unload)
	LPGAMEOBJECT player = GetPlayer();
	if (player == NULL) return; 

	// Update camera to follow mario
	float cx, cy;
	player->GetPosition(cx, cy);

	CGame *game = CGame::GetInstance();
	cx -= game->GetBackBufferWidth() / 2;
	cy -= game->GetBackBufferHeight() / 2;

	if (cx < 0) cx = 0;
	if (cx >= playSceneLength - game->GetBackBufferWidth())  cx = playSceneLength - game->GetBackBufferWidth();
	if (cy > 224 && !(dynamic_cast<CMario*>(player)->IsFlying())) cy = 224;
	HUD* hud = HUD::GetInstance();
	hud->SetPosition(cx+HUD_WIDTH/2, cy +HUD_HEIGHT/2+ game->GetBackBufferHeight());
	CGame::GetInstance()->SetCamPos(cx, cy + HUD_HEIGHT);

	PurgeDeletedObjects();
}

void CPlayScene::Render()
{
	for (int i = 0; i < this->numberOfLayers; i++)
	{
		for (int k = 0; k < objects[i].size(); k++)
			objects[i][k]->Render();
	}

}

/*
*	Clear all objects from this scene
*/
void CPlayScene::Clear()
{
	for (int i = 0; i < this->numberOfLayers; i++)
	{
		vector<LPGAMEOBJECT>::iterator it;
		for (it = objects[i].begin(); it != objects[i].end(); it++)
		{
			delete (*it);
		}
		objects[i].clear();
	}
	objects.clear();
}

/*
	Unload scene

	TODO: Beside objects, we need to clean up sprites, animations and textures as well 

*/
void CPlayScene::Unload()
{
	
	for (int i = 0; i < this->numberOfLayers; i++)
	{
		for (int k = 0; k < objects[i].size(); k++)
		{
			if (dynamic_cast<CMario*>(objects[i][k]) || dynamic_cast<HUD*>(objects[i][k]))
			{
				continue;
			}
			else
			{
				delete objects[i][k];
			}

		}
		objects[i].clear();
	}
	objects.clear();

	DebugOut(L"[INFO] Scene %d unloaded! \n", id);
}

bool CPlayScene::IsGameObjectDeleted(const LPGAMEOBJECT& o) { return o == NULL; }

void CPlayScene::PurgeDeletedObjects()
{

	for (int i = 0; i < this->numberOfLayers; i++)
	{
		vector<LPGAMEOBJECT>::iterator it;
		for (it = objects[i].begin(); it != objects[i].end(); it++)
		{
			LPGAMEOBJECT o = *it;
			if (o->IsDeleted())
			{
				delete o;
				*it = NULL;
			}
		}

		// NOTE: remove_if will swap all deleted items to the end of the vector
		// then simply trim the vector, this is much more efficient than deleting individual items
		objects[i].erase(
			std::remove_if(objects[i].begin(), objects[i].end(), CPlayScene::IsGameObjectDeleted),
			objects[i].end());
	}
	
}

void CPlayScene::AddObject(LPGAMEOBJECT obj, int layer) {

	objects[layer].push_back(obj);
}
