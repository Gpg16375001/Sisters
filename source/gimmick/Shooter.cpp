/*
________________________________________________________________________________________________________________

	FILE : Shooter.cpp

	________/ Explanation of file /___________________________________________________________

		Gimmick クラスの Shooter 実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include "Renderer.h"
#include "Gimmick.h"
#include "Chip.h"
#include "Sprite.h"
#include "KeyManager.h"


/*/
/*	--+ Shooter ・ｽﾌデ・ｽ[・ｽ^・ｽ・ｽ・ｽZ・ｽb・ｽg +-----
/*/
int Gimmick::nullCheck( )
{
	int iRet = -1 ;

	for ( int i = 0 ; i < 500 ; ++i )
	{
		if ( BulletData_[ i ]._useFlg )
		{
		} else {
			BulletData_[ i ]._useFlg = true ;
			iRet = i ;
			break ;
		}
	}
	return( iRet ) ;
}

int Gimmick::useCheck( int arg_used )
{
	int iRet = -1 ;

	if ( BulletData_[ arg_used ]._useFlg )
	{
		iRet = BulletData_[ arg_used ]._bmpNo ;
	}

	return( iRet ) ;
}

/*/
/*	弾の初期データをセット
/*/
void Gimmick::setBulletData( )
{
	for ( int i = 0 ; i < 500 ; ++i )
	{
		BulletData_[ i ]._bmpNo		= i + 500 ;
		BulletData_[ i ]._w			= 64 ;
		BulletData_[ i ]._h			= 64 ;
	}

}

/*/
/*	Shooter のデータをセット
/*/
int Gimmick::setShooter( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int arg_mode )
{
	GimmickData_[ GimmickNo_ ]._Gimmick	= GIMMICK_NAME_SHOOTER ;
	GimmickData_[ GimmickNo_ ]._bmpNo	= arg_bmpNo ;
	GimmickData_[ GimmickNo_ ]._x		= arg_x ;
	GimmickData_[ GimmickNo_ ]._y		= arg_y ;
	GimmickData_[ GimmickNo_ ]._spd		= arg_spd ;
	GimmickData_[ GimmickNo_ ]._delay	= arg_delay ;
	GimmickData_[ GimmickNo_ ]._mode	= arg_mode ;
	GimmickData_[ GimmickNo_ ]._off[ 2 ]= arg_spd ;

	AnimationData Epod_anim[ ] = {
		{ arg_bmpNo , 96 , {64 * 0 , 0 , 64 , 64} , ANIM_MODE_NEXT } ,
		{ arg_bmpNo ,  8 , {64 * 1 , 0 , 64 , 64} , ANIM_MODE_NEXT } ,
		{ arg_bmpNo ,  8 , {64 * 3 , 0 , 64 , 64} , ANIM_MODE_NEXT } ,
		{ arg_bmpNo , 10 , {64 * 2 , 0 , 64 , 64} , ANIM_MODE_LOOP } ,
	} ;
	memcpy( &GimmickData_[ GimmickNo_ ]._gAnim_01 , Epod_anim , 4 * sizeof( AnimationData ) ) ;

	GimmickData_[ GimmickNo_ ]._gAnim.setAnimData( GimmickData_[ GimmickNo_ ]._gAnim_01 ) ;

	GimmickNo_++ ;
	return( true ) ;

}

