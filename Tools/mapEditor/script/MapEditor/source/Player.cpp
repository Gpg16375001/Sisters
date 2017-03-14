/*
______________________________________________________________________________________________

	FILE : Player.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		Player ƒNƒ‰ƒX‚ÌÀ‘••”

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/

#include <windows.h>
#include <stdio.h>	// --- ƒRƒ“ƒ\[ƒ‹—p
#include <math.h>

#include "Common.h"

#define FSPD	2
#define FCNT	(32 / FSPD)
#define D_UP	48 * 0
#define D_DOWN	48 * 1
#define D_LEFT	48 * 2
#define D_RIGHT	48 * 3

// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
Player::Player( ) {
	m_actionNo = ePlayerBlank ;
}

// ƒfƒXƒgƒ‰ƒNƒ^
Player::~Player( ) {	}

// ƒAƒNƒVƒ‡ƒ“
int Player::action( ) {
	static int fcnt = FCNT ;
	static bool wflg = false ;

	// ƒAƒNƒVƒ‡ƒ“‚Å•ªŠò
	switch ( m_actionNo )
	{
		// ‰Šú
		case ePlayerBlank :
			m_actionNo++ ;
			break ;

		// ƒXƒ^ƒ“ƒoƒC
		case ePlayerStandby :
			if ( g_key.getKeyState(VK_LEFT) ) {
				m_actionNo = ePlayerMoveLeft ;
			}
			if ( g_key.getKeyState(VK_RIGHT) ) {
				m_actionNo = ePlayerMoveRight ;
			}
			if ( g_key.getKeyState(VK_UP) ) {
				m_actionNo = ePlayerMoveUp ;
			}
			if ( g_key.getKeyState(VK_DOWN) ) {
				m_actionNo = ePlayerMoveDown ;
			}
			break ;

		// ¶ˆÚ“®
		case ePlayerMoveLeft :

			if ( (g_mapData01[ (g_player.m_aPoint.y * MAP_X) + (g_player.m_aPoint.x - 1) ] & 0xef) == 0 ) {
				wflg = true ;
			}

			if ( wflg ) {
				g_player.setGPoint( (g_player.m_gPoint.x - FSPD) , g_player.m_gPoint.y ) ;
			}

			fcnt-- ;
			if ( fcnt <= 0 ) {
				fcnt = FCNT ;
				wflg = false ;
				m_actionNo = ePlayerStandby ;
			}
			break ;

		// ‰EˆÚ“®
		case ePlayerMoveRight :

			if ( (g_mapData01[ (g_player.m_aPoint.y * MAP_X) + (g_player.m_aPoint.x + 1) ] & 0xef) == 0 ) {
				wflg = true ;
			}

			if ( wflg ) {
				g_player.setGPoint( (g_player.m_gPoint.x + FSPD) , g_player.m_gPoint.y ) ;
			}

			fcnt-- ;
			if ( fcnt <= 0 ) {
				fcnt = FCNT ;
				wflg = false ;
				m_actionNo = ePlayerStandby ;
			}
			break ;

		// ãˆÚ“®
		case ePlayerMoveUp :

			if ( (g_mapData01[ ((g_player.m_aPoint.y - 1) * MAP_X) + g_player.m_aPoint.x ] & 0xef) == 0 ) {
				wflg = true ;
			}

			if ( wflg ) {
				g_player.setGPoint( g_player.m_gPoint.x , (g_player.m_gPoint.y - FSPD) ) ;
			}

			fcnt-- ;
			if ( fcnt <= 0 ) {
				fcnt = FCNT ;
				wflg = false ;
				m_actionNo = ePlayerStandby ;
			}
			break ;

		// ‰ºˆÚ“®
		case ePlayerMoveDown :

			if ( (g_mapData01[ ((g_player.m_aPoint.y + 1) * MAP_X) + g_player.m_aPoint.x ] & 0xef) == 0 ) {
				wflg = true ;
			}

			if ( wflg ) {
				g_player.setGPoint( g_player.m_gPoint.x , (g_player.m_gPoint.y + FSPD) ) ;
			}

			fcnt-- ;
			if ( fcnt <= 0 ) {
				fcnt = FCNT ;
				wflg = false ;
				m_actionNo = ePlayerStandby ;
			}
			break ;

	}

	// ƒvƒŒƒCƒ„[‚ÌƒZƒbƒg
	for ( int i = 0 ; i < (MAP_X * MAP_Y) ; i++ ) {
		if ( g_mapData01[ i ] == 16 ) {
//			g_Spr[ 0 ].setSprite( 0 , g_player.m_gPoint.x , g_player.m_gPoint.y - 16 , m_cPoint.left , m_cPoint.top , m_cPoint.right , m_cPoint.bottom ) ;
		}
	}

	return( true ) ;
}

// ƒOƒ[ƒoƒ‹À•W‚ÌƒZƒbƒg
int Player::setGPoint( int arg_gX , int arg_gY ) {

	m_gPoint.x = arg_gX ;
	m_gPoint.y = arg_gY ;

	return( true ) ;
}

// ”z—ñÀ•W‚ÌƒZƒbƒg
int Player::setAPoint( int arg_aX , int arg_aY ) {

	m_aPoint.x = arg_aX ;
	m_aPoint.y = arg_aY ;

	return( true ) ;
}



