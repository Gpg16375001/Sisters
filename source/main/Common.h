#include "ConsoleWindow.h"
#include "BitmapData.h"
#include "BackDropScreen.h"

extern ConsoleWindow console ;

// バックバッファ
extern HDC g_hBackBuf ;

// 共有のデバイスコンテキスト
extern HDC g_hWorkBuf ;

// ビットマップデータ
extern BitmapData g_bDataBGTable[ 4 ] ;		// 背景用
extern BitmapData g_bDataSprTable[ 128 ] ;		// スプライト用

// バックドロップ
extern BackDropScreen g_bds ;



