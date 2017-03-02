/*
________________________________________________________________________________________________________________

	FILE : Chip.cpp

	________/ Explanation of file /___________________________________________________________

		Chip クラスの実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include "Chip.h"
#include "Sprite.h"
#include "KeyManager.h"

/*/
/*	デストラクタ
/*/
Chip::~Chip( )
{
	// --- 使用されていたらオブジェクト破棄
	for ( int i = 0 ; i < MAX_BMP_CBG ; ++i )
	{
		if( bmpCBGTable_[ i ]._hBmp != NULL )
		{
			bmpCBGTable_[ i ]._hBmp = NULL ;
		}
		clearData( i ) ; 
	}
}

/*/
/*	初期化
/*/
void Chip::Initialize( )
{
	// --- 使用されていたらオブジェクト破棄
	for ( int i = 0 ; i < MAX_BMP_CBG ; ++i )
	{
		if( bmpCBGTable_[ i ]._hBmp != NULL )
		{
			bmpCBGTable_[ i ]._hBmp = NULL ;
		}
		clearData( i ) ; 
	}
	setMapSize( 0 , 0 ) ;
	RenderMapSize( 0 , 0 ) ;
	scrollX_ = 0 ;
	scrollY_ = 0 ;
	clearChipMap( ) ;

}

/*/
/*	画像データのクリア
/*/
int Chip::clearData( int arg_bmpNo )
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
int Chip::loadBmpData( int arg_bmpNo , HBITMAP arg_hbmp )
{
	// 使用されていたらオブジェクト破棄
	clearData( arg_bmpNo ) ;

	// データの読み込みと幅と高さをセット
	bmpCBGTable_[ arg_bmpNo ]._hBmp = arg_hbmp ;

	return ( true ) ;
}

/*/
/*	一括イメージ読み込み
/*/
int Chip::loadBmpDataAll( HBITMAP arg_hbmp )
{
	for ( int i = 0 ; i < MAX_BMP_CBG ; ++i )
	{
		loadBmpData( i , arg_hbmp ) ;
	}

	return ( true ) ;
}


/*/
/*	画面に描画できるグリッドの数を指定を指定
/*/
int Chip::RenderMapSize( int arg_w , int arg_h )
{
	renderMap_w_ = arg_w ;
	renderMap_h_ = arg_h ;

	return( true ) ;
}

/*/
/*	マップのサイズをセット
/*/
int Chip::setMapSize( int arg_w , int arg_h )
{
	map_w_ = arg_w ;
	map_h_ = arg_h ;

	return( true ) ;
}

/*/
/*	描画するかどうかのフラグをセット
/*/
int Chip::setUseFlg( int arg_bmpNo , bool arg_useFlg )
{
	bmpCBGTable_[ arg_bmpNo ]._useFlg = arg_useFlg ;

	return( true ) ;
}

/*/
/*	透明処理をするかどうかのフラグをセット
/*/
int Chip::setUseAlpha( int arg_bmpNo , bool arg_useAlpha )
{
	bmpCBGTable_[ arg_bmpNo ]._useAlpha = arg_useAlpha ;

	return( true ) ;
}

/*/
/*	回転処理をするかどうかのフラグをセット
/*/
int Chip::setUseRotate( int arg_bmpNo , bool arg_useRotate )
{
	bmpCBGTable_[ arg_bmpNo ]._useRotate = arg_useRotate ;

	return( true ) ;
}

/*/
/*	ポジションのセット
/*/
int Chip::setBmpXY( int arg_bmpNo , float arg_x , float arg_y )
{
	bmpCBGTable_[ arg_bmpNo ]._x = arg_x ;
	bmpCBGTable_[ arg_bmpNo ]._y = arg_y ;

	return( true ) ;
}

/*/
/*	切り取り位置のセット
/*/
int Chip::setBmpUV( int arg_bmpNo , int arg_u , int arg_v )
{
	bmpCBGTable_[ arg_bmpNo ]._u = arg_u ;
	bmpCBGTable_[ arg_bmpNo ]._v = arg_v ;

	return( true ) ;
}

/*/
/*	幅、高さのセット
/*/
int Chip::setBmpWH( int arg_bmpNo , int arg_w , int arg_h )
{
	bmpCBGTable_[ arg_bmpNo ]._w = arg_w ;
	bmpCBGTable_[ arg_bmpNo ]._h = arg_h ;

	return( true ) ;
}

/*/
/*	拡大率のセット
/*/
int Chip::setBmpScale( int arg_bmpNo , float arg_w , float arg_h )
{
	bmpCBGTable_[ arg_bmpNo ]._scaleX = arg_w ;
	bmpCBGTable_[ arg_bmpNo ]._scaleY = arg_h ;

	return( true ) ;
}

/*/
/*	アンカーをセット
/*/
int Chip::setAnchor( int arg_bmpNo , int arg_anchor )
{
	bmpCBGTable_[ arg_bmpNo ]._anchor = arg_anchor ;

	return( true ) ;
}

/*/
/*	透明度のセット
/*/
int Chip::setAlpha( int arg_bmpNo , int arg_alpha )
{
	bmpCBGTable_[ arg_bmpNo ]._alpha = arg_alpha ;	

	return( true ) ;
}

