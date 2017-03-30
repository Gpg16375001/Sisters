/*
________________________________________________________________________________________________________________

	FILE : Rocks.cpp

	________/ Explanation of file /___________________________________________________________

		Gimmick ÉNÉâÉXÇÃ Rocks é¿ëïïî

ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP
*/
#include "Renderer.h"
#include "Gimmick.h"
#include "Chip.h"
#include "Sprite.h"
#include "KeyManager.h"

/*/r
/*	--+ ÉMÉ~ÉbÉNÇÃÉfÅ[É^ÇÉZÉbÉg +-----
/*/

/*/
/*	ä‚ÇÃÉfÅ[É^ÇÉZÉbÉg
/*/
int Gimmick::setRocks( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int arg_mode )
{
	GimmickData_[ GimmickNo_ ]._Gimmick	= GIMMICK_NAME_ROCK ;
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
/*	Rocks Update
/*/
void Gimmick::Rocks( )
{
	for ( int g = 0 ; g < MAX_GIMMICK_NO ; ++g )
	{
		/*/
		/*	___/ Ç¢ÇÌ /___________________
		/*/
		if ( GimmickData_[ g ]._Gimmick == GIMMICK_NAME_ROCK )
		{
			/*/
			/*	ä‚ÅFê√é~
			/*/
//				printf( "GIMMICK_NAME_Rocks\n" ) ;
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_STAY )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//					printf( "GIMMICK_MODE_STAY\n" ) ;
					float fCheck = footCheck( g ) ;
					if ( fCheck != -1 )
					{
						GimmickData_[ g ]._off[ 1 ] = 0 ;
						GimmickData_[ g ]._y = fCheck ;
						Sprite::GetInstance()->setBmpData(
								GimmickData_[ g ]._bmpNo ,
								0 ,
								GimmickData_[ g ]._x + GimmickData_[ g ]._off[ 0 ] + Chip::GetInstance()->getScrollX( ) ,
								GimmickData_[ g ]._y + GimmickData_[ g ]._off[ 1 ] ,
								0 , 0 ,
								128 , 128 ,
								1.0f , 1.0f ,
								255 ,
								GimmickData_[ g ]._off[ 0 ]
							) ;
						GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
						GimmickData_[ g ]._h = GimmickData_[ g ]._y + 128 ;
					} else {
						GimmickData_[ g ]._off[ 1 ] += 9.81 ;
						Sprite::GetInstance()->setBmpData(
								GimmickData_[ g ]._bmpNo ,
								0 ,
								GimmickData_[ g ]._x + GimmickData_[ g ]._off[ 0 ] + Chip::GetInstance()->getScrollX( ) ,
								GimmickData_[ g ]._y + GimmickData_[ g ]._off[ 1 ] ,
								0 , 0 ,
								128 , 128 ,
								1.0f , 1.0f ,
								255 ,
								GimmickData_[ g ]._off[ 0 ]
							) ;
						GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
						GimmickData_[ g ]._h = GimmickData_[ g ]._y + 128 ;
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
			/*	ä‚ÅFì¡éÍ
			/*/
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_WAVE )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//						printf( "Gimmick_MODE_WAVE\n" ) ;
					switch ( (int)GimmickData_[ g ]._off[ 2 ] )
					{
						case 1 :
							moveRocks01( g ) ;
							break ;

						case 2 :
							moveRocks02( g ) ;
							break ;

						case 3 :
							moveRocks03( g ) ;
							break ;

						case 4 :
							moveRocks04( g ) ;
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
/*	ä‚ÅFìÆÇ´1
/*/
void Gimmick::moveRocks01( int g )
{
	switch ( (int)GimmickData_[ g ]._off[ 3 ] )
	{
		case 0 :
			GimmickData_[ g ]._off[ 7 ]++ ;
			Sprite::GetInstance()->setBmpData(
					GimmickData_[ g ]._bmpNo ,
					0 ,
					GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
					GimmickData_[ g ]._y ,
					0 , 0 ,
					128 , 128 ,
					1.0f , 1.0f ,
					255 ,
					GimmickData_[ g ]._off[ 0 ]
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
					GimmickData_[ g ]._y + Chip::GetInstance()->sinWave(GimmickData_[ g ]._off[ 1 ] , 320) ,
					0 , 0 ,
					128 , 128 ,
					1.0f , 1.0f ,
					255 ,
					GimmickData_[ g ]._off[ 0 ]
				) ;
			GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
			GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

			if ( Chip::GetInstance()->sinWave(GimmickData_[ g ]._off[ 1 ] , 320) <= -1 )
			{
				GimmickData_[ g ]._off[ 3 ]++ ;
			}
			break ;

	}

}

/*/
/*	ä‚ÅFìÆÇ´2
/*/
void Gimmick::moveRocks02( int g )
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

	}

}

/*/
/*	ä‚ÅFìÆÇ´3
/*/
void Gimmick::moveRocks03( int g )
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
/*	ä‚ÅFìÆÇ´4
/*/
void Gimmick::moveRocks04( int g )
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
/*	ä‚ÅFë´å≥É`ÉFÉbÉN
/*/
float Gimmick::footCheck( int arg_no )
{
	float footY = -1 ;
	float px = 0.0f , py = 0.0f ;
	float bl = 0.0f , br = 0.0f , bt = 0.0f , bb = 0.0f ;

	// Ç†ÇΩÇËîªíËÇÇ∆ÇÈÇΩÇﬂÇÃÉ`ÉbÉvÉfÅ[É^
	int *chipTable = Chip::GetInstance()->getChipTable( ) ;

	px = GimmickData_[ arg_no ]._x + 64 ;
	py = GimmickData_[ arg_no ]._y + 64 ;

	// îªíËÇÇ∆ÇÈîÕàÕÅ@ç°ÇÕëSëÃ
	for( int i = 0 ; i < (CHIP_X * CHIP_Y) ; ++i )
	{
		// âΩÇ©èÓïÒÇ™ì¸Ç¡ÇƒÇ¢ÇÈÇ∆Ç´
		if ( chipTable[ i ] != NULL )
		{
			bl = ( float )( (i % CHIP_X) * CHIP_W ) - RenderScale ;
			br = ( float )( (i % CHIP_X) * CHIP_W + CHIP_W ) - RenderScale ;
			bt = ( float )( (i / CHIP_X) * CHIP_H - 64 ) ;
			bb = ( float )( (i / CHIP_X) * CHIP_H - 64 + CHIP_H ) ;

			switch ( chipTable[ i ] )
			{
				// í èÌÉuÉçÉbÉNÇÃèÍçá
				case 1 :
				case 9 :
					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl <= px) && (px <= br) )
						{
							footY = bt ;
						}
					}
					break ;

			}
		}
	}

	return( footY ) ;

}


