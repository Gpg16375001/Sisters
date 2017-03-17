/*
______________________________________________________________________________________________

	FILE	: SceneManager.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneManagerÉNÉâÉX

	SceneManagerÉNÉâÉXÇÃé¿ëïïî

ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP
*/
#include <windows.h>
#include "SceneBlank.h"
#include "SceneTitle.h"

/*/
/*	 èâä˙âª
/*/
void SceneManager::Initialize( )
{
	Finalize( ) ;
	printf( "SceneManager\n" ) ;
	g_state = -1 ;						// ------------------------- Gvl
}

/*/
/*	 èIóπâª
/*/
void SceneManager::Finalize( )
{
	
}

/*/
/*	ÉfÉXÉgÉâÉNÉ^
/*/
SceneManager::~SceneManager( )
{
	Finalize( ) ;
}

/*/
/*	 çXêV
/*/
void SceneManager::Update( int arg_state )
{
	SceneBlank blank ;
	SceneTitle title ;

	// ÉVÅ[Éìì‡óe
	switch ( arg_state )
	{
		case S_Blank :
			blank.Update( ) ;
			blank.Render( ) ;
			break ;

		case S_InitTitle :
			// ÉMÉ~ÉbÉNÇÃèâä˙ÉZÉbÉg
			Gimmick::GetInstance()->Initialize( ) ;
			// ÉMÉ~ÉbÉNÇÉZÉbÉg
			Gimmick::GetInstance()->setMoveBlock( 50 , 2216 , 300 , 360 , 10 , GIMMICK_MODE_UPDOWN ) ;
			Gimmick::GetInstance()->setMoveBlock( 51 , 2408 , 300 , 360 , 10 , GIMMICK_MODE_UPDOWN ) ;
			Gimmick::GetInstance()->setMoveBlock( 52 , 2600 , 300 , 360 , 90 , GIMMICK_MODE_UPDOWN ) ;
			Gimmick::GetInstance()->setMoveBlock( 53 , 2792 , 300 , 360 , 90 , GIMMICK_MODE_UPDOWN ) ;
			Gimmick::GetInstance()->setMoveBlock( 54 , 2984 , 300 , 360 , 120 , GIMMICK_MODE_UPDOWN ) ;

			g_state++ ;
			break ;

		case S_PlayTitle :
			title.Update( ) ;
			title.Render( ) ;
			break ;

		case S_InitGame :
			break ;

		case S_PlayGame :
			break ;

	}
}



