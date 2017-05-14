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
#include <DxLib.h>
#include "SoundBGM.h"

// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
SoundBGM::SoundBGM( ) {
	htrack_ = 0 ;
}

// ƒfƒXƒgƒ‰ƒNƒ^
SoundBGM::~SoundBGM( ) {

}

// ‰¹ŠyÄ¶
int SoundBGM::play( int arg_hSound ) {
	PlaySoundMem( htrack_ , DX_PLAYTYPE_LOOP , 1 ) ;
	return( true ) ;
}

// ‰¹Šy“Ç‚İ‚İ
int SoundBGM::load( int arg_hSound , const TCHAR* arg_fileName ) {
	StopSoundMem( htrack_ ) ;
	htrack_ = LoadSoundMem( arg_fileName ) ;
	play( htrack_ ) ;
	return( true ) ;
}



