/*
______________________________________________________________________________________________

	FILE	: SceneBlank.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneBlankNX

	SceneBlankNXΜΐ

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
#include <windows.h>
#include "SceneBlank.h"

/*/
/*	RXgN^
/*/
SceneBlank::SceneBlank( )
{
	Initialize( ) ;
	printf( "Start.\n" ) ;

}

/*/
/*	fXgN^
/*/
SceneBlank::~SceneBlank( )
{
	printf( "End.\n" ) ;

}

/*/
/*	 ϊ»
/*/
void SceneBlank::Initialize( )
{
	printf( "SceneBlank -> " ) ;

}

/*/
/*	 IΉ»
/*/
void SceneBlank::Finalize( )
{
	/*/
	/*	wiΜNA
	/*/
	for ( int i = 0 ; i < BackGround::GetInstance()->getMaxBmp( ) ; ++i )
	{
		BackGround::GetInstance()->clearData( i ) ;
	}

	printf( "SceneBlank -> " ) ;

}

/*/
/*	 XV
/*/
void SceneBlank::Update( )
{
	// V[ΰe
	BackGround::GetInstance()->setBmpData(
			0 ,
			0 ,
			-200 , -200 ,
			0 , 0 ,
			2000 , 1000 ,
			1.0f , 1.0f
		) ;

	if ( KeyManager::GetInstance()->getKeyState( VK_RETURN ) )
		g_state = 0 ;												// ------------------------------- Gvl

}

/*/
/*	 `ζ
/*/
void SceneBlank::Render( )
{
	// V[ΰe

	/*/
	/*	wi`ζ
	/*/
	for ( int i = 0 ; i < BackGround::GetInstance()->getMaxBmp( ) ; ++i )
	{
		if ( BackGround::GetInstance()->getUseFlg( i ) )
		{
			Renderer::GetInstance()->selectBmp(
					BackGround::GetInstance()->getBmpData( i ) ,
					BackGround::GetInstance()->getBmpAnchor( i ) ,
					BackGround::GetInstance()->getBmpXPos( i ) ,
					BackGround::GetInstance()->getBmpYPos( i ) ,
					BackGround::GetInstance()->getBmpUPos( i ) ,
					BackGround::GetInstance()->getBmpVPos( i ) ,
					BackGround::GetInstance()->getBmpWidth( i ) ,
					BackGround::GetInstance()->getBmpHeight( i ) ,
					BackGround::GetInstance()->getBmpScaleX( i ) ,
					BackGround::GetInstance()->getBmpScaleY( i ) ,
					BackGround::GetInstance()->getBmpAlpha( i ) ,
					BackGround::GetInstance()->getBmpAngle( i )
				) ;
			Renderer::GetInstance()->Render( ) ;
		}
	}

	// ζΚΜNA
	/*/
	/*	wiΜNA
	/*/
	for ( int i = 0 ; i < BackGround::GetInstance()->getMaxBmp( ) ; ++i )
	{
		BackGround::GetInstance()->clearData( i ) ;
	}

}



