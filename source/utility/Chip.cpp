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
	MasterData::ReLoad( ) ;		// Chipデータの読み込み

}

/*/
/*	終了化
/*/
void Chip::Finalize( )
{
	scrollX_ = 0 ;
	scrollY_ = 0 ;

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

	// BMPのハンドルをセット
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
int Chip::setBmpUV( int arg_bmpNo , float arg_u , float arg_v )
{
	bmpCBGTable_[ arg_bmpNo ]._u = arg_u ;
	bmpCBGTable_[ arg_bmpNo ]._v = arg_v ;

	return( true ) ;
}

/*/
/*	幅、高さのセット
/*/
int Chip::setBmpWH( int arg_bmpNo , float arg_w , float arg_h )
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
		float arg_u , float arg_v ,
		float arg_w , float arg_h ,
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

	if ( scrollX_ >= RenderScale )
	{
		scrollX_ = RenderScale ;
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
	for ( auto it = MasterData::Data.begin() ; it != MasterData::Data.end() ; ++it )
	{
		for ( int i = 0 - (scrollX_ / map_w_) ; i < renderMap_w_ * renderMap_h_ - (scrollX_ / map_w_) ; ++i )
		{
			/*/
			/*	チップデータ
			/*/
			if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == it->getData()._mapNo )
			{
				setChipData(
						i ,
						0 ,
						i % map_w_ , i / map_h_ ,
						( float )((i % renderMap_w_) * CHIP_W) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) - RenderScale ,
						( float )((i / renderMap_w_) * CHIP_H - 128) + scrollY_ + it->getData()._off[ 0 ]  ,
						it->getData()._upos ,
						it->getData()._vpos ,
						it->getData()._width ,
						it->getData()._height ,
						1.0f , 1.0f
					) ;
			}
		}

	}

	printf( "	%d , %d \n" , scrollX_ , -(scrollX_ / 25) ) ;
	for ( int i = 0 - (scrollX_ / map_w_) ; i < renderMap_w_ * renderMap_h_ - (scrollX_ / map_w_) ; ++i )
	{
		/*/
		/*	チップデータ
		/*/
		// 四角い床
/*		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] <= 11 )
		{
			setChipData(
					i ,
					0 ,
					i % map_w_ , i / map_h_ ,
					( float )((i % renderMap_w_) * CHIP_W) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) - RenderScale ,
					( float )((i / renderMap_w_) * CHIP_H - 128) + scrollY_ ,
					(m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] * CHIP_W) ,
					0 ,
					64 , 64 ,
					1.0f , 1.0f
				) ;
		}
		// 大きい坂はいる前の特殊な四角い床 左
		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == 90 )
		{
			setChipData(
					i ,
					0 ,
					i % map_w_ , i / map_h_ ,
					( float )((i % renderMap_w_) * CHIP_W) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) - RenderScale ,
					( float )((i / renderMap_w_) * CHIP_H - 128) + scrollY_ ,
					(2 * CHIP_W) ,
					0 ,
					64 , 64 ,
					1.0f , 1.0f
				) ;
		}
		// 大きい坂はいる前の特殊な四角い床 右
		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == 91 )
		{
			setChipData(
					i ,
					0 ,
					i % map_w_ , i / map_h_ ,
					( float )((i % renderMap_w_) * CHIP_W) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) - RenderScale ,
					( float )((i / renderMap_w_) * CHIP_H - 128) + scrollY_ ,
					(2 * CHIP_W) ,
					0 ,
					64 , 64 ,
					1.0f , 1.0f
				) ;
		}
		// 大きい坂 周辺の何もしないブロック
		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == 92 )
		{
			setChipData(
					i ,
					0 ,
					i % map_w_ , i / map_h_ ,
					( float )((i % renderMap_w_) * CHIP_W) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) - RenderScale ,
					( float )((i / renderMap_w_) * CHIP_H - 128) + scrollY_ ,
					(2 * CHIP_W) ,
					0 ,
					64 , 64 ,
					1.0f , 1.0f
				) ;
		}

		// 坂
		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == 12 )
		{
			setChipData(
					i ,
					0 ,
					i % map_w_ , i / map_h_ ,
					( float )((i % renderMap_w_) * CHIP_W) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) - RenderScale ,
					( float )((i / renderMap_w_) * CHIP_H - 128) + scrollY_ - 64 ,
					((m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] - 12) * CHIP_W) ,
					64 ,
					256 , 128 ,
					1.0f , 1.0f
				) ;

		}

		// 坂
		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == 13 )
		{
			setChipData(
					i ,
					0 ,
					i % map_w_ , i / map_h_ ,
					( float )((i % renderMap_w_) * CHIP_W) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) - RenderScale ,
					( float )((i / renderMap_w_) * CHIP_H - 128) + scrollY_ - 64 ,
					((m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] - 9) * CHIP_W) ,
					64 ,
					256 , 128 ,
					1.0f , 1.0f
				) ;

		}

		// 大きい坂
		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == 14 )
		{
			setChipData(
					i ,
					0 ,
					i % map_w_ , i / map_h_ ,
					( float )((i % renderMap_w_) * CHIP_W) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) - RenderScale ,
					( float )((i / renderMap_w_) * CHIP_H - 128) + scrollY_ - 192 ,
					((m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] - 14) * CHIP_W) ,
					64 + 128 ,
					256 , 256 ,

					1.0f , 1.0f
				) ;

		}

		// 大きい坂
		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == 15 )
		{
			setChipData(
					i ,
					0 ,
					i % map_w_ , i / map_h_ ,
					( float )((i % renderMap_w_) * CHIP_W) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) - RenderScale ,
					( float )((i / renderMap_w_) * CHIP_H - 128) + scrollY_ - 192 ,
					((m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] - 11) * CHIP_W) ,
					64 + 128 ,
					256 , 256 ,
					1.0f , 1.0f
				) ;

		}

		// 大きい坂
		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == 16 )
		{
			setChipData(
					i ,
					0 ,
					i % map_w_ , i / map_h_ ,
					( float )((i % renderMap_w_) * CHIP_W) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) - RenderScale ,
					( float )((i / renderMap_w_) * CHIP_H - 128) + scrollY_ - 192 ,
					((m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] - 8) * CHIP_W) ,
					64 + 128 ,
					256 , 256 ,

					1.0f , 1.0f
				) ;

		}

		// 大きい坂
		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == 17 )
		{
			setChipData(
					i ,
					0 ,
					i % map_w_ , i / map_h_ ,
					( float )((i % renderMap_w_) * CHIP_W) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) - RenderScale ,
					( float )((i / renderMap_w_) * CHIP_H - 128) + scrollY_ - 192 ,
					((m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] - 5) * CHIP_W) ,
					64 + 128 ,
					256 , 256 ,
					1.0f , 1.0f
				) ;

		}

		if ( (20 <= m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ])
			&& (m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] <= 25) )
		{
			setChipData(
					i ,
					0 ,
					i % map_w_ , i / map_h_ ,
					( float )((i % renderMap_w_) * CHIP_W) + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) - RenderScale ,
					( float )((i / renderMap_w_) * CHIP_H - 128) + scrollY_ ,
					((m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] - 20) * CHIP_W) ,
					7 * CHIP_H ,
					64 , 64 ,
					1.0f , 1.0f
				) ;

		}

		// 黒くも
		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == 26 )
		{
			setChipData(
					i ,
					0 ,
					i % map_w_ , i / map_h_ ,
					( float )( (i % renderMap_w_) * CHIP_W + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) - RenderScale ) ,
					( float )( (i / renderMap_w_) * CHIP_H - 128 + scrollY_ ) ,
					((m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] - 20) * CHIP_W) ,
					7 * CHIP_H ,
					64 , 64 ,
					1.0f ,
					1.0f
				) ;

		}

		// 針
		if ( m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] == 27 )
		{
			setChipData(
					i ,
					0 ,
					i % map_w_ , i / map_h_ ,
					( float )( (i % renderMap_w_) * CHIP_W + scrollX_ - (scrollX_ / CHIP_W * CHIP_W) - RenderScale ) ,
					( float )( (i / renderMap_w_) * CHIP_H - 128 + scrollY_ ) ,
					((m_chipTable_[ CHIP_X * (i / renderMap_w_) - (scrollX_ / CHIP_W) + (i % renderMap_w_) ] - 20) * CHIP_W) ,
					7 * CHIP_H ,
					64 , 64 ,
					1.0f ,
					1.0f
				) ;

		}
*/
	}

}



