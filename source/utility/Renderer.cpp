/*
______________________________________________________________________________________________

	FILE : Renderer.cpp

	________/ Explanation of file /___________________________________________________________

		Renderer ƒNƒ‰ƒX‚ÌÀ‘••”

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/

#include <windows.h>
#include <stdio.h>	// --- ƒRƒ“ƒ\[ƒ‹—p
#include "Renderer.h"

/*/
/*	ƒfƒXƒgƒ‰ƒNƒ^
/*/
Renderer::~Renderer( )
{
	// — ‰æ–Ê‚Åg‚Á‚½‚à‚Ì‚ğÁ‚·
	if ( hDCBack_ != NULL )
	{
		DeleteDC( hDCBack_ ) ;
	}

	if ( hDCWork_ != NULL )
	{
		DeleteDC( hDCWork_ ) ;
	}

}

/*/
/*	‰Šú‰»
/*/
void Renderer::Initialize( )
{
	bmpData_ = NULL ;
	x_ = 0 ;
	y_ = 0 ;
	width_ = 0 ;
	height_ = 0 ;
}

/*/
/*	— ‰æ–Ê‚Ì•`‰æ‚É•K—v‚È‚à‚Ì‚ğ‚à‚ç‚¤
/*/
int Renderer::setHDC( HDC arg_hDCBack , HDC arg_hDCWork )
{
	hDCBack_ = arg_hDCBack ;
	hDCWork_ = arg_hDCWork ;

	return( true ) ;
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
	SelectObject( hDCWork_ , bmpData_ ) ;

	BitBlt(
		hDCBack_ ,
		x_ ,
		y_ ,
		width_ ,
		height_ ,
		hDCWork_ ,
		0 ,
		0 ,
		SRCCOPY
	) ;

	return ( true ) ;
}


/*/
/*	X² ‚Æ  Y² ‚ğƒZƒbƒg
/*/
int Renderer::setPos( int arg_x , int arg_y )
{
	x_ = arg_x ;
	y_ = arg_y ;

	return( true ) ;
}


