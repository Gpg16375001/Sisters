/*
______________________________________________________________________________________________

	FILE : BackDropScreen.cpp

	________/ Explanation of file /___________________________________________________________

		BackDropScreen ƒNƒ‰ƒX‚ÌÀ‘••”

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/

#include <windows.h>
#include <stdio.h>	// --- ƒRƒ“ƒ\[ƒ‹—p
#include "BackDropScreen.h"
#include "WinMain.h"

// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
BackDropScreen::BackDropScreen( )
{
	bmpNo_ = NULL ;
}

// ƒfƒXƒgƒ‰ƒNƒ^
BackDropScreen::~BackDropScreen( )
{
}

// •`‰æ‚µ‚½‚¢”wŒi‚Ì”Ô†‚ğƒZƒbƒg
int BackDropScreen::selectBmp( int arg_bmpNo )
{
	bmpNo_ = arg_bmpNo ;

	return ( true ) ;
}

// ƒoƒbƒNƒhƒƒbƒv•`‰æ
int BackDropScreen::draw()
{
/*
	SelectObject( hWork , bDataBGTable_[ bmpNo_ ].getBmpData( ) ) ;

	BitBlt(
		hDCBack_ ,
		0 ,
		0 ,
		bDataBGTable_[ bmpNo_ ].getBmpWidth( ) ,
		bDataBGTable_[ bmpNo_ ].getBmpHeight( ) ,
		g_hWorkBuf ,
		0 ,
		0 ,
		SRCCOPY
	) ;
*/
	return ( true ) ;
}


