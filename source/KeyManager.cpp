/*
______________________________________________________________________________________________

	FILE	: KeyManager.cpp
	NAME	: Teacher.K

	________/ Explanation of file /___________________________________________________________
    
		KeyManagerƒNƒ‰ƒX‚ÌÀ‘••”

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/

#include <windows.h>
#include <stdio.h>

#include "KeyManager.h"


/*/
/*	ƒfƒXƒgƒ‰ƒNƒ^
/*/
KeyManager::~KeyManager( )
{
	// I—¹‚ğo—Í
	printf( "Management of a keystroke is ended.\n" ) ;
}

/*/
/*	‰Šú‰»
/*/
void KeyManager::Initialize( )
{
	// ‚Æ‚è‚ ‚¦‚¸ƒf[ƒ^“ü‚ê‚Æ‚­
	GetKeyboardState( m_bKeyTbl ) ;

	// ŠJn‚ğo—Í
	printf( "Management of a keystroke is started.\n" ) ;

}

/*/
/*	ƒL[î•ñ‚ÌXV
/*/
int KeyManager::update( )
{
	// ‚Æ‚è‚ ‚¦‚¸ƒf[ƒ^“ü‚ê‚Æ‚­
	return( GetKeyboardState( m_bKeyTbl ) ) ;
}

/*/
/*	ƒL[î•ñ‚Ìæ“¾
/*/
BYTE KeyManager::getKeyState( BYTE arg_keyCode )
{
	// “n‚³‚ê‚½ƒL[î•ñ‚ğ•Ô‚·
	return( m_bKeyTbl[ arg_keyCode ] & 0x80 ) ;
}


		