/*/
/*	Shooter Update
/*/
void Gimmick::Shooter( )
{
	for ( int g = 0 ; g < MAX_GIMMICK_NO ; ++g )
	{
		/*/
		/*	___/ Shooter /___________________
		/*/
		if ( GimmickData_[ g ]._Gimmick == GIMMICK_NAME_SHOOTER )
		{
			/*/
			/*	Shooter：通常
			/*/
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_STAY )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//						printf( "Gimmick_MODE_STAY\n" ) ;
					// 本体
					GimmickData_[ g ]._gAnim.playAnim( ) ;
					AnimationData *nowAnim ;
					nowAnim = GimmickData_[ g ]._gAnim.getNowAnim( ) ;
					Sprite::GetInstance()->setBmpData(
							nowAnim->bmpNo ,
							0 ,
							GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
							GimmickData_[ g ]._y ,
							(float)nowAnim->cutRect.left ,
							(float)nowAnim->cutRect.top ,
							64 ,
							64 ,
							1.0f , 1.0f ,
							255 ,
							0
						) ;

					switch ( (int)GimmickData_[ g ]._off[ 2 ] )
					{
						case 1 :
							blockShot01( g ) ;
							break ;

						case 2 :
							blockShot02( g ) ;
							break ;

						case 3 :
							blockShot03( g ) ;
							break ;

						case 4 :
							blockShot04( g ) ;
							break ;

					}

				} else {
					GimmickData_[ g ]._delay-- ;
					if ( GimmickData_[ g ]._delay <= 0 )
					{
						GimmickData_[ g ]._useFlg = true ;
					}
				}

				// 弾のあたり判定　壁と
				for ( int allcnt = 0 ; allcnt < 500 ; ++allcnt )
				{
					int no = useCheck( allcnt ) ;
					if ( no != -1 )
					{
						int *chipTable = Chip::GetInstance()->getChipTable( ) ;	// あたり判定をとるためのチップデータ
						float bl = 0.0f , br = 0.0f , bt = 0.0f , bb = 0.0f ;
						float brad ;	// 弾の半径
						float x ;
						float y ;

						bl = BulletData_[ allcnt ]._x - Chip::GetInstance()->getScrollX( ) ;
						br = BulletData_[ allcnt ]._x - Chip::GetInstance()->getScrollX( ) + 45 ;
						bt = BulletData_[ allcnt ]._y ;
						bb = BulletData_[ allcnt ]._y + 45 ;

						brad = br - bl ;			// 弾の半径を求める
//						x = br - (br - bl) ;		// 弾の中心点 X軸
//						y = bb - (bb - bt) ;		// 弾の中心点 Y軸
						x = bl ;					// 弾の中心点 X軸
						y = bt ;					// 弾の中心点 Y軸

						// 判定をとる範囲　今は全体
						for( int icnt = 0 ; icnt < (CHIP_X * CHIP_Y) ; ++icnt )
						{
							// 何か情報が入っているとき
							if ( chipTable[ icnt ] != NULL )
							{
								bl = ( float )( (icnt % CHIP_X) * CHIP_W ) - RenderScale ;
								br = ( float )( (icnt % CHIP_X) * CHIP_W + CHIP_W ) - RenderScale ;
								bt = ( float )( (icnt / CHIP_X) * CHIP_H ) ;
								bb = ( float )( (icnt / CHIP_X) * CHIP_H + CHIP_H ) ;

								switch ( chipTable[ icnt ] )
								{
									// 通常ブロックの場合
									case 1 :
									case 2 :
									case 9 :
										if ( (bl <= x) && (x <= br) )
										{
											if ( (bt <= y) && (y <= bb) )
											{
												// 消滅させる
												//deleteBullet( allcnt ) ;

											}
										}
										break ;

									default :
										break ;

								}
							}

						}

					}


				}

			}

		}

	}

}

/*/
/*	Shooter：動き 1
/*/
void Gimmick::blockShot01( int g )
{
	switch ( (int)GimmickData_[ g ]._off[ 3 ] )
	{
		// 弾をセット
		case 0 :
			// 弾
			for ( int cyc = 0 ; cyc < 360 ; cyc+=60 )
			{
				int no = nullCheck( ) ;
				if ( no != -1 )
				{
					BulletData_[ no ]._x = GimmickData_[ g ]._x ;
					BulletData_[ no ]._y = GimmickData_[ g ]._y ;
					BulletData_[ no ]._off[ 0 ] = physic_.Mycos( cyc , 1 ) * 0.8f ;
					BulletData_[ no ]._off[ 1 ] = physic_.Mysin( cyc , 1 ) * 0.8f ;
				}
			}

			for ( int allcnt = 0 ; allcnt < 500 ; ++allcnt )
			{
				int no = useCheck( allcnt ) ;
				if ( no != -1 )
				{
					BulletData_[ allcnt ]._x += BulletData_[ allcnt ]._off[ 0 ] ;
					BulletData_[ allcnt ]._y += BulletData_[ allcnt ]._off[ 1 ] ;

					Sprite::GetInstance()->setBmpData(
							no ,
							0 ,
							BulletData_[ allcnt ]._x + Chip::GetInstance()->getScrollX( ) ,
							BulletData_[ allcnt ]._y ,
							0 , 0 ,
							64 , 64 ,
							1.0f , 1.0f ,
							232 ,
							0
						) ;
					BulletData_[ allcnt ]._delay++ ;	// 消えるまでの時間
					if ( BulletData_[ allcnt ]._delay >= 600 )
					{
						// 消滅させる
						BulletData_[ allcnt ]._useFlg	= false ;
						BulletData_[ allcnt ]._x		= 0.0f ;
						BulletData_[ allcnt ]._y		= 0.0f ;
						BulletData_[ allcnt ]._off[ 0 ] = 0.0f ;
						BulletData_[ allcnt ]._off[ 1 ] = 0.0f ;
						BulletData_[ allcnt ]._delay	= 0 ;
					}
				}
			}

			GimmickData_[ g ]._off[ 3 ]++ ;
			break ;

		// 弾を更新
		case 1 :
			// 弾
			for ( int allcnt = 0 ; allcnt < 500 ; ++allcnt )
			{
				int no = useCheck( allcnt ) ;
				if ( no != -1 )
				{
					BulletData_[ allcnt ]._x += BulletData_[ allcnt ]._off[ 0 ] ;
					BulletData_[ allcnt ]._y += BulletData_[ allcnt ]._off[ 1 ] ;

					Sprite::GetInstance()->setBmpData(
							no ,
							0 ,
							BulletData_[ allcnt ]._x + Chip::GetInstance()->getScrollX( ) ,
							BulletData_[ allcnt ]._y ,
							0 , 0 ,
							64 , 64 ,
							1.0f , 1.0f ,
							232 ,
							0
						) ;
					BulletData_[ allcnt ]._delay++ ;	// 消えるまでの時間
					if ( BulletData_[ allcnt ]._delay >= 600 )
					{
						// 消滅させる
						BulletData_[ allcnt ]._useFlg	= false ;
						BulletData_[ allcnt ]._x		= 0.0f ;
						BulletData_[ allcnt ]._y		= 0.0f ;
						BulletData_[ allcnt ]._off[ 0 ] = 0.0f ;
						BulletData_[ allcnt ]._off[ 1 ] = 0.0f ;
						BulletData_[ allcnt ]._delay	= 0 ;
					}
				}
			}

			GimmickData_[ g ]._off[ 4 ]++ ;
			if ( GimmickData_[ g ]._off[ 4 ] >= 200 )
			{
				GimmickData_[ g ]._off[ 4 ] = 0.0f ;
				GimmickData_[ g ]._off[ 3 ] = 0.0f ;
			}
			break ;

		case 2 :
			break ;

		case 3 :
			break ;

	}


}

