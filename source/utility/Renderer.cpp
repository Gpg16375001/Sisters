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
	u_ = 0 ;
	v_ = 0 ;
	w_ = 0 ;
	h_ = 0 ;
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
int Renderer::selectBmp(
		HGDIOBJ arg_bmpData ,
		int arg_x , int arg_y ,
		int arg_u , int arg_v ,
		int arg_w , int arg_h
	)
{
	bmpData_ = arg_bmpData ;
	setPos( arg_x , arg_y ) ;
	setUV( arg_u , arg_v ) ;
	setWH( arg_w , arg_h ) ;

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
		w_ ,
		h_ ,
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

/*/
/*	Ø‚èo‚µÀ•W‚ÌƒZƒbƒg
/*/
int Renderer::setUV( int arg_u , int arg_v )
{
	u_ = arg_u ;
	v_ = arg_v ;

	return( true ) ;
}

/*/
/*	Ø‚èo‚µ•‚‚³‚ÌƒZƒbƒg
/*/
int Renderer::setWH( int arg_w , int arg_h )
{
	w_ = arg_w ;
	h_ = arg_h ;

	return( true ) ;
}



