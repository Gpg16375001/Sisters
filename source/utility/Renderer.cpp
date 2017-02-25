/*
______________________________________________________________________________________________

	FILE : Renderer.cpp

	________/ Explanation of file /___________________________________________________________

		Renderer ƒNƒ‰ƒX‚ÌÀ‘••”

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/

#include <windows.h>
#include <stdio.h>	// --- ƒRƒ“ƒ\[ƒ‹—p
// #include "Renderer.h"

#include "Common.h"

/*/
/*	ƒfƒXƒgƒ‰ƒNƒ^
/*/
Renderer::~Renderer( )
{
}

/*/
/*	‰Šú‰»
/*/
void Renderer::Initialize( )
{
	bmpData_ = NULL ;
	width_ = 0 ;
	height_ = 0 ;
}

/*/
/*	•`‰æ‚µ‚½‚¢ƒrƒbƒgƒ}ƒbƒv‚ğƒZƒbƒg
/*/
int Renderer::selectBmp( HGDIOBJ arg_bmpData , int arg_width , int arg_height )
{
	bmpData_ = arg_bmpData ;
	width_ = arg_width ;
	height_ = arg_height ;

	return ( true ) ;
}

/*/
/*	ƒoƒbƒNƒoƒbƒtƒ@‚Ö•`‰æ
/*/
int Renderer::Render( )
{
	SelectObject( g_hWorkBuf , bmpData_ ) ;

	BitBlt(
		g_hBackBuf ,
		0 ,
		0 ,
		width_ ,
		height_ ,
		g_hWorkBuf ,
		0 ,
		0 ,
		SRCCOPY
	) ;

	return ( true ) ;
}


