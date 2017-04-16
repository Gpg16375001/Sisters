/*
________________________________________________________________________________________________________________

	FILE : Grass.cpp

	________/ Explanation of file /___________________________________________________________

		Gimmick ÉNÉâÉXÇÃ Grass é¿ëïïî

ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP
*/
#include "Renderer.h"
#include "Gimmick.h"
#include "Chip.h"
#include "Sprite.h"
#include "KeyManager.h"

/*/
/*	Grass ÇÃÉfÅ[É^ÇÉZÉbÉg
/*/
int Gimmick::setGrass( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int arg_mode )
{
	GimmickData_[ GimmickNo_ ]._Gimmick	= GIMMICK_NAME_GRASS ;
	GimmickData_[ GimmickNo_ ]._bmpNo	= arg_bmpNo ;
	GimmickData_[ GimmickNo_ ]._x		= arg_x ;
	GimmickData_[ GimmickNo_ ]._y		= arg_y ;
	GimmickData_[ GimmickNo_ ]._spd		= arg_spd ;
	GimmickData_[ GimmickNo_ ]._delay	= arg_delay ;
	GimmickData_[ GimmickNo_ ]._mode	= arg_mode ;
	GimmickData_[ GimmickNo_ ]._off[ 2 ]= arg_spd ;
	
	AnimationData grass_anim[ ] = {
		{ arg_bmpNo , 16 , {50 * 0 , 0 , 50 , 64} , ANIM_MODE_NEXT } ,
		{ arg_bmpNo , 16 , {50 * 1 , 0 , 50 , 64} , ANIM_MODE_NEXT } ,
		{ arg_bmpNo , 32 , {50 * 2 , 0 , 50 , 64} , ANIM_MODE_NEXT } ,
		{ arg_bmpNo , 12 , {50 * 1 , 0 , 50 , 64} , ANIM_MODE_LOOP } ,
	} ;
	memcpy( &GimmickData_[ GimmickNo_ ]._gAnim_01 , grass_anim , 4 * sizeof( AnimationData ) ) ;

	GimmickData_[ GimmickNo_ ]._gAnim.setAnimData( GimmickData_[ GimmickNo_ ]._gAnim_01 ) ;

	GimmickNo_++ ;
	return( true ) ;

}

/*/
/*	Grass Update
/*/
void Gimmick::Grass( )
{
	for ( int g = 0 ; g < MAX_GIMMICK_NO ; ++g )
	{
		/*/
		/*	___/ Grass /___________________
		/*/
		if ( GimmickData_[ g ]._Gimmick == GIMMICK_NAME_GRASS )
		{
			/*/
			/*	GrassÅFí èÌ
			/*/
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_STAY )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//						printf( "Gimmick_MODE_STAY\n" ) ;
					// ñ{ëÃ
					if ( (-600 < (GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) - 196))
						&& ((GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) - 196) < 800)
						)
					{
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
								(float)nowAnim->cutRect.right ,
								(float)nowAnim->cutRect.bottom ,
								1.0f , 1.0f ,
								210 ,
								0
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



