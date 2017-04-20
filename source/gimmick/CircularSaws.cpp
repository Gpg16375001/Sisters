/*
________________________________________________________________________________________________________________

	FILE : CircularSaws.cpp

	________/ Explanation of file /___________________________________________________________

		Gimmick クラスの CircularSaws 実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include "Renderer.h"
#include "Gimmick.h"
#include "Chip.h"
#include "Sprite.h"
#include "KeyManager.h"

/*/r
/*	--+ ギミックのデータをセット +-----
/*/

/*/
/*	まるのこのデータをセット
/*/
int Gimmick::setCircularSaws( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int arg_mode )
{
	GimmickData_[ GimmickNo_ ]._Gimmick	= GIMMICK_NAME_CIRCULARSAWS ;
	GimmickData_[ GimmickNo_ ]._bmpNo	= arg_bmpNo ;
	GimmickData_[ GimmickNo_ ]._x		= arg_x ;
	GimmickData_[ GimmickNo_ ]._y		= arg_y ;
	GimmickData_[ GimmickNo_ ]._delay	= arg_delay ;
	GimmickData_[ GimmickNo_ ]._mode	= arg_mode ;
	GimmickData_[ GimmickNo_ ]._off[ 2 ]= arg_spd ;
	GimmickNo_++ ;

	return( true ) ;
}


/*/
/*	CircularSaws Update
/*/
void Gimmick::CircularSaws( )
{
	for ( int g = 0 ; g < MAX_GIMMICK_NO ; ++g )
	{
		/*/
		/*	___/ まるのこ /___________________
		/*/
		if ( GimmickData_[ g ]._Gimmick == GIMMICK_NAME_CIRCULARSAWS )
		{
			/*/
			/*	まるのこ：静止
			/*/
//				printf( "GIMMICK_NAME_CIRCULARSAWS\n" ) ;
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_STAY )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//						printf( "GIMMICK_MODE_STAY\n" ) ;
					GimmickData_[ g ]._off[ 1 ]++ ;
					Sprite::GetInstance()->setBmpData(
							GimmickData_[ g ]._bmpNo ,
							0 ,
							GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
							GimmickData_[ g ]._y + Chip::GetInstance()->getScrollY( ) ,
							0 , 0 ,
							128 , 128 ,
							1.0f , 1.0f ,
							255 ,
							GimmickData_[ g ]._off[ 1 ]
						) ;
					GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
					GimmickData_[ g ]._h = GimmickData_[ g ]._y + 128 ;

				} else {
					GimmickData_[ g ]._delay-- ;
					if ( GimmickData_[ g ]._delay <= 0 )
					{
						GimmickData_[ g ]._useFlg = true ;
					}
				}

			}

			/*/
			/*	まるのこ：上下
			/*/
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_UPDOWN )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//						printf( "GIMMICK_MODE_UPDOWN\n" ) ;

					GimmickData_[ g ]._off[ 0 ]++ ;
					GimmickData_[ g ]._off[ 1 ]++ ;
					Sprite::GetInstance()->setBmpData(
							GimmickData_[ g ]._bmpNo ,
							0 ,
							GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
							GimmickData_[ g ]._y + Chip::GetInstance()->getScrollY( ) + Chip::GetInstance()->sinWave( GimmickData_[ g ]._off[ 0 ] , 128 ) ,
							0 , 0 ,
							128 , 128 ,
							1.0f , 1.0f ,
							255 ,
							GimmickData_[ g ]._off[ 1 ]
						) ;
					GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
					GimmickData_[ g ]._h = GimmickData_[ g ]._y + 128 ;

				} else {
					GimmickData_[ g ]._delay-- ;
					if ( GimmickData_[ g ]._delay <= 0 )
					{
						GimmickData_[ g ]._useFlg = true ;
					}
				}

			}

			/*/
			/*	まるのこ：左右
			/*/
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_LEFTRIGHT )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//						printf( "GIMMICK_MODE_LEFTRIGHT\n" ) ;

					GimmickData_[ g ]._off[ 0 ]++ ;
					GimmickData_[ g ]._off[ 1 ]++ ;
					Sprite::GetInstance()->setBmpData(
							GimmickData_[ g ]._bmpNo ,
							0 ,
							GimmickData_[ g ]._x + Chip::GetInstance()->cosWave( GimmickData_[ g ]._off[ 0 ] , 128 ) + Chip::GetInstance()->getScrollX( ) ,
							GimmickData_[ g ]._y + Chip::GetInstance()->getScrollY( ) ,
							0 , 0 ,
							128 , 128 ,
							1.0f , 1.0f ,
							255 ,
							GimmickData_[ g ]._off[ 1 ]
						) ;
					GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
					GimmickData_[ g ]._h = GimmickData_[ g ]._y + 128 ;

				} else {
					GimmickData_[ g ]._delay-- ;
					if ( GimmickData_[ g ]._delay <= 0 )
					{
						GimmickData_[ g ]._useFlg = true ;
					}
				}

			}

			/*/
			/*	まるのこ：円
			/*/
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_CYCLE )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//						printf( "GIMMICK_MODE_CYCLE\n" ) ;

					GimmickData_[ g ]._off[ 0 ]++ ;
					GimmickData_[ g ]._off[ 1 ]++ ;
					Sprite::GetInstance()->setBmpData(
							GimmickData_[ g ]._bmpNo ,
							0 ,
							GimmickData_[ g ]._x + Chip::GetInstance()->cosWave( GimmickData_[ g ]._off[ 0 ] , 128 ) + Chip::GetInstance()->getScrollX( ) ,
							GimmickData_[ g ]._y + Chip::GetInstance()->sinWave( GimmickData_[ g ]._off[ 0 ] , 128 ) + Chip::GetInstance()->getScrollY( ) ,
							0 , 0 ,
							128 , 128 ,
							1.0f , 1.0f ,
							255 ,
							GimmickData_[ g ]._off[ 1 ]
						) ;
					GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
					GimmickData_[ g ]._h = GimmickData_[ g ]._y + 128 ;

				} else {
					GimmickData_[ g ]._delay-- ;
					if ( GimmickData_[ g ]._delay <= 0 )
					{
						GimmickData_[ g ]._useFlg = true ;
					}
				}

			}

			/*/
			/*	まるのこ：特殊
			/*/
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_WAVE )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//						printf( "Gimmick_MODE_WAVE\n" ) ;
					switch ( (int)GimmickData_[ g ]._off[ 2 ] )
					{
						case 1 :
							moveSaws01( g ) ;
							break ;

						case 2 :
							moveSaws02( g ) ;
							break ;

						case 3 :
							moveSaws03( g ) ;
							break ;

						case 4 :
							moveSaws04( g ) ;
							break ;

					}

				} else {
					GimmickData_[ g ]._delay-- ;
					if ( GimmickData_[ g ]._delay <= 0 )
					{
						GimmickData_[ g ]._useFlg = true ;
					}
				}
			}

		}
	}

}

