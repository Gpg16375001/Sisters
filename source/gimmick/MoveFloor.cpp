/*
________________________________________________________________________________________________________________

	FILE : MoveFloor.cpp

	________/ Explanation of file /___________________________________________________________

		Gimmick ÉNÉâÉXÇÃ MoveFloor é¿ëïïî

ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP
*/
#include "Renderer.h"
#include "Gimmick.h"
#include "Chip.h"
#include "Sprite.h"
#include "KeyManager.h"


/*/r
/*	--+ MoveFloor ÇÃÉfÅ[É^ÇÉZÉbÉg +-----
/*/

/*/
/*	ìÆÇ≠è∞ÇÃÉfÅ[É^ÇÉZÉbÉg
/*/
int Gimmick::setMoveBlocks( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int arg_mode )
{
	GimmickData_[ GimmickNo_ ]._Gimmick	= GIMMICK_NAME_MOVEFLOOR ;
	GimmickData_[ GimmickNo_ ]._bmpNo	= arg_bmpNo ;
	GimmickData_[ GimmickNo_ ]._x		= arg_x ;
	GimmickData_[ GimmickNo_ ]._y		= arg_y ;
	GimmickData_[ GimmickNo_ ]._spd		= arg_spd ;
	GimmickData_[ GimmickNo_ ]._delay	= arg_delay ;
	GimmickData_[ GimmickNo_ ]._mode	= arg_mode ;
	GimmickData_[ GimmickNo_ ]._off[ 2 ]= arg_spd ;
	GimmickNo_++ ;

	return( true ) ;
}

