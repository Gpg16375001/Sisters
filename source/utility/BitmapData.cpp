/*
________________________________________________________________________________________________________________

	FILE : BitmapData.cpp

	________/ Explanation of file /___________________________________________________________

		BitmapData クラスの実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include <windows.h>
#include <stdio.h>

#include "BitmapData.h"

/*/
/*	デストラクタ
/*/
BitmapData::~BitmapData( )
{
	// --- 使用されていたらオブジェクト破棄
	for ( int i = 0 ; i < MAX_BMP_IMAGES ; ++i )
	{
		clearData( i ) ; 
	}
}

/*/
/*	初期化
/*/
void BitmapData::Initialize( )
{
	// --- 使用されていたらオブジェクト破棄
	for ( int i = 0 ; i < MAX_BMP_IMAGES ; ++i )
	{
		clearData( i ) ; 
	}
}

/*/
/*	画像データのクリア
/*/
int BitmapData::clearData( int arg_bmpNo )
{
	if( bmpDataTable_[ arg_bmpNo ]._hBmp != NULL )
	{
		DeleteObject( bmpDataTable_[ arg_bmpNo ]._hBmp ) ;
	}

	return ( true ) ;
}

/*/
/*	イメージ読み込み
/*/
int BitmapData::loadData( int arg_bmpNo , LPCTSTR arg_pStr , int arg_width , int arg_height )
{
	// 使用されていたらオブジェクト破棄
	clearData( arg_bmpNo ) ;

	// データの読み込みと幅と高さをセット
	bmpDataTable_[ arg_bmpNo ]._hBmp = (HBITMAP)LoadImage( NULL , arg_pStr , IMAGE_BITMAP , 0 , 0 , LR_LOADFROMFILE ) ;

	bmpDataTable_[ arg_bmpNo ]._width = arg_width ;
	bmpDataTable_[ arg_bmpNo ]._height = arg_height ;

	printf( "%S was loaded.\n" , arg_pStr ) ;

	return ( true ) ;
}

/*/
/*	ビットマップのハンドルのアクセッサ
/*/
HBITMAP BitmapData::getBmpData( int arg_bmpNo )
{
	return ( bmpDataTable_[ arg_bmpNo ]._hBmp ) ;
}

/*/
/*	ビットマップ幅のアクセッサ
/*/
int BitmapData::getBmpWidth( int arg_bmpNo )
{
	return ( bmpDataTable_[ arg_bmpNo ]._width ) ;
}

/*/
/*	ビットマップ高さのアクセッサ
/*/
int BitmapData::getBmpHeight( int arg_bmpNo )
{
	return ( bmpDataTable_[ arg_bmpNo ]._height ) ;
}


