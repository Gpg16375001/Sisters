/*
________________________________________________________________________________________________________________

	FILE : Gimmick.cpp

	________/ Explanation of file /___________________________________________________________

		Gimmick NXÌÀ

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
#include "Renderer.h"
#include "Gimmick.h"
#include "Chip.h"
#include "Sprite.h"
#include "KeyManager.h"

/*/
/*	fXgN^
/*/
Gimmick::~Gimmick( )
{
	printf( "Gimmick was end.\n" ) ;
}

/*/
/*	ú»
/*/
void Gimmick::Initialize( )
{
	printf( "Gimmick was created.\n" ) ;

	clearGimmickData( ) ;

	GimmickNo_ = 0 ;

}

/*/
/*	I¹»
/*/
void Gimmick::Finalize( )
{
	Initialize( ) ;

	clearGimmickData( ) ;
}

/*/
/*	ú»
/*/
void Gimmick::clearGimmickData( )
{
	for ( int i = 0 ; i < MAX_GIMMICK_NO ; ++i )
	{
		GimmickData_[ i ]._useFlg	= false ;	// `æ·é©Ç¤©ÌtO
		GimmickData_[ i ]._bmpNo	= 0 ;		// ©ªÌvfÔ ( _hBmp ÆÖAt¯é½ß )
		GimmickData_[ i ]._anchor	= 0 ;		// AJ[ÌÊu
		GimmickData_[ i ]._x		= 0 ;
		GimmickData_[ i ]._y		= 0 ;		// O[oÀW
		GimmickData_[ i ]._u		= 0 ;
		GimmickData_[ i ]._v		= 0 ;		// ØèæèÀW
		GimmickData_[ i ]._w		= 0 ;
		GimmickData_[ i ]._h		= 0 ;		// ³
		GimmickData_[ i ]._arrayX	= 0 ;
		GimmickData_[ i ]._arrayY	= 0 ;		// zñÀW
		GimmickData_[ i ]._delay	= 0 ;		// xê
		GimmickData_[ i ]._spd		= 0 ;		// ¬³
		GimmickData_[ i ]._Gimmick	= 0 ;		// M~bNÌíÞ
		GimmickData_[ i ]._mode		= 0 ;		// M~bNÌ[h
		GimmickData_[ i ]._off[ 0 ] = 0 ;		// ItZbg 1
		GimmickData_[ i ]._off[ 1 ] = 0 ;		// ItZbg 2
		GimmickData_[ i ]._off[ 2 ] = 0 ;		// ItZbg 3
		GimmickData_[ i ]._off[ 3 ] = 0 ;		// ItZbg 4
	}

}

/*/r
/*	--+ M~bNÌf[^ðZbg +-----
/*/

/*/
/*	®­°Ìf[^ðZbg
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
/*	ÜéÌ±Ìf[^ðZbg
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
/*	UèqÌf[^ðZbg
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
/*	dCÌf[^ðZbg
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
/*	SpeedUpÌf[^ðZbg
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
/*	­àÌf[^ðZbg
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
		/*	¬ÁÝÁ­ÌíÞª¯
		/*/
		switch ( GimmickData_[ g ]._Gimmick )
		{
			/*/
			/*	___/ ÜéÌ± /___________________
			/*/
			case GIMMICK_NAME_CIRCULARSAWS :
				/*/
				/*	ÜéÌ±FÃ~
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
				/*	ÜéÌ±Fãº
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
				/*	ÜéÌ±F¶E
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
				/*	ÜéÌ±F~
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
			/*	___/ ®­° /___________________
			/*/
			case GIMMICK_NAME_MOVEFLOOR :
				/*/
				/*	®­°FÃ~
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
				/*	®­°Fãº
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
				/*	®­°F¶E
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
				/*	®­°F~
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
				/*	®­°F¿
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
				/*	®­°F¸è
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
				/*	®­°FÁê
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
			/*	___/ Uèq /___________________
			/*/
			case GIMMICK_NAME_PENDULUM :
				/*/
				/*	UèqF¶E
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
							// ½
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
			/*	___/ dC /___________________
			/*/
			case GIMMICK_NAME_SHOCKER :
				/*/
				/*	dCFãº
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
				/*	dCF¶E
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
				/*	Speed UpFÃ~
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
			/*	___/ ­à /___________________
			/*/
			case GIMMICK_NAME_CLOUD :
				/*/
				/*	­àFÃ~
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
/*	®­°F®«1
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
/*	®­°F®«2
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
/*	®­°F®«3
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
/*	®­°F®«4
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



