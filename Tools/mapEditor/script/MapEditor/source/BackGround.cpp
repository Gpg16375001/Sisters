/*
______________________________________________________________________________________________

	FILE : BackGround.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		BackGround ƒNƒ‰ƒX‚ÌÀ‘••”

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/

#include <windows.h>
#include <stdio.h>	// --- ƒRƒ“ƒ\[ƒ‹—p

#include "Common.h"

// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
BackGround::BackGround( )
{
	m_bmpNo = NULL ;
	m_x = 0 ;
	m_y = 0 ;
}

// ƒfƒXƒgƒ‰ƒNƒ^
BackGround::~BackGround( )
{
}

// •`‰æ‚µ‚½‚¢ X² ‚ğƒZƒbƒg
int BackGround::setX( int arg_x )
{
	m_x = arg_x ;

	return ( true ) ;
}

// •`‰æ‚µ‚½‚¢ Y² ‚ğƒZƒbƒg
int BackGround::setY( int arg_y )
{
	m_y = arg_y ;

	return ( true ) ;
}

// •`‰æ‚µ‚½‚¢”wŒi‚Ì”Ô†‚ğƒZƒbƒg
int BackGround::selectBmp( int arg_bmpNo )
{
	m_bmpNo = arg_bmpNo ;

	return ( true ) ;
}

// ƒoƒbƒNƒOƒ‰ƒEƒ“ƒh•`‰æ
int BackGround::draw()
{
	SelectObject( g_hWorkBuf , g_bDataBGTable[ m_bmpNo ].getBmpData( ) ) ;

	BitBlt(
		g_hBackBuf ,
		m_x ,
		m_y ,
		g_bDataBGTable[ m_bmpNo ].getBmpWidth( ) ,
		g_bDataBGTable[ m_bmpNo ].getBmpHeight( ) ,
		g_hWorkBuf ,
		0 ,
		0 ,
		SRCCOPY
	) ;

	return ( true ) ;
}


