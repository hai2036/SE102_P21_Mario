#pragma once

//
// This file contains all IDs of game assets 
//

#define ID_TEX_MARIO 0
#define ID_TEX_ENEMY 10
#define ID_TEX_MISC 20
#define ID_TEX_TILES 30
#define ID_TEX_MISC_V2 40
#define ID_TEX_TILES_V2 50
#define ID_TEX_ENEMY_V2 60
#define ID_TEX_GAMEUI 100

// LIVE OBJECTS

#define OBJECT_TYPE_BORDER -1
#define OBJECT_TYPE_MARIO	0
#define OBJECT_TYPE_BRICK	1
#define OBJECT_TYPE_COIN 4
#define OBJECT_TYPE_PLATFORM 5
#define OBJECT_TYPE_GROUND	6
#define OBJECT_TYPE_BOX_PLATFORM 7
#define OBJECT_TYPE_PIPE 8
#define OBJECT_TYPE_BLOCKS 9
#define OBJECT_TYPE_PRIZE_BLOCK 10
#define OBJECT_TYPE_MOVING_PLATFORM 13


// ENEMY
#define OBJECT_TYPE_GOOMBA	2

#define OBJECT_TYPE_KOOPAS	3
#define KOOPA_TYPE_RED 1
#define KOOPA_TYPE_GREEN 2

#define OBJECT_TYPE_PARAGOOMBA	11
#define OBJECT_TYPE_PIRANHAPLANT	12
#define OBJECT_TYPE_PIRANHACLAMP	14
#define OBJECT_TYPE_BOOMERANGBRO	15

// BACKGROUND OBJECTS

#define OBJECT_TYPE_BACKGROUND_BUSH 101
#define OBJECT_TYPE_BACKGROUND_CLOUD 102
#define OBJECT_TYPE_BACKGROUND_HILL 103
#define OBJECT_TYPE_BACKGROUND_FISHCAKE 104
#define OBJECT_TYPE_BACKGROUND_END_VOID	110
#define OBJECT_TYPE_BACKGROUND_END_HILL	111

// PARTICLES
#define OBJECT_TYPE_PARTICLE 200
#define OBJECT_TYPE_DEBRIS 201

// PROJECTILES
#define OBJECT_TYPE_FIREBALL	80
#define OBJECT_TYPE_BOOMERANG	81

// POWER UP
#define OBEJECT_TYPE_LEVEL_UP	20
#define OBJECT_TYPE_SUPER_MUSHROOM 21
#define OBJECT_TYPE_SUPER_LEAF 22
#define OBJECT_TYPE_LIFE_MUSHROOM 23
//
#define OBJECT_TYPE_SWITCH_BLOCK 30
// PORTAL
#define OBJECT_TYPE_PORTAL	50

#pragma region HUD

#define ID_SPRITE_HUD 1000000

#define ID_SPRITE_HUD_BASE (ID_SPRITE_HUD + 1000)
#define ID_SPRITE_HUD_NUMBER (ID_SPRITE_HUD + 2000)
#define ID_SPRITE_HUD_LETTER (ID_SPRITE_HUD + 3000)
#define ID_SPRITE_HUD_SPEED (ID_SPRITE_HUD + 4000)
#define ID_SPRITE_HUD_PSIGN (ID_SPRITE_HUD + 5000)

#define ID_ANI_HUD_PSIGN 99106000

#pragma endregion

#pragma region MARIO 

#define ID_SPRITE_MARIO 10000
#define ID_SPRITE_MARIO_BIG (ID_SPRITE_MARIO + 1000)
#define ID_SPRITE_MARIO_BIG_IDLE (ID_SPRITE_MARIO_BIG + 100)
#define ID_SPRITE_MARIO_BIG_IDLE_LEFT (ID_SPRITE_MARIO_BIG_IDLE + 10)
#define ID_SPRITE_MARIO_BIG_IDLE_RIGHT (ID_SPRITE_MARIO_BIG_IDLE + 20)

