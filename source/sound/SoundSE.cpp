/*
______________________________________________________________________________________________

	FILE : SoundSE.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		SoundSE ƒNƒ‰ƒX‚ÌÀ‘••”

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/

#include <windows.h>
#include <stdio.h>	// --- ƒRƒ“ƒ\[ƒ‹—p

#include "SoundSE.h"

// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
SoundSE::SoundSE( ) {		}

// ƒfƒXƒgƒ‰ƒNƒ^
SoundSE::~SoundSE( ) {
	// SE‚ÌI—¹
	stop( ) ;
}

// ‰¹ŠyÄ¶
int SoundSE::play( LPCTSTR arg_pStr , HWND arg_hWindow ) {
	stop( ) ;
	mciSendString( arg_pStr , NULL , 0 , NULL ) ;
	mciSendString( TEXT( "play se notify" ) , NULL , 0 , arg_hWindow ) ;
	return( true ) ;
}

// ‰¹Šy’â~
int SoundSE::stop( ) {
	mciSendString( TEXT( "stop se" ) , NULL , 0 , NULL ) ;
	mciSendString( TEXT( "close se" ) , NULL , 0 , NULL ) ;
	return( true ) ;
}