/*/
/*	まるのこ：動き1
/*/
void Gimmick::moveSaws01( int g )
{
	switch ( (int)GimmickData_[ g ]._off[ 3 ] )
	{
		case 0 :
			GimmickData_[ g ]._off[ 7 ]++ ;
			Sprite::GetInstance()->setBmpData(
					GimmickData_[ g ]._bmpNo ,
					0 ,
					GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
					GimmickData_[ g ]._y + Chip::GetInstance()->getScrollY( ) ,
					0 , 0 ,
					128 , 128 ,
					1.0f , 1.0f ,
					255 ,
					GimmickData_[ g ]._off[ 7 ]
				) ;
			GimmickData_[ g ]._off[ 3 ]++ ;
			break ;

		case 1 :
			GimmickData_[ g ]._off[ 0 ] += 0.8f ;
			GimmickData_[ g ]._off[ 1 ] += 0.8f ;
			GimmickData_[ g ]._off[ 7 ]++ ;
			Sprite::GetInstance()->setBmpData(
					GimmickData_[ g ]._bmpNo ,
					0 ,
					GimmickData_[ g ]._x - Chip::GetInstance()->cosWave(GimmickData_[ g ]._off[ 0 ] , 128) + 128 + Chip::GetInstance()->getScrollX( ) ,
					GimmickData_[ g ]._y + Chip::GetInstance()->sinWave(GimmickData_[ g ]._off[ 1 ] , 320) + Chip::GetInstance()->getScrollY( ) ,
					0 , 0 ,
					128 , 128 ,
					1.0f , 1.0f ,
					255 ,
					GimmickData_[ g ]._off[ 7 ]
				) ;
			GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
			GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

			if ( Chip::GetInstance()->sinWave(GimmickData_[ g ]._off[ 1 ] , 320) <= -1 )
			{
				GimmickData_[ g ]._off[ 3 ]++ ;
			}
			break ;

		case 2 :
			GimmickData_[ g ]._off[ 0 ] += 0.8f ;
			GimmickData_[ g ]._off[ 1 ] += 0.8f ;
			GimmickData_[ g ]._off[ 7 ]++ ;
			Sprite::GetInstance()->setBmpData(
					GimmickData_[ g ]._bmpNo ,
					0 ,
					GimmickData_[ g ]._x + Chip::GetInstance()->cosWave(GimmickData_[ g ]._off[ 0 ] , 128) + 128 + 256 + Chip::GetInstance()->getScrollX( ) ,
					GimmickData_[ g ]._y + Chip::GetInstance()->sinWave(GimmickData_[ g ]._off[ 1 ] , 320) + Chip::GetInstance()->getScrollY( ) ,
					0 , 0 ,
					128 , 128 ,
					1.0f , 1.0f ,
					255 ,
					GimmickData_[ g ]._off[ 7 ]
				) ;
			GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
			GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

			if ( Chip::GetInstance()->sinWave(GimmickData_[ g ]._off[ 1 ] , 320) >= +1 )
			{
				GimmickData_[ g ]._off[ 3 ]++ ;
			}
			break ;

		case 3 :
			GimmickData_[ g ]._off[ 6 ]++ ;		// stay count
			GimmickData_[ g ]._off[ 7 ]++ ;
			Sprite::GetInstance()->setBmpData(
					GimmickData_[ g ]._bmpNo ,
					0 ,
					GimmickData_[ g ]._x + 256 + 256 + Chip::GetInstance()->getScrollX( ) ,
					GimmickData_[ g ]._y + GimmickData_[ g ]._off[ 1 ] - 352 + Chip::GetInstance()->getScrollY( ) ,
					0 , 0 ,
					128 , 128 ,
					1.0f , 1.0f ,
					255 ,
					GimmickData_[ g ]._off[ 7 ]
				) ;
			GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
			GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

			if ( GimmickData_[ g ]._off[ 6 ] >= 100 )
			{
				GimmickData_[ g ]._off[ 6 ] = 0.0f ;
				GimmickData_[ g ]._off[ 3 ]++ ;
			}
			break ;

		case 4 :
			GimmickData_[ g ]._off[ 0 ] -= 0.8f ;
			GimmickData_[ g ]._off[ 1 ] -= 0.8f ;
			GimmickData_[ g ]._off[ 7 ]++ ;
			Sprite::GetInstance()->setBmpData(
					GimmickData_[ g ]._bmpNo ,
					0 ,
					GimmickData_[ g ]._x + Chip::GetInstance()->cosWave(GimmickData_[ g ]._off[ 0 ] , 128) + 128 + 256 + Chip::GetInstance()->getScrollX( ) ,
					GimmickData_[ g ]._y + Chip::GetInstance()->sinWave(GimmickData_[ g ]._off[ 1 ] , 320) + Chip::GetInstance()->getScrollY( ) ,
					0 , 0 ,
					128 , 128 ,
					1.0f , 1.0f ,
					255 ,
					GimmickData_[ g ]._off[ 7 ]
				) ;
			GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
			GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

			if ( Chip::GetInstance()->sinWave(GimmickData_[ g ]._off[ 1 ] , 320) >= +1 )
			{
				GimmickData_[ g ]._off[ 3 ]++ ;
			}
			break ;

		case 5 :
			GimmickData_[ g ]._off[ 0 ] -= 0.8f ;
			GimmickData_[ g ]._off[ 1 ] -= 0.8f ;
			GimmickData_[ g ]._off[ 7 ]++ ;
			Sprite::GetInstance()->setBmpData(
					GimmickData_[ g ]._bmpNo ,
					0 ,
					GimmickData_[ g ]._x - Chip::GetInstance()->cosWave(GimmickData_[ g ]._off[ 0 ] , 128) + 128 + Chip::GetInstance()->getScrollX( ) ,
					GimmickData_[ g ]._y + Chip::GetInstance()->sinWave(GimmickData_[ g ]._off[ 1 ] , 320) + Chip::GetInstance()->getScrollY( ) ,
					0 , 0 ,
					128 , 128 ,
					1.0f , 1.0f ,
					255 ,
					GimmickData_[ g ]._off[ 7 ]
				) ;
			GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
			GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

			if ( Chip::GetInstance()->sinWave(GimmickData_[ g ]._off[ 1 ] , 320) <= 0 )
			{
				GimmickData_[ g ]._off[ 0 ] = 0.0f ;
				GimmickData_[ g ]._off[ 1 ] = 0.0f ;
				GimmickData_[ g ]._off[ 3 ]++ ;
			}
			break ;

		case 6 :
			GimmickData_[ g ]._off[ 6 ]++ ;		// stay count
			GimmickData_[ g ]._off[ 7 ]++ ;
			Sprite::GetInstance()->setBmpData(
					GimmickData_[ g ]._bmpNo ,
					0 ,
					GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
					GimmickData_[ g ]._y + GimmickData_[ g ]._off[ 1 ] + Chip::GetInstance()->getScrollY( ) ,
					0 , 0 ,
					128 , 128 ,
					1.0f , 1.0f ,
					255 ,
					GimmickData_[ g ]._off[ 7 ]
				) ;
			GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
			GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

			if ( GimmickData_[ g ]._off[ 6 ] >= 100 )
			{
				GimmickData_[ g ]._off[ 6 ] = 0.0f ;
				GimmickData_[ g ]._off[ 3 ] = 0.0f ;
			}
			break ;

	}

}