#define ID_SPRITE_MARIO_BIG_WALKING (ID_SPRITE_MARIO_BIG + 200)
#define ID_SPRITE_MARIO_BIG_WALKING_LEFT (ID_SPRITE_MARIO_BIG_WALKING + 10)
#define ID_SPRITE_MARIO_BIG_WALKING_RIGHT (ID_SPRITE_MARIO_BIG_WALKING + 20)
#define ID_SPRITE_MARIO_BIG_RUNNING (ID_SPRITE_MARIO_BIG + 300)
#define ID_SPRITE_MARIO_BIG_RUNNING_LEFT (ID_SPRITE_MARIO_BIG_RUNNING + 10)
#define ID_SPRITE_MARIO_BIG_RUNNING_RIGHT (ID_SPRITE_MARIO_BIG_RUNNING + 20)
#define ID_SPRITE_MARIO_BIG_JUMP (ID_SPRITE_MARIO_BIG + 400)
#define ID_SPRITE_MARIO_BIG_JUMP_WALK (ID_SPRITE_MARIO_BIG_JUMP + 10)
#define ID_SPRITE_MARIO_BIG_JUMP_WALK_LEFT (ID_SPRITE_MARIO_BIG_JUMP_WALK + 2)
#define ID_SPRITE_MARIO_BIG_JUMP_WALK_RIGHT (ID_SPRITE_MARIO_BIG_JUMP_WALK + 6)
#define ID_SPRITE_MARIO_BIG_JUMP_RUN (ID_SPRITE_MARIO_BIG_JUMP + 20)
#define ID_SPRITE_MARIO_BIG_JUMP_RUN_LEFT (ID_SPRITE_MARIO_BIG_JUMP_RUN + 2)
#define ID_SPRITE_MARIO_BIG_JUMP_RUN_RIGHT (ID_SPRITE_MARIO_BIG_JUMP_RUN + 6)
#define ID_SPRITE_MARIO_BIG_SIT (ID_SPRITE_MARIO_BIG + 500)
#define ID_SPRITE_MARIO_BIG_SIT_LEFT (ID_SPRITE_MARIO_BIG_SIT + 10)
#define ID_SPRITE_MARIO_BIG_SIT_RIGHT (ID_SPRITE_MARIO_BIG_SIT + 20)
#define ID_SPRITE_MARIO_BIG_BRACE (ID_SPRITE_MARIO_BIG + 600)
#define ID_SPRITE_MARIO_BIG_BRACE_LEFT (ID_SPRITE_MARIO_BIG_BRACE + 10)
#define ID_SPRITE_MARIO_BIG_BRACE_RIGHT (ID_SPRITE_MARIO_BIG_BRACE + 20)

#define ID_SPRITE_MARIO_DIE (ID_SPRITE_MARIO + 3000)

#define ID_SPRITE_MARIO_SMALL (ID_SPRITE_MARIO + 2000)
#define ID_SPRITE_MARIO_SMALL_IDLE (ID_SPRITE_MARIO_SMALL + 100)
#define ID_SPRITE_MARIO_SMALL_IDLE_LEFT (ID_SPRITE_MARIO_SMALL_IDLE + 10)
#define ID_SPRITE_MARIO_SMALL_IDLE_RIGHT (ID_SPRITE_MARIO_SMALL_IDLE + 20)

