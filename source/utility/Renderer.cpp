/*
______________________________________________________________________________________________

	FILE : Renderer.cpp

	________/ Explanation of file /___________________________________________________________

		Renderer クラスの実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/

#include <windows.h>
#include <math.h>

#include "ConsoleWindow.h"
#include "Renderer.h"

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
	static BLENDFUNCTION	s_blendFunc = { AC_SRC_OVER , 0 , 255 , 0 } ;
	float radian , x , y ;
	POINT rotatePoint[ 3 ] ;
	int i ;

	// 使用されていたら
	if ( useFlg_ ) {
	printf( "バックバッファへ転送\n" ) ;

		/*/
		/*	回転処理
		/*/
		if ( rotateFlg_ ) {
			// 角度を radian に変換
			radian = degree_ * 3.14f / 180.0f ;

			// 左上頂点を回転変換
			// 点の位置を求める
			rotatePoint[ 0 ].x = -( w_ / 2 ) ;
			rotatePoint[ 0 ].y = -( h_ / 2 ) ;
			x = ( float )rotatePoint[ 0 ].x ;
			y = ( float )rotatePoint[ 0 ].y ;
			// 加法の定理
			rotatePoint[ 0 ].x = ( int )( x * cos(radian) - y * sin(radian)  ) ;
			rotatePoint[ 0 ].y = ( int )( x * sin(radian) + y * cos(radian)  ) ;

			// 右上頂点を回転変換
			rotatePoint[ 1 ].x = ( w_ / 2 ) ;
			rotatePoint[ 1 ].y = -( h_ / 2 ) ;
			x = ( float )rotatePoint[ 1 ].x ;
			y = ( float )rotatePoint[ 1 ].y ;
			rotatePoint[ 1 ].x = ( int )( x * cos(radian) - y * sin(radian)  ) ;
			rotatePoint[ 1 ].y = ( int )( x * sin(radian) + y * cos(radian)  ) ;

			// 左下頂点を回転変換
			rotatePoint[ 2 ].x = -( w_ / 2 ) ;
			rotatePoint[ 2 ].y = ( h_ / 2 ) ;
			x = ( float )rotatePoint[ 2 ].x ;
			y = ( float )rotatePoint[ 2 ].y ;
			rotatePoint[ 2 ].x = ( int )( x * cos(radian) - y * sin(radian)  ) ;
			rotatePoint[ 2 ].y = ( int )( x * sin(radian) + y * cos(radian)  ) ;

			// 平行移動で中心位置を戻す
			for ( i = 0 ; i < 3 ; i++ ) {
				rotatePoint[ i ].x += ( w_ / 2 ) ;
				rotatePoint[ i ].y += ( h_ / 2 ) ;
			}

			// ビットマップを選択
			SelectObject( hDCWork_ , bmp_ ) ;

			// 作業用デバイスコンテキストの生成
			hDC = GetDC( hWnd_ ) ;
			s_tRBWorkHDC = CreateCompatibleDC( hDC ) ;
			s_tRBWorkBmp = CreateCompatibleBitmap( hDC , w_ , h_ ) ;	// 大きさが合わない場合変える
			SelectObject( s_tRBWorkHDC , s_tRBWorkBmp ) ;	// 真っ白
			ReleaseDC( hWnd_ , hDC ) ;

			// 作業デバイスコンテキストをカラーキーで塗りつぶす
			RECT fillBox ;
			fillBox.left = 0 ;
			fillBox.top = 0 ;
			fillBox.right = w_ ;
			fillBox.bottom = h_ ;
			HBRUSH hBrush ;
			hBrush = CreateSolidBrush( RGB(0 , 255 , 0) ) ;
			FillRect( s_tRBWorkHDC , &fillBox , hBrush ) ;
			DeleteObject( hBrush ) ;

			// 作業用に転送
			PlgBlt( s_tRBWorkHDC , rotatePoint , hDCWork_ , u_ , v_ , w_ , h_ , NULL , 0 , 0 ) ;

			// バックバッファに転送
			TransparentBlt(
					hDCWork_ ,
					x_ , y_ ,
					w_ , h_ ,
					s_tRBWorkHDC ,
					u_ , v_ ,
					w_ , h_ ,
					RGB( 0 , 255 , 0 )
				) ;

			// DC と ビットマップ領域の解放
			DeleteDC( s_tRBWorkHDC ) ;
			DeleteObject( s_tRBWorkBmp ) ;

		} 

		/*/
		/*	バックバッファへ転送
		/*/
		// 指定されているスプライトの選択
		SelectObject( hDCWork_ , bmp_ ) ;

		TransparentBlt(
				*hDCBack_ ,
				x_ , y_ ,
				(int)(w_ * scaleX_) ,
				(int)(h_ * scaleY_) ,
				hDCWork_ ,
				u_ , v_ ,
				w_ , h_ ,
				RGB( 0 , 255 , 0 )
			) ;

		/*/
		/*	半透明処理をする場合
		/*/
		if ( alphaFlg_ ) {
			// 指定されているスプライトの選択
			SelectObject( hDCWork_ , bmp_ ) ;

			// 作業用デバイスコンテキストの生成
			hDC = GetDC( hWnd_ ) ;
			s_tRBWorkHDC = CreateCompatibleDC( hDC ) ;
			s_tRBWorkBmp = CreateCompatibleBitmap( hDC , w_ , h_ ) ;
			SelectObject( s_tRBWorkHDC , s_tRBWorkBmp ) ;	// 真っ白
			ReleaseDC( hWnd_ , hDC ) ;

			// 描画からバックバッファを切り取る (背景)
			BitBlt( s_tRBWorkHDC , 0 , 0 , w_ , h_ , *hDCBack_ , x_ , y_ , SRCCOPY ) ;

			// 切り取ったDCに描画したい画像を張り付ける【ここで上に張り付けるビットマップが完成する】
			TransparentBlt(
					s_tRBWorkHDC ,
					0 , 0 ,
					w_ , h_ ,
					hDCWork_ ,
					u_ , v_ ,
					w_ , h_ ,
					RGB( 0 , 255 , 0 )
				) ;

			// アルファブレンド【半透明処理】
			s_blendFunc.SourceConstantAlpha = alpha_ ;		// アルファ値を入れる
			AlphaBlend(
					*hDCBack_ ,
					x_ , y_ ,
					w_ , h_ ,
					s_tRBWorkHDC ,
					0 , 0 ,
					w_ , h_ ,
					s_blendFunc
				) ;

			// DC と ビットマップ領域の解放
			DeleteDC( s_tRBWorkHDC ) ;
			DeleteObject( s_tRBWorkBmp ) ;
			
			printf("setAlpha was true ! \n") ;

		}

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



