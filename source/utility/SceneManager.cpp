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
//			Gimmick::GetInstance()->setCircularSaws( 10 , PTC(70) , PTC(3) , 360 , 0 , GIMMICK_MODE_LEFTRIGHT ) ;	// ä€ãò

//			Gimmick::GetInstance()->setMoveBlocks( 50 , PTC(70) , PTC(3) , 360 , 0 , GIMMICK_MODE_LEFTRIGHT ) ;		// ìÆÇ≠è∞

			Gimmick::GetInstance()->setPendulums( 100 , PTC(70) , PTC(3) , 360 , 0 , GIMMICK_MODE_LEFTRIGHT ) ;		// êUÇËéq
			Gimmick::GetInstance()->setPendulums( 101 , PTC(76) , PTC(3) , 360 , 192 , GIMMICK_MODE_LEFTRIGHT ) ;
			Gimmick::GetInstance()->setPendulums( 102 , PTC(82) , PTC(3) , 360 , 0 , GIMMICK_MODE_LEFTRIGHT ) ;

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