#define ID_SPRITE_MARIO_SMALL_WALKING (ID_SPRITE_MARIO_SMALL + 200)
#define ID_SPRITE_MARIO_SMALL_WALKING_LEFT (ID_SPRITE_MARIO_SMALL_WALKING + 10)
#define ID_SPRITE_MARIO_SMALL_WALKING_RIGHT (ID_SPRITE_MARIO_SMALL_WALKING + 20)
#define ID_SPRITE_MARIO_SMALL_RUNNING (ID_SPRITE_MARIO_SMALL + 300)
#define ID_SPRITE_MARIO_SMALL_RUNNING_LEFT (ID_SPRITE_MARIO_SMALL_RUNNING + 10)
#define ID_SPRITE_MARIO_SMALL_RUNNING_RIGHT (ID_SPRITE_MARIO_SMALL_RUNNING + 20)
#define ID_SPRITE_MARIO_SMALL_JUMP (ID_SPRITE_MARIO_SMALL + 400)
#define ID_SPRITE_MARIO_SMALL_JUMP_WALK (ID_SPRITE_MARIO_SMALL_JUMP + 10)
#define ID_SPRITE_MARIO_SMALL_JUMP_WALK_LEFT (ID_SPRITE_MARIO_SMALL_JUMP_WALK + 2)
#define ID_SPRITE_MARIO_SMALL_JUMP_WALK_RIGHT (ID_SPRITE_MARIO_SMALL_JUMP_WALK + 6)
#define ID_SPRITE_MARIO_SMALL_JUMP_RUN (ID_SPRITE_MARIO_SMALL_JUMP + 20)
#define ID_SPRITE_MARIO_SMALL_JUMP_RUN_LEFT (ID_SPRITE_MARIO_SMALL_JUMP_RUN + 2)
#define ID_SPRITE_MARIO_SMALL_JUMP_RUN_RIGHT (ID_SPRITE_MARIO_SMALL_JUMP_RUN + 6)

#define ID_SPRITE_MARIO_SMALL_SIT (ID_SPRITE_MARIO_SMALL + 500)
#define ID_SPRITE_MARIO_SMALL_SIT_LEFT (ID_SPRITE_MARIO_SMALL_SIT + 10)
#define ID_SPRITE_MARIO_SMALL_SIT_RIGHT (ID_SPRITE_MARIO_SMALL_SIT + 20)

#define ID_SPRITE_MARIO_SMALL_BRACE (ID_SPRITE_MARIO_SMALL + 500)
#define ID_SPRITE_MARIO_SMALL_BRACE_LEFT (ID_SPRITE_MARIO_SMALL_BRACE + 10)
#define ID_SPRITE_MARIO_SMALL_BRACE_RIGHT (ID_SPRITE_MARIO_SMALL_BRACE + 20)

#pragma endregion 

//GROUND
#define ID_SPRITE_DIRT_GROUND 60000
#define ID_SPRITE_GRASS_GROUND 61000
#define ID_SPRITE_WOODEN_GROUND 62000

//PLATFORM
#define ID_SPRITE_WOODEN_MOVING_PLATFORM	63000

//BRICK

#define ID_SPRITE_BRICK 20000

//GOOMBA

#define ID_SPRITE_GOOMBA 30000
#define ID_SPRITE_GOOMBA_WALK (ID_SPRITE_GOOMBA + 1000)
#define ID_SPRITE_GOOMBA_DIE (ID_SPRITE_GOOMBA + 2000)

//COIN

#define ID_SPRITE_COIN 40000

//CLOUD

#define ID_SPRITE_CLOUD 50000
#define ID_SPRITE_CLOUD_BEGIN (ID_SPRITE_CLOUD + 1000)
#define ID_SPRITE_CLOUD_MIDDLE (ID_SPRITE_CLOUD + 2000)
#define ID_SPRITE_CLOUD_END (ID_SPRITE_CLOUD + 3000)

//BOX PLATFORM
#define ID_SPRITE_BOX_PLATFORM 70000

#define ID_SPRITE_BOX_PLATFORM_SHADOW_CORNER (ID_SPRITE_BOX_PLATFORM + 1)
#define ID_SPRITE_BOX_PLATFORM_SHADOW_EDGE (ID_SPRITE_BOX_PLATFORM + 2)

