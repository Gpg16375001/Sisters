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
	// ƒXƒvƒ‰ƒCƒg 1–‡•`‰æ
	g_Spr[ 0 ].draw( ) ;

	// ƒ`ƒbƒv‚Ì•`‰æ
	g_CBG.draw( ) ;

	/*/
	/*	brush‚½‚¿
	/*/
	// ƒOƒŠƒbƒh
	SelectObject( g_hBackBuf , g_redPen ) ;
	for ( int x = 0 ; x < 64 ; x++ ) {
		MoveToEx( g_hBackBuf , (x * 16) , 0 , 0 ) ;
		LineTo( g_hBackBuf , (x * 16) , WINDOW_H ) ;
	}
	for ( int y = 0 ; y < 64 ; y++ ) {
		MoveToEx( g_hBackBuf , 0, (y * 16) , 0 ) ;
		LineTo( g_hBackBuf , WINDOW_W , (y * 16) ) ;
	}
	//				Left		Top			Right		Bottom
	RECT rc2 = { cell( 0 ) , cell( 0 ) , cell( 2 ) , cell( 38 ) }  ;
	FillRect( g_hBackBuf , &rc2 , g_brush[ 0 ] );

	RECT rc3 = { cell( 0 ) , cell( 0 ) , cell( 50 ) , cell( 2 ) }  ;
	FillRect( g_hBackBuf , &rc3 , g_brush[ 0 ] );

	RECT rc4 = { cell( 0 ) , cell( 26 ) , cell( 50 ) , cell( 38 ) }  ;
	FillRect( g_hBackBuf , &rc4 , g_brush[ 0 ] );

	RECT rc5 = { cell( 48 ) , cell( 0 ) , cell( 50 ) , cell( 38 ) }  ;
	FillRect( g_hBackBuf , &rc5 , g_brush[ 0 ] );

	// ƒXƒvƒ‰ƒCƒg 128–‡•`‰æ
	for ( int i = 1 ; i < BMP_DATA_SPR_MAX ; ++i ) {
		g_Spr[ i ].draw( ) ;
	}

	// ƒXƒvƒ‰ƒCƒg 128–‡‰Šú‰»
	for ( int i = 0 ; i < BMP_DATA_SPR_MAX ; ++i ) {
		g_Spr[ i ].clearSprite( ) ;
	}

	return( true ) ;
}



