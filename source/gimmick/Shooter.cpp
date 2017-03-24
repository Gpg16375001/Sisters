/*
________________________________________________________________________________________________________________

	FILE : Shooter.cpp

	________/ Explanation of file /___________________________________________________________

		Gimmick ÉNÉâÉXÇÃ Shooter é¿ëïïî

ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP
*/
#include "Renderer.h"
#include "Gimmick.h"
#include "Chip.h"
#include "Sprite.h"
#include "KeyManager.h"


/*/r
/*	--+ Shooter ÇÃÉfÅ[É^ÇÉZÉbÉg +-----
/*/

/*/
/*	éÀåÇï®ÇÃÉfÅ[É^ÇÉZÉbÉg
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
		/*	___/ éÀåÇï® /___________________
		/*/
		if ( GimmickData_[ g ]._Gimmick == GIMMICK_NAME_MOVEFLOOR )
		{
			/*/
			/*	éÀåÇï®ÅFê√é~
			/*/
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_STAY )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//						printf( "Gimmick_MODE_STAY\n" ) ;
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

			}

		}
	}

}

/*/
/*	éÀåÇï®ÅFìÆÇ´1
/*/
void Gimmick::blockShot01( int g )
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

		case 2 :
			break ;

		case 3 :
			break ;

	}

}

/*/
/*	éÀåÇï®ÅFìÆÇ´2
/*/
void Gimmick::blockShot02( int g )
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

		case 2 :
			break ;

		case 3 :
			break ;

	}

}

/*/
/*	éÀåÇï®ÅFìÆÇ´3
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
/*	éÀåÇï®ÅFìÆÇ´4
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