#define ID_SPRITE_BOX_PLATFORM_WHITE (ID_SPRITE_BOX_PLATFORM + 1000)
#define ID_SPRITE_BOX_PLATFORM_WHITE_1 (ID_SPRITE_BOX_PLATFORM_WHITE + 1)
#define ID_SPRITE_BOX_PLATFORM_WHITE_2 (ID_SPRITE_BOX_PLATFORM_WHITE + 2)
#define ID_SPRITE_BOX_PLATFORM_WHITE_3 (ID_SPRITE_BOX_PLATFORM_WHITE + 3)
#define ID_SPRITE_BOX_PLATFORM_WHITE_4 (ID_SPRITE_BOX_PLATFORM_WHITE + 4)
#define ID_SPRITE_BOX_PLATFORM_WHITE_5 (ID_SPRITE_BOX_PLATFORM_WHITE + 5)
#define ID_SPRITE_BOX_PLATFORM_WHITE_6 (ID_SPRITE_BOX_PLATFORM_WHITE + 6)
#define ID_SPRITE_BOX_PLATFORM_WHITE_7 (ID_SPRITE_BOX_PLATFORM_WHITE + 7)
#define ID_SPRITE_BOX_PLATFORM_WHITE_8 (ID_SPRITE_BOX_PLATFORM_WHITE + 8)
#define ID_SPRITE_BOX_PLATFORM_WHITE_9 (ID_SPRITE_BOX_PLATFORM_WHITE + 9)

#define ID_SPRITE_BOX_PLATFORM_GREEN (ID_SPRITE_BOX_PLATFORM + 2000)
#define ID_SPRITE_BOX_PLATFORM_GREEN_1 (ID_SPRITE_BOX_PLATFORM_GREEN + 1)
#define ID_SPRITE_BOX_PLATFORM_GREEN_2 (ID_SPRITE_BOX_PLATFORM_GREEN + 2)
#define ID_SPRITE_BOX_PLATFORM_GREEN_3 (ID_SPRITE_BOX_PLATFORM_GREEN + 3)
#define ID_SPRITE_BOX_PLATFORM_GREEN_4 (ID_SPRITE_BOX_PLATFORM_GREEN + 4)
#define ID_SPRITE_BOX_PLATFORM_GREEN_5 (ID_SPRITE_BOX_PLATFORM_GREEN + 5)
#define ID_SPRITE_BOX_PLATFORM_GREEN_6 (ID_SPRITE_BOX_PLATFORM_GREEN + 6)
#define ID_SPRITE_BOX_PLATFORM_GREEN_7 (ID_SPRITE_BOX_PLATFORM_GREEN + 7)
#define ID_SPRITE_BOX_PLATFORM_GREEN_8 (ID_SPRITE_BOX_PLATFORM_GREEN + 8)
#define ID_SPRITE_BOX_PLATFORM_GREEN_9 (ID_SPRITE_BOX_PLATFORM_GREEN + 9)

#define ID_SPRITE_BOX_PLATFORM_PINK (ID_SPRITE_BOX_PLATFORM + 3000)
#define ID_SPRITE_BOX_PLATFORM_PINK_1 (ID_SPRITE_BOX_PLATFORM_PINK + 1)
#define ID_SPRITE_BOX_PLATFORM_PINK_2 (ID_SPRITE_BOX_PLATFORM_PINK + 2)
#define ID_SPRITE_BOX_PLATFORM_PINK_3 (ID_SPRITE_BOX_PLATFORM_PINK + 3)
#define ID_SPRITE_BOX_PLATFORM_PINK_4 (ID_SPRITE_BOX_PLATFORM_PINK + 4)
#define ID_SPRITE_BOX_PLATFORM_PINK_5 (ID_SPRITE_BOX_PLATFORM_PINK + 5)
#define ID_SPRITE_BOX_PLATFORM_PINK_6 (ID_SPRITE_BOX_PLATFORM_PINK + 6)
#define ID_SPRITE_BOX_PLATFORM_PINK_7 (ID_SPRITE_BOX_PLATFORM_PINK + 7)
#define ID_SPRITE_BOX_PLATFORM_PINK_8 (ID_SPRITE_BOX_PLATFORM_PINK + 8)
#define ID_SPRITE_BOX_PLATFORM_PINK_9 (ID_SPRITE_BOX_PLATFORM_PINK + 9)

