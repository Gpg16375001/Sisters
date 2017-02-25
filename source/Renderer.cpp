/*
______________________________________________________________________________________________

	FILE : Renderer.cpp

	________/ Explanation of file /___________________________________________________________

		Renderer クラスの実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/

#include <windows.h>
#include <math.h>

#include "Common.h"

// デストラクタ
Renderer::~Renderer( ) {	}

// スプライトのセット
int Renderer::setRender(
		HBITMAP arg_bmp ,								// . スプライトのパス
		int anchor ,									// . アンカー ( 配置位置 )
		int arg_x , int arg_y ,							// . 左上の座標
		int arg_u , int arg_v ,							// . 切り出し座標
		int arg_w , int arg_h ,							// . 幅と高さ
		float arg_scaleX , float arg_scaleY ,			// . スケール倍率
		float arg_degree ,								// . 回転する角度
		float arg_alpha									// . 透明度
	) {
	// すべての情報をリセット
	printf( "BMP File Was Set\n" ) ;
	setFlg( true ) ;									// フラグのセット
	selectBmp( arg_bmp ) ;								// スプライトのセット
	setPos( arg_x , arg_y ) ;							// 座標のセット
	setUV( arg_u , arg_v ) ;							// 切り出し座標のセット
	setWH( arg_w , arg_h ) ;							// 切り出し幅高さのセット
	setScaleXY( arg_scaleX , arg_scaleY ) ;				// スケールのセット

	if ( arg_degree != 0 )
	{
		setRotate( arg_degree ) ;						// 回転処理のセット
	}
	if ( arg_alpha != 0 )
	{
		setAlpha( arg_alpha ) ;							// アルファ処理のセット
	}
	return( true ) ;
}

// スプライトのクリア
int Renderer::clearScreen( ) {
	// すべての情報をクリア
	selectBmp( NULL ) ;				// スプライトのセット
	setPos( 0 , 0 ) ;				// 座標のセット
	setUV( 0 , 0 ) ;				// 切り出し座標のセット
	setWH( 0 , 0 ) ;				// 切り出し幅高さのセット
	setScaleXY( 1.0f , 1.0f ) ;		// スケールのセット
	setAlpha( 0 ) ;					// アルファ処理のセット
	setRotate( 0.0f ) ;				// 回転処理のセット
	setFlg( false ) ;				// フラグのセット
	setAlphaFlg( false ) ;			// フラグのセット
	setRotateFlg( false ) ;			// フラグのセット
	return( true ) ;
}

// 使用フラグのセット
int Renderer::setFlg( int arg_flg ) {
	useFlg_ = arg_flg ;
	return( true ) ;
}

// 描画したいスプライトをセット
int Renderer::selectBmp( HBITMAP arg_bmp ) {
	bmp_ = arg_bmp ;
	return( true ) ;
}

// 描画座標【左上】
int Renderer::setPos( int arg_x , int arg_y ) {
	x_ = arg_x ;
	y_ = arg_y ;
	return( true ) ;
}

// 切り出し座標
int Renderer::setUV( int arg_u , int arg_v ) {
	u_ = arg_u ;
	v_ = arg_v ;
	return( true ) ;
}

// 切り出し幅高さ
int Renderer::setWH( int arg_w , int arg_h ) {
	w_ = arg_w ;
	h_ = arg_h ;
	return( true ) ;
}

// BMPの描画
int Renderer::draw( ) {
	HDC hDC ;
	static HDC				s_tRBWorkHDC ;
	static HBITMAP			s_tRBWorkBmp ;

/*
	static BLENDFUNCTION	s_blendFunc = { AC_SRC_OVER , 0 , 255 , 0 } ;
	float radian , x , y ;
	POINT rotatePoint[ 3 ] ;
	int i ;
*/

	// 使用されていたら
	if ( useFlg_ ) {
		printf( "バックバッファへ転送\n" ) ;

		// 作業用デバイスコンテキストの生成
		hDC = GetDC( hWnd_ ) ;
		hDCWork_ = CreateCompatibleDC( hDC ) ;
		bmp_ = CreateCompatibleBitmap( hDC , w_ , h_ ) ;
		SelectObject( hDCWork_ , bmp_ ) ;
		ReleaseDC( hWnd_ , hDC ) ;

		TransparentBlt(
			*hDCBack_ ,
			x_ , y_ ,
			w_ , h_ ,
			hDCWork_ ,
			u_ , v_ ,
			w_ , h_ ,
			RGB( 0 , 255 , 0 )
			) ;

	}

	return( true ) ;
}

// スケール (拡大率)
int Renderer::setScaleXY( float arg_scaleX , float arg_scaleY ) {
	scaleX_ = arg_scaleX ;
	scaleY_ = arg_scaleY ;
	return( true ) ;
}

// 半透明のフラグセット
int Renderer::setAlphaFlg( int arg_alphaFlg ) {
	alphaFlg_ = arg_alphaFlg ;
	return( true ) ;
}

// 半透明の値セット
int Renderer::setAlpha( float arg_alpha ) {
	setAlphaFlg( true ) ;

	alpha_ = (int)( 255 * arg_alpha ) ;

	if ( alpha_ > 255 ) {
		alpha_ = 255 ;
	}

	return( true ) ;
}

// 回転のフラグセット
int Renderer::setRotateFlg( int arg_rotateFlg ) {
	rotateFlg_ = arg_rotateFlg ;
	return( true ) ;
}

// 回転角度をセット
int Renderer::setRotate( float arg_degree ) {
	setRotateFlg( true ) ;
	degree_ = arg_degree ;
	return( true ) ;
}



