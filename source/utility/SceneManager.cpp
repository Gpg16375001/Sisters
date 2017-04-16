/*
______________________________________________________________________________________________

	FILE	: SceneManager.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneManagerƒNƒ‰ƒX

	SceneManagerƒNƒ‰ƒX‚ÌÀ‘••”

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
#include <windows.h>
#include "LoadMapData.h"
#include "SceneBlank.h"
#include "SceneTitle.h"
#include "SceneGame01.h"
#include "SceneGame02.h"
#include "SceneAnim01.h"

#define		MAP01	TEXT("data/map/mapData01.txt")
#define		MAP02	TEXT("data/map/mapData02.txt")
#define		MAP03	TEXT("data/map/mapData03.txt")

#define		SCENE_GAME01	1
#define		SCENE_GAME02	2
#define		SCENE_GAME03	3

/*/
/*	 ‰Šú‰»
/*/
void SceneManager::Initialize( )
{
	Finalize( ) ;
	printf( "SceneManager\n" ) ;
	g_state = -1 ;						// ------------------------- Gvl
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
	SceneTitle title ;
	SceneGame01 game01 ;
	SceneGame02 game02 ;
	SceneAnim01 anim01 ;

	if ( KeyManager::GetInstance()->getKeyState( VK_F5 ) )
	{
		Chip::GetInstance()->Reload( ) ;
		Gimmick::GetInstance()->Reload( ) ;
		printf( "Was ReLoading !\n" ) ;
	}

	// ƒV[ƒ““à—e
	switch ( arg_state )
	{
		case S_Blank :
			blank.Update( ) ;
			blank.Render( ) ;
			break ;

		case S_InitTitle :
			g_state++ ;
			break ;

		case S_PlayTitle :
			SceneCut::GetInstance()->fadeOut( ) ;
			title.Update( ) ;
			title.Render( ) ;
			break ;

		case S_InitAnim01 :
			// ƒtƒFƒCƒh‚ÌƒZƒbƒg
			if ( SceneCut::GetInstance()->fadeIn( ) == 1 )
			{
				// ƒ}ƒbƒv“Ç‚İ‚İ
				LoadMapData::ReLoad( MAP03 ) ;
				g_state++ ;
			}
			break ;

		case S_PlayAnim01 :
			SceneCut::GetInstance()->fadeOut( ) ;
			anim01.Update( ) ;
			anim01.Render( ) ;
			break ;

		case S_InitGame01 :
			// ƒtƒFƒCƒh‚ÌƒZƒbƒg
			if ( SceneCut::GetInstance()->fadeIn( ) == 1 )
			{
				// ƒ}ƒbƒv“Ç‚İ‚İ
				LoadMapData::ReLoad( MAP01 ) ;

				// ƒMƒ~ƒbƒN‚Ì‰ŠúƒZƒbƒg
				Gimmick::GetInstance()->Initialize( ) ;

				// ƒMƒ~ƒbƒN‚ğƒZƒbƒg
				Gimmick::GetInstance()->setGimmickData( SCENE_GAME01 ) ;
/*
				Gimmick::GetInstance()->setMoveBlocks( 50 , PTC(224) , PTC(7) ,   2 ,   0 , GIMMICK_MODE_WAVE ) ;		// “®‚­°
				Gimmick::GetInstance()->setMoveBlocks( 51 , PTC(291) , PTC(3) ,   0 ,   0 , GIMMICK_MODE_UPDOWN ) ;		// “®‚­°

				Gimmick::GetInstance()->setPendulums( 100 , PTC(298) , PTC(7) ,   0 ,   0 , GIMMICK_MODE_CYCLE ) ;		// U‚èq
				Gimmick::GetInstance()->setPendulums( 101 , PTC(307) , PTC(7) ,   0 ,1024 , GIMMICK_MODE_CYCLE ) ;		// U‚èq

				Gimmick::GetInstance()->setCircularSaws( 10 , PTC(208) , PTC(8) ,   0 , 0 , GIMMICK_MODE_LEFTRIGHT ) ;	// ŠÛ‹˜
				Gimmick::GetInstance()->setCircularSaws( 11 , PTC(218) , PTC(3) ,   0 , 0 , GIMMICK_MODE_CYCLE ) ;		// ŠÛ‹˜
				Gimmick::GetInstance()->setCircularSaws( 12 , PTC(240) , PTC(4) ,   1 , 0 , GIMMICK_MODE_WAVE ) ;		// ŠÛ‹˜

				Gimmick::GetInstance()->setClouds( 150 , PTC(232) , PTC(6) ,   0 ,   0 , GIMMICK_MODE_STAY ) ;			// ‰_
				Gimmick::GetInstance()->setClouds( 151 , PTC(235) , PTC(6) ,   0 ,  90 , GIMMICK_MODE_STAY ) ;			// ‰_
				Gimmick::GetInstance()->setClouds( 152 , PTC(238) , PTC(6) ,   0 ,  40 , GIMMICK_MODE_STAY ) ;			// ‰_
				Gimmick::GetInstance()->setClouds( 153 , PTC(242) , PTC(6) ,   0 ,  20 , GIMMICK_MODE_STAY ) ;			// ‰_
				Gimmick::GetInstance()->setClouds( 154 , PTC(246) , PTC(6) ,   0 , 130 , GIMMICK_MODE_STAY ) ;			// ‰_
				Gimmick::GetInstance()->setClouds( 155 , PTC(255) , PTC(4) ,   0 ,   0 , GIMMICK_MODE_STAY ) ;			// ‰_
				Gimmick::GetInstance()->setClouds( 156 , PTC(278) , PTC(4) ,   0 ,   0 , GIMMICK_MODE_STAY ) ;			// ‰_
				Gimmick::GetInstance()->setClouds( 157 , PTC(281) , PTC(1) ,   0 ,  90 , GIMMICK_MODE_STAY ) ;			// ‰_

				Gimmick::GetInstance()->setShockers( 400 , PTC(234) , PTC(0) , 448 ,   0 , GIMMICK_MODE_UPDOWN ) ;		// “d‹C
				Gimmick::GetInstance()->setShockers( 401 , PTC(237) , PTC(0) , 448 ,   0 , GIMMICK_MODE_UPDOWN ) ;		// “d‹C

				Gimmick::GetInstance()->setShooter( 200 , PTC(208) , PTC(3) , 1 ,   0 , GIMMICK_MODE_STAY ) ;			// “GPOD
				Gimmick::GetInstance()->setShooter( 201 , PTC(281) , PTC(6) , 1 ,   0 , GIMMICK_MODE_STAY ) ;			// “GPOD

//				Gimmick::GetInstance()->setShooter( 202 , PTC( 32) , PTC(5) , 2 ,   0 , GIMMICK_MODE_STAY ) ;			// “GPOD
*/
				g_state++ ;
			}
			break ;

		case S_PlayGame01 :
			SceneCut::GetInstance()->fadeOut( ) ;
			game01.Update( ) ;
			game01.Render( ) ;
			break ;

		case S_InitGame02 :
			// ƒtƒFƒCƒh‚ÌƒZƒbƒg
			if ( SceneCut::GetInstance()->fadeIn( ) == 1 )
			{
				// ƒ}ƒbƒv“Ç‚İ‚İ
				LoadMapData::ReLoad( MAP02 ) ;

				// ƒMƒ~ƒbƒN‚Ì‰ŠúƒZƒbƒg
				Gimmick::GetInstance()->Initialize( ) ;

				// ƒMƒ~ƒbƒN‚ğƒZƒbƒg
	//			Gimmick::GetInstance()->setCircularSaws( 10 , PTC(70) , PTC(3) , 360 , 0 , GIMMICK_MODE_LEFTRIGHT ) ;	// ŠÛ‹˜

				Gimmick::GetInstance()->setMoveBlocks( 50 , PTC(104) , PTC(3) ,   0 ,   0 , GIMMICK_MODE_CYCLE ) ;		// “®‚­°
				Gimmick::GetInstance()->setMoveBlocks( 51 , PTC(104) , PTC(3) ,   0 ,  96 , GIMMICK_MODE_CYCLE ) ;		// “®‚­°
				Gimmick::GetInstance()->setMoveBlocks( 52 , PTC(104) , PTC(3) ,   0 , 192 , GIMMICK_MODE_CYCLE ) ;		// “®‚­°
				Gimmick::GetInstance()->setMoveBlocks( 53 , PTC(104) , PTC(3) ,   0 , 288 , GIMMICK_MODE_CYCLE ) ;		// “®‚­°
				Gimmick::GetInstance()->setMoveBlocks( 54 , PTC(108) , PTC(0) , 120 ,   0 , GIMMICK_MODE_DROP ) ;		// “®‚­°
				Gimmick::GetInstance()->setMoveBlocks( 55 , PTC(108) , PTC(0) , 120 , 192 , GIMMICK_MODE_DROP ) ;		// “®‚­°
				Gimmick::GetInstance()->setMoveBlocks( 56 , PTC(110) , PTC(0) , 120 ,   0 , GIMMICK_MODE_UPPER ) ;		// “®‚­°
				Gimmick::GetInstance()->setMoveBlocks( 57 , PTC(110) , PTC(0) , 120 , 192 , GIMMICK_MODE_UPPER ) ;		// “®‚­°
				Gimmick::GetInstance()->setMoveBlocks( 58 , PTC( 89) , PTC(3) ,   1 ,   0 , GIMMICK_MODE_WAVE ) ;		// “®‚­°

				Gimmick::GetInstance()->setPendulums( 100 , PTC(70) , PTC(3) ,   0 ,   0 , GIMMICK_MODE_LEFTRIGHT ) ;	// U‚èq
				Gimmick::GetInstance()->setPendulums( 101 , PTC(76) , PTC(3) ,   0 , 256 , GIMMICK_MODE_LEFTRIGHT ) ;	// U‚èq
				Gimmick::GetInstance()->setPendulums( 102 , PTC(82) , PTC(3) ,   0 ,   0 , GIMMICK_MODE_LEFTRIGHT ) ;	// U‚èq

				Gimmick::GetInstance()->setShockers( 400 , PTC(56) , PTC(6) ,  40 ,   0 , GIMMICK_MODE_LEFTRIGHT ) ;	// “d‹C
				Gimmick::GetInstance()->setShockers( 401 , PTC(53) , PTC(6) ,  40 ,   0 , GIMMICK_MODE_LEFTRIGHT ) ;	// “d‹C
				Gimmick::GetInstance()->setShockers( 402 , PTC(50) , PTC(6) ,  40 ,   0 , GIMMICK_MODE_LEFTRIGHT ) ;	// “d‹C
				Gimmick::GetInstance()->setShockers( 403 , PTC(56) , PTC(3) , 512 ,   0 , GIMMICK_MODE_LEFTRIGHT ) ;	// “d‹C
				Gimmick::GetInstance()->setShockers( 404 , PTC(56) , PTC(3) , 512 , 192 , GIMMICK_MODE_LEFTRIGHT ) ;	// “d‹C

				Gimmick::GetInstance()->setShockers( 405 , PTC(91) , PTC(4) , 256 ,   0 , GIMMICK_MODE_UPDOWN ) ;		// “d‹C
				Gimmick::GetInstance()->setShockers( 407 , PTC(92) , PTC(4) , 256 ,   0 , GIMMICK_MODE_UPDOWN ) ;		// “d‹C

				Gimmick::GetInstance()->setSpeedUp( 450 , PTC(45) , PTC(6) ,   0 ,   0 , GIMMICK_MODE_STAY ) ;			// Speed Up

				g_state++ ;
			}
			break ;

		case S_PlayGame02 :
			SceneCut::GetInstance()->fadeOut( ) ;
			game02.Update( ) ;
			game02.Render( ) ;
			break ;

		case S_InitGame03 :	
			g_state = S_InitGame02 ;
			break ;

		case S_PlayGame03 :
			break ;

	}

	/*/
	/*	ƒV[ƒ“Ø‚è‘Ö‚¦‚ÌŠG‚ğ•`‰æ
	/*/
	for ( int i = 0 ; i < SceneCut::GetInstance()->getMaxBmp( ) ; ++i )
	{
		if ( SceneCut::GetInstance()->getUseFlg( i ) )
		{
			Renderer::GetInstance()->selectBmp(
					SceneCut::GetInstance()->getBmpData( i ) ,
					0 ,
					SceneCut::GetInstance()->getBmpXPos( i ) ,
					SceneCut::GetInstance()->getBmpYPos( i ) ,
					0 ,
					0 ,
					SceneCut::GetInstance()->getBmpWidth( i ) ,
					SceneCut::GetInstance()->getBmpHeight( i ) ,
					1.0f ,
					1.0f ,
					SceneCut::GetInstance()->getBmpAlpha( i )
				) ;
			Renderer::GetInstance()->Render( ) ;
		}
	}

}



