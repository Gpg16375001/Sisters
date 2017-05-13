#pragma once

#include "ConsoleWindow.h"
#include "KeyManager.h"
#include "../sound/SoundBGM.h"
#include "../sound/SoundSE.h"
#include "BitmapData.h"
#include "Renderer.h"
#include "BackGround.h"
#include "Sprite.h"
#include "Chip.h"
#include "../utility/SceneCut.h"
#include "SceneManager.h"
#include "../characters/Animation.h"
#include "../characters/Physics.h"
#include "../characters/Afterimage.h"
#include "../characters/Player.h"
#include "../gimmick/Gimmick.h"

#define CHIP_MAP_SIZE_X		1024
#define CHIP_MAP_SIZE_Y		12

extern int g_mapData01[ CHIP_MAP_SIZE_X * CHIP_MAP_SIZE_Y ] ;
extern int g_state ;
extern SoundSE g_sSE ;
extern int use_se ;		// SE

