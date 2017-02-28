/*
______________________________________________________________________________________________

	FILE	: SceneManager.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneManagerƒNƒ‰ƒX

	SceneManagerƒNƒ‰ƒX‚ÌÀ‘••”

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
#include <windows.h>
#include "SceneBlank.h"

/*/
/*	 ‰Šú‰»
/*/
void SceneManager::Initialize( )
{
	Finalize( ) ;
	printf( "SceneManager\n" ) ;
}

/*/
/*	 I—¹‰»
/*/
void SceneManager::Finalize( )
{
	
}

/*/
/*	ƒfƒXƒgƒ‰ƒNƒ^
/*/
SceneManager::~SceneManager( )
{
	Finalize( ) ;
}

/*/
/*	 XV
/*/
void SceneManager::Update( int arg_state )
{
	SceneBlank blank ;

	// ƒV[ƒ““à—e
	switch ( arg_state )
	{
		case S_Blank :
			blank.Update( ) ;
			blank.Render( ) ;
			break ;

		case S_InitTitle :
			break ;

		case S_PlayTitle :
			break ;

		case S_InitGame :
			break ;

		case S_PlayGame :
			break ;

	}
}



