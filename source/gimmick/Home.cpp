/*
________________________________________________________________________________________________________________

	FILE : Home.cpp

	________/ Explanation of file /___________________________________________________________

		Gimmick ÉNÉâÉXÇÃ Home é¿ëïïî

ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP
*/
#include "Renderer.h"
#include "Gimmick.h"
#include "Chip.h"
#include "Sprite.h"
#include "KeyManager.h"

/*/
/*	Home ÇÃÉfÅ[É^ÇÉZÉbÉg
/*/
int Gimmick::setHome( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int arg_mode )
{
	GimmickData_[ GimmickNo_ ]._Gimmick	= GIMMICK_NAME_HOME ;
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
/*	Home Update
/*/
void Gimmick::Home( )
{
	for ( int g = 0 ; g < MAX_GIMMICK_NO ; ++g )
	{
		/*/
		/*	___/ Home /___________________
		/*/
		if ( GimmickData_[ g ]._Gimmick == GIMMICK_NAME_HOME )
		{
			/*/
			/*	HomeÅFí èÌ
			/*/
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_STAY )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//					printf( "Gimmick_MODE_STAY\n" ) ;
					// ñ{ëÃ
					Sprite::GetInstance()->setBmpData(
							GimmickData_[ g ]._bmpNo ,
							0 ,
							GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
							GimmickData_[ g ]._y + Chip::GetInstance()->getScrollY( ) ,
							0.0f ,
							0.0f ,
							400.0f ,
							300.0f ,
							1.0f , 1.0f ,
							255 ,
							0
						) ;

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



