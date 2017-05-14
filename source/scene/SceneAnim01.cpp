/*
______________________________________________________________________________________________

	FILE	: SceneAnim01.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneAnim01クラス

	SceneAnim01クラスの実装部


￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include <windows.h>
#include "SceneAnim01.h"

/*/
/*	コンストラクタ
/*/
SceneAnim01::SceneAnim01( )
{
	Initialize( ) ;
	//printf( "Start.\n" ) ;

}

/*/
/*	デストラクタ
/*/
SceneAnim01::~SceneAnim01( )
{
	//printf( "End.\n" ) ;

}

/*/
/*	 初期化
/*/
void SceneAnim01::Initialize( )
{
	//printf( "SceneAnim01 -> " ) ;

	/*/
	/*	___/ 背景 /___________________
	/*/
	BackGround::GetInstance()->setBmpData(
			0 ,
			0 ,
			-200 , -200 ,
			0 , 0 ,
			2000 , 1000 ,
			1.0f , 1.0f
		) ;

	MasterData::ReLoad( ) ;
	player_.setAnimData( 0 ) ;
	player2_.setAnimData( 1 ) ;
	waiwai_.setAnimData( 2 ) ;
	boss_.setAnimData( 3 ) ;

	// カメラの初期位置
	Chip::GetInstance()->clearScroll( ) ;

	// BGM
	g_bgm.load( 0 , TEXT("data/sound/bgm1.mp3") ) ;

}

/*/
/*	 終了化
/*/
void SceneAnim01::Finalize( )
{
	Initialize( ) ;
	g_state = -1 ;

	//printf( "SceneAnim01 -> " ) ;

}

/*/
/*	 更新
/*/
void SceneAnim01::Update( )
{
	static float old_y = 0 ;
	static bool bgm_flg = false ;
	static int waitTime = 0 ;

	if ( KeyManager::GetInstance()->getKeyState( VK_RETURN ) && waitTime >= 50 )
	{
		Initialize( ) ;

		// 開始地点の修正
		Chip::GetInstance()->clearScroll( ) ;
		Chip::GetInstance()->setScrollSize( -600 + RenderScale , 0 ) ;

		// BGM
		g_bgm.load( 0 , TEXT("data/sound/bgm2.mp3") ) ;

		g_state++ ;												// ------------------------------- Gvl
		waitTime = 0 ;
		old_y = 0 ;
		bgm_flg = false ;
	}
	waitTime++ ;

	if ( KeyManager::GetInstance()->getKeyState( VK_F5 ) )
	{
		Chip::GetInstance()->Reload( ) ;
		Chip::GetInstance()->clearScroll( ) ;
		printf( "Was ReLoading !\n" ) ;
	}

	// シーン内容
	// 画面内だけチップを配置
	for ( int i = 0 ; i < Chip::GetInstance()->getMapSizeX() * Chip::GetInstance()->getMapSizeY() ; ++i )
	{
		Chip::GetInstance()->setChipMap(
				(i % Chip::GetInstance()->getMapSizeX()) ,
				(i / Chip::GetInstance()->getMapSizeX()) ,
				g_mapData01[ i ]
			) ;
	}

	// チップのマップ読み込み
	Chip::GetInstance()->Update( ) ;

	// ギミックの読み込み
	Gimmick::GetInstance()->Update( ) ;

	/*/
	/*	アニメーションのアップデート
	/*/
	// --/ プレイヤー1 /--
	player_._playAnim( 0 ) ;
	Anim_Data *nowPlayer = player_.getNowAnimation( ) ;

	// カメラ位置をプレイヤーに合わせる
	_sx = nowPlayer->x - _sx ;
	if ( nowPlayer->x >= 300 )
	{
		Chip::GetInstance()->setScrollSize( ( int )-_sx , 0 ) ;
	}
	_sx = nowPlayer->x ;
	// もしループしたらカメラ位置を最初に戻す
	if ( nowPlayer->animMode == ANIM_MODE_LOOP )
	{
		Chip::GetInstance()->clearScroll( ) ;
	}
	// もしストップしたらつぎのステージへ
	if ( nowPlayer->animMode == ANIM_MODE_STOP )
	{
		Initialize( ) ;
		// BGM
		g_bgm.load( 0 , TEXT("data/sound/bgm2.mp3") ) ;

		Chip::GetInstance()->clearScroll( ) ;
		Chip::GetInstance()->setScrollSize( -600 + RenderScale , 0 ) ;
		g_state++ ;												// ------------------------------- Gvl
		waitTime = 0 ;
		old_y = 0 ;
		bgm_flg = false ;
	}

	Sprite::GetInstance()->setBmpData(
				nowPlayer->bmpNo ,
				7 ,
				nowPlayer->x + Chip::GetInstance()->getScrollX( ) ,
				nowPlayer->y ,
				(float)nowPlayer->cutRect.left ,
				(float)nowPlayer->cutRect.top ,
				(float)nowPlayer->cutRect.right ,
				(float)nowPlayer->cutRect.bottom ,
				1.0f , 1.0f ,
				255 ,
				0
		) ;

	// --/ プレイヤー2 /--
	player2_._playAnim( 1 ) ;
	Anim_Data *nowPlayer2 = player2_.getNowAnimation( ) ;
	Sprite::GetInstance()->setBmpData(
				nowPlayer2->bmpNo ,
				7 ,
				nowPlayer2->x + Chip::GetInstance()->getScrollX( ) ,
				nowPlayer2->y ,
				(float)nowPlayer2->cutRect.left ,
				(float)nowPlayer2->cutRect.top ,
				(float)nowPlayer2->cutRect.right ,
				(float)nowPlayer2->cutRect.bottom ,
				1.0f , 1.0f ,
				255 ,
				0
		) ;
	// プレイヤー2が連れ去られるとき
	if ( (nowPlayer2->y != old_y) && (bgm_flg) )
	{
		// BGM
		g_bgm.load( 0 , TEXT("data/sound/bgm2.mp3") ) ;
		g_sSE.play( 2 ) ;
		old_y = -1 ;
		bgm_flg = false ;
	}
	if ( old_y != -1 )
	{
		old_y = nowPlayer2->y ;
		bgm_flg = true ;
	}

	// --/ リアクション /--
	waiwai_._playAnim( 2 ) ;
	Anim_Data *nowWaiwai = waiwai_.getNowAnimation( ) ;
	Sprite::GetInstance()->setBmpData(
				nowWaiwai->bmpNo ,
				7 ,
				nowWaiwai->x + Chip::GetInstance()->getScrollX( ) ,
				nowWaiwai->y ,
				(float)nowWaiwai->cutRect.left ,
				(float)nowWaiwai->cutRect.top ,
				(float)nowWaiwai->cutRect.right ,
				(float)nowWaiwai->cutRect.bottom ,
				1.0f , 1.0f ,
				255 ,
				0
		) ;

	// --/ BOSS /--
	boss_._playAnim( 3 ) ;
	Anim_Data *nowBoss = boss_.getNowAnimation( ) ;
	Sprite::GetInstance()->setBmpData(
				nowBoss->bmpNo ,
				7 ,
				nowBoss->x + Chip::GetInstance()->getScrollX( ) ,
				nowBoss->y ,
				(float)nowBoss->cutRect.left ,
				(float)nowBoss->cutRect.top ,
				(float)nowBoss->cutRect.right ,
				(float)nowBoss->cutRect.bottom ,
				0.5f , 0.5f ,
				255 ,
				0
		) ;

}