#define ID_SPRITE_BOX_PLATFORM_BLUE (ID_SPRITE_BOX_PLATFORM + 4000)
#define ID_SPRITE_BOX_PLATFORM_BLUE_1 (ID_SPRITE_BOX_PLATFORM_BLUE + 1)
#define ID_SPRITE_BOX_PLATFORM_BLUE_2 (ID_SPRITE_BOX_PLATFORM_BLUE + 2)
#define ID_SPRITE_BOX_PLATFORM_BLUE_3 (ID_SPRITE_BOX_PLATFORM_BLUE + 3)
#define ID_SPRITE_BOX_PLATFORM_BLUE_4 (ID_SPRITE_BOX_PLATFORM_BLUE + 4)
#define ID_SPRITE_BOX_PLATFORM_BLUE_5 (ID_SPRITE_BOX_PLATFORM_BLUE + 5)
#define ID_SPRITE_BOX_PLATFORM_BLUE_6 (ID_SPRITE_BOX_PLATFORM_BLUE + 6)
#define ID_SPRITE_BOX_PLATFORM_BLUE_7 (ID_SPRITE_BOX_PLATFORM_BLUE + 7)
#define ID_SPRITE_BOX_PLATFORM_BLUE_8 (ID_SPRITE_BOX_PLATFORM_BLUE + 8)
#define ID_SPRITE_BOX_PLATFORM_BLUE_9 (ID_SPRITE_BOX_PLATFORM_BLUE + 9)

//PIPE 

#define ID_SPRITE_PIPE 80000
#define	ID_SPRITE_PIPE_HEAD_LEFT (ID_SPRITE_PIPE + 1)
#define	ID_SPRITE_PIPE_HEAD_RIGHT (ID_SPRITE_PIPE + 2)
#define	ID_SPRITE_PIPE_BODY_LEFT (ID_SPRITE_PIPE + 3)
#define	ID_SPRITE_PIPE_BODY_RIGHT (ID_SPRITE_PIPE + 4)

//BLACK PIPE

#define ID_SPRITE_BLACK_PIPE	81000
#define	ID_SPRITE_BLACK_PIPE_HEAD_LEFT (ID_SPRITE_BLACK_PIPE + 1)
#define	ID_SPRITE_BLACK_PIPE_HEAD_RIGHT (ID_SPRITE_BLACK_PIPE + 2)
#define	ID_SPRITE_BLACK_PIPE_BODY_LEFT (ID_SPRITE_BLACK_PIPE + 3)
#define	ID_SPRITE_BLACK_PIPE_BODY_RIGHT (ID_SPRITE_BLACK_PIPE + 4)

//BACKGROUND BUSH

#define ID_SPRITE_BACKGROUND_BUSH 1010000

//BACKGROUND CLOUD

#define ID_SPRITE_BACKGROUND_CLOUD 1020000
#define ID_SPRITE_BACKGROUND_CLOUD_LEFT_TOP (ID_SPRITE_BACKGROUND_CLOUD + 1001)
#define ID_SPRITE_BACKGROUND_CLOUD_LEFT_BOTTOM (ID_SPRITE_BACKGROUND_CLOUD + 1002)
#define ID_SPRITE_BACKGROUND_CLOUD_MIDDLE_TOP (ID_SPRITE_BACKGROUND_CLOUD + 2001)
#define ID_SPRITE_BACKGROUND_CLOUD_MIDDLE_BOTTOM (ID_SPRITE_BACKGROUND_CLOUD + 2002)
#define ID_SPRITE_BACKGROUND_CLOUD_RIGHT_TOP (ID_SPRITE_BACKGROUND_CLOUD + 3001)
#define ID_SPRITE_BACKGROUND_CLOUD_RIGHT_BOTTOM (ID_SPRITE_BACKGROUND_CLOUD + 3002)

//BACKGROUND HILL

