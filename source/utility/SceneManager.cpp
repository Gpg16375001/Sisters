/*
______________________________________________________________________________________________

	FILE	: SceneManager.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneManagerクラス

	SceneManagerクラスの実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include <windows.h>
#include "LoadMapData.h"
#include "SceneBlank.h"
#include "SceneTitle.h"
#include "SceneGame01.h"
#include "SceneGame02.h"
#include "SceneGame03.h"
#include "SceneAnim01.h"

#define		MAP01	TEXT("data/map/mapData01.txt")
#define		MAP02	TEXT("data/map/mapData02.txt")
#define		MAP03	TEXT("data/map/mapData03.txt")
#define		MAP04	TEXT("data/map/mapData04.txt")

#define		SCENE_ANIM01	0
#define		SCENE_GAME01	1
#define		SCENE_GAME02	2
#define		SCENE_GAME03	3

/*/
/*	 初期化
/*/
void SceneManager::Initialize( )
{
	Finalize( ) ;
	printf( "SceneManager\n" ) ;
	g_state = -1 ;						// ------------------------- Gvl
}

/*/
/*	 終了化
/*/
void SceneManager::Finalize( )
{
	
}

/*/
/*	デストラクタ
/*/
SceneManager::~SceneManager( )
{
	Finalize( ) ;
}

