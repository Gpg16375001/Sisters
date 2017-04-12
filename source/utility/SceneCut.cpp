/*
________________________________________________________________________________________________________________

	FILE : SceneCut.cpp

	________/ Explanation of file /___________________________________________________________

		SceneCut クラスの実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include <windows.h>
#include <stdio.h>

#include "SceneCut.h"

/*/
/*	デストラクタ
/*/
SceneCut::~SceneCut( )
{
	// --- 使用されていたらオブジェクト破棄
	for ( int i = 0 ; i < MAX_BMP ; ++i )
	{
		if( bmpTable_[ i ]._hBmp != NULL )
		{
			DeleteObject( bmpTable_[ i ]._hBmp ) ;
		}
		clearData( i ) ; 
	}
}

/*/
/*	初期化
/*/
void SceneCut::Initialize( )
{
	// --- 使用されていたらオブジェクト破棄
	for ( int i = 0 ; i < MAX_BMP ; ++i )
	{
		if( bmpTable_[ i ]._hBmp != NULL )
		{
			DeleteObject( bmpTable_[ i ]._hBmp ) ;
		}
		clearData( i ) ; 
	}
}

/*/
/*	画像データのクリア
/*/
int SceneCut::clearData( int arg_bmpNo )
{
	setUseFlg( arg_bmpNo , false ) ;
	setBmpXY( arg_bmpNo , 0.0f , 0.0f ) ;
	setBmpWH( arg_bmpNo , 0 , 0 ) ;
	setAlpha( arg_bmpNo , 255 ) ;
	setUseAlpha( arg_bmpNo , false ) ;

	return( true ) ;
}

/*/
/*	イメージ読み込み
/*/
int SceneCut::loadBmpData( int arg_bmpNo , HBITMAP arg_hbmp )
{
	// 使用されていたらオブジェクト破棄
	clearData( arg_bmpNo ) ;

	// データの読み込みと幅と高さをセット
	bmpTable_[ arg_bmpNo ]._hBmp = arg_hbmp ;

	return ( true ) ;
}


/*/
/*	描画するかどうかのフラグをセット
/*/
int SceneCut::setUseFlg( int arg_bmpNo , bool arg_useFlg )
{
	bmpTable_[ arg_bmpNo ]._useFlg = arg_useFlg ;

	return( true ) ;
}

/*/
/*	透明処理をするかどうかのフラグをセット
/*/
int SceneCut::setUseAlpha( int arg_bmpNo , bool arg_useAlpha )
{
	bmpTable_[ arg_bmpNo ]._useAlpha = arg_useAlpha ;

	return( true ) ;
}

/*/
/*	ポジションのセット
/*/
int SceneCut::setBmpXY( int arg_bmpNo , float arg_x , float arg_y )
{
	bmpTable_[ arg_bmpNo ]._x = arg_x ;
	bmpTable_[ arg_bmpNo ]._y = arg_y ;

	return( true ) ;
}

/*/
/*	幅、高さのセット
/*/
int SceneCut::setBmpWH( int arg_bmpNo , int arg_w , int arg_h )
{
	bmpTable_[ arg_bmpNo ]._w = arg_w ;
	bmpTable_[ arg_bmpNo ]._h = arg_h ;

	return( true ) ;
}

/*/
/*	透明度のセット
/*/
int SceneCut::setAlpha( int arg_bmpNo , int arg_alpha )
{
	bmpTable_[ arg_bmpNo ]._alpha = arg_alpha ;	

	return( true ) ;
}

/*/
/*	描画する情報をセット
/*/
int SceneCut::setBmpData(
		int arg_bmpNo ,
		float arg_x , float arg_y ,
		int arg_w , int arg_h ,
		int arg_alpha
	) 
{
	setUseFlg( arg_bmpNo , true ) ;
	setBmpXY( arg_bmpNo , arg_x , arg_y ) ;
	setBmpWH( arg_bmpNo , arg_w , arg_h ) ;
	if ( arg_alpha < 255 )
	{
		setUseAlpha( arg_bmpNo , true ) ;
		setAlpha( arg_bmpNo , arg_alpha ) ;
	}

	return( true ) ;
}

int SceneCut::fadeIn( )
{
	int iRet = -1 ;

	SceneCut::GetInstance()->setBmpData( 0 , 0 , 0 , 800 , 700 , alphaCnt_ ) ;
	alphaCnt_ += 6 ;

	if ( alphaCnt_ >= 255 )
	{
		alphaCnt_ = 255 ;
		iRet = 1 ;
	}

	return( iRet ) ;
}

int SceneCut::BlackOut( )
{
	int iRet = -1 ;

	alphaCnt_ = 255 ;
	SceneCut::GetInstance()->setBmpData( 0 , 0 , 0 , 800 , 700 , alphaCnt_ ) ;
	iRet = 1 ;

	return( iRet ) ;
}

int SceneCut::fadeOut( )
{
	int iRet = -1 ;

	SceneCut::GetInstance()->setBmpData( 0 , 0 , 0 , 800 , 700 , alphaCnt_ ) ;
	alphaCnt_ -= 8 ;

	if ( alphaCnt_ <= 0 )
	{
		alphaCnt_ = 0 ;
		iRet = 1 ;
	}

	return( iRet ) ;
}


