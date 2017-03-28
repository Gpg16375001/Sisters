/*
________________________________________________________________________________________________________________

	FILE : Sprite.cpp

	________/ Explanation of file /___________________________________________________________

		Sprite クラスの実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include "Sprite.h"

/*/
/*	デストラクタ
/*/
Sprite::~Sprite( )
{
	// --- 使用されていたらオブジェクト破棄
	for ( int i = 0 ; i < MAX_BMP_SPRITE ; ++i )
	{
		if( bmpBGTable_[ i ]._hBmp != NULL )
		{
			bmpBGTable_[ i ]._hBmp = NULL ;
		}
		clearData( i ) ; 
	}
}

/*/
/*	初期化
/*/
void Sprite::Initialize( )
{
	// --- 使用されていたらオブジェクト破棄
	for ( int i = 0 ; i < MAX_BMP_SPRITE ; ++i )
	{
		if( bmpBGTable_[ i ]._hBmp != NULL )
		{
			bmpBGTable_[ i ]._hBmp = NULL ;
		}
		clearData( i ) ; 
	}
}

/*/
/*	画像データのクリア
/*/
int Sprite::clearData( int arg_bmpNo )
{
	setUseFlg( arg_bmpNo , false ) ;
	setBmpXY( arg_bmpNo , 0.0f , 0.0f ) ;
	setBmpUV( arg_bmpNo , 0 , 0 ) ;
	setBmpWH( arg_bmpNo , 0 , 0 ) ;
	setBmpScale( arg_bmpNo , 0 , 0 ) ;
	setAlpha( arg_bmpNo , 255 ) ;
	setUseAlpha( arg_bmpNo , false ) ;
	setAngle( arg_bmpNo , 0 ) ;
	setUseRotate( arg_bmpNo , false ) ;
	setUseRender( arg_bmpNo , false ) ;

	return( true ) ;
}

/*/
/*	イメージ読み込み
/*/
int Sprite::loadBmpData( int arg_bmpNo , HBITMAP arg_hbmp )
{
	// 使用されていたらオブジェクト破棄
	clearData( arg_bmpNo ) ;

	// データの読み込みと幅と高さをセット
	bmpBGTable_[ arg_bmpNo ]._hBmp = arg_hbmp ;

	return ( true ) ;
}

/*/
/*	イメージ読み込み
/*/
int Sprite::loadBmpDataFor( int arg_bmpNo , HBITMAP arg_hbmp , int arg_no )
{
	for ( int i = arg_bmpNo ; i < arg_bmpNo + arg_no ; ++i )
	{
		loadBmpData( i , arg_hbmp ) ;
	}

	return ( true ) ;
}


/*/
/*	描画するかどうかのフラグをセット
/*/
int Sprite::setUseFlg( int arg_bmpNo , bool arg_useFlg )
{
	bmpBGTable_[ arg_bmpNo ]._useFlg = arg_useFlg ;

	return( true ) ;
}

/*/
/*	透明処理をするかどうかのフラグをセット
/*/
int Sprite::setUseAlpha( int arg_bmpNo , bool arg_useAlpha )
{
	bmpBGTable_[ arg_bmpNo ]._useAlpha = arg_useAlpha ;

	return( true ) ;
}

/*/
/*	回転処理をするかどうかのフラグをセット
/*/
int Sprite::setUseRotate( int arg_bmpNo , bool arg_useRotate )
{
	bmpBGTable_[ arg_bmpNo ]._useRotate = arg_useRotate ;

	return( true ) ;
}

/*/
/*	ポジションのセット
/*/
int Sprite::setBmpXY( int arg_bmpNo , float arg_x , float arg_y )
{
	bmpBGTable_[ arg_bmpNo ]._x = arg_x ;
	bmpBGTable_[ arg_bmpNo ]._y = arg_y ;

	return( true ) ;
}

/*/
/*	切り取り位置のセット
/*/
int Sprite::setBmpUV( int arg_bmpNo , int arg_u , int arg_v )
{
	bmpBGTable_[ arg_bmpNo ]._u = arg_u ;
	bmpBGTable_[ arg_bmpNo ]._v = arg_v ;

	return( true ) ;
}

/*/
/*	幅、高さのセット
/*/
int Sprite::setBmpWH( int arg_bmpNo , int arg_w , int arg_h )
{
	bmpBGTable_[ arg_bmpNo ]._w = arg_w ;
	bmpBGTable_[ arg_bmpNo ]._h = arg_h ;

	return( true ) ;
}

/*/
/*	拡大率のセット
/*/
int Sprite::setBmpScale( int arg_bmpNo , float arg_w , float arg_h )
{
	bmpBGTable_[ arg_bmpNo ]._scaleX = arg_w ;
	bmpBGTable_[ arg_bmpNo ]._scaleY = arg_h ;

	return( true ) ;
}

/*/
/*	アンカーをセット
/*/
int Sprite::setAnchor( int arg_bmpNo , int arg_anchor )
{
	bmpBGTable_[ arg_bmpNo ]._anchor = arg_anchor ;

	return( true ) ;
}

/*/
/*	透明度のセット
/*/
int Sprite::setAlpha( int arg_bmpNo , int arg_alpha )
{
	bmpBGTable_[ arg_bmpNo ]._alpha = arg_alpha ;	

	return( true ) ;
}

/*/
/*	角度のセット
/*/
int Sprite::setAngle( int arg_bmpNo , float arg_degree )
{
	bmpBGTable_[ arg_bmpNo ]._degree = arg_degree ;

	return( true ) ;
}

/*/
/*	描画するかのフラグのセット
/*/
int Sprite::setUseRender( int arg_bmpNo , bool arg_flg )
{
	bmpBGTable_[ arg_bmpNo ]._useRender = arg_flg ;

	return( true ) ;
}

/*/
/*	描画する情報をセット
/*/
int Sprite::setBmpData(
		int arg_bmpNo ,
		int arg_anchor ,
		float arg_x , float arg_y ,
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



