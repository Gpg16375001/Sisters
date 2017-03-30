/*
______________________________________________________________________________________________

	FILE : Sprite.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		Sprite クラスの実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/

#include <windows.h>
#include <stdio.h>	// --- コンソール用

#include "Common.h"

// コンストラクタ
Sprite::Sprite( ) {
	// インスタンス化時の初期化
	clearSprite( ) ;
}

// デストラクタ
Sprite::~Sprite( ) {	}

// スプライトのセット
int Sprite::setSprite(
		int arg_bmpNo ,				// スプライトの番号
		int arg_x , int arg_y ,		// 左上の座標
		int arg_u , int arg_v ,		// 切り出し座標
		int arg_w , int arg_h 		// 幅と高さ
	) {								 
	// すべての情報をリセット
	setFlg( true ) ;				// フラグのセット
	selectBmp( arg_bmpNo ) ;		// スプライトのセット
	setPos( arg_x , arg_y ) ;		// 座標のセット
	setUV( arg_u , arg_v ) ;		// 切り出し座標のセット
	setWH( arg_w , arg_h ) ;		// 切り出し幅高さのセット
	return( true ) ;
}

// スプライトのクリア
int Sprite::clearSprite( ) {
	// すべての情報をクリア
	selectBmp( 0 ) ;				// スプライトのセット
	setPos( 0 , 0 ) ;				// 座標のセット
	setUV( 0 , 0 ) ;				// 切り出し座標のセット
	setWH( 0 , 0 ) ;				// 切り出し幅高さのセット
	setScaleXY( 0.0 , 0.0 ) ;		// スケールのセット
	setAlpha( 0 ) ;					// アルファ処理のセット
	setRotate( 0.0f ) ;				// 回転処理のセット
	setFlg( false ) ;				// フラグのセット
	setScaleFlg( false ) ;			// フラグのセット
	setAlphaFlg( false ) ;			// フラグのセット
	setRotateFlg( false ) ;			// フラグのセット
	return( true ) ;
}

// 使用フラグのセット
int Sprite::setFlg( int arg_flg ) {
	m_useFlg = arg_flg ;
	return( true ) ;
}

// 描画したいスプライト番号をセット
int Sprite::selectBmp( int arg_bmpNo ) {
	m_bmpNo = arg_bmpNo ;
	return( true ) ;
}

// 描画座標【左上】
int Sprite::setPos( int arg_x , int arg_y ) {
	m_x = arg_x ;
	m_y = arg_y ;
	return( true ) ;
}

// 切り出し座標
int Sprite::setUV( int arg_u , int arg_v ) {
	m_u = arg_u ;
	m_v = arg_v ;
	return( true ) ;
}

// 切り出し幅高さ
int Sprite::setWH( int arg_w , int arg_h ) {
	m_w = arg_w ;
	m_h = arg_h ;
	return( true ) ;
}

// BMPの描画
int Sprite::draw( ) {
	HDC hDC ;
	static HDC				s_tRBWorkHDC ;
	static HBITMAP			s_tRBWorkBmp ;
	static BLENDFUNCTION	s_blendFunc = { AC_SRC_OVER , 0 , 255 , 0 } ;
	float radian , x , y ;
	POINT rotatePoint[ 3 ] ;
	int i ;

	// 使用されていたら
	if ( m_useFlg ) {

		if ( m_rotateFlg == (int)true ) {
			// 角度を radian に変換
			radian = m_degree * 3.14f / 180.0f ;

			// 左上頂点を回転変換
			// 点の位置を求める
			rotatePoint[ 0 ].x = -( m_w / 2 ) ;
			rotatePoint[ 0 ].y = -( m_h / 2 ) ;
			x = ( float )rotatePoint[ 0 ].x ;
			y = ( float )rotatePoint[ 0 ].y ;
			// 加法の定理
			rotatePoint[ 0 ].x = ( int )( x * cos(radian) - y * sin(radian)  ) ;
			rotatePoint[ 0 ].y = ( int )( x * sin(radian) + y * cos(radian)  ) ;

			// 右上頂点を回転変換
			rotatePoint[ 1 ].x = ( m_w / 2 ) ;
			rotatePoint[ 1 ].y = -( m_h / 2 ) ;
			x = ( float )rotatePoint[ 1 ].x ;
			y = ( float )rotatePoint[ 1 ].y ;
			rotatePoint[ 1 ].x = ( int )( x * cos(radian) - y * sin(radian)  ) ;
			rotatePoint[ 1 ].y = ( int )( x * sin(radian) + y * cos(radian)  ) ;

			// 左下頂点を回転変換
			rotatePoint[ 2 ].x = -( m_w / 2 ) ;
			rotatePoint[ 2 ].y = ( m_h / 2 ) ;
			x = ( float )rotatePoint[ 2 ].x ;
			y = ( float )rotatePoint[ 2 ].y ;
			rotatePoint[ 2 ].x = ( int )( x * cos(radian) - y * sin(radian)  ) ;
			rotatePoint[ 2 ].y = ( int )( x * sin(radian) + y * cos(radian)  ) ;

			// 平行移動で中心位置を戻す
			for ( i = 0 ; i < 3 ; i++ ) {
				rotatePoint[ i ].x += ( m_w / 2 ) ;
				rotatePoint[ i ].y += ( m_h / 2 ) ;
			}

			// ビットマップを選択
			SelectObject( g_hWorkBuf , g_bDataSprTable[ m_bmpNo ].getBmpData( ) ) ;

			// 作業用デバイスコンテキストの生成
			hDC = GetDC( g_hWindow ) ;
			s_tRBWorkHDC = CreateCompatibleDC( hDC ) ;
			s_tRBWorkBmp = CreateCompatibleBitmap( hDC , m_w , m_h ) ;
			SelectObject( s_tRBWorkHDC , s_tRBWorkBmp ) ;	// 真っ白
			ReleaseDC( g_hWindow , hDC ) ;

			// 作業デバイスコンテキストをカラーキーで塗りつぶす
			RECT fillBox ;
			fillBox.left = 0 ;
			fillBox.top = 0 ;
			fillBox.right = m_w ;
			fillBox.bottom = m_h ;
			HBRUSH hBrush ;
			hBrush = CreateSolidBrush( RGB(0 , 255 , 0) ) ;
			FillRect( s_tRBWorkHDC , &fillBox , hBrush ) ;
			DeleteObject( hBrush ) ;

			// 作業用に転送
			PlgBlt( s_tRBWorkHDC , rotatePoint , g_hWorkBuf , m_u , m_v , m_w , m_h , NULL , 0 , 0 ) ;

			// バックバッファに転送
			TransparentBlt(
					g_hBackBuf ,
					m_x , m_y ,
					m_w , m_h ,
					s_tRBWorkHDC ,
					m_u , m_v ,
					m_w , m_h ,
					RGB( 0 , 255 , 0 )
				) ;

			// DC と ビットマップ領域の解放
			DeleteDC( s_tRBWorkHDC ) ;
			DeleteObject( s_tRBWorkBmp ) ;

		} else if ( m_alphaFlg == (int)true ) {		// 半透明処理をする場合
			// 指定されているスプライトの選択
			SelectObject( g_hWorkBuf , g_bDataSprTable[ m_bmpNo ].getBmpData( ) ) ;

			// 作業用デバイスコンテキストの生成
			hDC = GetDC( g_hWindow ) ;
			s_tRBWorkHDC = CreateCompatibleDC( hDC ) ;
			s_tRBWorkBmp = CreateCompatibleBitmap( hDC , m_w , m_h ) ;
			SelectObject( s_tRBWorkHDC , s_tRBWorkBmp ) ;	// 真っ白
			ReleaseDC( g_hWindow , hDC ) ;

			// 描画からバックバッファを切り取る (背景)
			BitBlt( s_tRBWorkHDC , 0 , 0 , m_w , m_h , g_hBackBuf , m_x , m_y , SRCCOPY ) ;

			// 切り取ったDCに描画したい画像を張り付ける【ここで上に張り付けるビットマップが完成する】
			TransparentBlt(
					s_tRBWorkHDC ,
					0 , 0 ,
					m_w , m_h ,
					g_hWorkBuf ,
					m_u , m_v ,
					m_w , m_h ,
					RGB( 0 , 255 , 0 )
				) ;

			// アルファブレンド【半透明処理】
			s_blendFunc.SourceConstantAlpha = m_alpha ;		// アルファ値を入れる
			AlphaBlend(
					g_hBackBuf ,
					m_x , m_y ,
					m_w , m_h ,
					s_tRBWorkHDC ,
					0 , 0 ,
					m_w , m_h ,
					s_blendFunc
				) ;

			// DC と ビットマップ領域の解放
			DeleteDC( s_tRBWorkHDC ) ;
			DeleteObject( s_tRBWorkBmp ) ;
			
			printf("setAlpha was true ! \n") ;

		} else if ( m_scaleFlg == (int)true ) {		// 拡大する描画
			// 指定されているスプライトの選択
			SelectObject( g_hWorkBuf , g_bDataSprTable[ m_bmpNo ].getBmpData( ) ) ;

			TransparentBlt(
					g_hBackBuf ,
					(m_x / 2) , (m_y / 2) ,
					(int)(m_w * m_scaleX) ,
					(int)(m_h * m_scaleY) ,
					g_hWorkBuf ,
					m_u , m_v ,
					m_w , m_h ,
					RGB( 0 , 255 , 0 )
				) ;

		} else {	// 通常の描画

			// 指定されているスプライトの選択
			SelectObject( g_hWorkBuf , g_bDataSprTable[ m_bmpNo ].getBmpData( ) ) ;

			TransparentBlt(
					g_hBackBuf ,
					m_x , m_y ,
					m_w , m_h ,
					g_hWorkBuf ,
					m_u , m_v ,
					m_w , m_h ,
					RGB( 0 , 255 , 0 )
				) ;
		}
	}

	return( true ) ;
}

// スケールフラグのセット
int Sprite::setScaleFlg( int arg_scaleFlg ) {
	m_scaleFlg = arg_scaleFlg ;
	return( true ) ;
}

// スケール (拡大率)
int Sprite::setScaleXY( float arg_scaleX , float arg_scaleY ) {
	setScaleFlg( true ) ;
	m_scaleX = arg_scaleX ;
	m_scaleY = arg_scaleY ;
	return( true ) ;
}

// 半透明のフラグセット
int Sprite::setAlphaFlg( int arg_alphaFlg ) {
	m_alphaFlg = arg_alphaFlg ;
	return( true ) ;
}

// 半透明の値セット
int Sprite::setAlpha( float arg_alpha ) {
	setAlphaFlg( true ) ;

	m_alpha = (int)( 255 * arg_alpha ) ;

	if ( m_alpha > 255 ) {
		m_alpha = 255 ;
	}

	return( true ) ;
}

// 回転のフラグセット
int Sprite::setRotateFlg( int arg_rotateFlg ) {
	m_rotateFlg = arg_rotateFlg ;
	return( true ) ;
}

// 回転角度をセット
int Sprite::setRotate( float arg_degree ) {
	setRotateFlg( true ) ;
	m_degree = arg_degree ;
	return( true ) ;
}



