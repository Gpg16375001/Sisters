
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
	printf( "MainAppのプロシージャが発行されました。\n" ) ;

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
	Renderer::GetInstance()->setHDC( GetHWindow( ) , GetHDCBack( ) , GetHDCWork() ) ;

	// Key 情報の取得 初期化
	KeyManager::GetInstance()->Initialize( ) ;

	// 画像データ庫の初期化
	BitmapData::GetInstance()->Initialize( ) ;
	BackGround::GetInstance()->Initialize( ) ;

	// 画像の読み込み
	BitmapData::GetInstance()->loadData( 0 , TEXT("data/image/bgs/bg01.bmp") , 2000 , 1000 ) ;
	BitmapData::GetInstance()->loadData( 1 , TEXT("data/image/sprites/PlayerL.bmp") , 2000 , 178 ) ;
	BitmapData::GetInstance()->loadData( 2 , TEXT("data/image/chips/grass_default.bmp") , 64 , 64 ) ;
	BitmapData::GetInstance()->loadData( 3 , TEXT("data/image/sprites/gimic/marunoko.bmp") , 256 , 256 ) ;

	// 背景読み込み
	BackGround::GetInstance()->loadBmpData( 0 , BitmapData::GetInstance()->getBmpData( 0 ) ) ;

	// シーン

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
/*	描画
/*/
void MainApp::Render_( )
{
	printf( "メイン描画\n" ) ;

	// シーン描画の配置
	for ( int i = 0 ; i < BackGround::GetInstance()->getMaxBmp( ) ; ++i )
	{
		if ( BackGround::GetInstance()->getUseFlg( i ) )
		{
			printf( "描画      BMP番号 ：%4d \n" , i ) ;
			printf( "透明処理  true=1  ：%4d \n" , BackGround::GetInstance()->getUseAlpha( i ) ) ;
			printf( "透明度    alpha   ：%4d \n" , BackGround::GetInstance()->getBmpAlpha( i ) ) ;
			printf( "回転処理  true=1  ：%4d \n" , BackGround::GetInstance()->getUseRotate( i ) ) ;
			printf( "回転角度  angle   ：%4.0f \n" , BackGround::GetInstance()->getBmpAngle( i ) ) ;
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

	// 画面のクリア
	for ( int i = 0 ; i < BackGround::GetInstance()->getMaxBmp( ) ; ++i )
	{
		BackGround::GetInstance()->clearData( i ) ;
	}

	// デバッグの表示


}



