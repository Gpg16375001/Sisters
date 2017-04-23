/*
________________________________________________________________________________________________________________

	FILE : Enemy.cpp

	________/ Explanation of file /___________________________________________________________

		Gimmick ÉNÉâÉXÇÃ Enemy é¿ëïïî

ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP
*/
#include "Renderer.h"
#include "Gimmick.h"
#include "Chip.h"
#include "Sprite.h"
#include "KeyManager.h"

/*/
/*	Enemy ÇÃÉfÅ[É^ÇÉZÉbÉg
/*/
int Gimmick::setEnemy( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int arg_mode )
{
	GimmickData_[ GimmickNo_ ]._Gimmick	= GIMMICK_NAME_ENEMY ;
	GimmickData_[ GimmickNo_ ]._bmpNo	= arg_bmpNo ;
	GimmickData_[ GimmickNo_ ]._x		= arg_x ;
	GimmickData_[ GimmickNo_ ]._y		= arg_y ;
	GimmickData_[ GimmickNo_ ]._spd		= arg_spd ;
	GimmickData_[ GimmickNo_ ]._delay	= arg_delay ;
	GimmickData_[ GimmickNo_ ]._mode	= arg_mode ;
	GimmickData_[ GimmickNo_ ]._off[ 2 ]= arg_spd ;
	
	AnimationData Enemy_anim[ ] = {
		{ arg_bmpNo , 8 , {90 * 0 , 0 , 90 , 80} , ANIM_MODE_NEXT } ,
		{ arg_bmpNo , 8 , {90 * 1 , 0 , 90 , 80} , ANIM_MODE_NEXT } ,
		{ arg_bmpNo , 8 , {90 * 2 , 0 , 90 , 80} , ANIM_MODE_NEXT } ,
		{ arg_bmpNo , 8 , {90 * 3 , 0 , 90 , 80} , ANIM_MODE_LOOP } ,
	} ;
	memcpy( &GimmickData_[ GimmickNo_ ]._gAnim_01 , Enemy_anim , 4 * sizeof( AnimationData ) ) ;

	GimmickData_[ GimmickNo_ ]._gAnim.setAnimData( GimmickData_[ GimmickNo_ ]._gAnim_01 ) ;

	GimmickNo_++ ;
	return( true ) ;

}

