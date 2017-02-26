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
		if( bmpDataTable_[ i ]._hBmp != NULL )
		{
			DeleteObject( bmpDataTable_[ i ]._hBmp ) ;
		}
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
		if( bmpDataTable_[ i ]._hBmp != NULL )
		{
			DeleteObject( bmpDataTable_[ i ]._hBmp ) ;
		}
		clearData( i ) ; 
	}
}

/*/
/*	画像データのクリア
/*/
int BitmapData::clearData( int arg_bmpNo )
{
	setUseFlg( arg_bmpNo , false ) ;
	setBmpXY( arg_bmpNo , 0 , 0 ) ;
	setBmpUV( arg_bmpNo , 0 , 0 ) ;
	setBmpWH( arg_bmpNo , 0 , 0 ) ;
	setBmpScale( arg_bmpNo , 0 , 0 ) ;
	setAlpha( arg_bmpNo , 255 ) ;
	setUseAlpha( arg_bmpNo , false ) ;
	setAngle( arg_bmpNo , 0 ) ;
	setUseRotate( arg_bmpNo , false ) ;

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
/*	描画するかどうかのフラグをセット
/*/
int BitmapData::setUseFlg( int arg_bmpNo , bool arg_useFlg )
{
	bmpDataTable_[ arg_bmpNo ]._useFlg = arg_useFlg ;

	return( true ) ;
}

/*/
/*	透明処理をするかどうかのフラグをセット
/*/
int BitmapData::setUseAlpha( int arg_bmpNo , bool arg_useAlpha )
{
	bmpDataTable_[ arg_bmpNo ]._useAlpha = arg_useAlpha ;

	return( true ) ;
}

/*/
/*	回転処理をするかどうかのフラグをセット
/*/
int BitmapData::setUseRotate( int arg_bmpNo , bool arg_useRotate )
{
	bmpDataTable_[ arg_bmpNo ]._useRotate = arg_useRotate ;

	return( true ) ;
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
/*	拡大率のセット
/*/
int BitmapData::setBmpScale( int arg_bmpNo , float arg_w , float arg_h )
{
	bmpDataTable_[ arg_bmpNo ]._scaleX = arg_w ;
	bmpDataTable_[ arg_bmpNo ]._scaleY = arg_h ;

	return( true ) ;
}

/*/
/*	アンカーをセット
/*/
int BitmapData::setAnchor( int arg_bmpNo , int arg_anchor )
{
	bmpDataTable_[ arg_bmpNo ]._anchor = arg_anchor ;

	return( true ) ;
}

/*/
/*	透明度のセット
/*/
int BitmapData::setAlpha( int arg_bmpNo , int arg_alpha )
{
	setUseAlpha( arg_bmpNo , true ) ;
	bmpDataTable_[ arg_bmpNo ]._alpha = arg_alpha ;	

	return( true ) ;
}

/*/
/*	角度のセット
/*/
int BitmapData::setAngle( int arg_bmpNo , float arg_angle )
{
	setUseRotate( arg_bmpNo , true ) ;
	bmpDataTable_[ arg_bmpNo ]._angle = arg_angle ;

	return( true ) ;
}

/*/
/*	描画する情報をセット
/*/
int BitmapData::setBmpData(
		int arg_bmpNo ,
		int arg_anchor ,
		int arg_x , int arg_y ,
		int arg_u , int arg_v ,
		int arg_w , int arg_h ,
		float arg_scaleX , float arg_scaleY ,
		int arg_alpha ,
		float arg_angle
	) 
{
	setUseFlg( arg_bmpNo , true ) ;
	setAnchor( arg_bmpNo , arg_anchor ) ;
	setBmpXY( arg_bmpNo , arg_x , arg_y ) ;
	setBmpUV( arg_bmpNo , arg_u , arg_v ) ;
	setBmpWH( arg_bmpNo , arg_w , arg_h ) ;
	setBmpScale( arg_bmpNo , arg_scaleX , arg_scaleY ) ;
	if ( arg_alpha < 255 )
	{
		setUseAlpha( arg_bmpNo , true ) ;
		setAlpha( arg_bmpNo , arg_alpha ) ;
	}
	if ( arg_angle != 0 )
	{
		setUseRotate( arg_bmpNo , true ) ;
		setAngle( arg_bmpNo , arg_angle ) ;
	}

	return( true ) ;
}



