
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
	/*	WinMainのプロシージャで処理をするのでここは関係ない
	/*	windowが抑えられているときも回る
	/*/

	return DefWindowProc( hWnd , msg , wParam , lParam ) ;
}

/*/
/*	<-継承-> 初期化
/*	WM_CREATE と同じ。( こちらの方が早い )
/*/
void MainApp::Initalize( )
{
	// 描画場所の確保
	Renderer::GetInstance()->Initialize( ) ;
	Renderer::GetInstance()->setHDC( GetHDCBack( ) , GetHDCWork() ) ;

	// Key 情報の取得 初期化
	KeyManager::GetInstance()->Initialize( ) ;

	// 画像データ庫の初期化
	BitmapData::GetInstance()->Initialize( ) ;

	// 画像の読み込み
	BitmapData::GetInstance()->loadData( 0 , TEXT("data/image/bg/bg01.bmp") , 2000 , 1000 ) ;
	BitmapData::GetInstance()->loadData( 1 , TEXT("data/image/bg/bg01.bmp") , 2000 , 1000 ) ;
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
	printf( "メインループ\n" ) ;
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

}

/*/
/*	描画
/*/
void MainApp::Render_( )
{
	printf( "メイン描画\n" ) ;
	// 画面のクリア
	

	// シーン描画の配置
	Renderer::GetInstance()->selectBmp(
			BitmapData::GetInstance()->getBmpData( 0 ) ,
			BitmapData::GetInstance()->getBmpWidth( 0 ) ,
			BitmapData::GetInstance()->getBmpHeight( 0 )
		) ;
	Renderer::GetInstance()->setPos( 0 , 0 ) ;
	Renderer::GetInstance()->Render( ) ;

	Renderer::GetInstance()->selectBmp(
			BitmapData::GetInstance()->getBmpData( 1 ) ,
			BitmapData::GetInstance()->getBmpWidth( 1 ) ,
			BitmapData::GetInstance()->getBmpHeight( 1 )
		) ;
	Renderer::GetInstance()->setPos( 100 , 100 ) ;
	Renderer::GetInstance()->Render( ) ;

	// デバッグの表示


}



