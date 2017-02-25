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
	setPos( 0 , 0 ) ;
	setUV( 0 , 0 ) ;
	setWH( 0 , 0 ) ;
	setScale( 1.0f , 1.0f ) ;

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
		HGDIOBJ arg_bmpData ,						// . ‰æ‘œƒf[ƒ^
		int arg_anchor ,							 // . ƒAƒ“ƒJ[
		int arg_x , int arg_y ,						// . ”z’uÀ•W
		int arg_u , int arg_v ,						// . Ø‚èæ‚èˆÊ’u
		int arg_w , int arg_h ,						// . •‚‚³
		float arg_scaleX , float arg_scaleY			// . Šg‘å—¦
	)
{
	bmpData_ = arg_bmpData ;
	setAnchor( arg_anchor ) ;
	setPos( arg_x , arg_y ) ;
	setUV( arg_u , arg_v ) ;
	setWH( arg_w , arg_h ) ;
	setScale( arg_scaleX , arg_scaleY ) ;

	return ( true ) ;
}

/*/
/*	ƒoƒbƒNƒoƒbƒtƒ@‚Ö•`‰æ
/*/
int Renderer::Render( )
{
	SelectObject( hDCWork_ , bmpData_ ) ;

	TransparentBlt(
		hDCBack_ ,
		(int)( x_ - ((w_*scaleX_/2)*anchorX_) ) , (int)( y_ - ((h_*scaleX_/2)*anchorY_) ) ,
		(int)( w_ * scaleX_ ) , (int)( h_ * scaleY_ ) ,
		hDCWork_ ,
		u_ , v_ ,
		w_ , h_ ,
		RGB( 0 , 255 , 0 )
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

/*/
/*	Šg‘å—¦‚ÌƒZƒbƒg
/*/
int Renderer::setScale( float arg_w , float arg_h )
{
	scaleX_ = arg_w ;
	scaleY_ = arg_h ;

	return( true ) ;
}

/*/
/*	ƒAƒ“ƒJ[‚ÌƒZƒbƒg
/*/
int Renderer::setAnchor( int arg_anchor )
{
	anchorX_ = arg_anchor % 3 ;
	anchorY_ = arg_anchor / 3 ;

	return( true ) ;
}


