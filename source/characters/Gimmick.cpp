/*
________________________________________________________________________________________________________________

	FILE : Gimmick.cpp

	________/ Explanation of file /___________________________________________________________

		Gimmick ÉNÉâÉXÇÃé¿ëïïî

ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP
*/
#include "Gimmick.h"
#include "Chip.h"
#include "Sprite.h"
#include "KeyManager.h"

/*/
/*	ÉfÉXÉgÉâÉNÉ^
/*/
Gimmick::~Gimmick( )
{
	printf( "Gimmick was end.\n" ) ;
}

/*/
/*	èâä˙âª
/*/
void Gimmick::Initialize( )
{
	printf( "Gimmick was created.\n" ) ;

	clearGimmickData( ) ;

	GimmickNo_ = 0 ;

}

/*/
/*	èIóπâª
/*/
void Gimmick::Finalize( )
{
	Initialize( ) ;

	clearGimmickData( ) ;
}

/*/
/*	èâä˙âª
/*/
void Gimmick::clearGimmickData( )
{
	for ( int i = 0 ; i < MAX_GIMMICK_NO ; ++i )
	{
		GimmickData_[ i ]._useFlg	= false ;	// ï`âÊÇ∑ÇÈÇ©Ç«Ç§Ç©ÇÃÉtÉâÉO
		GimmickData_[ i ]._bmpNo	= 0 ;		// é©ï™ÇÃóvëfî‘çÜ ( _hBmp Ç∆ä÷òAïtÇØÇÈÇΩÇﬂ )
		GimmickData_[ i ]._anchor	= 0 ;		// ÉAÉìÉJÅ[ÇÃà íu
		GimmickData_[ i ]._x		= 0 ;
		GimmickData_[ i ]._y		= 0 ;		// ÉOÉçÅ[ÉoÉãç¿ïW
		GimmickData_[ i ]._u		= 0 ;
		GimmickData_[ i ]._v		= 0 ;		// êÿÇËéÊÇËç¿ïW
		GimmickData_[ i ]._w		= 0 ;
		GimmickData_[ i ]._h		= 0 ;		// ïùçÇÇ≥
		GimmickData_[ i ]._arrayX	= 0 ;
		GimmickData_[ i ]._arrayY	= 0 ;		// îzóÒç¿ïW
		GimmickData_[ i ]._delay	= 0 ;		// íxÇÍ
		GimmickData_[ i ]._spd		= 0 ;		// ë¨Ç≥
		GimmickData_[ i ]._Gimmick	= 0 ;		// ÉMÉ~ÉbÉNÇÃéÌóﬁ
		GimmickData_[ i ]._mode		= 0 ;		// ÉMÉ~ÉbÉNÇÃÉÇÅ[Éh
		GimmickData_[ i ]._off[ 0 ] = 0 ;		// ÉIÉtÉZÉbÉg
		GimmickData_[ i ]._off[ 1 ] = 0 ;		// ÉIÉtÉZÉbÉg
	}

}

/*/
/*	--+ ÉMÉ~ÉbÉNÇÃÉfÅ[É^ÇÉZÉbÉg +-----
/*/

/*/
/*	ìÆÇ≠è∞ÅFí èÌ
/*/
int Gimmick::setMoveBlock( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int arg_mode )
{
	GimmickData_[ GimmickNo_ ]._Gimmick	= GIMMICK_NAME_MOVEFLOOR ;
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
/*	seetGimmicks
/*/
void Gimmick::setGimmicks( )
{

}

/*/
/*	Update
/*
/*	
/*/
void Gimmick::Update( )
{
	for ( int g = 0 ; g < MAX_GIMMICK_NO ; ++g )
	{
		/*/
		/*	ÉXÉvÉâÉCÉgÉfÅ[É^
		/*/
		switch ( GimmickData_[ g ]._Gimmick )
		{
			/*/
			/*	___/ Ç‹ÇÈÇÃÇ± /___________________
			/*/
			case GIMMICK_NAME_MARU :
				// â°à⁄ìÆÇÃä€ãò

				// â~à⁄ìÆÇÃä€ãò

				// â~à⁄ìÆÇÃä€ãò

				break ;

			/*/
			/*	___/ ìÆÇ≠è∞ /___________________
			/*/
			case GIMMICK_NAME_MOVEFLOOR :
				/*/
				/*	ìÆÇ≠è∞ÅFê√é~
				/*/
				printf( "GIMMICK_NAME_MOVEFLOOR\n" ) ;
				if ( GimmickData_[ g ]._mode == GIMMICK_MODE_STAY )
				{
					if ( GimmickData_[ g ]._useFlg )
					{
						printf( "GIMMICK_MODE_STAY\n" ) ;
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
						printf( "GIMMICK_MODE_UPDOWN\n" ) ;

						GimmickData_[ g ]._off[ 0 ]++ ;
						Sprite::GetInstance()->setBmpData(
								GimmickData_[ g ]._bmpNo ,
								0 ,
								GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
								GimmickData_[ g ]._y + Chip::GetInstance()->sinWave( GimmickData_[ g ]._off[ 0 ] , 128 , GimmickData_[ g ]._spd ) ,
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

				break ;
		}
	}

}