#define ID_SPRITE_BACKGROUND_HILL 1030000
#define ID_SPRITE_BACKGROUND_HILL_LEFT_CLIFF (ID_SPRITE_BACKGROUND_HILL + 1001)
#define ID_SPRITE_BACKGROUND_HILL_RIGHT_CLIFF (ID_SPRITE_BACKGROUND_HILL + 1002)
#define ID_SPRITE_BACKGROUND_HILL_LEFT_EDGE (ID_SPRITE_BACKGROUND_HILL + 2001)
#define ID_SPRITE_BACKGROUND_HILL_RIGHT_EDGE (ID_SPRITE_BACKGROUND_HILL + 2002)
#define ID_SPRITE_BACKGROUND_HILL_BODY (ID_SPRITE_BACKGROUND_HILL + 3000)

//BACKGROUND FISHCAKE

#define ID_SPRITE_BACKGROUND_FISHCAKE 1040000
#define ID_SPRITE_BACKGROUND_FISHCAKE_SMALL (ID_SPRITE_BACKGROUND_FISHCAKE + 1000)
#define ID_SPRITE_BACKGROUND_FISHCAKE_BIG_LEFT (ID_SPRITE_BACKGROUND_FISHCAKE + 2001)
#define ID_SPRITE_BACKGROUND_FISHCAKE_BIG_RIGHT (ID_SPRITE_BACKGROUND_FISHCAKE + 2002)

//BACKGROUND END VOID

#define ID_SPRITE_BACKGROUND_END_VOID 1100000
#define ID_SPRITE_BACKGROUND_END_VOID_EDGE (ID_SPRITE_BACKGROUND_END_VOID + 1000)
#define ID_SPRITE_BACKGROUND_END_VOID_BODY (ID_SPRITE_BACKGROUND_END_VOID + 2000)

//BACKGROUND END HILL

#define ID_SPRITE_BACKGROUND_END_HILL 1110000
#define ID_SPRITE_BACKGROUND_END_HILL_LEFT_CLIFF (ID_SPRITE_BACKGROUND_END_HILL + 1001)
#define ID_SPRITE_BACKGROUND_END_HILL_RIGHT_CLIFF (ID_SPRITE_BACKGROUND_END_HILL + 1002)
#define ID_SPRITE_BACKGROUND_END_HILL_LEFT_EDGE (ID_SPRITE_BACKGROUND_END_HILL + 2001)
#define ID_SPRITE_BACKGROUND_END_HILL_RIGHT_EDGE (ID_SPRITE_BACKGROUND_END_HILL + 2002)
#define ID_SPRITE_BACKGROUND_END_HILL_BODY (ID_SPRITE_BACKGROUND_END_HILL + 3000)

//PARTICLE

#define ID_SPRITE_PARTICLE 2000000
#define ID_SPRITE_PARTICLE_SMOKE (ID_SPRITE_PARTICLE + 1000)
#define ID_SPRITE_PARTICLE_HIT (ID_SPRITE_PARTICLE + 2000)
#define ID_SPRITE_PARTICLE_SCORE (ID_SPRITE_PARTICLE + 3000)

#define ID_ANI_PARTICLE_SMOKE 992001000
#define ID_ANI_PARTICLE_HIT 992002000
#define ID_ANI_PARTICLE_SCORE 992003000

//DEBRIS

#define ID_SPRITE_DEBRIS 2010000
#define ID_SPRITE_DEBRIS_BRICK (ID_SPRITE_DEBRIS + 1000)

#define ID_ANI_DEBRIS_BRICK 992011000

//PARAGOOMBA

#define ID_SPRITE_PARAGOOMBA 120000
#define ID_SPRITE_PARAGOOMBA_DIE (ID_SPRITE_PARAGOOMBA + 1000)
#define ID_SPRITE_PARAGOOMBA_FOOT_WALK (ID_SPRITE_PARAGOOMBA + 2000)
#define ID_SPRITE_PARAGOOMBA_WING_WALK (ID_SPRITE_PARAGOOMBA + 3000)
#define ID_SPRITE_PARAGOOMBA_WING_FLY (ID_SPRITE_PARAGOOMBA_WING_WALK + 100)

