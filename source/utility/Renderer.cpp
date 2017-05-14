/*
______________________________________________________________________________________________

	FILE : Renderer.cpp

	________/ Explanation of file /___________________________________________________________

		Renderer クラスの実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include <windows.h>
#include <stdio.h>	// --- コンソール用
#include <DxLib.h>
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
	sceneCut = 0 ;

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
		float arg_x , float arg_y ,					// . 配置座標
		float arg_u , float arg_v ,					// . 切り取り位置
		float arg_w , float arg_h ,					// . 幅高さ
		float arg_scaleX , float arg_scaleY ,		// . 拡大率
		int arg_alpha ,								// . 透明度
		float arg_degree							// . 角度
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
		setAlphaFlg( true ) ;
		setAlpha( arg_alpha ) ;
	}
	if ( arg_degree != 0 )
	{
		setRotateFlg( true ) ;
		setAngle( arg_degree ) ;
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
	float	radian , x , y ;
	POS		rotatePoint[ 3 ] ;
	POINT	rotateP[ 3 ] ;
	int i ;

	// 指定されているスプライトの選択
	SelectObject( hDCWork_ , bmpData_ ) ;

	if ( alphaFlg_ ) {

		// 新規作業用デバイスコンテキストの生成 ( 大きめに作る )
		hDC = GetDC( hWnd_ ) ;
		s_tRBWorkHDC = CreateCompatibleDC( hDC ) ;
		s_tRBWorkBmp = CreateCompatibleBitmap( hDC , (int)(w_ * scaleX_) , (int)(h_ * scaleY_) ) ;
		SelectObject( s_tRBWorkHDC , s_tRBWorkBmp ) ;	// 真っ白
		ReleaseDC( hWnd_ , hDC ) ;

		// 描画からバックバッファを切り取る ( 背景 )
		BitBlt( s_tRBWorkHDC ,
				0 , 0 ,
				(int)(w_ * scaleX_) , (int)(h_ * scaleY_) ,
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
				(int)u_ , (int)v_ ,
				(int)(w_ * scaleX_) , (int)(h_ * scaleY_) ,
				RGB( 0 , 255 , 0 )
			) ;

		// アルファブレンド【半透明処理】
		s_blendFunc.SourceConstantAlpha = alpha_ ;		// アルファ値を入れる
		AlphaBlend(
				hDCBack_ ,
				(int)( x_ - ((w_*scaleX_/2)*anchorX_) ) , (int)( y_ - ((h_*scaleX_/2)*anchorY_) ) ,
				(int)(w_ * scaleX_) , (int)(h_ * scaleY_) ,
				s_tRBWorkHDC ,
				0 , 0 ,
				(int)(w_ * scaleX_) , (int)(h_ * scaleY_) ,
				s_blendFunc
			) ;

		// DC と ビットマップ領域の解放
		DeleteDC( s_tRBWorkHDC ) ;
		DeleteObject( s_tRBWorkBmp ) ;
	}
	else if ( rotateFlg_ )
	{
		// 角度を radian に変換
		radian = degree_ * 3.14f / 180.0f ;

		// 左上頂点を回転変換
		// 点の位置を求める
		rotatePoint[ 0 ].x = -( w_ / 2.0f ) ;
		rotatePoint[ 0 ].y = -( h_ / 2.0f ) ;
		x = rotatePoint[ 0 ].x ;
		y = rotatePoint[ 0 ].y ;
		// 加法の定理
		rotatePoint[ 0 ].x = ( x * cos(radian) - y * sin(radian) ) ;
		rotatePoint[ 0 ].y = ( x * sin(radian) + y * cos(radian) ) ;

		// 右上頂点を回転変換
		rotatePoint[ 1 ].x = ( w_ / 2.0f ) ;
		rotatePoint[ 1 ].y = -( h_ / 2.0f ) ;
		x = rotatePoint[ 1 ].x ;
		y = rotatePoint[ 1 ].y ;
		rotatePoint[ 1 ].x = ( x * cos(radian) - y * sin(radian) ) ;
		rotatePoint[ 1 ].y = ( x * sin(radian) + y * cos(radian) ) ;

		// 左下頂点を回転変換
		rotatePoint[ 2 ].x = -( w_ / 2.0f ) ;
		rotatePoint[ 2 ].y = ( h_ / 2.0f ) ;
		x = rotatePoint[ 2 ].x ;
		y = rotatePoint[ 2 ].y ;
		rotatePoint[ 2 ].x = ( x * cos(radian) - y * sin(radian) ) ;
		rotatePoint[ 2 ].y = ( x * sin(radian) + y * cos(radian) ) ;

		// 平行移動で中心位置を戻す
		for ( i = 0 ; i < 3 ; i++ )
		{
			rotatePoint[ i ].x += ( w_ / 2.0f ) ;
			rotatePoint[ i ].y += ( h_ / 2.0f ) ;
		}

		// 作業用デバイスコンテキストの生成 ( 大きめに作る )
		hDC = GetDC( hWnd_ ) ;
		s_tRBWorkHDC = CreateCompatibleDC( hDC ) ;
		s_tRBWorkBmp = CreateCompatibleBitmap( hDC , (int)w_ , (int)h_ ) ;
		SelectObject( s_tRBWorkHDC , s_tRBWorkBmp ) ;	// 真っ白
		ReleaseDC( hWnd_ , hDC ) ;

		// 作業デバイスコンテキストをカラーキーで塗りつぶす
		RECT fillBox ;
		fillBox.left = 0 ;
		fillBox.top = 0 ;
		fillBox.right = (LONG)w_ ;
		fillBox.bottom = (LONG)h_ ;
		HBRUSH hBrush ;
		hBrush = CreateSolidBrush( RGB(0 , 255 , 0) ) ;
		FillRect( s_tRBWorkHDC , &fillBox , hBrush ) ;
		DeleteObject( hBrush ) ;

		// POINT型にする
		for ( i = 0 ; i < 3 ; i++ )
		{
			rotateP[ i ].x = ( int )rotatePoint[ i ].x ;
			rotateP[ i ].y = ( int )rotatePoint[ i ].y ;
		}

		// 作業用に転送
		PlgBlt( s_tRBWorkHDC ,
				rotateP ,
				hDCWork_ ,
				0 , 0 ,
				(int)w_ ,
				(int)h_ ,
				NULL ,
				0 , 0
			) ;

		// バックバッファに転送
		TransparentBlt(
				hDCBack_ ,
				(int)( x_ - ((w_*scaleX_/2)*anchorX_) ) , (int)( y_ - ((h_*scaleX_/2)*anchorY_) ) ,
				(int)( w_ * scaleX_ ) , (int)( h_ * scaleY_ ) ,
				s_tRBWorkHDC ,
				(int)u_ , (int)v_ ,
				(int)w_ , (int)h_ ,
				RGB( 0 , 255 , 0 )
			) ;

		// DC と ビットマップ領域の解放
		DeleteDC( s_tRBWorkHDC ) ;
		DeleteObject( s_tRBWorkBmp ) ;

	} else {

		// バックバッファへ転送
		TransparentBlt(
			hDCBack_ ,
			(int)( x_ - ((w_*scaleX_/2)*anchorX_) ) , (int)( y_ - ((h_*scaleX_/2)*anchorY_) ) ,
			(int)( w_ * scaleX_ ) , (int)( h_ * scaleY_ ) ,
			hDCWork_ ,
			(int)u_ , (int)v_ ,
			(int)w_ , (int)h_ ,
			RGB( 0 , 255 , 0 )
		) ;

	}

	// 終了したので初期化
	Initialize( ) ;

	return ( true ) ;
}

int Renderer::DrawRote( const TCHAR* url )
{
	int Handle;     // 画像格納用ハンドル
	Handle = LoadGraph( url ) ;
	DrawRotaGraph( x_ ,  y_ , 1.0f , degree_ , Handle , FALSE ) ;

	return( true ) ;

}


/*/
/*	X軸 と  Y軸 をセット
/*/
int Renderer::setPos( float arg_x , float arg_y )
{
	x_ = arg_x ;
	y_ = arg_y ;

	return( true ) ;
}

/*/
/*	切り出し座標のセット
/*/
int Renderer::setUV( float arg_u , float arg_v )
{
	u_ = arg_u ;
	v_ = arg_v ;

	return( true ) ;
}

/*/
/*	切り出し幅高さのセット
/*/
int Renderer::setWH( float arg_w , float arg_h )
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
	setAlphaFlg( true ) ;
	alpha_ = arg_alpha ;	

	return( true ) ;
}

/*/
/*	角度のセット
/*/
int Renderer::setAngle( float arg_degree )
{
	setRotateFlg( true ) ;
	degree_ = arg_degree ;

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


