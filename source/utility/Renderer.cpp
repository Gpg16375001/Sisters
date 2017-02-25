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
	x_ = 0 ;
	y_ = 0 ;
	u_ = 0 ;
	v_ = 0 ;
	w_ = 0 ;
	h_ = 0 ;
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
		HGDIOBJ arg_bmpData ,
		int arg_x , int arg_y ,
		int arg_u , int arg_v ,
		int arg_w , int arg_h
	)
{
	bmpData_ = arg_bmpData ;
	setPos( arg_x , arg_y ) ;
	setUV( arg_u , arg_v ) ;
	setWH( arg_w , arg_h ) ;

	return ( true ) ;
}

/*/
/*	バックバッファへ描画
/*/
int Renderer::Render( )
{
	SelectObject( hDCWork_ , bmpData_ ) ;

	BitBlt(
		hDCBack_ ,
		x_ ,
		y_ ,
		w_ ,
		h_ ,
		hDCWork_ ,
		0 ,
		0 ,
		SRCCOPY
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



