/*
______________________________________________________________________________________________

	FILE : SoundBGM.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		SoundBGM ƒNƒ‰ƒX‚ÌÀ‘••”

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/

#include <windows.h>
#include <stdio.h>	// --- ƒRƒ“ƒ\[ƒ‹—p

#include "Common.h"

// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
SoundBGM::SoundBGM( ) {		}

// ƒfƒXƒgƒ‰ƒNƒ^
SoundBGM::~SoundBGM( ) {
	// BGM‚ÌI—¹
	stop( ) ;
}

// ‰¹ŠyÄ¶
int SoundBGM::play( LPCTSTR arg_pStr ) {
	PlaySound( arg_pStr , NULL , SND_FILENAME | SND_ASYNC | SND_LOOP ) ;
	return( true ) ;
}

// ‰¹Šy’â~
int SoundBGM::stop( ) {
	PlaySound( NULL , NULL , SND_PURGE ) ;
	return( true ) ;
}



