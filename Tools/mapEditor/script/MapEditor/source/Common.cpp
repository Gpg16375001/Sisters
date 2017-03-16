
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: KeyManager.cpp
	NAME	: Teacher.K

+ ------ Explanation of file --------------------------------------------------------------------------
       
	共通での処理、または汎用性がある関数や変数の実体宣言部

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>	// --- コンソール用

#include "Common.h"

/* -----------------------------------------------------------------------------------------
|
|       グローバル変数＆オブジェクトの実体宣言
|
+ --------------------------------------------------------------------------------------- */
// --- コンソールウィンドウ
ConsoleWindow g_cWin;	

// --- ウィンドウなどのタイトル
TCHAR g_szAppTitle[ ] = TEXT( "MapEditor" ) ;
TCHAR g_szWndClass[ ] = TEXT( "EditorSample" ) ;

// --- インスタンスハンドル
HINSTANCE g_hInstance = NULL ;	

// --- ウインドウハンドル
HWND g_hWindow = NULL ;	

// --- lParam
LPARAM g_lParam ;	

// --- キーマネージャー
KeyManager g_key ;

// ビットマップデータ
BitmapData g_bDataSprTable[ BMP_DATA_SPR_MAX ] ;	// スプライト用
BitmapData g_bDataBGTable[ BMP_DATA_BG_MAX ] ;		// 背景用

// バックバッファ
HDC g_hBackBuf = NULL ;

// 共有のデバイスコンテキスト
HDC g_hWorkBuf = NULL ;

// スプライト
Sprite g_Spr[ BMP_DATA_SPR_MAX ] ;

// マップデータ
int g_mapData01[ MAP_X * MAP_Y ] = { 0 } ;

// チップテーブル
BitmapData g_bDataCBGTable[ BMP_DATA_CBG_MAX ] ;

// チップテーブル
ChipBackGround g_CBG ;

// マップデータ吐き出し
CreateData g_cmap ;

// pen
HPEN g_redPen ;

// brush
HBRUSH g_brush[ 4 ] ;

// scroll
int g_scroll = 0 ;

// chip select
int g_chip = 1 ;

// mouse
int g_mouseX = 0 , g_mouseY = 0 ;

/* -----------------------------------------------------------------------------------------
|
|       グローバル関数の実装部
|
+ --------------------------------------------------------------------------------------- */
VOID funcFileSave( HWND hWnd )
{
	static OPENFILENAME    ofn ;
	static TCHAR           szPath[ MAX_PATH ] ;
	static TCHAR           szFile[ MAX_PATH ] ;
	static char			szFilePath[ MAX_PATH ] ;

	if ( szPath[0] == TEXT('\0') )
	{
	    GetCurrentDirectory( MAX_PATH , szPath ) ;
	}
	// file保存用の構造体の初期セット
	if ( ofn.lStructSize == 0 )
	{
		ofn.lStructSize         = sizeof(OPENFILENAME) ;
		ofn.hwndOwner           = hWnd ;
		ofn.lpstrInitialDir     = szPath ;       // 初期フォルダ位置
		ofn.lpstrFile           = szFile ;       // 選択ファイル格納
		ofn.nMaxFile            = MAX_PATH ;
		ofn.lpstrDefExt         = TEXT(".txt") ;
		ofn.lpstrFilter         = TEXT("txtファイル(*.txt)\0*.txt\0") ;
		ofn.lpstrTitle          = TEXT("TXTファイルを保存します。") ;
		ofn.Flags               = OFN_OVERWRITEPROMPT | OFN_CREATEPROMPT ;
	}

	if ( GetSaveFileName( &ofn ) )
	{
		for ( int i = ofn.nFileOffset ; szFile[ i ] != '\0' ; ++i )
		{
			szFilePath[ i - ofn.nFileOffset ] = ( char )szFile[ i ] ;
		}
	    MessageBox( hWnd , szFile , TEXT("ファイル名を付けて保存") , MB_OK ) ;
		g_cmap.CreateMapData( szFilePath ) ;
	}

}

