/*
________________________________________________________________________________________________________________

	FILE : Clouds.cpp

	________/ Explanation of file /___________________________________________________________

		Gimmick �N���X�� Clouds ������

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include "Renderer.h"
#include "Gimmick.h"
#include "Chip.h"
#include "Sprite.h"
#include "KeyManager.h"

/*/r
/*	--+ �M�~�b�N�̃f�[�^���Z�b�g +-----
/*/

/*/
/*	�����̃f�[�^���Z�b�g
/*/
int Gimmick::setClouds( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int arg_mode )
{
	GimmickData_[ GimmickNo_ ]._Gimmick	= GIMMICK_NAME_CLOUD ;
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
/*	Clouds Update
/*/
void Gimmick::Clouds( )
{
	for ( int g = 0 ; g < MAX_GIMMICK_NO ; ++g )
	{
		/*/
		/*	___/ ���� /___________________
		/*/
		if ( GimmickData_[ g ]._Gimmick == GIMMICK_NAME_CLOUD )
		{
			/*/
			/*	�����F�Î~
			/*/
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_STAY )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//						printf( "GIMMICK_MODE_STAY\n" ) ;

					GimmickData_[ g ]._off[ 0 ]++ ;
					if ( (-600 < (GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) - 196))
						&& ((GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) - 196) < 800)
						)
					{
						Sprite::GetInstance()->setBmpData(
								GimmickData_[ g ]._bmpNo ,
								0 ,
								GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
								GimmickData_[ g ]._y + Chip::GetInstance()->sinWave( GimmickData_[ g ]._off[ 0 ] , 4 ) ,
								0 , 0 ,
								128 , 64 ,
								1.0f + Chip::GetInstance()->sinWave( GimmickData_[ g ]._off[ 0 ] , 2 ) / 100 ,
								1.0f + Chip::GetInstance()->sinWave( GimmickData_[ g ]._off[ 0 ] , 4 ) / 100 ,
								255 ,
								0
							) ;
					}
					GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
					GimmickData_[ g ]._h = GimmickData_[ g ]._y + 64 ;
						
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



