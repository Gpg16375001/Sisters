/*
______________________________________________________________________________________________

	FILE : SoundBGM.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		SoundBGM NXÌÀ

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/

#include <windows.h>
#include <stdio.h>	// --- R\[p

#include "Common.h"

// RXgN^
SoundBGM::SoundBGM( ) {		}

// fXgN^
SoundBGM::~SoundBGM( ) {
	// BGMÌI¹
	stop( ) ;
}

// ¹yÄ¶
int SoundBGM::play( LPCTSTR arg_pStr ) {
	PlaySound( arg_pStr , NULL , SND_FILENAME | SND_ASYNC | SND_LOOP ) ;
	return( true ) ;
}

// ¹yâ~
int SoundBGM::stop( ) {
	PlaySound( NULL , NULL , SND_PURGE ) ;
	return( true ) ;
}