void SetLoop( )
{
	static bool keyflg = true ;

	/*/
	/*	キー入力
	/*/
	if ( keyflg )
	{
		if ( g_key.getKeyState( VK_RIGHT ) && (g_scroll < MAP_X -  23) )
		{
			g_scroll++ ;
			keyflg = false ;
//			printf( "Pushed Left\n" ) ;
		}
		if ( g_key.getKeyState( VK_LEFT ) && (g_scroll > 0) )
		{
			g_scroll-- ;
			keyflg = false ;
//			printf( "Pushed Right\n" ) ;
		}

	} else {

		if ( g_key.getKeyState( VK_SHIFT ) )
		{
			keyflg = true ;
//			printf( "Uped keyflg\n" ) ;
		}
		if ( (g_key.getKeyState( VK_LEFT ))  || (g_key.getKeyState( VK_RIGHT )) )
		{
		} else {
			keyflg = true ;
//			printf( "Uped keyflg\n" ) ;
		}
	}

	/*/
	/*	バックドロップ
	/*/
	//			  Left		   Top			Right		Bottom
		RECT rc1 = { cell( 0 ) , cell( 0 ) , cell( 64 ) , cell( 38 ) }  ;
		FillRect( g_hBackBuf , &rc1 , g_brush[ 1 ] );
		g_Spr[ 0 ].setSprite(
			0  ,
			cell( 4 ) ,
			cell( 4 ) ,
			0 , 0 ,
			1000 , 1000
		) ;
	g_Spr[ 0 ].setScaleXY( 0.74f , 0.5f ) ;
	
	/*/
	/*	スプライトセット
	/*/
	g_Spr[ 1 ].setSprite(
		1  ,
		cell( 4 ) ,
		cell( 28 ) ,
		1 * CHIP_W ,
		0 * CHIP_H ,
		CHIP_W , CHIP_H
	) ;
	g_Spr[ 2 ].setSprite(
		1  ,
		cell( 8 ) ,
		cell( 28 ) ,
		2 * CHIP_W ,
		0 * CHIP_H ,
		CHIP_W , CHIP_H
	) ;
	g_Spr[ 3 ].setSprite(
		1  ,
		cell( 12 ) ,
		cell( 28 ) ,
		3 * CHIP_W ,
		0 * CHIP_H ,
		CHIP_W , CHIP_H
	) ;
	g_Spr[ 4 ].setSprite(
		1  ,
		cell( 16 ) ,
		cell( 28 ) ,
		4 * CHIP_W ,
		0 * CHIP_H ,
		CHIP_W , CHIP_H
	) ;
	g_Spr[ 5 ].setSprite(
		1  ,
		cell( 20 ) ,
		cell( 28 ) ,
		5 * CHIP_W ,
		0 * CHIP_H ,
		CHIP_W , CHIP_H
	) ;
	g_Spr[ 6 ].setSprite(
		1  ,
		cell( 24 ) ,
		cell( 28 ) ,
		6 * CHIP_W ,
		0 * CHIP_H ,
		CHIP_W , CHIP_H
	) ;
	g_Spr[ 7 ].setSprite(
		1  ,
		cell( 28 ) ,
		cell( 28 ) ,
		7 * CHIP_W ,
		0 * CHIP_H ,
		CHIP_W , CHIP_H
	) ;
	g_Spr[ 8 ].setSprite(
		1  ,
		cell( 32 ) ,
		cell( 28 ) ,
		8 * CHIP_W ,
		0 * CHIP_H ,
		CHIP_W , CHIP_H
	) ;
	g_Spr[ 9 ].setSprite(
		1  ,
		cell( 36 ) ,
		cell( 28 ) ,
		9 * CHIP_W ,
		0 * CHIP_H ,
		CHIP_W , CHIP_H
	) ;
	g_Spr[ 10 ].setSprite(
		1  ,
		cell( 40 ) ,
		cell( 28 ) ,
		10 * CHIP_W ,
		0 * CHIP_H ,
		CHIP_W , CHIP_H
	) ;
	g_Spr[ 11 ].setSprite(
		1  ,
		cell( 44 ) ,
		cell( 28 ) ,
		11 * CHIP_W ,
		0 * CHIP_H ,
		CHIP_W , CHIP_H
	) ;
	g_Spr[ 12 ].setSprite(
		1  ,
		cell( 6 ) ,
		cell( 32 ) ,
		0 * CHIP_W ,
		1 * CHIP_H ,
		4 * CHIP_W ,
		2 * CHIP_H
	) ;
	g_Spr[ 13 ].setSprite(
		1  ,
		cell( 16 ) ,
		cell( 32 ) ,
		4 * CHIP_W ,
		1 * CHIP_H ,
		4 * CHIP_W ,
		2 * CHIP_H
	) ;

	// Arrow
	g_Spr[ 30 ].setSprite(
		2  ,
		cell( (g_chip * 4) ) ,
		cell( (30 + (g_chip / 32)) ) ,
		0 , 0 ,
		32 , 32
	) ;

	/*/
	/*	チップセット
	/*/
	g_CBG.clearChip( ) ;
	for ( int i = 0 ; i < (MAP_X * MAP_Y) ; i++ ) {
		g_CBG.setChip( (i % MAP_X) , (i / MAP_X) , g_mapData01[ i ] ) ;
	}

}

void actionLoop( )
{
	g_mouseX = LOWORD( g_lParam ) ;
	g_mouseY = HIWORD( g_lParam ) ;

	for ( int i = 0 ; i <= 11 ; ++i )
	{
		if ( (cell( (i * 4) ) < g_mouseX) && (g_mouseX < cell( (i * 4 + 2) ))
			&& (cell( 28 ) < g_mouseY) && (g_mouseY < cell( 30 )) )
		{
			g_chip = i ;
		}
	}
}



