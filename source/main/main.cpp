
#include <Windows.h>
#include "main.h"
#include "ConsoleWindow.h"
#include "BitmapData.h"
#include "BackDropScreen.h"
#include "Renderer.h"

ConsoleWindow console ;

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
	printf( "MainApp のプロシージャ\n" ) ;

	return DefWindowProc( hWnd , msg , wParam , lParam ) ;
}

/*/
/*	<-継承-> 初期化
/*/
void MainApp::Initalize( )
{
	// 画像の読み込み
	Renderer::GetInstance()->setHWindow( GetHWindow( ) ) ;
	Renderer::GetInstance()->setHDC( GetBackHDC( ) ) ;

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
	// キー情報更新
	printf( "メインループ\n" ) ;

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
	Renderer::GetInstance()->setRender( 
		(HBITMAP)LoadImage( NULL , TEXT("C:/work/Sisters/data/image/bg/bg01.bmp") , IMAGE_BITMAP , 0 , 0 , LR_LOADFROMFILE ) ,
		0 ,
		0 , 0 ,
		0 , 0 ,
		1000 , 1000
		) ;

}

/*/
/*	描画
/*/
void MainApp::Render_( )
{
	printf( "メイン描画\n" ) ;
	// 画面のクリア


	// シーン描画の配置
	Renderer::GetInstance()->draw( ) ;

	// デバッグの表示


}



