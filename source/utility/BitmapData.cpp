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
	setUseFlg( arg_bmpNo , false ) ;
	setBmpXY( arg_bmpNo , 0 , 0 ) ;
	setBmpUV( arg_bmpNo , 0 , 0 ) ;
	setBmpWH( arg_bmpNo , 0 , 0 ) ;

	return( true ) ;
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

	setBmpWH( arg_bmpNo , arg_width , arg_height ) ;

	printf( "%S was loaded.\n" , arg_pStr ) ;

	return ( true ) ;
}

/*/
/*	ポジションのセット
/*/
int BitmapData::setBmpXY( int arg_bmpNo , int arg_x , int arg_y )
{
	bmpDataTable_[ arg_bmpNo ]._x = arg_x ;
	bmpDataTable_[ arg_bmpNo ]._y = arg_y ;

	return( true ) ;
}

/*/
/*	切り取り位置のセット
/*/
int BitmapData::setBmpUV( int arg_bmpNo , int arg_u , int arg_v )
{
	bmpDataTable_[ arg_bmpNo ]._u = arg_u ;
	bmpDataTable_[ arg_bmpNo ]._v = arg_v ;

	return( true ) ;
}

/*/
/*	幅、高さのセット
/*/
int BitmapData::setBmpWH( int arg_bmpNo , int arg_w , int arg_h )
{
	bmpDataTable_[ arg_bmpNo ]._w = arg_w ;
	bmpDataTable_[ arg_bmpNo ]._h = arg_h ;

	return( true ) ;
}

/*/
/*	描画するかどうかのフラグをセット
/*/
int BitmapData::setUseFlg( int arg_bmpNo , bool arg_useFlg )
{
	bmpDataTable_[ arg_bmpNo ]._useFlg = arg_useFlg ;

	return( true ) ;
}

/*/
/*	描画する情報をセット
/*/
int BitmapData::setBmpData(
		int arg_bmpNo ,
		int arg_x , int arg_y ,
		int arg_u , int arg_v ,
		int arg_w , int arg_h
	) 
{
	setUseFlg( arg_bmpNo , true ) ;
	setBmpXY( arg_bmpNo , arg_x , arg_y ) ;
	setBmpUV( arg_bmpNo , arg_u , arg_v ) ;
	setBmpWH( arg_bmpNo , arg_w , arg_h ) ;

	return( true ) ;
}