/*/
/*	Enemy Update
/*/
void Gimmick::Enemy( )
{
	for ( int g = 0 ; g < MAX_GIMMICK_NO ; ++g )
	{
		/*/
		/*	___/ Enemy /___________________
		/*/
		if ( GimmickData_[ g ]._Gimmick == GIMMICK_NAME_ENEMY )
		{
			/*/
			/*	EnemyÅFí èÌ
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
						GimmickData_[ g ]._y += 9.81f / 60 ;
						//float fcheck = FootCheck() ;
						//if ( fcheck != 0 )
						//{
						//	GimmickData_[ g ]._y = fcheck ;
						//}

						GimmickData_[ g ]._gAnim.playAnim( ) ;
						AnimationData *nowAnim ;
						nowAnim = GimmickData_[ g ]._gAnim.getNowAnim( ) ;
						Sprite::GetInstance()->setBmpData(
								nowAnim->bmpNo ,
								0 ,
								GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
								GimmickData_[ g ]._y + Chip::GetInstance()->getScrollY( ) ,
								(float)nowAnim->cutRect.left ,
								(float)nowAnim->cutRect.top ,
								(float)nowAnim->cutRect.right ,
								(float)nowAnim->cutRect.bottom ,
								1.0f , 1.0f ,
								255 ,
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

/*/
/*	ë´å≥É`ÉFÉbÉN
/*	ë´å≥ÇÃç¿ïWÇï‘Ç∑
/*/
float Gimmick::FootCheck( )
{

	float footY = 0.0f ;
	float px = 0.0f , py = 0.0f ;
	float pl = 0.0f , pr = 0.0f ;
	float bl = 0.0f , br = 0.0f , bt = 0.0f , bb = 0.0f ;

	// Ç†ÇΩÇËîªíËÇÇ∆ÇÈÇΩÇﬂÇÃÉ`ÉbÉvÉfÅ[É^
	int *chipTable = Chip::GetInstance()->getChipTable( ) ;

	for ( int g = 0 ; g < MAX_GIMMICK_NO ; ++g )
	{
		//  false : ç∂å¸Ç´
		px = GimmickData_[ g ]._x - Chip::GetInstance()->getScrollX() + 8 ;
		pl = GimmickData_[ g ]._x - Chip::GetInstance()->getScrollX() - 12 ;
		pr = GimmickData_[ g ]._x - Chip::GetInstance()->getScrollX() + 16 ;
		py = GimmickData_[ g ]._y ;

		// îªíËÇÇ∆ÇÈîÕàÕÅ@ç°ÇÕëSëÃ
		for( int i = 0 ; i < (CHIP_X * CHIP_Y) ; ++i )
		{
			// âΩÇ©èÓïÒÇ™ì¸Ç¡ÇƒÇ¢ÇÈÇ∆Ç´
			if ( chipTable[ i ] != NULL )
			{
				bl = ( float )( (i % CHIP_X) * CHIP_W ) - RenderScale ;
				br = ( float )( (i % CHIP_X) * CHIP_W + CHIP_W ) - RenderScale ;
				bt = ( float )( (i / CHIP_X) * CHIP_H - 64 ) + Chip::GetInstance()->getScrollY( ) ;
				bb = ( float )( (i / CHIP_X) * CHIP_H - 64 + CHIP_H ) + Chip::GetInstance()->getScrollY( ) ;

				switch ( chipTable[ i ] )
				{
					// í èÌÉuÉçÉbÉNÇÃèÍçá
					case 1 :
					case 9 :
						if ( (bt <= py) && (py < bb) )
						{
							if ( (bl <= pr) && (pl <= br) )
							{
								footY = bt ;

								//printf( "chipTable = %d : x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// é©ï™ÇÃç¿ïWà íuÇÃî‘çÜ
								//printf( "footY = %8.4f \n" , footY ) ;		// blockÇÃç¿ïWà íu

							}
						}
						break ;

					case 3 :
					case 5 :
						if ( (bt <= py) && (py < bb) )
						{
							if ( (bl <= px) && (px <= br) )
							{
								footY = bt-1 ;
								footY = bt ;
							}
						}
						break ;

					case 7 :
					case 10 :
						Vector2D_compo P1 , P3 ;
						Vector2D_compo P2 ;		// äÓèÄì_ (br,bb)
						Vector2D_compo P4 ;		// ÉvÉåÉCÉÑÅ[ÇÃç¿ïW
						float s1 , s2 ;			// ñ êœ
						float cross[ 2 ] ;		// åì_
						float ax , ay ;
						float P2a ;				// åì_Ç‹Ç≈ÇÃãóó£
						float P2p ;				// ÉvÉåÉCÉÑÅ[Ç‹Ç≈ÇÃãóó£

						// ÇªÇÍÇºÇÍÇ…ë„ì¸
						P1.x = bl - 64 ;
						P1.y = bb + 64 ;
						P2.x = br + 64 ;
						P2.y = bb + 64 ;
						P3.x = br + 64 ;
						P3.y = bt - 64 ;
						P4.x = px ;
						P4.y = py ;

						// ÇªÇÍÇºÇÍÇÃñ êœÇãÅÇﬂÇÈ
						s1 = ((P4.x - P2.x) * (P1.y - P2.y) - (P4.y - P2.y) * (P1.x - P2.x)) * 0.5f ;
						s2 = ((P4.x - P2.x) * (P2.y - P3.y) - (P4.y - P2.y) * (P2.x - P3.x)) * 0.5f ;

						// î‰ó¶Ç©ÇÁåì_ÇãÅÇﬂÇÈ
						cross[ 0 ] = P1.x + (P3.x - P1.x) * s1 / (s1 + s2) ;
						cross[ 1 ] = P1.y + (P3.y - P1.y) * s1 / (s1 + s2) ;

						// äÓèÄì_Ç©ÇÁåì_Ç‹Ç≈ÇÃãóó£
						ax = P2.x - cross[ 0 ] ;
						ay = P2.y - cross[ 1 ] ;
						P2a = ax * ax + ay * ay ;
						P2a = sqrt( P2a ) ;

						// äÓèÄì_Ç©ÇÁÉvÉåÉCÉÑÅ[Ç‹Ç≈ÇÃãóó£
						ax = P2.x - P4.x ;
						ay = P2.y - P4.y ;
						P2p = ax * ax + ay * ay ;
						P2p = sqrt( P2a ) ;

						if ( (P2p <= P2a) && (bl - 32 <= px) && (px <= br+12) && (bt-14 <= py) )
						{
							footY = cross[ 1 ] ;

						}
						break  ;

					case 4 :
					case 6 :
						if ( (bt <= py) && (py < bb) )
						{
							if ( (bl <= px) && (px <= br) )
							{
								footY = bt - 1 ;

								//printf( "chipTable = %d : x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// é©ï™ÇÃç¿ïWà íuÇÃî‘çÜ
								//printf( "footY = %8.4f \n" , footY ) ;		// blockÇÃç¿ïWà íu

							}
						}
						break ;

					case 8 :
					case 11 :
						// ÇªÇÍÇºÇÍÇ…ë„ì¸
						P1.x = br + 64 ;
						P1.y = bb + 64 ;
						P2.x = bl - 64 ;
						P2.y = bb + 64 ;
						P3.x = bl - 64 ;
						P3.y = bt - 64 ;
						P4.x = px ;
						P4.y = py ;

						// ÇªÇÍÇºÇÍÇÃñ êœÇãÅÇﬂÇÈ
						s1 = ((P4.x - P2.x) * (P1.y - P2.y) - (P4.y - P2.y) * (P1.x - P2.x)) * 0.5f ;
						s2 = ((P4.x - P2.x) * (P2.y - P3.y) - (P4.y - P2.y) * (P2.x - P3.x)) * 0.5f ;

						// åì_ÇãÅÇﬂÇÈ
						cross[ 0 ] = P1.x + (P3.x - P1.x) * s1 / (s1 + s2) ;
						cross[ 1 ] = P1.y + (P3.y - P1.y) * s1 / (s1 + s2) ;

						// äÓèÄì_Ç©ÇÁåì_Ç‹Ç≈ÇÃãóó£
						ax = P2.x - cross[ 0 ] ;
						ay = P2.y - cross[ 1 ] ;
						P2a = ax * ax + ay * ay ;
						P2a = sqrt( P2a ) ;

						// äÓèÄì_Ç©ÇÁÉvÉåÉCÉÑÅ[Ç‹Ç≈ÇÃãóó£
						ax = P2.x - P4.x ;
						ay = P2.y - P4.y ;
						P2p = ax * ax + ay * ay ;
						P2p = sqrt( P2a ) ;

						if ( (P2p <= P2a) && (bl - 4 <= px) && (px <= br+32) && (bt-14 <= py) )
						{
							footY = cross[ 1 ] ;

						}
						break ;

					case 12 :
						// ÇªÇÍÇºÇÍÇ…ë„ì¸
						P1.x = bl - 64 ;
						P1.y = bb + 32 ;
						P2.x = br + 192 + 4 ;
						P2.y = bb + 32 ;
						P3.x = br + 192 + 4 ;
						P3.y = bt - 64 ;
						P4.x = px ;
						P4.y = py ;

						// ÇªÇÍÇºÇÍÇÃñ êœÇãÅÇﬂÇÈ
						s1 = ((P4.x - P2.x) * (P1.y - P2.y) - (P4.y - P2.y) * (P1.x - P2.x)) * 0.5f ;
						s2 = ((P4.x - P2.x) * (P2.y - P3.y) - (P4.y - P2.y) * (P2.x - P3.x)) * 0.5f ;

						// î‰ó¶Ç©ÇÁåì_ÇãÅÇﬂÇÈ
						cross[ 0 ] = P1.x + (P3.x - P1.x) * s1 / (s1 + s2) ;
						cross[ 1 ] = P1.y + (P3.y - P1.y) * s1 / (s1 + s2) ;

						// äÓèÄì_Ç©ÇÁåì_Ç‹Ç≈ÇÃãóó£
						ax = P2.x - cross[ 0 ] ;
						ay = P2.y - cross[ 1 ] ;
						P2a = ax * ax + ay * ay ;
						P2a = sqrt( P2a ) ;

						// äÓèÄì_Ç©ÇÁÉvÉåÉCÉÑÅ[Ç‹Ç≈ÇÃãóó£
						ax = P2.x - P4.x ;
						ay = P2.y - P4.y ;
						P2p = ax * ax + ay * ay ;
						P2p = sqrt( P2a ) ;

						if ( (P2p <= P2a) && (bl - 64 <= px) && (px <= br + 196) && (bt-64 <= py) )
						{
							footY = cross[ 1 ] ;

						}
						break  ;

					case 13 :
						// ÇªÇÍÇºÇÍÇ…ë„ì¸
						P1.x = bl + 192 + 96 ;
						P1.y = bb + 16 ;
						P2.x = br + 32 ;
						P2.y = bb + 16 ;
						P3.x = br + 32 ;
						P3.y = bt - 16 ;
						P4.x = px ;
						P4.y = py ;

						// ÇªÇÍÇºÇÍÇÃñ êœÇãÅÇﬂÇÈ
						s1 = ((P4.x - P2.x) * (P1.y - P2.y) - (P4.y - P2.y) * (P1.x - P2.x)) * 0.5f ;
						s2 = ((P4.x - P2.x) * (P2.y - P3.y) - (P4.y - P2.y) * (P2.x - P3.x)) * 0.5f ;

						// î‰ó¶Ç©ÇÁåì_ÇãÅÇﬂÇÈ
						cross[ 0 ] = P1.x + (P3.x - P1.x) * s1 / (s1 + s2) ;
						cross[ 1 ] = P1.y + (P3.y - P1.y) * s1 / (s1 + s2) ;

						// äÓèÄì_Ç©ÇÁåì_Ç‹Ç≈ÇÃãóó£
						ax = P2.x - cross[ 0 ] ;
						ay = P2.y - cross[ 1 ] ;
						P2a = ax * ax + ay * ay ;
						P2a = sqrt( P2a ) ;

						// äÓèÄì_Ç©ÇÁÉvÉåÉCÉÑÅ[Ç‹Ç≈ÇÃãóó£
						ax = P2.x - P4.x ;
						ay = P2.y - P4.y ;
						P2p = ax * ax + ay * ay ;
						P2p = sqrt( P2a ) ;

						if ( (P2p <= P2a) && (bl - 0 <= px) && (px <= br + 260) && (bt-64 <= py) )
						{
							footY = cross[ 1 ] ;

						}
						break  ;

					default :
						break ;

				}
			}
		}

	}
	return( footY ) ;

}

