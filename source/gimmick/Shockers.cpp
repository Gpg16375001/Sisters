/*
________________________________________________________________________________________________________________

	FILE : Shockers.cpp

	________/ Explanation of file /___________________________________________________________

		Gimmick ÉNÉâÉXÇÃ Shockers é¿ëïïî

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
/*	ìdãCÇÃÉfÅ[É^ÇÉZÉbÉg
/*/
int Gimmick::setShockers( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int arg_mode )
{
	GimmickData_[ GimmickNo_ ]._Gimmick	= GIMMICK_NAME_SHOCKER ;
	GimmickData_[ GimmickNo_ ]._bmpNo	= arg_bmpNo ;
	GimmickData_[ GimmickNo_ ]._x		= arg_x ;
	GimmickData_[ GimmickNo_ ]._y		= arg_y ;
	GimmickData_[ GimmickNo_ ]._spd		= arg_spd ;
	GimmickData_[ GimmickNo_ ]._delay	= arg_delay ;
	GimmickData_[ GimmickNo_ ]._mode	= arg_mode ;
	GimmickNo_++ ;

	return( true ) ;
}


/*/
/*	Shockers Update
/*/
void Gimmick::Shockers( )
{
	for ( int g = 0 ; g < MAX_GIMMICK_NO ; ++g )
	{
		/*/
		/*	___/ ìdãC /___________________
		/*/
		if ( GimmickData_[ g ]._Gimmick == GIMMICK_NAME_SHOCKER )
		{
			/*/
			/*	ìdãCÅFè„â∫
			/*/
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_UPDOWN )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//						printf( "GIMMICK_MODE_UPDOWN\n" ) ;

					GimmickData_[ g ]._off[ 0 ] += 4 ;
					Sprite::GetInstance()->setBmpData(
							GimmickData_[ g ]._bmpNo ,
							0 ,
							GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
							GimmickData_[ g ]._y + GimmickData_[ g ]._off[ 0 ] + Chip::GetInstance()->getScrollY( ) ,
							64 , 0 ,
							64 , 64 ,
							1.0f , 1.0f ,
							255 ,
							0
						) ;
					GimmickData_[ g ]._w = GimmickData_[ g ]._x + 64 ;
					GimmickData_[ g ]._h = GimmickData_[ g ]._y + 64 ;

					if ( GimmickData_[ g ]._off[ 0 ] >= GimmickData_[ g ]._spd )
					{
						GimmickData_[ g ]._off[ 0 ] = 0 ;
						GimmickData_[ g ]._useFlg = false ;
						GimmickData_[ g ]._delay = 8 ;
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
			/*	ìdãCÅFç∂âE
			/*/
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_LEFTRIGHT )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//						printf( "GIMMICK_MODE_LEFTRIGHT\n" ) ;

					GimmickData_[ g ]._off[ 0 ] -= 4 ;
					Sprite::GetInstance()->setBmpData(
							GimmickData_[ g ]._bmpNo ,
							0 ,
							GimmickData_[ g ]._x + GimmickData_[ g ]._off[ 0 ] + Chip::GetInstance()->getScrollX( ) ,
							GimmickData_[ g ]._y + Chip::GetInstance()->getScrollY( ) ,
							0 , 0 ,
							64 , 64 ,
							1.0f , 1.0f ,
							255 ,
							0
						) ;
					GimmickData_[ g ]._w = GimmickData_[ g ]._x + 64 ;
					GimmickData_[ g ]._h = GimmickData_[ g ]._y + 64 ;

					if ( GimmickData_[ g ]._off[ 0 ] <= -GimmickData_[ g ]._spd )
					{
						GimmickData_[ g ]._off[ 0 ] = 0 ;
						GimmickData_[ g ]._useFlg = false ;
						GimmickData_[ g ]._delay = 8 ;
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



