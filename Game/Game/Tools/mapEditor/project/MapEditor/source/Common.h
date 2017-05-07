
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: KeyManager.h
	NAME	: Teacher.K

+ ------ Explanation of file --------------------------------------------------------------------------
       
	全てのファイルで共通のヘッダーファイル

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

/* -----------------------------------------------------------------------------------------
|
|       共通ヘッダー
|
+ --------------------------------------------------------------------------------------- */
#include "ConsoleWindow.h"	// --- コンソールウィンドウ
#include "KeyManager.h"		// --- キーマネージャー

#include "BitmapData.h"
#include "Sprite.h"
#include <math.h>
#include "DrawLoop.h"
#include "ChipBackGround.h"
#include "TimeProc.h"
#include "CreateData.h"

/* -----------------------------------------------------------------------------------------
|
|       DEFINE宣言
|
+ --------------------------------------------------------------------------------------- */
#define WINDOW_W 800
#define WINDOW_H 600

#define GAME_FPS	60					// --- １秒間で６０回の画面更新
#define GAME_FRAME	( 1000 / GAME_FPS )	// --- 1000ミリ秒をFPSで除算で１フレームのスピードを求める

#define BMP_DATA_SPR_MAX	128
#define BMP_DATA_BG_MAX		8
#define BMP_DATA_CBG_MAX	8

#define MAP_X	1024
#define MAP_Y	12

#define ANIM_DATA_MAX	128

#define		cell( arg_cell )	(arg_cell * 16)

/* -----------------------------------------------------------------------------------------
|
|       型宣言
|
+ --------------------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------------------
|
|       プロトタイプ宣言
|
+ --------------------------------------------------------------------------------------- */
VOID funcFileSave( HWND hWnd ) ;
void SetLoop( ) ;
void actionLoop( ) ;

/* -----------------------------------------------------------------------------------------
|
|       外部参照宣言
|
+ --------------------------------------------------------------------------------------- */
// --- コンソールウィンドウ
extern ConsoleWindow g_cWin;	

// --- ウィンドウなどのタイトル
extern TCHAR g_szAppTitle[ ] ;
extern TCHAR g_szWndClass[ ] ;

// --- インスタンスハンドル
extern HINSTANCE g_hInstance ;

// --- ウインドウハンドル
extern HWND g_hWindow ;	

// --- lParam
extern LPARAM g_lParam ;	

// --- キーマネージャー
extern KeyManager g_key ;

// ビットマップデータ
extern BitmapData g_bDataSprTable[ BMP_DATA_SPR_MAX ] ;	// スプライト用
extern BitmapData g_bDataBGTable[ BMP_DATA_BG_MAX ] ;	// 背景用

// バックバッファ
extern HDC g_hBackBuf ;

// 共有のデバイスコンテキスト
extern HDC g_hWorkBuf ;

// スプライト
extern Sprite g_Spr[ BMP_DATA_SPR_MAX ] ;

// マップデータ
extern int g_mapData01[ MAP_X * MAP_Y ] ;

// チップテーブル
extern BitmapData g_bDataCBGTable[ BMP_DATA_CBG_MAX ] ;

// チップテーブル
extern ChipBackGround g_CBG ;

// マップデータ吐き出し
extern CreateData g_cmap ;

// pen
extern HPEN g_redPen ;

// brush
extern HBRUSH g_brush[ 4 ] ;

// scroll
extern int g_scroll ;

// chip select
extern int g_chip ;

// mouse
extern int g_mouseX, g_mouseY ;


