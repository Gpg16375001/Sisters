
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
/*/
void MainApp::Initalize( )
{
	// Key 情報の取得 初期化
	KeyManager::GetInstance()->Initialize( ) ;

	// 時間の初期化
	old_time_ = timeGetTime( ) ;
	start_time_ = old_time_ ;

	/*
	// 裏画面生成
	HDC hDC = GetDC( hWnd_ ) ;
	hDCBack_ = CreateCompatibleDC( hDC ) ;
	bitmap_ = CreateCompatibleBitmap( hDC , wSize_w_ , wSize_h_ ) ;
	SelectObject( hDCBack_ , bitmap_ ) ;							// デストラクタで解放される
	ReleaseDC( hWnd_ , hDC ) ;
	*/

	static HBITMAP s_hBackBufBmp ;
	// 裏画面の作成
	HDC hDC = GetDC( hWnd_ ) ;													// 指定ウィンドウクラスのデバイスコンテキストの取得
	g_hWorkBuf = CreateCompatibleDC( hDC ) ;								// 共用のデバイスコンテキスト
	s_hBackBufBmp = CreateCompatibleBitmap( hDC , wSize_w_, wSize_h_ ) ;	// クライアント領域のビットマップを生成
	g_hBackBuf = CreateCompatibleDC( hDC ) ;								// バックバッファ用のデバイスコンテキスト
	SelectObject( g_hBackBuf , s_hBackBufBmp ) ;							// バックバッファのDCにBMPをセットする
	ReleaseDC( hWnd_ , hDC ) ;												// デバイスコンテキストの解放

	// 画像データ庫の初期化
	BitmapData::GetInstance()->Initialize( ) ;

	// 画像の読み込み
	BitmapData::GetInstance()->loadData( 0 , TEXT("data/image/bg/bg01.bmp") , 2000 , 1000 ) ;

	Renderer::GetInstance()->Initialize( ) ;
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
	Renderer::GetInstance()->selectBmp(
		BitmapData::GetInstance()->getBmpData( 0 ) ,
		BitmapData::GetInstance()->getBmpWidth( 0 ) ,
		BitmapData::GetInstance()->getBmpHeight( 0 )
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
	Renderer::GetInstance()->Render( ) ;

	// デバッグの表示


}