/*/
/*	まるのこ：動き2
/*/
void Gimmick::moveSaws02( int g )
{
	switch ( (int)GimmickData_[ g ]._off[ 3 ] )
	{
		case 0 :
			Sprite::GetInstance()->setBmpData(
					GimmickData_[ g ]._bmpNo ,
					0 ,
					GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
					GimmickData_[ g ]._y + Chip::GetInstance()->getScrollY( ) ,
					0 , 0 ,
					256 , 64 ,
					0.5f , 0.5f ,
					255 ,
					0
				) ;
			break ;

		case 1 :
			GimmickData_[ g ]._off[ 0 ] += 0.6f ;
			GimmickData_[ g ]._off[ 1 ] += 0.6f ;
			Sprite::GetInstance()->setBmpData(
					GimmickData_[ g ]._bmpNo ,
					0 ,
					GimmickData_[ g ]._x + GimmickData_[ g ]._off[ 0 ] + Chip::GetInstance()->getScrollX( ) ,
					GimmickData_[ g ]._y + Chip::GetInstance()->getScrollY( ) ,
					0 , 0 ,
					256 , 64 ,
					0.5f , 0.5f ,
					255 ,
					0
				) ;
			GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
			GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

			if ( GimmickData_[ g ]._off[ 0 ] >= 120 )
			{
				GimmickData_[ g ]._off[ 3 ]++ ;
			}
			break ;

		case 2 :
			GimmickData_[ g ]._off[ 0 ] += 0.6f ;
			GimmickData_[ g ]._off[ 1 ] += 0.6f ;
			Sprite::GetInstance()->setBmpData(
					GimmickData_[ g ]._bmpNo ,
					0 ,
					GimmickData_[ g ]._x + GimmickData_[ g ]._off[ 0 ] + Chip::GetInstance()->getScrollX( ) ,
					GimmickData_[ g ]._y - GimmickData_[ g ]._off[ 1 ] + 120 + Chip::GetInstance()->getScrollY( ) ,
					0 , 0 ,
					256 , 64 ,
					0.5f , 0.5f ,
					255 ,
					0
				) ;
			GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
			GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

			if ( GimmickData_[ g ]._off[ 0 ] >= 240 )
			{
				GimmickData_[ g ]._off[ 3 ]++ ;
			}
			break ;

		case 3 :
			GimmickData_[ g ]._off[ 1 ] -= 1.2f ;
			Sprite::GetInstance()->setBmpData(
					GimmickData_[ g ]._bmpNo ,
					0 ,
					GimmickData_[ g ]._x + GimmickData_[ g ]._off[ 0 ] + Chip::GetInstance()->getScrollX( ) ,
					GimmickData_[ g ]._y - GimmickData_[ g ]._off[ 1 ] + 120 + Chip::GetInstance()->getScrollY( ) ,
					0 , 0 ,
					256 , 64 ,
					0.5f , 0.5f ,
					255 ,
					0
				) ;
			GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
			GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

			if ( GimmickData_[ g ]._off[ 1 ] <= -400 )
			{
				GimmickData_[ g ]._off[ 3 ] = 0 ;
				GimmickData_[ g ]._off[ 0 ] = 0 ;
				GimmickData_[ g ]._off[ 1 ] = 0 ;
			}
			break ;

	}

}

/*/
/*	まるのこ：動き3
/*/
void Gimmick::moveSaws03( int g )
{
	switch ( (int)GimmickData_[ g ]._off[ 3 ] )
	{
		case 0 :
			Sprite::GetInstance()->setBmpData(
					GimmickData_[ g ]._bmpNo ,
					0 ,
					GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
					GimmickData_[ g ]._y + Chip::GetInstance()->getScrollY( ) ,
					0 , 0 ,
					256 , 64 ,
					0.5f , 0.5f ,
					255 ,
					0
				) ;
			break ;

		case 1 :
			break ;

	}

}

/*/
/*	まるのこ：動き4
/*/
void Gimmick::moveSaws04( int g )
{
	switch ( (int)GimmickData_[ g ]._off[ 3 ] )
	{
		case 0 :
			Sprite::GetInstance()->setBmpData(
					GimmickData_[ g ]._bmpNo ,
					0 ,
					GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
					GimmickData_[ g ]._y + Chip::GetInstance()->getScrollY( ) ,
					0 , 0 ,
					256 , 64 ,
					0.5f , 0.5f ,
					255 ,
					0
				) ;
			break ;

		case 1 :
			break ;

	}

}




