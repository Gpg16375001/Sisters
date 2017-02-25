/*
______________________________________________________________________________________________

	FILE : Renderer.cpp

	________/ Explanation of file /___________________________________________________________

		Renderer クラスの実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/

#include <windows.h>
#include <stdio.h>	// --- コンソール用
#include "Renderer.h"

/*/
/*	デストラクタ
/*/
Renderer::~Renderer( )
{
	// 裏画面で使ったものを消す
	if ( hDCBack_ != NULL )
	{
		DeleteDC( hDCBack_ ) ;
	}

	if ( hDCWork_ != NULL )
	{
		DeleteDC( hDCWork_ ) ;
	}

}

/*/
/*	初期化
/*/
void Renderer::Initialize( )
{
	bmpData_ = NULL ;
	setPos( 0 , 0 ) ;
	setUV( 0 , 0 ) ;
	setWH( 0 , 0 ) ;
	setScale( 1.0f , 1.0f ) ;

}

/*/
/*	裏画面の描画に必要なものをもらう
/*/
int Renderer::setHDC( HDC arg_hDCBack , HDC arg_hDCWork )
{
	hDCBack_ = arg_hDCBack ;
	hDCWork_ = arg_hDCWork ;

	return( true ) ;
}

/*/
/*	描画したいビットマップをセット
/*/
int Renderer::selectBmp(
		HGDIOBJ arg_bmpData ,						// . 画像データ
		int arg_x , int arg_y ,						// . 配置座標
		int arg_u , int arg_v ,						// . 切り取り位置
		int arg_w , int arg_h ,						// . 幅高さ
		float arg_scaleX , float arg_scaleY			// . 拡大率
	)
{
	bmpData_ = arg_bmpData ;
	setPos( arg_x , arg_y ) ;
	setUV( arg_u , arg_v ) ;
	setWH( arg_w , arg_h ) ;
	setScale( arg_scaleX , arg_scaleY ) ;

	return ( true ) ;
}

/*/
/*	バックバッファへ描画
/*/
int Renderer::Render( )
{
	SelectObject( hDCWork_ , bmpData_ ) ;

	TransparentBlt(
		hDCBack_ ,
		x_ , y_ ,
		(int)(w_ * scaleX_) , (int)(h_ * scaleY_) ,
		hDCWork_ ,
		u_ , v_ ,
		w_ , h_ ,
		RGB( 0 , 255 , 0 )
	) ;

	return ( true ) ;
}


/*/
/*	X軸 と  Y軸 をセット
/*/
int Renderer::setPos( int arg_x , int arg_y )
{
	x_ = arg_x ;
	y_ = arg_y ;

	return( true ) ;
}

/*/
/*	切り出し座標のセット
/*/
int Renderer::setUV( int arg_u , int arg_v )
{
	u_ = arg_u ;
	v_ = arg_v ;

	return( true ) ;
}

/*/
/*	切り出し幅高さのセット
/*/
int Renderer::setWH( int arg_w , int arg_h )
{
	w_ = arg_w ;
	h_ = arg_h ;

	return( true ) ;
}

/*/
/*	拡大率のセット
/*/
int Renderer::setScale( float arg_w , float arg_h )
{
	scaleX_ = arg_w ;
	scaleY_ = arg_h ;

	return( true ) ;
}