/*/
/*	 更新
/*/
void SceneManager::Update( int arg_state )
{
	SceneBlank blank ;
	SceneTitle title ;
	SceneGame01 game01 ;
	SceneGame02 game02 ;
	SceneGame03 game03 ;
	static SceneAnim01 anim01 ;

	// シーン内容
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
			// フェイドのセット
			if ( SceneCut::GetInstance()->fadeIn( ) == 1 )
			{
				// マップ読み込み
				LoadMapData::ReLoad( MAP04 ) ;

				// ギミックの初期セット
				Gimmick::GetInstance()->Initialize( ) ;

				// ギミックをセット
				Gimmick::GetInstance()->setGimmickData( SCENE_ANIM01 ) ;

				g_state++ ;
			}
			break ;

		case S_PlayAnim01 :
			SceneCut::GetInstance()->fadeOut( ) ;
			anim01.Update( ) ;
			anim01.Render( ) ;
			break ;

		case S_InitGame01 :
			// フェイドのセット
			if ( SceneCut::GetInstance()->fadeIn( ) == 1 )
			{
				// マップ読み込み
				LoadMapData::ReLoad( MAP01 ) ;

				// ギミックの初期セット
				Gimmick::GetInstance()->Initialize( ) ;

				// ギミックをセット
				Gimmick::GetInstance()->setGimmickData( SCENE_GAME01 ) ;

				g_state++ ;
			}
			break ;

		case S_PlayGame01 :
			SceneCut::GetInstance()->fadeOut( ) ;
			game01.Update( ) ;
			game01.Render( ) ;
			break ;

		case S_InitGame02 :
			// フェイドのセット
			if ( SceneCut::GetInstance()->fadeIn( ) == 1 )
			{
				// マップ読み込み
				LoadMapData::ReLoad( MAP02 ) ;

				// ギミックの初期セット
				Gimmick::GetInstance()->Initialize( ) ;

				// ギミックをセット
				Gimmick::GetInstance()->setGimmickData( SCENE_GAME02 ) ;

				// ギミックをセット
	//			Gimmick::GetInstance()->setCircularSaws( 10 , PTC(70) , PTC(3) , 360 , 0 , GIMMICK_MODE_LEFTRIGHT ) ;	// 丸鋸
/*
				Gimmick::GetInstance()->setMoveBlocks( 50 , PTC(104) , PTC(3) ,   0 ,   0 , GIMMICK_MODE_CYCLE ) ;		// 動く床
				Gimmick::GetInstance()->setMoveBlocks( 51 , PTC(104) , PTC(3) ,   0 ,  96 , GIMMICK_MODE_CYCLE ) ;		// 動く床
				Gimmick::GetInstance()->setMoveBlocks( 52 , PTC(104) , PTC(3) ,   0 , 192 , GIMMICK_MODE_CYCLE ) ;		// 動く床
				Gimmick::GetInstance()->setMoveBlocks( 53 , PTC(104) , PTC(3) ,   0 , 288 , GIMMICK_MODE_CYCLE ) ;		// 動く床
				Gimmick::GetInstance()->setMoveBlocks( 54 , PTC(108) , PTC(0) , 120 ,   0 , GIMMICK_MODE_DROP ) ;		// 動く床
				Gimmick::GetInstance()->setMoveBlocks( 55 , PTC(108) , PTC(0) , 120 , 192 , GIMMICK_MODE_DROP ) ;		// 動く床
				Gimmick::GetInstance()->setMoveBlocks( 56 , PTC(110) , PTC(0) , 120 ,   0 , GIMMICK_MODE_UPPER ) ;		// 動く床
				Gimmick::GetInstance()->setMoveBlocks( 57 , PTC(110) , PTC(0) , 120 , 192 , GIMMICK_MODE_UPPER ) ;		// 動く床
				Gimmick::GetInstance()->setMoveBlocks( 58 , PTC( 89) , PTC(3) ,   1 ,   0 , GIMMICK_MODE_WAVE ) ;		// 動く床

				Gimmick::GetInstance()->setPendulums( 100 , PTC(70) , PTC(3) ,   0 ,   0 , GIMMICK_MODE_LEFTRIGHT ) ;	// 振り子
				Gimmick::GetInstance()->setPendulums( 101 , PTC(76) , PTC(3) ,   0 , 256 , GIMMICK_MODE_LEFTRIGHT ) ;	// 振り子
				Gimmick::GetInstance()->setPendulums( 102 , PTC(82) , PTC(3) ,   0 ,   0 , GIMMICK_MODE_LEFTRIGHT ) ;	// 振り子

				Gimmick::GetInstance()->setShockers( 400 , PTC(56) , PTC(6) ,  40 ,   0 , GIMMICK_MODE_LEFTRIGHT ) ;	// 電気
				Gimmick::GetInstance()->setShockers( 401 , PTC(53) , PTC(6) ,  40 ,   0 , GIMMICK_MODE_LEFTRIGHT ) ;	// 電気
				Gimmick::GetInstance()->setShockers( 402 , PTC(50) , PTC(6) ,  40 ,   0 , GIMMICK_MODE_LEFTRIGHT ) ;	// 電気
				Gimmick::GetInstance()->setShockers( 403 , PTC(56) , PTC(3) , 512 ,   0 , GIMMICK_MODE_LEFTRIGHT ) ;	// 電気
				Gimmick::GetInstance()->setShockers( 404 , PTC(56) , PTC(3) , 512 , 192 , GIMMICK_MODE_LEFTRIGHT ) ;	// 電気

				Gimmick::GetInstance()->setShockers( 405 , PTC(91) , PTC(4) , 256 ,   0 , GIMMICK_MODE_UPDOWN ) ;		// 電気
				Gimmick::GetInstance()->setShockers( 407 , PTC(92) , PTC(4) , 256 ,   0 , GIMMICK_MODE_UPDOWN ) ;		// 電気

				Gimmick::GetInstance()->setSpeedUp( 450 , PTC(45) , PTC(6) ,   0 ,   0 , GIMMICK_MODE_STAY ) ;			// Speed Up
*/
				g_state++ ;
			}
			break ;

		case S_PlayGame02 :
			SceneCut::GetInstance()->fadeOut( ) ;
			game02.Update( ) ;
			game02.Render( ) ;
			break ;

		case S_InitGame03 :
			// フェイドのセット
			if ( SceneCut::GetInstance()->fadeIn( ) == 1 )
			{
				// マップ読み込み
				LoadMapData::ReLoad( MAP03 ) ;

				// ギミックの初期セット
				Gimmick::GetInstance()->Initialize( ) ;

				// ギミックをセット
				Gimmick::GetInstance()->setGimmickData( SCENE_GAME03 ) ;

				g_state++ ;
			}
			break ;

		case S_PlayGame03 :
			SceneCut::GetInstance()->fadeOut( ) ;
			game03.Update( ) ;
			game03.Render( ) ;
			break ;

	}

	/*/
	/*	シーン切り替え時の絵を描画
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



