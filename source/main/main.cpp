
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
	BitmapData::GetInstance()->loadData( 0 , TEXT("data/image/bgs/bg01.bmp") , 2000 , 1000 ) ;
	BitmapData::GetInstance()->loadData( 1 , TEXT("data/image/sprites/PlayerL.bmp") , 2000 , 178 ) ;
	BitmapData::GetInstance()->loadData( 2 , TEXT("data/image/chips/grass_default.bmp") , 64 , 64 ) ;

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
	BitmapData::GetInstance()->setBmpData(
			0 ,
			0 ,
			0 , 0 ,
			0 , 0 ,
			1000 , 1000 ,
			1.0f , 1.0f
		) ;
	BitmapData::GetInstance()->setBmpData(
			1 ,
			0 ,
			0 , 200 ,
			0 , 0 ,
			2000 , 178 ,
			1.0f , 1.0f
		) ;
	BitmapData::GetInstance()->setBmpData(
			2 ,
			0 ,
			200 , 378 ,
			0 , 0 ,
			64 , 64 ,
			1.5f , 1.5f
		) ;

}

/*/
/*	描画
/*/
void MainApp::Render_( )
{
	printf( "メイン描画\n" ) ;

	// シーン描画の配置
	for ( int i = 0 ; i < BitmapData::GetInstance()->getMaxBmp( ) ; ++i )
	{
		if ( BitmapData::GetInstance()->getUseFlg( i ) )
		{
			printf( "描画：BMP番号%4d \n" , i ) ;
			Renderer::GetInstance()->selectBmp(
					BitmapData::GetInstance()->getBmpData( i ) ,
					BitmapData::GetInstance()->getBmpAnchor( i ) ,
					BitmapData::GetInstance()->getBmpXPos( i ) ,
					BitmapData::GetInstance()->getBmpYPos( i ) ,
					BitmapData::GetInstance()->getBmpUPos( i ) ,
					BitmapData::GetInstance()->getBmpVPos( i ) ,
					BitmapData::GetInstance()->getBmpWidth( i ) ,
					BitmapData::GetInstance()->getBmpHeight( i ) ,
					BitmapData::GetInstance()->getBmpScaleX( i ) ,
					BitmapData::GetInstance()->getBmpScaleY( i )
				) ;
			Renderer::GetInstance()->Render( ) ;
		}
	}

	// 画面のクリア
	for ( int i = 0 ; i < BitmapData::GetInstance()->getMaxBmp( ) ; ++i )
	{
		BitmapData::GetInstance()->clearData( i ) ;
	}

	// デバッグの表示


}



