/*
______________________________________________________________________________________________

	FILE : DrawLoop.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		DrawLoop ‚ÌÀ‘••”

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/

#include <windows.h>
#include <stdio.h>	// --- ƒRƒ“ƒ\[ƒ‹—p

#include "Common.h"

int DrawLoop( )
{
	// ƒoƒbƒNƒhƒƒbƒv–Ê‚Ì•`‰æ
	g_bScreen.draw( ) ;

	// ”wŒi‚Ì•`‰æ 
	for ( int i = 0 ; i < BMP_DATA_BG_MAX ; ++i ) {
		g_bgScreen[ i ].draw( ) ;
	}

	// ƒ`ƒbƒv‚Ì•`‰æ
	g_CBG.draw( ) ;

	// ƒXƒvƒ‰ƒCƒg 128–‡•`‰æ
	for ( int i = 0 ; i < BMP_DATA_SPR_MAX ; ++i ) {
		g_Spr[ i ].draw( ) ;
	}

	// ƒXƒvƒ‰ƒCƒg 128–‡‰Šú‰»
	for ( int i = 0 ; i < BMP_DATA_SPR_MAX ; ++i ) {
		g_Spr[ i ].clearSprite( ) ;
	}

	return( true ) ;
}