/*/
/*	MoveFloor Update
/*/
void Gimmick::MoveFloor( )
{
	for ( int g = 0 ; g < MAX_GIMMICK_NO ; ++g )
	{
		/*/
		/*	___/ ìÆÇ≠è∞ /___________________
		/*/
		if ( GimmickData_[ g ]._Gimmick == GIMMICK_NAME_MOVEFLOOR )
		{
			/*/
			/*	ìÆÇ≠è∞ÅFê√é~
			/*/
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_STAY )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//						printf( "Gimmick_MODE_STAY\n" ) ;
					Sprite::GetInstance()->setBmpData(
							GimmickData_[ g ]._bmpNo ,
							0 ,
							GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
							GimmickData_[ g ]._y ,
							0 , 0 ,
							256 , 64 ,
							0.5f , 0.5f ,
							255 ,
							0
						) ;
					GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
					GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

				} else {
					GimmickData_[ g ]._delay-- ;
					if ( GimmickData_[ g ]._delay <= 0 )
					{
						GimmickData_[ g ]._useFlg = true ;
					}
				}

			}

			/*/
			/*	ìÆÇ≠è∞ÅFè„â∫
			/*/
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_UPDOWN )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//						printf( "Gimmick_MODE_UPDOWN\n" ) ;

					GimmickData_[ g ]._off[ 0 ]++ ;
					Sprite::GetInstance()->setBmpData(
							GimmickData_[ g ]._bmpNo ,
							0 ,
							GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
							GimmickData_[ g ]._y + Chip::GetInstance()->sinWave( GimmickData_[ g ]._off[ 0 ] , 128 ) ,
							0 , 0 ,
							256 , 64 ,
							0.5f , 0.5f ,
							255 ,
							0
						) ;
					GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
					GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

				} else {
					GimmickData_[ g ]._delay-- ;
					if ( GimmickData_[ g ]._delay <= 0 )
					{
						GimmickData_[ g ]._useFlg = true ;
					}
				}

			}

			/*/
			/*	ìÆÇ≠è∞ÅFç∂âE
			/*/
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_LEFTRIGHT )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//						printf( "Gimmick_MODE_LEFTRIGHT\n" ) ;

					GimmickData_[ g ]._off[ 0 ]++ ;
					Sprite::GetInstance()->setBmpData(
							GimmickData_[ g ]._bmpNo ,
							0 ,
							GimmickData_[ g ]._x + Chip::GetInstance()->cosWave( GimmickData_[ g ]._off[ 0 ] , 128 ) + Chip::GetInstance()->getScrollX( ) ,
							GimmickData_[ g ]._y ,
							0 , 0 ,
							256 , 64 ,
							0.5f , 0.5f ,
							255 ,
							0
						) ;
					GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
					GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

				} else {
					GimmickData_[ g ]._delay-- ;
					if ( GimmickData_[ g ]._delay <= 0 )
					{
						GimmickData_[ g ]._useFlg = true ;
					}
				}

			}

			/*/
			/*	ìÆÇ≠è∞ÅFâ~
			/*/
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_CYCLE )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//						printf( "Gimmick_MODE_CYCLE\n" ) ;

					GimmickData_[ g ]._off[ 0 ]++ ;
					Sprite::GetInstance()->setBmpData(
							GimmickData_[ g ]._bmpNo ,
							0 ,
							GimmickData_[ g ]._x + Chip::GetInstance()->cosWave( GimmickData_[ g ]._off[ 0 ] , 128 ) + Chip::GetInstance()->getScrollX( ) ,
							GimmickData_[ g ]._y + Chip::GetInstance()->sinWave( GimmickData_[ g ]._off[ 0 ] , 128 ) ,
							0 , 0 ,
							256 , 64 ,
							0.5f , 0.5f ,
							255 ,
							0
						) ;
					GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
					GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

				} else {
					GimmickData_[ g ]._delay-- ;
					if ( GimmickData_[ g ]._delay <= 0 )
					{
						GimmickData_[ g ]._useFlg = true ;
					}
				}

			}

			/*/
			/*	ìÆÇ≠è∞ÅFóéÇø
			/*/
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_DROP )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//						printf( "Gimmick_MODE_DROP\n" ) ;

					GimmickData_[ g ]._off[ 0 ] += (GimmickData_[ g ]._spd / 60) ;
					Sprite::GetInstance()->setBmpData(
							GimmickData_[ g ]._bmpNo ,
							0 ,
							GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
							GimmickData_[ g ]._y + GimmickData_[ g ]._off[ 0 ] ,
							0 , 0 ,
							256 , 64 ,
							0.5f , 0.5f ,
							255 ,
							0
						) ;
					GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
					GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

					if ( GimmickData_[ g ]._off[ 0 ] >= 700 )
					{
						GimmickData_[ g ]._off[ 0 ] = -100 ;
					}

				} else {
					GimmickData_[ g ]._delay-- ;
					if ( GimmickData_[ g ]._delay <= 0 )
					{
						GimmickData_[ g ]._useFlg = true ;
					}
				}

			}

			/*/
			/*	ìÆÇ≠è∞ÅFè∏ÇË
			/*/
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_UPPER )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//						printf( "Gimmick_MODE_UPPER\n" ) ;

					GimmickData_[ g ]._off[ 0 ] -= (GimmickData_[ g ]._spd / 60) ;
					Sprite::GetInstance()->setBmpData(
							GimmickData_[ g ]._bmpNo ,
							0 ,
							GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
							GimmickData_[ g ]._y + GimmickData_[ g ]._off[ 0 ] ,
							0 , 0 ,
							256 , 64 ,
							0.5f , 0.5f ,
							255 ,
							0
						) ;
					GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
					GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

					if ( GimmickData_[ g ]._off[ 0 ] <= -100 )
					{
						GimmickData_[ g ]._off[ 0 ] = 700 ;
					}

				} else {
					GimmickData_[ g ]._delay-- ;
					if ( GimmickData_[ g ]._delay <= 0 )
					{
						GimmickData_[ g ]._useFlg = true ;
					}
				}

			}

			/*/
			/*	ìÆÇ≠è∞ÅFì¡éÍ
			/*/
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_WAVE )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//						printf( "Gimmick_MODE_WAVE\n" ) ;
					switch ( (int)GimmickData_[ g ]._off[ 2 ] )
					{
						case 1 :
							moveFloor01( g ) ;
							break ;

						case 2 :
							moveFloor02( g ) ;
							break ;

						case 3 :
							moveFloor03( g ) ;
							break ;

						case 4 :
							moveFloor04( g ) ;
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
/*	ìÆÇ≠è∞ÅFìÆÇ´1
/*/
void Gimmick::moveFloor01( int g )
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
					256 , 64 ,
					0.5f , 0.5f ,
					255 ,
					0
				) ;
			break ;

		case 1 :
			GimmickData_[ g ]._off[ 0 ] += 0.4f ;
			GimmickData_[ g ]._off[ 1 ] += 0.4f ;
			Sprite::GetInstance()->setBmpData(
					GimmickData_[ g ]._bmpNo ,
					0 ,
					GimmickData_[ g ]._x - Chip::GetInstance()->cosWave(GimmickData_[ g ]._off[ 0 ] , 128) + 128 + Chip::GetInstance()->getScrollX( ) ,
					GimmickData_[ g ]._y + Chip::GetInstance()->sinWave(GimmickData_[ g ]._off[ 1 ] , 320) ,
					0 , 0 ,
					256 , 64 ,
					0.5f , 0.5f ,
					255 ,
					0
				) ;
			GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
			GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

			if ( Chip::GetInstance()->sinWave(GimmickData_[ g ]._off[ 1 ] , 320) <= -1 )
			{
				GimmickData_[ g ]._off[ 3 ]++ ;
			}
			break ;

		case 2 :
			GimmickData_[ g ]._off[ 0 ] += 0.4f ;
			GimmickData_[ g ]._off[ 1 ] += 0.4f ;
			Sprite::GetInstance()->setBmpData(
					GimmickData_[ g ]._bmpNo ,
					0 ,
					GimmickData_[ g ]._x + Chip::GetInstance()->cosWave(GimmickData_[ g ]._off[ 0 ] , 128) + 128 + 256 + Chip::GetInstance()->getScrollX( ) ,
					GimmickData_[ g ]._y + Chip::GetInstance()->sinWave(GimmickData_[ g ]._off[ 1 ] , 320) ,
					0 , 0 ,
					256 , 64 ,
					0.5f , 0.5f ,
					255 ,
					0
				) ;
			GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
			GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

			if ( Chip::GetInstance()->sinWave(GimmickData_[ g ]._off[ 1 ] , 320) >= +1 )
			{
				GimmickData_[ g ]._off[ 3 ]++ ;
			}
			break ;

		case 3 :
			GimmickData_[ g ]._off[ 1 ] += 2.2f ;
			Sprite::GetInstance()->setBmpData(
					GimmickData_[ g ]._bmpNo ,
					0 ,
					GimmickData_[ g ]._x + 256 + 256 + Chip::GetInstance()->getScrollX( ) ,
					GimmickData_[ g ]._y + GimmickData_[ g ]._off[ 1 ] - 352 ,
					0 , 0 ,
					256 , 64 ,
					0.5f , 0.5f ,
					255 ,
					0
				) ;
			GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
			GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

			if ( GimmickData_[ g ]._off[ 1 ] >= 900 )
			{
				GimmickData_[ g ]._off[ 3 ] = 0 ;
				GimmickData_[ g ]._off[ 0 ] = 0 ;
				GimmickData_[ g ]._off[ 1 ] = 0 ;
			}
			break ;

	}

}

/*/
/*	ìÆÇ≠è∞ÅFìÆÇ´2
/*/
void Gimmick::moveFloor02( int g )
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
					GimmickData_[ g ]._y ,
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
					GimmickData_[ g ]._y - GimmickData_[ g ]._off[ 1 ] + 120 ,
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
					GimmickData_[ g ]._y - GimmickData_[ g ]._off[ 1 ] + 120 ,
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
/*	ìÆÇ≠è∞ÅFìÆÇ´3
/*/
void Gimmick::moveFloor03( int g )
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
/*	ìÆÇ≠è∞ÅFìÆÇ´4
/*/
void Gimmick::moveFloor04( int g )
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