#define ID_ANI_PARAGOOMBA_DIE 991210
#define ID_ANI_PARAGOOMBA_FOOT_WALK 991220
#define ID_ANI_PARAGOOMBA_WING_WALK 991230
#define ID_ANI_PARAGOOMBA_WING_FLY 991231

//PIRANHAPLANT

#define ID_SPRITE_PIRANHAPLANT 130000

#define ID_SPRITE_PIRANHAPLANT_RED (ID_SPRITE_PIRANHAPLANT + 1000)

#define ID_SPRITE_PIRANHAPLANT_RED_OPEN_DOWN_LEFT (ID_SPRITE_PIRANHAPLANT_RED + 111)
#define ID_SPRITE_PIRANHAPLANT_RED_OPEN_DOWN_RIGHT (ID_SPRITE_PIRANHAPLANT_RED + 112)
#define ID_SPRITE_PIRANHAPLANT_RED_OPEN_UP_LEFT (ID_SPRITE_PIRANHAPLANT_RED + 121)
#define ID_SPRITE_PIRANHAPLANT_RED_OPEN_UP_RIGHT (ID_SPRITE_PIRANHAPLANT_RED + 122)

#define ID_SPRITE_PIRANHAPLANT_RED_CLOSE_DOWN_LEFT (ID_SPRITE_PIRANHAPLANT_RED + 211)
#define ID_SPRITE_PIRANHAPLANT_RED_CLOSE_DOWN_RIGHT (ID_SPRITE_PIRANHAPLANT_RED + 212)
#define ID_SPRITE_PIRANHAPLANT_RED_CLOSE_UP_LEFT (ID_SPRITE_PIRANHAPLANT_RED + 221)
#define ID_SPRITE_PIRANHAPLANT_RED_CLOSE_UP_RIGHT (ID_SPRITE_PIRANHAPLANT_RED + 222)

#define ID_SPRITE_PIRANHAPLANT_GREEN (ID_SPRITE_PIRANHAPLANT + 2000)

#define ID_SPRITE_PIRANHAPLANT_GREEN_OPEN_DOWN_LEFT (ID_SPRITE_PIRANHAPLANT_GREEN + 111)
#define ID_SPRITE_PIRANHAPLANT_GREEN_OPEN_DOWN_RIGHT (ID_SPRITE_PIRANHAPLANT_GREEN + 112)
#define ID_SPRITE_PIRANHAPLANT_GREEN_OPEN_UP_LEFT (ID_SPRITE_PIRANHAPLANT_GREEN + 121)
#define ID_SPRITE_PIRANHAPLANT_GREEN_OPEN_UP_RIGHT (ID_SPRITE_PIRANHAPLANT_GREEN + 122)

#define ID_SPRITE_PIRANHAPLANT_GREEN_CLOSE_DOWN_LEFT (ID_SPRITE_PIRANHAPLANT_GREEN + 211)
#define ID_SPRITE_PIRANHAPLANT_GREEN_CLOSE_DOWN_RIGHT (ID_SPRITE_PIRANHAPLANT_GREEN + 212)
#define ID_SPRITE_PIRANHAPLANT_GREEN_CLOSE_UP_LEFT (ID_SPRITE_PIRANHAPLANT_GREEN + 221)
#define ID_SPRITE_PIRANHAPLANT_GREEN_CLOSE_UP_RIGHT (ID_SPRITE_PIRANHAPLANT_GREEN + 222)

#define ID_ANI_PIRANHAPLANT_CHOMP 99130000

#define ID_ANI_PIRANHAPLANT_CHOMP_RED (ID_ANI_PIRANHAPLANT_CHOMP + 1000)

