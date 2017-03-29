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


/*/
/*	--+ Shooter ÅEΩÃÉfÅEΩ[ÅEΩ^ÅEΩÅEΩÅEΩZÅEΩbÅEΩg +-----
/*/
int Gimmick::nullCheck( )
{
	int iRet = -1 ;

	for ( int i = 0 ; i < 500 ; ++i )
	{
		if ( BulletData_[ i ]._useFlg )
		{
		} else {
			BulletData_[ i ]._useFlg = true ;
			iRet = i ;
			break ;
		}
	}
	return( iRet ) ;
}

int Gimmick::useCheck( int arg_used )
{
	int iRet = -1 ;

	if ( BulletData_[ arg_used ]._useFlg )
	{
		iRet = BulletData_[ arg_used ]._bmpNo ;
	}

	return( iRet ) ;
}

/*/
/*	íeÇÃèâä˙ÉfÅ[É^ÇÉZÉbÉg
/*/
void Gimmick::setBulletData( )
{
	for ( int i = 0 ; i < 500 ; ++i )
	{
		BulletData_[ i ]._bmpNo		= i + 500 ;
		BulletData_[ i ]._w			= 64 ;
		BulletData_[ i ]._h			= 64 ;
	}

}

/*/
/*	Shooter ÇÃÉfÅ[É^ÇÉZÉbÉg
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

	AnimationData Epod_anim[ ] = {
		{ arg_bmpNo , 96 , {64 * 0 , 0 , 64 , 64} , ANIM_MODE_NEXT } ,
		{ arg_bmpNo ,  8 , {64 * 1 , 0 , 64 , 64} , ANIM_MODE_NEXT } ,
		{ arg_bmpNo ,  8 , {64 * 3 , 0 , 64 , 64} , ANIM_MODE_NEXT } ,
		{ arg_bmpNo , 10 , {64 * 2 , 0 , 64 , 64} , ANIM_MODE_LOOP } ,
	} ;
	memcpy( &GimmickData_[ GimmickNo_ ]._gAnim_01 , Epod_anim , 4 * sizeof( AnimationData ) ) ;

	GimmickData_[ GimmickNo_ ]._gAnim.setAnimData( GimmickData_[ GimmickNo_ ]._gAnim_01 ) ;

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
		/*	___/ Shooter /___________________
		/*/
		if ( GimmickData_[ g ]._Gimmick == GIMMICK_NAME_SHOOTER )
		{
			/*/
			/*	ShooterÅFí èÌ
			/*/
			if ( GimmickData_[ g ]._mode == GIMMICK_MODE_STAY )
			{
				if ( GimmickData_[ g ]._useFlg )
				{
//						printf( "Gimmick_MODE_STAY\n" ) ;
					// ñ{ëÃ
					GimmickData_[ g ]._gAnim.playAnim( ) ;
					AnimationData *nowAnim ;
					nowAnim = GimmickData_[ g ]._gAnim.getNowAnim( ) ;
					Sprite::GetInstance()->setBmpData(
							nowAnim->bmpNo ,
							0 ,
							GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
							GimmickData_[ g ]._y ,
							nowAnim->cutRect.left ,
							nowAnim->cutRect.top ,
							64 ,
							64 ,
							1.0f , 1.0f ,
							255 ,
							0
						) ;

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
/*	ShooterÅFìÆÇ´ 1
/*/
void Gimmick::blockShot01( int g )
{
	switch ( (int)GimmickData_[ g ]._off[ 3 ] )
	{
		// íeÇÉZÉbÉg
		case 0 :
			// íe
			for ( int cyc = 0 ; cyc < 360 ; cyc+=60 )
			{
				int no = nullCheck( ) ;
				if ( no != -1 )
				{
					BulletData_[ no ]._x = GimmickData_[ g ]._x ;
					BulletData_[ no ]._y = GimmickData_[ g ]._y ;
					BulletData_[ no ]._off[ 0 ] = cos( 3.14159265f / 180.0f * cyc ) * 0.8f ;
					BulletData_[ no ]._off[ 1 ] = sin( 3.14159265f / 180.0f * cyc ) * 0.8f ;
				}
			}

			for ( int allcnt = 0 ; allcnt < 500 ; ++allcnt )
			{
				int no = useCheck( allcnt ) ;
				if ( no != -1 )
				{
					BulletData_[ allcnt ]._x += BulletData_[ allcnt ]._off[ 0 ] ;
					BulletData_[ allcnt ]._y += BulletData_[ allcnt ]._off[ 1 ] ;

					Sprite::GetInstance()->setBmpData(
							no ,
							0 ,
							BulletData_[ allcnt ]._x + Chip::GetInstance()->getScrollX( ) ,
							BulletData_[ allcnt ]._y ,
							0 , 0 ,
							64 , 64 ,
							1.0f , 1.0f ,
							232 ,
							0
						) ;
					BulletData_[ allcnt ]._delay++ ;	// è¡Ç¶ÇÈÇ‹Ç≈ÇÃéûä‘
					if ( BulletData_[ allcnt ]._delay >= 800 )
					{
						// è¡ñ≈Ç≥ÇπÇÈ
						BulletData_[ allcnt ]._useFlg	= false ;
						BulletData_[ allcnt ]._x		= 0.0f ;
						BulletData_[ allcnt ]._y		= 0.0f ;
						BulletData_[ allcnt ]._off[ 0 ] = 0.0f ;
						BulletData_[ allcnt ]._off[ 1 ] = 0.0f ;
						BulletData_[ allcnt ]._delay	= 0 ;
					}
				}
			}

			GimmickData_[ g ]._off[ 3 ]++ ;
			break ;

		// íeÇçXêV
		case 1 :
			// íe
			for ( int allcnt = 0 ; allcnt < 500 ; ++allcnt )
			{
				int no = useCheck( allcnt ) ;
				if ( no != -1 )
				{
					BulletData_[ allcnt ]._x += BulletData_[ allcnt ]._off[ 0 ] ;
					BulletData_[ allcnt ]._y += BulletData_[ allcnt ]._off[ 1 ] ;

					Sprite::GetInstance()->setBmpData(
							no ,
							0 ,
							BulletData_[ allcnt ]._x + Chip::GetInstance()->getScrollX( ) ,
							BulletData_[ allcnt ]._y ,
							0 , 0 ,
							64 , 64 ,
							1.0f , 1.0f ,
							232 ,
							0
						) ;
					BulletData_[ allcnt ]._delay++ ;	// è¡Ç¶ÇÈÇ‹Ç≈ÇÃéûä‘
					if ( BulletData_[ allcnt ]._delay >= 800 )
					{
						// è¡ñ≈Ç≥ÇπÇÈ
						BulletData_[ allcnt ]._useFlg	= false ;
						BulletData_[ allcnt ]._x		= 0.0f ;
						BulletData_[ allcnt ]._y		= 0.0f ;
						BulletData_[ allcnt ]._off[ 0 ] = 0.0f ;
						BulletData_[ allcnt ]._off[ 1 ] = 0.0f ;
						BulletData_[ allcnt ]._delay	= 0 ;
					}
				}
			}

			GimmickData_[ g ]._off[ 4 ]++ ;
			if ( GimmickData_[ g ]._off[ 4 ] >= 200 )
			{
				GimmickData_[ g ]._off[ 4 ] = 0.0f ;
				GimmickData_[ g ]._off[ 3 ] = 0.0f ;
			}
			break ;

		case 2 :
			break ;

		case 3 :
			break ;

	}

}

/*/
/*	ShooterÅFìÆÇ´ 2
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
/*	ShooterÅFìÆÇ´ 3
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
/*	ShooterÅFìÆÇ´ 4
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




