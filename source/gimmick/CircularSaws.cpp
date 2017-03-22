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
	GimmickData_[ GimmickNo_ ]._spd		= arg_spd ;
	GimmickData_[ GimmickNo_ ]._delay	= arg_delay ;
	GimmickData_[ GimmickNo_ ]._mode	= arg_mode ;
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
							GimmickData_[ g ]._y ,
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
							GimmickData_[ g ]._y + Chip::GetInstance()->sinWave( GimmickData_[ g ]._off[ 0 ] , 128 ) ,
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
							GimmickData_[ g ]._y ,
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
							GimmickData_[ g ]._y + Chip::GetInstance()->sinWave( GimmickData_[ g ]._off[ 0 ] , 128 ) ,
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

		}
	}

}



