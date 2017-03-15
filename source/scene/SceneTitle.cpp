/*
______________________________________________________________________________________________

	FILE	: SceneTitle.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneTitleNX

	SceneTitleNXΜΐ


PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
#include <windows.h>
#include "SceneTitle.h"

/*/
/*	RXgN^
/*/
SceneTitle::SceneTitle( )
{
	Initialize( ) ;
	printf( "Start.\n" ) ;

}

/*/
/*	fXgN^
/*/
SceneTitle::~SceneTitle( )
{
	Initialize( ) ;
	printf( "End.\n" ) ;

}

/*/
/*	 ϊ»
/*/
void SceneTitle::Initialize( )
{
	printf( "SceneTitle -> " ) ;

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
/*	 XV
/*/
void SceneTitle::Update( )
{
	static Player player ;
		
	if ( KeyManager::GetInstance()->getKeyState( VK_F2 ) )
	{
		player.Finalize( ) ;
		player.Initialize( ) ;
		g_state = -1 ;
	}

	// V[ΰe
	// ζΚΰΎ―`bvπzu
	for ( int i = 0 ; i < Chip::GetInstance()->getMapSizeX() * Chip::GetInstance()->getMapSizeY() ; ++i )
	{
		Chip::GetInstance()->setChipMap(
				(i % Chip::GetInstance()->getMapSizeX()) ,
				(i / Chip::GetInstance()->getMapSizeX()) ,
				g_mapData01[ i ]
			) ;
	}

	// `bvΜ}bvΗέέ
	Chip::GetInstance()->Update( ) ;
	
	// vC[ΜAbvf[g
	player.Update( ) ;

}

/*/
/*	 `ζ
/*/
void SceneTitle::Render( )
{
	// V[ΰe

	/*/
	/*	wi`ζ
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
	/*	`bvwi`ζ
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
	/*	Sprite `ζ
	/*/
	for ( int i = 0 ; i < Sprite::GetInstance()->getMaxBmp( ) ; ++i )
	{
		if ( Sprite::GetInstance()->getUseFlg( i ) )
		{
			//printf( "`ζ      BMPΤ F%4d \n" , i ) ;
			//printf( "§Ύ  true=1  F%4d \n" , Sprite::GetInstance()->getUseAlpha( i ) ) ;
			//printf( "§Ύx    alpha   F%4d \n" , Sprite::GetInstance()->getBmpAlpha( i ) ) ;
			//printf( "ρ]  true=1  F%4d \n" , Sprite::GetInstance()->getUseRotate( i ) ) ;
			//printf( "ρ]px  angle   F%4.0f \n" , Sprite::GetInstance()->getBmpAngle( i ) ) ;
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


	// ζΚΜNA
	/*/
	/*	wiΜNA
	/*/
	for ( int i = 0 ; i < BackGround::GetInstance()->getMaxBmp( ) ; ++i )
	{
		BackGround::GetInstance()->clearData( i ) ;
	}

	/*/
	/*	`bvΜNA
	/*/
	for ( int i = 0 ; i < Chip::GetInstance()->getMaxBmp( ) ; ++i )
	{
		Chip::GetInstance()->clearData( i ) ;
	}

	/*/
	/*	Sprite ΜNA
	/*/
	for ( int i = 0 ; i < Sprite::GetInstance()->getMaxBmp( ) ; ++i )
	{
		Sprite::GetInstance()->clearData( i ) ;
	}


}