/*/
/*	角度のセット
/*/
int Chip::setAngle( int arg_bmpNo , float arg_degree )
{
	bmpCBGTable_[ arg_bmpNo ]._degree = arg_degree ;

	return( true ) ;
}


/*/
/*	配列座標のセット
/*/
int Chip::setArray( int arg_bmpNo , int arg_ax , int arg_ay  )
{
	bmpCBGTable_[ arg_bmpNo ]._arrayX = arg_ax ;
	bmpCBGTable_[ arg_bmpNo ]._arrayY = arg_ay ;

	return( true ) ;
}

/*/
/*	描画する情報をセット
/*/
int Chip::setChipData(
		int arg_bmpNo ,
		int arg_anchor ,
		int arg_arrayX , int arg_arrayY ,
		float arg_x , float arg_y ,
		int arg_u , int arg_v ,
		int arg_w , int arg_h ,
		float arg_scaleX , float arg_scaleY ,
		int arg_alpha ,
		float arg_degree
	) 
{
	bmpCBGTable_[ arg_bmpNo ]._bmpNo = arg_bmpNo ;
	setUseFlg( arg_bmpNo , true ) ;
	setAnchor( arg_bmpNo , arg_anchor ) ;
	setArray( arg_bmpNo , arg_arrayX , arg_arrayY ) ;
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

/*/
/*	チップのセット
/*/
int Chip::setChipMap( int arg_x , int arg_y , int arg_chipNo ) {
	m_chipTable_[ (CHIP_X * arg_y) + arg_x ] = arg_chipNo ;

	return( true ) ;
}

/*/
/*	チップデータのクリアー
/*/
int Chip::clearChipMap( ) {
	memset( m_chipTable_ , 0 , CHIP_X * CHIP_Y * sizeof(int) ) ;

	return( true ) ;
}

/*/
/*	スクロールの値をセット
/*/
int Chip::setScrollSize( int arg_x , int arg_y  )
{
	scrollX_ += arg_x ;
	scrollY_ += arg_y ;

	if ( scrollX_ >= 32 )
	{
		scrollX_ = 32 ;
	}

	return( true ) ;
}

/*/
/*	Update
/*
/*	自分のマップデータをもとにグリッド配置の計算をする
/*/
void Chip::Update( )
{
	printf( "	%d , %d \n" , scrollX_ , -(scrollX_ / 25) ) ;
	for ( int i = 0 - (scrollX_ / map_w_) ; i < renderMap_w_ * renderMap_h_ - (scrollX_ / map_w_) ; ++i )
	{
		/*/
		/*	チップデータ
		/*/
		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] <= 8 )
		{
			setChipData(
					i ,
					0 ,
					i % map_w_ , i / map_h_ ,
					( float )((i % renderMap_w_) * CHIP_W - 32) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) ,
					( float )((i / renderMap_w_) * CHIP_H - 128) + scrollY_ ,
					(m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] * CHIP_W) ,
					0 ,
					64 , 64 ,
					1.0f , 1.0f
				) ;
		}

		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == 9 )
		{
			setChipData(
					i ,
					0 ,
					i % map_w_ , i / map_h_ ,
					( float )((i % renderMap_w_) * CHIP_W - 32) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) ,
					( float )((i / renderMap_w_) * CHIP_H - 128) + scrollY_ ,
					((m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] - 9) * CHIP_W) ,
					128 ,
					128 , 128 ,
					1.0f , 1.0f
				) ;

		}

		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == 10 )
		{
			setChipData(
					i ,
					0 ,
					i % map_w_ , i / map_h_ ,
					( float )((i % renderMap_w_) * CHIP_W - 32) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) ,
					( float )((i / renderMap_w_) * CHIP_H - 128) + scrollY_ ,
					((m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] - 4) * CHIP_W) ,
					128 ,
					128 , 128 ,
					1.0f , 1.0f
				) ;

		}

		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == 11 )
		{
			setChipData(
					i ,
					0 ,
					i % map_w_ , i / map_h_ ,
					( float )((i % renderMap_w_) * CHIP_W - 32) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) ,
					( float )((i / renderMap_w_) * CHIP_H - 128) + scrollY_ - 64 ,
					((m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] - 11) * CHIP_W) ,
					64 ,
					256 , 128 ,
					1.0f , 1.0f
				) ;

		}

		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == 12 )
		{
			setChipData(
					i ,
					0 ,
					i % map_w_ , i / map_h_ ,
					( float )((i % renderMap_w_) * CHIP_W - 32) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) ,
					( float )((i / renderMap_w_) * CHIP_H - 128) + scrollY_ - 64 ,
					((m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] - 8) * CHIP_W) ,
					64 ,
					256 , 128 ,
					1.0f , 1.0f
				) ;

		}

		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == 13 )
		{
			setChipData(
					i ,
					0 ,
					i % map_w_ , i / map_h_ ,
					( float )((i % renderMap_w_) * CHIP_W - 32) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) ,
					( float )((i / renderMap_w_) * CHIP_H - 128) + scrollY_ - 192 ,
					((m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] - 13) * CHIP_W) ,
					64 + 128 ,
					256 , 256 ,
					1.0f , 1.0f
				) ;

		}

		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == 14 )
		{
			setChipData(
					i ,
					0 ,
					i % map_w_ , i / map_h_ ,
					( float )((i % renderMap_w_) * CHIP_W - 32) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) ,
					( float )((i / renderMap_w_) * CHIP_H - 128) + scrollY_ - 192 ,
					((m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] - 10) * CHIP_W) ,
					64 + 128 ,
					256 , 256 ,
					1.0f , 1.0f
				) ;

		}


		/*/
		/*	スプライトデータ
		/*/
		int useBmpNo = 0 ;

		/*/
		/*	___/ まるのこ /___________________
		/*/
		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == 50 )
		{
			static float spin = 0.0f ;

			for ( int b = 10 ; b < 30 ; ++b )
			{
				/*/
				/*	・使ってない丸鋸を選択する
				/*/
				if ( Sprite::GetInstance()->getUseFlg( b ) )
				{
				} else {
					useBmpNo = b ;
				}
			}
			printf( "useBmpNo = %d \n" , useBmpNo ) ;
			Sprite::GetInstance()->setBmpData(
					useBmpNo ,
					4 ,
					( float )( ((i % renderMap_w_) * CHIP_W - 32) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) ) ,
					( float )( ((i / renderMap_w_) * CHIP_H - 128) + scrollY_ ) ,
					0 , 0 ,
					128 , 128 ,
					1.0f , 1.0f ,
					255 ,
					spin += 2.0f
				) ;

		}

		// 横移動の丸鋸
		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == 51 )
		{
			static float spin = 0.0f ;
			static float move = 0.0f ;

			for ( int b = 10 ; b < 30 ; ++b )
			{
				/*/
				/*	・使ってない丸鋸を選択する
				/*/
				if ( Sprite::GetInstance()->getUseFlg( b ) )
				{
				} else {
					useBmpNo = b ;
				}
			}
			move++ ;
			Sprite::GetInstance()->setBmpData(
					useBmpNo ,
					4 ,
					( float )( ((i % renderMap_w_) * CHIP_W - 32) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) + sinWave(move , 128 , 360) ) ,
					( float )( ((i / renderMap_w_) * CHIP_H - 128) + scrollY_ ) ,
					0 , 0 ,
					128 , 128 ,
					1.0f , 1.0f ,
					255 ,
					spin += 2.0f
				) ;

		}

		// 円移動の丸鋸
		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == 52 )
		{
			static float	spin = 0.0f ;
			static float	moveX = 0.0f ;
			static float	moveY = 0.0f ;

			for ( int b = 10 ; b < 30 ; ++b )
			{
				/*/
				/*	・使ってない丸鋸を選択する
				/*/
				if ( Sprite::GetInstance()->getUseFlg( b ) )
				{
				} else {
					useBmpNo = b ;
				}
			}
			moveX++ ;
			moveY++ ;
			Sprite::GetInstance()->setBmpData(
					useBmpNo ,
					4 ,
					( float )( ((i % renderMap_w_) * CHIP_W - 32) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) + sinWave( moveX , 128 , 128 ) ) ,
					( float )( ((i / renderMap_w_) * CHIP_H - 128) + scrollY_ + cosWave( moveY , 128 , 128 ) ) ,
					0 , 0 ,
					128 , 128 ,
					1.0f , 1.0f ,
					255 ,
					spin += 2.0f
				) ;

		}

		// 円移動の丸鋸
		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == 53 )
		{
			static float	spin = 0.0f ;
			static float	moveX = 0.0f ;
			static float	moveY = 0.0f ;
			static int		sinX = 0 ;
			static int		cosY = 0 ;

			printf( "x = %d y = %d \n" , sinX , cosY ) ;

/*
			if ( KeyManager::GetInstance()->getKeyState( VK_UP ) )
				sinX++ ;

			if ( KeyManager::GetInstance()->getKeyState( VK_DOWN ) )
				sinX-- ;

			if ( KeyManager::GetInstance()->getKeyState( VK_LEFT ) )
				cosY++ ;

			if ( KeyManager::GetInstance()->getKeyState( VK_RIGHT ) )
				cosY-- ;
*/

			for ( int b = 10 ; b < 30 ; ++b )
			{
				/*/
				/*	・使ってない丸鋸を選択する
				/*/
				if ( Sprite::GetInstance()->getUseFlg( b ) )
				{
				} else {
					useBmpNo = b ;
				}
			}
			moveX += 0.2f ;
			moveY += 0.2f ;
			Sprite::GetInstance()->setBmpData(
					useBmpNo ,
					4 ,
					( float )( ((i % renderMap_w_) * CHIP_W - 32) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) + sinWave( moveX , 200 , sinX ) ) ,
					( float )( ((i / renderMap_w_) * CHIP_H - 128) + scrollY_ + sinWave( moveY , 100 , cosY ) ) ,
					0 , 0 ,
					128 , 128 ,
					1.0f , 1.0f ,
					255 ,
					spin += 2.0f
				) ;

		}


	}

}



