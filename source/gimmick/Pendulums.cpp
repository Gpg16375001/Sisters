/*
________________________________________________________________________________________________________________

	FILE : Pendulums.cpp

	________/ Explanation of file /___________________________________________________________

		Gimmick ÉNÉâÉXÇÃ Pendulums é¿ëïïî

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
/*	êUÇËéqÇÃÉfÅ[É^ÇÉZÉbÉg
/*/
int Gimmick::setPendulums( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int arg_mode )
{
	GimmickData_[ GimmickNo_ ]._Gimmick	= GIMMICK_NAME_PENDULUM ;
	GimmickData_[ GimmickNo_ ]._bmpNo	= arg_bmpNo ;
	GimmickData_[ GimmickNo_ ]._x		= arg_x ;
	GimmickData_[ GimmickNo_ ]._y		= arg_y ;
	GimmickData_[ GimmickNo_ ]._spd		= arg_spd ;
	GimmickData_[ GimmickNo_ ]._delay	= arg_delay ;
	GimmickData_[ GimmickNo_ ]._mode	= arg_mode ;
	GimmickNo_++ ;
	GimmickData_[ GimmickNo_ ]._Gimmick	= -1 ;
	GimmickData_[ GimmickNo_ ]._bmpNo	= arg_bmpNo - 10 ;
	GimmickData_[ GimmickNo_ ]._x		= arg_x ;
	GimmickData_[ GimmickNo_ ]._y		= arg_y ;
	GimmickData_[ GimmickNo_ ]._spd		= arg_spd ;
	GimmickData_[ GimmickNo_ ]._delay	= arg_delay ;
	GimmickData_[ GimmickNo_ ]._mode	= -1 ;
	GimmickNo_++ ;

	return( true ) ;
}

/*/
/*	Pendulums Update
/*/
void Gimmick::Pendulums( )
{
	for ( int g = 0 ; g < MAX_GIMMICK_NO ; ++g )
	{
		/*/
		/*	___/ êUÇËéq /___________________
		/*/
		if ( GimmickData_[ g ]._Gimmick == GIMMICK_NAME_PENDULUM )
		{
			/*/
			/*	êUÇËéqÅFç∂âE
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
							GimmickData_[ g ]._y + Chip::GetInstance()->sinWave( GimmickData_[ g ]._off[ 1 ] , 128 ) ,
							0 , 0 ,
							128 , 128 ,
							1.0f , 1.0f ,
							255 ,
							0
						) ;

					GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
					GimmickData_[ g ]._h = GimmickData_[ g ]._y + 128 ;
					if  ( Chip::GetInstance()->sinWave( GimmickData_[ g ]._off[ 1 ] , 128 ) < 0 )
					{
						GimmickData_[ g ]._off[ 1 ] = 0 ;
					}
					if  ( Chip::GetInstance()->sinWave( GimmickData_[ g ]._off[ 0 ] , 128 ) <= -180 )
					{
						GimmickData_[ g ]._off[ 0 ] = 0 ;
						GimmickData_[ g ]._off[ 1 ] = 0 ;
					}
						
					if ( (-380 < (GimmickData_[ g+1 ]._x + Chip::GetInstance()->getScrollX( ) - 196))
						&& ((GimmickData_[ g+1 ]._x + Chip::GetInstance()->getScrollX( ) - 196) < 800)
						)
					{
						// çΩ
						Sprite::GetInstance()->setBmpData(
								GimmickData_[ g+1 ]._bmpNo ,
								0 ,
								GimmickData_[ g+1 ]._x + Chip::GetInstance()->cosWave( GimmickData_[ g ]._off[ 0 ] , 52 ) + Chip::GetInstance()->getScrollX( ) - 196 ,
								GimmickData_[ g+1 ]._y - 192 ,
								0 , 0 ,
								512 , 256 ,
								1.0f , 1.0f ,
								255 ,
								-Chip::GetInstance()->cosWave( GimmickData_[ g ]._off[ 0 ] , 26 )
							) ;
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



