#pragma once

#include "ConsoleWindow.h"
#include "KeyManager.h"
#include "BitmapData.h"
#include "Renderer.h"
#include "BackGround.h"
#include "Sprite.h"
#include "Chip.h"
#include "SceneManager.h"
#include "../characters/Physics.h"
#include "../characters/Player.h"

extern int g_mapData01[ 64 * 12 ] ;
extern int g_state ;

extern float g_px , g_py ;		// デバッグ用 プレイヤーの座標
extern int g_bx1 , g_by1 ;	// デバッグ用 ブロックのあたり判定の座標 1
extern int g_bx2 , g_by2 ;	// デバッグ用 ブロックのあたり判定の座標 2
extern int g_bx3 , g_by3 ;	// デバッグ用 ブロックのあたり判定の座標 3
extern int g_bx4 , g_by4 ;	// デバッグ用 ブロックのあたり判定の座標 4
extern int g_bx5 , g_by5 ;	// デバッグ用 ブロックのあたり判定の座標 5
extern int g_bx6 , g_by6 ;	// デバッグ用 ブロックのあたり判定の座標 6
extern int g_bx7 , g_by7 ;	// デバッグ用 ブロックのあたり判定の座標 7 
extern int g_bx8 , g_by8 ;	// デバッグ用 ブロックのあたり判定の座標 8 
extern int g_bx9 , g_by9 ;	// デバッグ用 ブロックのあたり判定の座標 9

extern int fpscnt ;



