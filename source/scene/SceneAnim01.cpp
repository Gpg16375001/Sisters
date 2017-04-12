/*
______________________________________________________________________________________________

	FILE	: SceneAnim01.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneAnim01NX

	SceneAnim01NXÌÀ


PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
#include <windows.h>
#include "SceneAnim01.h"

/*/
/*	RXgN^
/*/
SceneAnim01::SceneAnim01( )
{
	Initialize( ) ;
	printf( "Start.\n" ) ;

}

/*/
/*	fXgN^
/*/
SceneAnim01::~SceneAnim01( )
{
	printf( "End.\n" ) ;

}

/*/
/*	 ú»
/*/
void SceneAnim01::Initialize( )
{
	printf( "SceneAnim01 -> " ) ;

	/*/
	/*	___/ wi /___________________
	/*/
	BackGround::GetInstance()->setBmpData(
			0 ,
			0 ,
			-200 , -200 ,
			0 , 0 ,
			2000 , 1000 ,
			1.0f , 1.0f
		) ;

}

/*/
/*	 I¹»
/*/
void SceneAnim01::Finalize( )
{
	Initialize( ) ;
	g_state = -1 ;

	printf( "SceneAnim01 -> " ) ;

}

/*/
/*	 XV
/*/
void SceneAnim01::Update( )
{
	static int waitTime = 0 ;
	if ( KeyManager::GetInstance()->getKeyState( VK_RETURN ) && waitTime >= 120 )
	{
		g_state++ ;												// ------------------------------- Gvl
		waitTime = 0 ;
	}
	waitTime++ ;

	// V[àe
	// æÊà¾¯`bvðzu
	for ( int i = 0 ; i < Chip::GetInstance()->getMapSizeX() * Chip::GetInstance()->getMapSizeY() ; ++i )
	{
		Chip::GetInstance()->setChipMap(
				(i % Chip::GetInstance()->getMapSizeX()) ,
				(i / Chip::GetInstance()->getMapSizeX()) ,
				g_mapData01[ i ]
			) ;
	}

	// `bvÌ}bvÇÝÝ
	Chip::GetInstance()->Update( ) ;

}

/*/
/*	 `æ
/*/
void SceneAnim01::Render( )
{
	// V[àe

	/*/
	/*	wi`æ
	/*/
	BackGround::GetInstance()->setBmpData(
			1 ,
			0 ,
			(Chip::GetInstance()->getScrollX() / 4) % 856 ,
			0 ,
			0 , 0 ,
			2000 , 1000 ,
			1.0f , 1.0f
		) ;
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

	/*/
	/*	`bvwi`æ
	/*/
	for ( int i = 0 ; i < Chip::GetInstance()->getMaxBmp( ) ; ++i )
	{
		if ( Chip::GetInstance()->getUseFlg( i ) )
		{
			Renderer::GetInstance()->selectBmp(
					Chip::GetInstance()->getBmpData( i ) ,
					Chip::GetInstance()->getBmpAnchor( i ) ,
					Chip::GetInstance()->getBmpXPos( i ) ,
					Chip::GetInstance()->getBmpYPos( i ) ,
					Chip::GetInstance()->getBmpUPos( i ) ,
					Chip::GetInstance()->getBmpVPos( i ) ,
					Chip::GetInstance()->getBmpWidth( i ) ,
					Chip::GetInstance()->getBmpHeight( i ) ,
					Chip::GetInstance()->getBmpScaleX( i ) ,
					Chip::GetInstance()->getBmpScaleY( i ) ,
					Chip::GetInstance()->getBmpAlpha( i ) ,
					Chip::GetInstance()->getBmpAngle( i )
				) ;
			Renderer::GetInstance()->Render( ) ;
		}
	}

	/*/
	/*	Sprite `æ
	/*/
	for ( int i = 0 ; i < Sprite::GetInstance()->getMaxBmp( ) ; ++i )
	{
		if ( Sprite::GetInstance()->getUseFlg( i ) )
		{
			//printf( "`æ      BMPÔ F%4d \n" , i ) ;
			//printf( "§¾  true=1  F%4d \n" , Sprite::GetInstance()->getUseAlpha( i ) ) ;
			//printf( "§¾x    alpha   F%4d \n" , Sprite::GetInstance()->getBmpAlpha( i ) ) ;
			//printf( "ñ]  true=1  F%4d \n" , Sprite::GetInstance()->getUseRotate( i ) ) ;
			//printf( "ñ]px  angle   F%4.0f \n" , Sprite::GetInstance()->getBmpAngle( i ) ) ;
			Renderer::GetInstance()->selectBmp(
					Sprite::GetInstance()->getBmpData( i ) ,
					Sprite::GetInstance()->getBmpAnchor( i ) ,
					Sprite::GetInstance()->getBmpXPos( i ) ,
					Sprite::GetInstance()->getBmpYPos( i ) ,
					Sprite::GetInstance()->getBmpUPos( i ) ,
					Sprite::GetInstance()->getBmpVPos( i ) ,
					Sprite::GetInstance()->getBmpWidth( i ) ,
					Sprite::GetInstance()->getBmpHeight( i ) ,
					Sprite::GetInstance()->getBmpScaleX( i ) ,
					Sprite::GetInstance()->getBmpScaleY( i ) ,
					Sprite::GetInstance()->getBmpAlpha( i ) ,
					Sprite::GetInstance()->getBmpAngle( i )
				) ;
			Renderer::GetInstance()->Render( ) ;
		}
	}
	
	/*/
	/*	fobOp
	/*/
	HBRUSH brush_red ;
	brush_red = CreateSolidBrush( RGB(255 , 0 , 0) ) ;
	FillRect( Renderer::GetInstance()->getHDCBack() , &g_ac , brush_red ) ;
	DeleteObject( brush_red ) ;

	// æÊÌNA
	/*/
	/*	wiÌNA
	/*/
	for ( int i = 0 ; i < BackGround::GetInstance()->getMaxBmp( ) ; ++i )
	{
		BackGround::GetInstance()->clearData( i ) ;
	}

	/*/
	/*	`bvÌNA
	/*/
	for ( int i = 0 ; i < Chip::GetInstance()->getMaxBmp( ) ; ++i )
	{
		Chip::GetInstance()->clearData( i ) ;
	}

	/*/
	/*	Sprite ÌNA
	/*/
	for ( int i = 0 ; i < Sprite::GetInstance()->getMaxBmp( ) ; ++i )
	{
		Sprite::GetInstance()->clearData( i ) ;
	}


}