/*/
/*	Shooter：動き 2
/*/
void Gimmick::blockShot02( int g )
{
	static int cc = 0 ;

	switch ( (int)GimmickData_[ g ]._off[ 3 ] )
	{
		case 0 :
			// 弾
			for ( int cyc = 0 ; cyc < 360 ; cyc+=360 )
			{
				for ( int cnt = 1 ; cnt <= 6 ; ++cnt )
				{
					int no = nullCheck( ) ;
					if ( no != -1 )
					{
						BulletData_[ no ]._x = GimmickData_[ g ]._x ;
						BulletData_[ no ]._y = GimmickData_[ g ]._y ;
						BulletData_[ no ]._off[ 0 ] = physic_.Mycos( (cyc + cc) , 1 ) * (55.0f * cnt) ;
						BulletData_[ no ]._off[ 1 ] = physic_.Mysin( (cyc + cc) , 1 ) * (55.0f * cnt) ;
						BulletData_[ no ]._x += BulletData_[ no ]._off[ 0 ] ;
						BulletData_[ no ]._y += BulletData_[ no ]._off[ 1 ] ;
					}
				}
			}
			cc++ ;

			for ( int allcnt = 0 ; allcnt < 500 ; ++allcnt )
			{
				int no = useCheck( allcnt ) ;
				if ( no != -1 )
				{
					Sprite::GetInstance()->setBmpData(
							no ,
							0 ,
							BulletData_[ allcnt ]._x + Chip::GetInstance()->getScrollX( ) ,
							BulletData_[ allcnt ]._y ,
							0 , 0 ,
							64 , 64 ,
							1.0f , 1.0f ,
							232 ,
							0
						) ;
					BulletData_[ allcnt ]._delay++ ;	// 消えるまでの時間
					if ( BulletData_[ allcnt ]._delay >= 1 )
					{
						// 消滅させる
						BulletData_[ allcnt ]._useFlg	= false ;
						BulletData_[ allcnt ]._x		= 0.0f ;
						BulletData_[ allcnt ]._y		= 0.0f ;
						BulletData_[ allcnt ]._off[ 0 ] = 0.0f ;
						BulletData_[ allcnt ]._off[ 1 ] = 0.0f ;
						BulletData_[ allcnt ]._delay	= 0 ;
					}
				}
			}

//			GimmickData_[ g ]._off[ 3 ]++ ;
			break ;

		case 1 :
			break ;

		case 2 :
			break ;

		case 3 :
			break ;

	}

}

/*/
/*	Shooter：動き 3
/*/
void Gimmick::blockShot03( int g )
{
	switch ( (int)GimmickData_[ g ]._off[ 3 ] )
	{
		case 0 :
			Sprite::GetInstance()->setBmpData(
					GimmickData_[ g ]._bmpNo ,
					0 ,
					GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
					GimmickData_[ g ]._y ,
					0 , 0 ,
					64 , 64 ,
					1.0f , 1.0f ,
					255 ,
					0
				) ;
			break ;

		case 1 :
			break ;

	}

}

/*/
/*	Shooter：動き 4
/*/
void Gimmick::blockShot04( int g )
{
	switch ( (int)GimmickData_[ g ]._off[ 3 ] )
	{
		case 0 :
			Sprite::GetInstance()->setBmpData(
					GimmickData_[ g ]._bmpNo ,
					0 ,
					GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
					GimmickData_[ g ]._y ,
					0 , 0 ,
					64 , 64 ,
					1.0f , 1.0f ,
					255 ,
					0
				) ;
			break ;

		case 1 :
			break ;

	}

}




