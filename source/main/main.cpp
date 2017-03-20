
#include <Windows.h>
#include "main.h"
#include "Common.h"

int WINAPI WinMain( HINSTANCE , HINSTANCE , LPSTR , int )
{
	// クラス名とタイトルの設定
	MainApp app( TEXT("Sisters") , TEXT("Sisters") ) ;

	// アプリをスタート
	app.Start( ) ;

	return 0;
}


/*/
/*	コンストラクタ
/*/
MainApp::MainApp( TCHAR* szClassName , TCHAR* szTitleName )
	: WinMain( szClassName , szTitleName )
	, is_debug_render_( true )
{
	printf( "始まったよ!\n" ) ;

}

/*/
/*	デストラクタ
/*/
MainApp::~MainApp( )
{

}

/*/
/*	<-継承-> ウインドプロシージャ
/*/
LRESULT MainApp::WndProc( HWND hWnd , UINT msg , UINT wParam , LONG lParam )
{
	/*/
	/*	WinMainのプロシージャで処理をするのでここは関係ない。
	/*	WinMainのプロシージャが終わり次第呼ばれる。
	/*/
//	printf( "MainAppのプロシージャが発行されました。\n" ) ;

	return DefWindowProc( hWnd , msg , wParam , lParam ) ;
}

/*/
/*	<-継承-> 初期化
/*	WM_CREATE と同じ。( こちらの方が早い )
/*/
void MainApp::Initalize( )
{
	printf( "//-----------------------------------\n" ) ;
	printf( "Initialize が発行されました\n" );

	// 描画場所の確保
	Renderer::GetInstance()->Initialize( ) ;
	Renderer::GetInstance()->setHDC( GetHWindow( ) , GetHDCBack( ) , GetHDCWork() ) ;

	// Key 情報の取得 初期化
	KeyManager::GetInstance()->Initialize( ) ;

	// 画像データ庫の初期化
	BitmapData::GetInstance()->Initialize( ) ;
	BackGround::GetInstance()->Initialize( ) ;
	Chip::GetInstance()->Initialize( ) ;
	Sprite::GetInstance()->Initialize( ) ;

	// 画像の読み込み
	BitmapData::GetInstance()->loadData( 0 , TEXT("data/image/bgs/bg01.bmp") , 2000 , 1000 ) ;
	BitmapData::GetInstance()->loadData( 1 , TEXT("data/image/sprites/PlayerR.bmp") , 2000 , 178 ) ;
	BitmapData::GetInstance()->loadData( 2 , TEXT("data/image/chips/all_grass.bmp") , 640 , 500 ) ;
	BitmapData::GetInstance()->loadData( 3 , TEXT("data/image/sprites/gimic/marunoko.bmp") , 128 , 128 ) ;
	BitmapData::GetInstance()->loadData( 4 , TEXT("data/image/sprites/PlayerL.bmp") , 2000 , 178 ) ;
	BitmapData::GetInstance()->loadData( 5 , TEXT("data/image/sprites/gimic/movefloor.bmp") , 256 , 64 ) ;
	BitmapData::GetInstance()->loadData( 6 , TEXT("data/image/bgs/bg02.bmp") , 2000 , 1000 ) ;
	BitmapData::GetInstance()->loadData( 7 , TEXT("data/image/sprites/gimic/huriko.bmp") , 128 , 128 ) ;
	BitmapData::GetInstance()->loadData( 8 , TEXT("data/image/sprites/gimic/rope.bmp") , 512 , 512 ) ;
	BitmapData::GetInstance()->loadData( 9 , TEXT("data/image/sprites/gimic/shock.bmp") , 128 , 64 ) ;
	BitmapData::GetInstance()->loadData( 10 , TEXT("data/image/sprites/gimic/speedup.bmp") , 128 , 64 ) ;
	BitmapData::GetInstance()->loadData( 11 , TEXT("data/image/sprites/PlayerDeth.bmp") , 200 , 178 ) ;
	BitmapData::GetInstance()->loadData( 12 , TEXT("data/image/sprites/hp.bmp") , 200 , 178 ) ;
	BitmapData::GetInstance()->loadData( 13 , TEXT("data/image/sprites/gimic/cloud.bmp") , 128 , 64 ) ;
	
	// 背景読み込み
	BackGround::GetInstance()->loadBmpData( 0 , BitmapData::GetInstance()->getBmpData( 0 ) ) ;
	BackGround::GetInstance()->loadBmpData( 1 , BitmapData::GetInstance()->getBmpData( 6 ) ) ;

	// チップ読み込み
	Chip::GetInstance()->setMapSize( CHIP_MAP_SIZE_X , CHIP_MAP_SIZE_Y ) ;
	Chip::GetInstance()->RenderMapSize( 12 + 10 , 10 + 4 ) ;
	Chip::GetInstance()->loadBmpDataAll( BitmapData::GetInstance()->getBmpData( 2 ) ) ;

	// Sprite の読み込み
	Sprite::GetInstance()->loadBmpData( 0 , BitmapData::GetInstance()->getBmpData( 4 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1 , BitmapData::GetInstance()->getBmpData( 1 ) ) ;
	Sprite::GetInstance()->loadBmpData( 3 , BitmapData::GetInstance()->getBmpData( 11 ) ) ;
	Sprite::GetInstance()->loadBmpData( 4 , BitmapData::GetInstance()->getBmpData( 11 ) ) ;
	Sprite::GetInstance()->loadBmpData( 8 , BitmapData::GetInstance()->getBmpData( 12 ) ) ;
	Sprite::GetInstance()->loadBmpDataFor( 10 , BitmapData::GetInstance()->getBmpData( 3 ) , 40 ) ;		// 10 ~ 49 まで　まるのこ
	Sprite::GetInstance()->loadBmpDataFor( 50 , BitmapData::GetInstance()->getBmpData( 5 ) , 40 ) ;		// 50 ~ 89 まで　動く床
	Sprite::GetInstance()->loadBmpDataFor( 90 , BitmapData::GetInstance()->getBmpData( 8 ) , 10 ) ;		// 90 ~ 99 まで　振り子のくさり
	Sprite::GetInstance()->loadBmpDataFor( 100 , BitmapData::GetInstance()->getBmpData( 7 ) , 10 ) ;	// 100 ~ 109 まで　振り子
	Sprite::GetInstance()->loadBmpDataFor( 400 , BitmapData::GetInstance()->getBmpData( 9 ) , 50 ) ;	// 400 ~ 449 まで　電気
	Sprite::GetInstance()->loadBmpDataFor( 450 , BitmapData::GetInstance()->getBmpData( 10 ) , 10 ) ;	// 450 ~ 459 まで　SpeedUp
	Sprite::GetInstance()->loadBmpDataFor( 150 , BitmapData::GetInstance()->getBmpData( 13 ) , 20 ) ;	// 150 ~ 199 まで　雲

	// シーン
	SceneManager::GetInstance()->Initialize() ;
}

/*/
/*	<-継承-> 終了化
/*/
void MainApp::Finalize( )
{

}

/*/
/*	<-継承-> メインループ
/*/
void MainApp::Update( )
{
	printf( "//-----------------------------------\n" ) ;
	printf( "メインループ : Updateイベントが発行されました\n" );
	// キー情報更新
	KeyManager::GetInstance()->update( ) ;

	// 更新
	Update_( ) ;

	// 描画
	Render_( ) ;
}

/*/
/*	更新 ( セット )
/*/
void MainApp::Update_( )
{
	// シーンの更新
	SceneManager::GetInstance()->Update( g_state ) ;			// -------------------------------------- Gvl

}

/*/
/*	描画
/*/
void MainApp::Render_( )
{
	printf( "Main::Render_ が発行されました\n" ) ;

	// シーン描画の配置
//	SceneManager::GetInstance()->Render( ) ;

	// デバッグの表示


}



