
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
#include "BackDropScreen.h"
#include "BackGround.h"
#include "Sprite.h"
#include <math.h>
#include "SoundBGM.h"
#include "SoundSE.h"
#include "SceneLoop.h"
#include "DrawLoop.h"
#include "ChipBackGround.h"
#include "TimeProc.h"
#include "Player.h"
#include "Animation.h"
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

#define BGM_FILE_PASS_01 ( TEXT( "source/sound/bgm01.wav" ) )
#define SE_FILE_PASS_01 ( TEXT( "open source/sound/se01.wav alias se" ) )
#define SE_FILE_PASS_02 ( TEXT( "open source/sound/bomb1.wav alias se" ) )

#define MAP_X	25
#define MAP_Y	18

#define ANIM_DATA_MAX	128

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

/* -----------------------------------------------------------------------------------------
|
|       外部参照宣言
|
+ --------------------------------------------------------------------------------------- */
// --- コンソールウィンドウ
extern ConsoleWindow g_cWin;	

// --- ウィンドウなどのタイトル
extern TCHAR g_szAppTitle[ ];
extern TCHAR g_szWndClass[ ];

// --- インスタンスハンドル
extern HINSTANCE g_hInstance;

// --- ウインドウハンドル
extern HWND g_hWindow;	

// --- キーマネージャー
extern KeyManager g_key;

// ビットマップデータ
extern BitmapData g_bDataSprTable[ BMP_DATA_SPR_MAX ] ;	// スプライト用
extern BitmapData g_bDataBGTable[ BMP_DATA_BG_MAX ] ;	// 背景用

// バックバッファ
extern HDC g_hBackBuf ;

// 共有のデバイスコンテキスト
extern HDC g_hWorkBuf ;

// バックドロップ
extern BackDropScreen g_bScreen ;

// バックグラウンド
extern BackGround g_bgScreen[ BMP_DATA_BG_MAX ] ;

// スプライト
extern Sprite g_Spr[ BMP_DATA_SPR_MAX ] ;

// BGM
extern SoundBGM g_sBGM ;

// SE
extern SoundSE g_sSE ;

// シーンループ
extern int g_sceneNo ;

// マップデータ
extern int g_mapData01[ MAP_X * MAP_Y ] ;

// チップテーブル
extern BitmapData g_bDataCBGTable[ BMP_DATA_CBG_MAX ] ;

// チップテーブル
extern ChipBackGround g_CBG ;

// プレイヤー
extern Player g_player ;

// マップデータ吐き出し
extern CreateData g_cmap ;


