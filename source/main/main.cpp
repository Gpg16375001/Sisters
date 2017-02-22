
#include <Windows.h>
#include "main.h"
#include "ConsoleWindow.h"

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
	ConsoleWindow console ;

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

	return DefWindowProc( hWnd , msg , wParam , lParam ) ;
}

/*/
/*	<-継承-> 初期化
/*/
void MainApp::Initalize( )
{

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


	// 更新
	Update_( ) ;

	// 描画
	Render_( ) ;
}

/*/
/*	更新
/*/
void MainApp::Update_( )
{
	// シーンの更新

}

/*/
/*	描画
/*/
void MainApp::Render_( )
{
	// 画面のクリア

	// シーン描画の配置

	// デバッグの表示


}



