#include "Common.h"

ConsoleWindow console ;

// バックバッファ
HDC g_hBackBuf = NULL ;

// 共有のデバイスコンテキスト
HDC g_hWorkBuf = NULL ;

// ビットマップデータ
BitmapData g_bDataBGTable[ 4 ] ;		// 背景用
BitmapData g_bDataSprTable[ 128 ] ;		// スプライト用

// バックドロップ
BackDropScreen g_bds ;


