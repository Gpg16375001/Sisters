/*
________________________________________________________________________________________________________________

	FILE : Gimmick.cpp

	________/ Explanation of file /___________________________________________________________

		Gimmick ÉNÉâÉXÇÃé¿ëïïî

ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP
*/
#include "Renderer.h"
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
		GimmickData_[ i ]._off[ 0 ] = 0 ;		// ÉIÉtÉZÉbÉg 1
		GimmickData_[ i ]._off[ 1 ] = 0 ;		// ÉIÉtÉZÉbÉg 2
		GimmickData_[ i ]._off[ 2 ] = 0 ;		// ÉIÉtÉZÉbÉg 3
		GimmickData_[ i ]._off[ 3 ] = 0 ;		// ÉIÉtÉZÉbÉg 4
	}

}

/*/r
/*	--+ ÉMÉ~ÉbÉNÇÃÉfÅ[É^ÇÉZÉbÉg +-----
/*/

/*/
/*	ìÆÇ≠è∞ÇÃÉfÅ[É^ÇÉZÉbÉg
/*/
int Gimmick::setMoveBlocks( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int arg_mode )
{
	GimmickData_[ GimmickNo_ ]._Gimmick	= GIMMICK_NAME_MOVEFLOOR ;
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
/*	Ç‹ÇÈÇÃÇ±ÇÃÉfÅ[É^ÇÉZÉbÉg
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
/*	SpeedUpÇÃÉfÅ[É^ÇÉZÉbÉg
/*/
int Gimmick::setSpeedUp( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int arg_mode )
{
	GimmickData_[ GimmickNo_ ]._Gimmick	= GIMMICK_NAME_SPEEDUP ;
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
/*	Ç≠Ç‡ÇÃÉfÅ[É^ÇÉZÉbÉg
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
/*	Update
/*
/*	
/*/
void Gimmick::Update( )
{
	for ( int g = 0 ; g < MAX_GIMMICK_NO ; ++g )
	{
		/*/
		/*	Ç¨Ç¡Ç›Ç¡Ç≠ÇÃéÌóﬁï™ÇØ
		/*/
		switch ( GimmickData_[ g ]._Gimmick )
		{
			/*/
			/*	___/ Ç‹ÇÈÇÃÇ± /___________________
			/*/
			case GIMMICK_NAME_CIRCULARSAWS :
				/*/
				/*	Ç‹ÇÈÇÃÇ±ÅFê√é~
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
				/*	Ç‹ÇÈÇÃÇ±ÅFè„â∫
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
				/*	Ç‹ÇÈÇÃÇ±ÅFç∂âE
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
				/*	Ç‹ÇÈÇÃÇ±ÅFâ~
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

				break ;

			/*/
			/*	___/ ìÆÇ≠è∞ /___________________
			/*/
			case GIMMICK_NAME_MOVEFLOOR :
				/*/
				/*	ìÆÇ≠è∞ÅFê√é~
				/*/
//				printf( "GIMMICK_NAME_MOVEFLOOR\n" ) ;
				if ( GimmickData_[ g ]._mode == GIMMICK_MODE_STAY )
				{
					if ( GimmickData_[ g ]._useFlg )
					{
//						printf( "GIMMICK_MODE_STAY\n" ) ;
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
//						printf( "GIMMICK_MODE_UPDOWN\n" ) ;

						GimmickData_[ g ]._off[ 0 ]++ ;
						Sprite::GetInstance()->setBmpData(
								GimmickData_[ g ]._bmpNo ,
								0 ,
								GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
								GimmickData_[ g ]._y + Chip::GetInstance()->sinWave( GimmickData_[ g ]._off[ 0 ] , 128 ) ,
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
				/*	ìÆÇ≠è∞ÅFç∂âE
				/*/
				if ( GimmickData_[ g ]._mode == GIMMICK_MODE_LEFTRIGHT )
				{
					if ( GimmickData_[ g ]._useFlg )
					{
//						printf( "GIMMICK_MODE_LEFTRIGHT\n" ) ;

						GimmickData_[ g ]._off[ 0 ]++ ;
						Sprite::GetInstance()->setBmpData(
								GimmickData_[ g ]._bmpNo ,
								0 ,
								GimmickData_[ g ]._x + Chip::GetInstance()->cosWave( GimmickData_[ g ]._off[ 0 ] , 128 ) + Chip::GetInstance()->getScrollX( ) ,
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
				/*	ìÆÇ≠è∞ÅFâ~
				/*/
				if ( GimmickData_[ g ]._mode == GIMMICK_MODE_CYCLE )
				{
					if ( GimmickData_[ g ]._useFlg )
					{
//						printf( "GIMMICK_MODE_CYCLE\n" ) ;

						GimmickData_[ g ]._off[ 0 ]++ ;
						Sprite::GetInstance()->setBmpData(
								GimmickData_[ g ]._bmpNo ,
								0 ,
								GimmickData_[ g ]._x + Chip::GetInstance()->cosWave( GimmickData_[ g ]._off[ 0 ] , 128 ) + Chip::GetInstance()->getScrollX( ) ,
								GimmickData_[ g ]._y + Chip::GetInstance()->sinWave( GimmickData_[ g ]._off[ 0 ] , 128 ) ,
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
				/*	ìÆÇ≠è∞ÅFóéÇø
				/*/
				if ( GimmickData_[ g ]._mode == GIMMICK_MODE_DROP )
				{
					if ( GimmickData_[ g ]._useFlg )
					{
//						printf( "GIMMICK_MODE_DROP\n" ) ;

						GimmickData_[ g ]._off[ 0 ] += (GimmickData_[ g ]._spd / 60) ;
						Sprite::GetInstance()->setBmpData(
								GimmickData_[ g ]._bmpNo ,
								0 ,
								GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
								GimmickData_[ g ]._y + GimmickData_[ g ]._off[ 0 ] ,
								0 , 0 ,
								256 , 64 ,
								0.5f , 0.5f ,
								255 ,
								0
							) ;
						GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
						GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

						if ( GimmickData_[ g ]._off[ 0 ] >= 700 )
						{
							GimmickData_[ g ]._off[ 0 ] = -100 ;
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
				/*	ìÆÇ≠è∞ÅFè∏ÇË
				/*/
				if ( GimmickData_[ g ]._mode == GIMMICK_MODE_UPPER )
				{
					if ( GimmickData_[ g ]._useFlg )
					{
//						printf( "GIMMICK_MODE_UPPER\n" ) ;

						GimmickData_[ g ]._off[ 0 ] -= (GimmickData_[ g ]._spd / 60) ;
						Sprite::GetInstance()->setBmpData(
								GimmickData_[ g ]._bmpNo ,
								0 ,
								GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
								GimmickData_[ g ]._y + GimmickData_[ g ]._off[ 0 ] ,
								0 , 0 ,
								256 , 64 ,
								0.5f , 0.5f ,
								255 ,
								0
							) ;
						GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
						GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

						if ( GimmickData_[ g ]._off[ 0 ] <= -100 )
						{
							GimmickData_[ g ]._off[ 0 ] = 700 ;
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
				/*	ìÆÇ≠è∞ÅFì¡éÍ
				/*/
				if ( GimmickData_[ g ]._mode == GIMMICK_MODE_WAVE )
				{
					if ( GimmickData_[ g ]._useFlg )
					{
//						printf( "GIMMICK_MODE_WAVE\n" ) ;
						switch ( (int)GimmickData_[ g ]._off[ 2 ] )
						{
							case 1 :
								moveFloor01( g ) ;
								break ;

							case 2 :
								moveFloor02( g ) ;
								break ;

							case 3 :
								moveFloor03( g ) ;
								break ;

							case 4 :
								moveFloor04( g ) ;
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
				break ;

			/*/
			/*	___/ êUÇËéq /___________________
			/*/
			case GIMMICK_NAME_PENDULUM :
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
								GimmickData_[ g ]._y + Chip::GetInstance()->sinWave( GimmickData_[ g ]._off[ 1 ] , 32 ) ,
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
						
						if ( (-380 < (GimmickData_[ g+1 ]._x + Chip::GetInstance()->getScrollX( ) - 196))
							&& ((GimmickData_[ g+1 ]._x + Chip::GetInstance()->getScrollX( ) - 196) < 800)
							)
						{
							// çΩ
							Sprite::GetInstance()->setBmpData(
									GimmickData_[ g+1 ]._bmpNo ,
									0 ,
									GimmickData_[ g+1 ]._x + Chip::GetInstance()->getScrollX( ) - 196 ,
									GimmickData_[ g+1 ]._y - 448 ,
									0 , 0 ,
									512 , 512 ,
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
				break ;

			/*/
			/*	___/ ìdãC /___________________
			/*/
			case GIMMICK_NAME_SHOCKER :
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
								GimmickData_[ g ]._y + GimmickData_[ g ]._off[ 0 ] ,
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
								GimmickData_[ g ]._y ,
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
				break ;

			/*/
			/*	___/ SPPED UP /___________________
			/*/
			case GIMMICK_NAME_SPEEDUP :
				/*/
				/*	Speed UpÅFê√é~
				/*/
				if ( GimmickData_[ g ]._mode == GIMMICK_MODE_STAY )
				{
					if ( GimmickData_[ g ]._useFlg )
					{
//						printf( "GIMMICK_MODE_STAY\n" ) ;

						GimmickData_[ g ]._off[ 0 ]++ ;
						Sprite::GetInstance()->setBmpData(
								GimmickData_[ g ]._bmpNo ,
								0 ,
								GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
								GimmickData_[ g ]._y + Chip::GetInstance()->sinWave( GimmickData_[ g ]._off[ 0 ] , 8 ) ,
								0 , 0 ,
								128 , 64 ,
								1.0f , 1.0f ,
								255 ,
								0
							) ;
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
				break ;

			/*/
			/*	___/ Ç≠Ç‡ /___________________
			/*/
			case GIMMICK_NAME_CLOUD :
				/*/
				/*	Ç≠Ç‡ÅFê√é~
				/*/
				if ( GimmickData_[ g ]._mode == GIMMICK_MODE_STAY )
				{
					if ( GimmickData_[ g ]._useFlg )
					{
//						printf( "GIMMICK_MODE_STAY\n" ) ;

						GimmickData_[ g ]._off[ 0 ]++ ;
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
				break ;

		}
	}

}

/*/
/*	ìÆÇ≠è∞ÅFìÆÇ´1
/*/
void Gimmick::moveFloor01( int g )
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
			GimmickData_[ g ]._off[ 0 ]++ ;
			GimmickData_[ g ]._off[ 1 ]++ ;
			Sprite::GetInstance()->setBmpData(
					GimmickData_[ g ]._bmpNo ,
					0 ,
					GimmickData_[ g ]._x + GimmickData_[ g ]._off[ 0 ] + Chip::GetInstance()->getScrollX( ) ,
					GimmickData_[ g ]._y + Chip::GetInstance()->sinWave(GimmickData_[ g ]._off[ 0 ] , 192) ,
					0 , 0 ,
					256 , 64 ,
					0.5f , 0.5f ,
					255 ,
					0
				) ;
			GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
			GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;
			break ;

	}

}

/*/
/*	ìÆÇ≠è∞ÅFìÆÇ´2
/*/
void Gimmick::moveFloor02( int g )
{
	switch ( (int)GimmickData_[ g ]._off[ 3 ] )
	{
		case 0 :
			break ;

		case 1 :
			break ;

	}

}

/*/
/*	ìÆÇ≠è∞ÅFìÆÇ´3
/*/
void Gimmick::moveFloor03( int g )
{
	switch ( (int)GimmickData_[ g ]._off[ 3 ] )
	{
		case 0 :
			break ;

		case 1 :
			break ;

	}

}

/*/
/*	ìÆÇ≠è∞ÅFìÆÇ´4
/*/
void Gimmick::moveFloor04( int g )
{
	switch ( (int)GimmickData_[ g ]._off[ 3 ] )
	{
		case 0 :
			break ;

		case 1 :
			break ;

	}

}



