/*
______________________________________________________________________________________________

	FILE : BackDropScreen.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		BackDropScreen ƒNƒ‰ƒX‚ÌÀ‘••”

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/

#include <windows.h>
#include <stdio.h>	// --- ƒRƒ“ƒ\[ƒ‹—p

#include "Common.h"

// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
BackDropScreen::BackDropScreen( )
{
	m_bmpNo = NULL ;
}

// ƒfƒXƒgƒ‰ƒNƒ^
BackDropScreen::~BackDropScreen( )
{
}

// •`‰æ‚µ‚½‚¢”wŒi‚Ì”Ô†‚ğƒZƒbƒg
int BackDropScreen::selectBmp( int arg_bmpNo )
{
	m_bmpNo = arg_bmpNo ;

	return ( true ) ;
}

// ƒoƒbƒNƒhƒƒbƒv•`‰æ
int BackDropScreen::draw()
{
	SelectObject( g_hWorkBuf , g_bDataBGTable[ m_bmpNo ].getBmpData( ) ) ;

	BitBlt(
		g_hBackBuf ,
		0 ,
		0 ,
		g_bDataBGTable[ m_bmpNo ].getBmpWidth( ) ,
		g_bDataBGTable[ m_bmpNo ].getBmpHeight( ) ,
		g_hWorkBuf ,
		0 ,
		0 ,
		SRCCOPY
	) ;

	return ( true ) ;
}