#define ID_ANI_PIRANHAPLANT_CHOMP_RED_DOWN_LEFT (ID_ANI_PIRANHAPLANT_CHOMP_RED + 11)
#define ID_ANI_PIRANHAPLANT_CHOMP_RED_DOWN_RIGHT (ID_ANI_PIRANHAPLANT_CHOMP_RED + 12)
#define ID_ANI_PIRANHAPLANT_CHOMP_RED_UP_LEFT (ID_ANI_PIRANHAPLANT_CHOMP_RED + 21)
#define ID_ANI_PIRANHAPLANT_CHOMP_RED_UP_RIGHT (ID_ANI_PIRANHAPLANT_CHOMP_RED + 22)

#define ID_ANI_PIRANHAPLANT_CHOMP_GREEN (ID_ANI_PIRANHAPLANT_CHOMP + 2000)

#define ID_ANI_PIRANHAPLANT_CHOMP_GREEN_DOWN_LEFT (ID_ANI_PIRANHAPLANT_CHOMP_GREEN + 11)
#define ID_ANI_PIRANHAPLANT_CHOMP_GREEN_DOWN_RIGHT (ID_ANI_PIRANHAPLANT_CHOMP_GREEN + 12)
#define ID_ANI_PIRANHAPLANT_CHOMP_GREEN_UP_LEFT (ID_ANI_PIRANHAPLANT_CHOMP_GREEN + 21)
#define ID_ANI_PIRANHAPLANT_CHOMP_GREEN_UP_RIGHT (ID_ANI_PIRANHAPLANT_CHOMP_GREEN + 22)

//PIRANHACLAMP

#define ID_SPRITE_PIRANHACLAMP 140000

#define ID_ANI_PIRANHACLAMP_CHOMP 99140000

//BOOMERANGBRO

#define ID_SPRITE_BOOMERANGBRO 150000

#define ID_SPRITE_BOOMERANGBRO_DIE (ID_SPRITE_BOOMERANGBRO + 1000)

#define ID_SPRITE_BOOMERANGBRO_WALK (ID_SPRITE_BOOMERANGBRO + 2000
#define ID_SPRITE_BOOMERANGBRO_WALK_UNREADY (ID_SPRITE_BOOMERANGBRO_WALK + 100)
#define ID_SPRITE_BOOMERANGBRO_WALK_READY (ID_SPRITE_BOOMERANGBRO_WALK + 200)

#define ID_ANI_BOOMERANGBRO_DIE 99151000

#define ID_ANI_BOOMERANGBRO_WALK_UNREADY_STAND_LEFT 99152110
#define ID_ANI_BOOMERANGBRO_WALK_UNREADY_MOVE_LEFT (ID_ANI_BOOMERANGBRO_WALK_UNREADY_STAND_LEFT + 1)

#define ID_ANI_BOOMERANGBRO_WALK_READY_STAND_LEFT 99152210
#define ID_ANI_BOOMERANGBRO_WALK_READY_MOVE_LEFT (ID_ANI_BOOMERANGBRO_WALK_READY_STAND_LEFT + 1)

#define ID_ANI_BOOMERANGBRO_WALK_UNREADY_STAND_RIGHT 99152120
#define ID_ANI_BOOMERANGBRO_WALK_UNREADY_MOVE_RIGHT (ID_ANI_BOOMERANGBRO_WALK_UNREADY_STAND_RIGHT + 1)

#define ID_ANI_BOOMERANGBRO_WALK_READY_STAND_RIGHT 99152220
#define ID_ANI_BOOMERANGBRO_WALK_READY_MOVE_RIGHT (ID_ANI_BOOMERANGBRO_WALK_READY_STAND_RIGHT + 1)

//PARAGOOMBA

#define ID_ANI_PARAGOOMBA_DIE 991210
#define ID_ANI_PARAGOOMBA_FOOT_WALK 991220
#define ID_ANI_PARAGOOMBA_WING_WALK 991230
#define ID_ANI_PARAGOOMBA_WING_FLY 991231

//FIREBALL

#define ID_SPRITE_FIREBALL 800000

#define ID_ANI_FIREBALL 99800000

//BOOMERANG

#define ID_SPRITE_BOOMERANG 810000

#define ID_ANI_BOOMERANG 99810000