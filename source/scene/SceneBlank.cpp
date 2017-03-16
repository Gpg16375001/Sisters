/*
______________________________________________________________________________________________

	FILE	: SceneBlank.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneBlankƒNƒ‰ƒX

	SceneBlankƒNƒ‰ƒX‚ÌÀ‘••”

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
#include <windows.h>
#include "SceneBlank.h"

/*/
/*	ƒRƒ“ƒXƒgƒ‰ƒNƒ^
/*/
SceneBlank::SceneBlank( )
{
	Initialize( ) ;
	printf( "Start.\n" ) ;

}

/*/
/*	ƒfƒXƒgƒ‰ƒNƒ^
/*/
SceneBlank::~SceneBlank( )
{
	printf( "End.\n" ) ;

}

/*/
/*	 ‰Šú‰»
/*/
void SceneBlank::Initialize( )
{
	printf( "SceneBlank -> " ) ;

}

/*/
/*	 I—¹‰»
/*/
void SceneBlank::Finalize( )
{
	/*/
	/*	”wŒi‚ÌƒNƒŠƒA
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
	// ƒV[ƒ““à—e
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
/*	 •`‰æ
/*/
void SceneBlank::Render( )
{
	// ƒV[ƒ““à—e

	/*/
	/*	”wŒi•`‰æ
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

	// ‰æ–Ê‚ÌƒNƒŠƒA
	/*/
	/*	”wŒi‚ÌƒNƒŠƒA
	/*/
	for ( int i = 0 ; i < BackGround::GetInstance()->getMaxBmp( ) ; ++i )
	{
		BackGround::GetInstance()->clearData( i ) ;
	}

}



