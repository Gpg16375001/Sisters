/*
______________________________________________________________________________________________

	FILE	: ConsoleWindow.cpp

	________/ Explanation of file /___________________________________________________________
       
    ConsoleWindowƒNƒ‰ƒX‚ÌÀ‘••”

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/

#include <windows.h>
#include <stdio.h>	// --- ƒRƒ“ƒ\[ƒ‹—p

#include "ConsoleWindow.h"

// --- ƒRƒ“ƒXƒgƒ‰ƒNƒ^
void ConsoleWindow::Initialize( )
{
	// --- ŠÈˆÕƒfƒoƒbƒO—p‚Éprintf‚ğg‚¦‚é‚æ‚¤‚É‚·‚é
	AllocConsole( ) ;
	
	freopen_s( &m_fIn,  "CON", "r", stdin ) ;     // --- •W€“ü—Í‚ÌŠ„‚è“–‚Ä
	freopen_s( &m_fOut, "CON", "w", stdout ) ;    // --- •W€o—Í‚ÌŠ„‚è“–‚Ä


	// ŠJn‚ğo—Í
	printf( "It succeeded in starting of a console screen.\nA standard input/output can be used.\n\n" ) ;
}

// --- ƒfƒXƒgƒ‰ƒNƒ^
ConsoleWindow::~ConsoleWindow( )
{
	// --- ƒRƒ“ƒ\[ƒ‹‚Ìíœ
	fclose( m_fIn ) ;
	fclose( m_fIn ) ;
	FreeConsole( ) ;    

}
		
