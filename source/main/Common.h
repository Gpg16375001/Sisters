#pragma once

#include "ConsoleWindow.h"
#include "KeyManager.h"
#include "BitmapData.h"
#include "Renderer.h"
#include "BackGround.h"
#include "Sprite.h"
#include "Chip.h"
#include "SceneManager.h"
#include "../characters/Animation.h"
#include "../characters/Physics.h"
#include "../characters/Player.h"

#define CHIP_MAP_SIZE_X		256
#define CHIP_MAP_SIZE_Y		12

extern int g_mapData01[ CHIP_MAP_SIZE_X * CHIP_MAP_SIZE_Y ] ;
extern int g_state ;

extern float g_px , g_py ;		// デバッグ用 プレイヤーの座標

extern int fpscnt ;



