/*
________________________________________________________________________________________________________________

	FILE : BackGround.cpp

	________/ Explanation of file /___________________________________________________________

		BackGround クラスの実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include <windows.h>
#include <stdio.h>

#include "BackGround.h"

/*/
/*	デストラクタ
/*/
BackGround::~BackGround( )
{
	// --- 使用されていたらオブジェクト破棄
	for ( int i = 0 ; i < MAX_BMP_BG ; ++i )
	{
		if( bmpBGTable_[ i ]._hBmp != NULL )
		{
			DeleteObject( bmpBGTable_[ i ]._hBmp ) ;
		}
		clearData( i ) ; 
	}
}

/*/
/*	初期化
/*/
void BackGround::Initialize( )
{
	// --- 使用されていたらオブジェクト破棄
	for ( int i = 0 ; i < MAX_BMP_BG ; ++i )
	{
		if( bmpBGTable_[ i ]._hBmp != NULL )
		{
			DeleteObject( bmpBGTable_[ i ]._hBmp ) ;
		}
		clearData( i ) ; 
	}
}

/*/
/*	画像データのクリア
/*/
int BackGround::clearData( int arg_bmpNo )
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
int BackGround::loadBmpData( int arg_bmpNo , HBITMAP arg_hbmp )
{
	// 使用されていたらオブジェクト破棄
	clearData( arg_bmpNo ) ;

	// データの読み込みと幅と高さをセット
	bmpBGTable_[ arg_bmpNo ]._hBmp = arg_hbmp ;

	return ( true ) ;
}


/*/
/*	描画するかどうかのフラグをセット
/*/
int BackGround::setUseFlg( int arg_bmpNo , bool arg_useFlg )
{
	bmpBGTable_[ arg_bmpNo ]._useFlg = arg_useFlg ;

	return( true ) ;
}

/*/
/*	透明処理をするかどうかのフラグをセット
/*/
int BackGround::setUseAlpha( int arg_bmpNo , bool arg_useAlpha )
{
	bmpBGTable_[ arg_bmpNo ]._useAlpha = arg_useAlpha ;

	return( true ) ;
}

/*/
/*	回転処理をするかどうかのフラグをセット
/*/
int BackGround::setUseRotate( int arg_bmpNo , bool arg_useRotate )
{
	bmpBGTable_[ arg_bmpNo ]._useRotate = arg_useRotate ;

	return( true ) ;
}

/*/
/*	ポジションのセット
/*/
int BackGround::setBmpXY( int arg_bmpNo , int arg_x , int arg_y )
{
	bmpBGTable_[ arg_bmpNo ]._x = arg_x ;
	bmpBGTable_[ arg_bmpNo ]._y = arg_y ;

	return( true ) ;
}

/*/
/*	切り取り位置のセット
/*/
int BackGround::setBmpUV( int arg_bmpNo , int arg_u , int arg_v )
{
	bmpBGTable_[ arg_bmpNo ]._u = arg_u ;
	bmpBGTable_[ arg_bmpNo ]._v = arg_v ;

	return( true ) ;
}

/*/
/*	幅、高さのセット
/*/
int BackGround::setBmpWH( int arg_bmpNo , int arg_w , int arg_h )
{
	bmpBGTable_[ arg_bmpNo ]._w = arg_w ;
	bmpBGTable_[ arg_bmpNo ]._h = arg_h ;

	return( true ) ;
}

/*/
/*	拡大率のセット
/*/
int BackGround::setBmpScale( int arg_bmpNo , float arg_w , float arg_h )
{
	bmpBGTable_[ arg_bmpNo ]._scaleX = arg_w ;
	bmpBGTable_[ arg_bmpNo ]._scaleY = arg_h ;

	return( true ) ;
}

/*/
/*	アンカーをセット
/*/
int BackGround::setAnchor( int arg_bmpNo , int arg_anchor )
{
	bmpBGTable_[ arg_bmpNo ]._anchor = arg_anchor ;

	return( true ) ;
}

/*/
/*	透明度のセット
/*/
int BackGround::setAlpha( int arg_bmpNo , int arg_alpha )
{
	bmpBGTable_[ arg_bmpNo ]._alpha = arg_alpha ;	

	return( true ) ;
}

/*/
/*	角度のセット
/*/
int BackGround::setAngle( int arg_bmpNo , float arg_degree )
{
	bmpBGTable_[ arg_bmpNo ]._degree = arg_degree ;

	return( true ) ;
}

/*/
/*	描画する情報をセット
/*/
int BackGround::setBmpData(
		int arg_bmpNo ,
		int arg_anchor ,
		int arg_x , int arg_y ,
		int arg_u , int arg_v ,
		int arg_w , int arg_h ,
		float arg_scaleX , float arg_scaleY ,
		int arg_alpha ,
		float arg_degree
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
	if ( arg_degree != 0 )
	{
		setUseRotate( arg_bmpNo , true ) ;
		setAngle( arg_bmpNo , arg_degree ) ;
	}

	return( true ) ;
}



