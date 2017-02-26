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
	setAnchor( 0 ) ;
	setPos( 0 , 0 ) ;
	setUV( 0 , 0 ) ;
	setWH( 0 , 0 ) ;
	setScale( 1.0f , 1.0f ) ;
	setAlphaFlg( false ) ;
	setRotateFlg( false ) ;

}

/*/
/*	裏画面の描画に必要なものをもらう
/*/
int Renderer::setHDC( HWND arg_hWnd , HDC arg_hDCBack , HDC arg_hDCWork )
{
	hWnd_ = arg_hWnd ;
	hDCBack_ = arg_hDCBack ;
	hDCWork_ = arg_hDCWork ;

	return( true ) ;
}

/*/
/*	描画したいビットマップをセット
/*/
int Renderer::selectBmp(
		HGDIOBJ arg_bmpData ,						// . 画像データ
		int arg_anchor ,							// . アンカー
		int arg_x , int arg_y ,						// . 配置座標
		int arg_u , int arg_v ,						// . 切り取り位置
		int arg_w , int arg_h ,						// . 幅高さ
		float arg_scaleX , float arg_scaleY ,		// . 拡大率
		int arg_alpha ,								// . 透明度
		float arg_angle								// . 角度
	)
{
	bmpData_ = arg_bmpData ;
	setAnchor( arg_anchor ) ;
	setPos( arg_x , arg_y ) ;
	setUV( arg_u , arg_v ) ;
	setWH( arg_w , arg_h ) ;
	setScale( arg_scaleX , arg_scaleY ) ;
	if ( arg_alpha < 255 )
	{
		alphaFlg_ = true ;
		setAlpha( arg_alpha ) ;
	}
	if ( arg_angle != 0 )
	{
		rotateFlg_ = true ;
		setAngle( arg_angle ) ;
	}

	return ( true ) ;
}

/*/
/*	バックバッファへ描画
/*/
int Renderer::Render( )
{
	HDC hDC ;
	static HDC				s_tRBWorkHDC ;
	static HBITMAP			s_tRBWorkBmp ;
	static BLENDFUNCTION	s_blendFunc = { AC_SRC_OVER , 0 , 255 , 0 } ;
	float radian , x , y ;
	POINT rotatePoint[ 3 ] ;
	int i ;

	if ( rotateFlg_ )
	{


	} else if ( alphaFlg_ ) {
		// 指定されているスプライトの選択
		SelectObject( hDCWork_ , bmpData_ ) ;

		// 新規作業用デバイスコンテキストの生成 ( 大きめに作る )
		hDC = GetDC( hWnd_ ) ;
		s_tRBWorkHDC = CreateCompatibleDC( hDC ) ;
		s_tRBWorkBmp = CreateCompatibleBitmap( hDC , (int)(w_ * scaleX_ * 1.5) , (int)(h_ * scaleY_ * 1.5) ) ;
		SelectObject( s_tRBWorkHDC , s_tRBWorkBmp ) ;	// 真っ白
		ReleaseDC( hWnd_ , hDC ) ;

		// 描画からバックバッファを切り取る ( 背景 )
		BitBlt( s_tRBWorkHDC ,
				0 , 0 ,
				(int)(w_ * scaleX_ * 1.5) , (int)(h_ * scaleY_ * 1.5) ,
				hDCBack_ ,
				(int)( x_ - ((w_*scaleX_/2)*anchorX_) ) , (int)( y_ - ((h_*scaleX_/2)*anchorY_) ) ,
				SRCCOPY
			) ;

		// 切り取ったDCに描画したい画像を張り付ける【ここで上に張り付けるビットマップが完成する】
		TransparentBlt(
				s_tRBWorkHDC ,
				0 , 0 ,
				(int)(w_ * scaleX_) , (int)(h_ * scaleY_) ,
				hDCWork_ ,
				u_ , v_ ,
				(int)(w_ * scaleX_) , (int)(h_ * scaleY_) ,
				RGB( 0 , 255 , 0 )
			) ;

		// アルファブレンド【半透明処理】
		s_blendFunc.SourceConstantAlpha = alpha_ ;		// アルファ値を入れる
		AlphaBlend(
				hDCBack_ ,
				(int)( x_ - ((w_*scaleX_/2)*anchorX_) ) , (int)( y_ - ((h_*scaleX_/2)*anchorY_) ) ,
				(int)(w_ * scaleX_ * 1.5) , (int)(h_ * scaleY_ * 1.5) ,
				s_tRBWorkHDC ,
				0 , 0 ,
				(int)(w_ * scaleX_ * 1.5) , (int)(h_ * scaleY_ * 1.5) ,
				s_blendFunc
			) ;

		// DC と ビットマップ領域の解放
		DeleteDC( s_tRBWorkHDC ) ;
		DeleteObject( s_tRBWorkBmp ) ;

	} else {
		// 画像の選択
		SelectObject( hDCWork_ , bmpData_ ) ;

		// バックバッファへ転送
		TransparentBlt(
			hDCBack_ ,
			(int)( x_ - ((w_*scaleX_/2)*anchorX_) ) , (int)( y_ - ((h_*scaleX_/2)*anchorY_) ) ,
			(int)( w_ * scaleX_ ) , (int)( h_ * scaleY_ ) ,
			hDCWork_ ,
			u_ , v_ ,
			w_ , h_ ,
			RGB( 0 , 255 , 0 )
		) ;

	}

	// 終了したので初期化
	Initialize( ) ;

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

/*/
/*	アンカーのセット
/*/
int Renderer::setAnchor( int arg_anchor )
{
	anchorX_ = arg_anchor % 3 ;
	anchorY_ = arg_anchor / 3 ;

	return( true ) ;
}

/*/
/*	透明度のセット
/*/
int Renderer::setAlpha( int arg_alpha )
{
	alpha_ = arg_alpha ;	

	return( true ) ;
}

/*/
/*	角度のセット
/*/
int Renderer::setAngle( float arg_angle )
{
	angle_ = arg_angle ;

	return( true ) ;
}

/*/
/*	透明度のフラグをセット
/*/
int Renderer::setAlphaFlg( bool arg_alphaFlg )
{
	alphaFlg_ = arg_alphaFlg ;	

	return( true ) ;
}

/*/
/*	角度のフラグをセット
/*/
int Renderer::setRotateFlg( bool arg_rotateFlg )
{
	rotateFlg_ = arg_rotateFlg ;

	return( true ) ;
}


