/*
______________________________________________________________________________________________

	FILE : ChipBackGround.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		ChipBackGround ƒNƒ‰ƒX‚ÌÀ‘••”

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/

#include <windows.h>
#include <stdio.h>	// --- ƒRƒ“ƒ\[ƒ‹—p

#include "Common.h"

// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
ChipBackGround::ChipBackGround( ) {
	// ƒCƒ“ƒXƒ^ƒ“ƒX‰»‚Ì‰Šú‰»
	m_bmpNo	= 0 ;
	m_x		= 0 ;
	m_y		= 0 ;

	clearChip( ) ;
}

// ƒfƒXƒgƒ‰ƒNƒ^
ChipBackGround::~ChipBackGround( ) {	}

// •`‰æ‚µ‚½‚¢”wŒi‚Ì”Ô†‚ğƒZƒbƒg
int ChipBackGround::selectBmp( int arg_bmpNo ) {
	m_bmpNo = arg_bmpNo ;

	return( true ) ;
}

// •`‰æŠJn’n“_‚ÌÀ•W‚ÌƒZƒbƒg
int ChipBackGround::setPos( int arg_x , int arg_y ) {
	m_x = arg_x ;
	m_y = arg_y ;
	return( true ) ;
}

// ƒ`ƒbƒv‚ÌƒZƒbƒg
int ChipBackGround::setChip( int arg_x , int arg_y , int arg_chipNo ) {
	m_chipTable[ (CHIP_X * arg_y) + arg_x ] = arg_chipNo ;
	return( true ) ;
}

// ƒ`ƒbƒvƒf[ƒ^‚Ì‚‘¬ƒRƒs[
int ChipBackGround::setFastChip( int *arg_chipData ) {
	memcpy( m_chipTable , arg_chipData , CHIP_X * CHIP_Y * sizeof(int) ) ;
	return( true ) ;
}

// ƒ`ƒbƒvƒf[ƒ^‚ÌƒNƒŠƒA[
int ChipBackGround::clearChip( ) {
	memset( m_chipTable , 0 , CHIP_X * CHIP_Y * sizeof(int) ) ;
	return( true ) ;
}

// ƒ`ƒbƒv‚Ì•`‰æ
int ChipBackGround::draw( ) {
	int i ;
	
	m_x = 32 ;
	m_y = 32 ;
	SelectObject( g_hWorkBuf , g_bDataCBGTable[ m_bmpNo ].getBmpData( ) ) ;
	for ( i = 0 ; i < ( CHIP_X * CHIP_Y ) ; i++ ) {

		if ( m_chipTable[ i ] <= 11 ) {
			TransparentBlt(
				g_hBackBuf ,
				(( (i - g_scroll) % CHIP_X ) * CHIP_W + m_x) ,
				(( i / CHIP_X ) * CHIP_H + m_y) ,
				CHIP_W ,
				CHIP_H ,
				g_hWorkBuf ,
				m_chipTable[ i ] * CHIP_W ,
				0 ,
				CHIP_W ,
				CHIP_H ,
				RGB( 0 , 255 , 0 )
			) ;
		}

		if ( m_chipTable[ i ] == 12 ) {
			TransparentBlt(
				g_hBackBuf ,
				(( (i - g_scroll) % CHIP_X ) * CHIP_W + m_x) ,
				(( i / CHIP_X ) * CHIP_H - 0) ,
				CHIP_W * 4 ,
				CHIP_H * 2 ,
				g_hWorkBuf ,
				0 ,
				CHIP_H * 1 ,
				CHIP_W * 4 ,
				CHIP_H * 2 ,
				RGB( 0 , 255 , 0 )
			) ;
		}

		if ( m_chipTable[ i ] == 13 ) {
			TransparentBlt(
				g_hBackBuf ,
				(( (i - g_scroll) % CHIP_X ) * CHIP_W + m_x) ,
				(( i / CHIP_X ) * CHIP_H - 0) ,
				CHIP_W * 4 ,
				CHIP_H * 2 ,
				g_hWorkBuf ,
				CHIP_W * 4 ,
				CHIP_H * 1 ,
				CHIP_W * 4 ,
				CHIP_H * 2 ,
				RGB( 0 , 255 , 0 )
			) ;
		}

		if ( m_chipTable[ i ] == 14 ) {
			TransparentBlt(
				g_hBackBuf ,
				(( (i - g_scroll) % CHIP_X ) * CHIP_W + m_x) ,
				(( i / CHIP_X ) * CHIP_H - 64) ,
				CHIP_W * 4 ,
				CHIP_H * 4 ,
				g_hWorkBuf ,
				0 * CHIP_W ,
				3 * CHIP_H ,
				4 * CHIP_W ,
				4 * CHIP_H ,
				RGB( 0 , 255 , 0 )
			) ;
		}

		if ( m_chipTable[ i ] == 15 ) {
			TransparentBlt(
				g_hBackBuf ,
				(( (i - g_scroll) % CHIP_X ) * CHIP_W + m_x) ,
				(( i / CHIP_X ) * CHIP_H - 64) ,
				CHIP_W * 4 ,
				CHIP_H * 4 ,
				g_hWorkBuf ,
				4 * CHIP_W ,
				3 * CHIP_H ,
				4 * CHIP_W ,
				4 * CHIP_H ,
				RGB( 0 , 255 , 0 )
			) ;

		}
	}

	return( true ) ;
}