/*/
/*	 描画
/*/
void SceneAnim01::Render( )
{
	// シーン内容

	/*/
	/*	背景描画
	/*/
	BackGround::GetInstance()->setBmpData(
			1 ,
			0 ,
			(Chip::GetInstance()->getScrollX() / 4) % 856 ,
			0 ,
			0 , 0 ,
			2000.0f , 1000.0f ,
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
	/*	チップ背景描画
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
	/*	Sprite 描画
	/*/
	for ( int i = 0 ; i < Sprite::GetInstance()->getMaxBmp( ) ; ++i )
	{
		if ( Sprite::GetInstance()->getUseFlg( i ) )
		{
			//printf( "描画      BMP番号 ：%4d \n" , i ) ;
			//printf( "透明処理  true=1  ：%4d \n" , Sprite::GetInstance()->getUseAlpha( i ) ) ;
			//printf( "透明度    alpha   ：%4d \n" , Sprite::GetInstance()->getBmpAlpha( i ) ) ;
			//printf( "回転処理  true=1  ：%4d \n" , Sprite::GetInstance()->getUseRotate( i ) ) ;
			//printf( "回転角度  angle   ：%4.0f \n" , Sprite::GetInstance()->getBmpAngle( i ) ) ;
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
	/*	Sprite のクリア
	/*/
	for ( int i = 0 ; i < Sprite::GetInstance()->getMaxBmp( ) ; ++i )
	{
		Sprite::GetInstance()->clearData( i ) ;
	}

	/*/
	/*	チップのクリア
	/*/
	for ( int i = 0 ; i < Chip::GetInstance()->getMaxBmp( ) ; ++i )
	{
		Chip::GetInstance()->clearData( i ) ;
	}

	// 画面のクリア
	/*/
	/*	背景のクリア
	/*/
	for ( int i = 0 ; i < BackGround::GetInstance()->getMaxBmp( ) ; ++i )
	{
		BackGround::GetInstance()->clearData( i ) ;
	}


}



