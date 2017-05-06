/*
______________________________________________________________________________________________

	FILE	: Afterimage.cpp

	________/ Explanation of file /___________________________________________________________
       
    AfterimageƒNƒ‰ƒX

	AfterimageƒNƒ‰ƒX‚ÌÀ‘••”


PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
#include <windows.h>
#include "Common.h"

/*/
/*	ƒRƒ“ƒXƒgƒ‰ƒNƒ^
/*/
Afterimage::Afterimage( )
	: mode_( e_init )					// ‰ŠúƒAƒNƒVƒ‡ƒ“ƒ‚[ƒh
	, Afterimage_xpos_( 0.0f )			// •`‰æ‚·‚é X ƒ|ƒWƒVƒ‡ƒ“
	, Afterimage_ypos_( 0.0f )			// •`‰æ‚·‚é Y ƒ|ƒWƒVƒ‡ƒ“
	, alpha_( 255.0f )					// “§–¾“x
	, flipMag_( false )					// false : ’Êí true : ”½“]
	, create_flg_( false )
{
	Initialize( ) ;
	printf( "Afterimage -> " ) ;
	printf( "Start.\n" ) ;

}

/*/
/*	ƒfƒXƒgƒ‰ƒNƒ^
/*/
Afterimage::~Afterimage( )
{
	Initialize( ) ;
	Finalize( ) ;
	printf( "End.\n" ) ;

}

/*/
/*	 ‰Šú‰»
/*/
void Afterimage::Initialize( )
{
	Finalize( ) ;

	/*/
	/*	ƒvƒŒƒCƒ„[ ‰ŠúƒZƒbƒg
	/*/
	mode_				= e_init ;		// ‰ŠúƒAƒNƒVƒ‡ƒ“ƒ‚[ƒh
	Afterimage_xpos_	= 0.0f ;		// •`‰æ‚·‚é X ƒ|ƒWƒVƒ‡ƒ“
	Afterimage_ypos_	= 0.0f ;		// •`‰æ‚·‚é Y ƒ|ƒWƒVƒ‡ƒ“
	alpha_				= 255.0f ;		// “§–¾“x
	flipMag_			= false ;		// false : ’Êí true : ”½“]
	create_flg_			= false ;

}

/*/
/*	 I—¹‰»
/*/
void Afterimage::Finalize( )
{
	Afterimage_xpos_	= 0.0f ;
	Afterimage_ypos_	= 0.0f ;
	alpha_				= 0.0f ;
	mode_				= e_init ;
	flipMag_			= false ;		// false : ’Êí true : ”½“]
	create_flg_			= false ;

}

/*/
/*	ƒvƒŒƒCƒ„[‚ÌƒAƒNƒVƒ‡ƒ“
/*/
void Afterimage::AfterimageAction( int arg_bmpno , float arg_xpos , float arg_ypos , RECT arg_rc , bool arg_flip )
{

	// ŠeƒAƒNƒVƒ‡ƒ“‚Ö
	switch( mode_ )
	{
		// ‰ŠúƒZƒbƒg
		case e_init :
			Initialize( ) ;

			Afterimage_bmpno_ = arg_bmpno ;
			Afterimage_xpos_ = arg_xpos ;
			Afterimage_ypos_ = arg_ypos ;
			Afterimage_rc_ = arg_rc ;
			flipMag_ = arg_flip ;
			create_flg_ = true ;
			mode_ = e_anim ;
			break ;

		// c‘œ’†
		case e_anim :
			printf( "e_anim\n" ) ;
			break ;

	}

}

/*/
/*	 XV
/*/
void Afterimage::Update( )
{
	alpha_ -= 16.0f ;
	if ( alpha_ <= 0.0f )
	{
		Finalize( ) ;
		return ;
	}

	// c‘œƒAƒjƒ[ƒVƒ‡ƒ“
	Sprite::GetInstance()->setBmpData(
			Afterimage_bmpno_ ,
			7 ,
			Afterimage_xpos_  + Chip::GetInstance()->getScrollX( ),
			Afterimage_ypos_ ,
			(float)Afterimage_rc_.left ,
			(float)Afterimage_rc_.top ,
			(float)Afterimage_rc_.right ,
			(float)Afterimage_rc_.bottom ,
			1.0f , 1.0f ,
			( int )alpha_ ,
			flipMag_ * 180//Afterimage_vec_.deg
		) ;

}



