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
#include "Renderer.h"

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
int BackDropScreen::Render( )
{

	return ( true ) ;
}


