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
SoundSE::SoundSE( ) {
	for ( int i = 0 ; i < 8 ; ++i )
	{
		htrack_[ i ] = 0 ;
	}
}

// ƒfƒXƒgƒ‰ƒNƒ^
SoundSE::~SoundSE( ) {

}

// ‰¹ŠyÄ¶
int SoundSE::play( int arg_hSound ) {
	PlaySoundMem( htrack_[ arg_hSound ] , DX_PLAYTYPE_BACK , 0 ) ;
	return( true ) ;
}

// ‰¹Šy“Ç‚İ‚İ
int SoundSE::load( int arg_hSound , const TCHAR* arg_fileName ) {
	htrack_[ arg_hSound ] = LoadSoundMem( arg_fileName ) ;
	return( true ) ;
}



