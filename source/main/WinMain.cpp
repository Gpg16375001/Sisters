
#include "WinMain.h"
#include "ConsoleWindow.h"

/*/
/*	コンストラクタ
/*/
WinMain::WinMain( TCHAR* arg_szClassName , TCHAR* arg_szTitleName )
	: wPos_x_	( 32 )
	, wPos_y_	( 32 )
	, wSize_w_	( 800 )
	, wSize_h_	( 600 )
	, hWnd_		( NULL )
	, bitmap_	( NULL )
	, hDCBack_	( NULL )
{
	// 時間の精度を上げる
	timeBeginPeriod( 1 ) ;

	//	ウィンドウクラス名とウィンドウタイトルを入れる	
	lstrcpy( szClassName_ , arg_szClassName ) ;
	lstrcpy( szTitleName_ , arg_szTitleName ) ;

	// インスタンスを受け取る
	hInst_ = GetModuleHandle( NULL ) ;								// NULL を指定すると、呼び出し側プロセスの作成に使われたファイルのハンドルが返る　( https://msdn.microsoft.com/ja-jp/library/cc429129.aspx )

	/* ____ ウィンドウクラス構造体の定義 ____ */
	wc_.cbSize = sizeof( WNDCLASSEX ) ;
	wc_.style = ( CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS ) ;
	wc_.lpfnWndProc = ( WNDPROC ) WndProc_ ;						// 静的メンバ関数の WndProc_( ) を渡す	( 後に動的な方が来る )
	wc_.cbClsExtra = 0 ;
	wc_.cbWndExtra = 0 ;
	wc_.hInstance = hInst_ ;
	wc_.hIcon = LoadIcon( NULL , IDI_APPLICATION ) ;
	wc_.hCursor = LoadCursor( NULL , IDC_ARROW ) ;
	wc_.hbrBackground = ( HBRUSH )( COLOR_WINDOW + 1 ) ;			// バックドロップの色
	wc_.lpszMenuName = NULL ;
	wc_.lpszClassName = szClassName_ ;								// ウィンドウクラスの名前
	wc_.hIconSm = LoadIcon( NULL , IDI_APPLICATION ) ;

}

/*/
/*	デストラクタ
/*/
WinMain::~WinMain( )
{
	// 裏画面で使ったものを消す
	if ( bitmap_ != NULL )
	{
		DeleteObject( bitmap_ ) ;
	}

	if ( hDCBack_ != NULL )
	{
		DeleteDC( hDCBack_ ) ;
	}

	// 時間の精度を戻す
	timeEndPeriod( 1 ) ;

}

/*/
/*	ウィンドウの座標変更
/*/
void WinMain::SetWindowPos( int arg_x , int arg_y )
{
	wPos_x_ = arg_x ;
	wPos_y_ = arg_y ;
	if ( hWnd_ != NULL )
	{
		// ウィンドウの位置の変更
		MoveWindow( hWnd_ , wPos_x_ , wPos_y_ , wSize_w_ , wSize_h_ , TRUE ) ;
	}
}

/*/
/*	ウィンドウのサイズ変更
/*/
void WinMain::SetWindowSize( int arg_w , int arg_h )
{
	wSize_w_ = arg_w ;
	wSize_h_ = arg_h ;
	if ( hWnd_ != NULL )
	{
		// クライアントサイズをもらう ( SIZE型で帰ってくる )
		SIZE size = GetClientSize_( wSize_w_, wSize_h_ ) ;
		MoveWindow( hWnd_ , wPos_x_ , wPos_y_ , size.cx , size.cy , TRUE ) ;
	}
}

/*/
/*	開始
/*/
bool WinMain::Start( )
{
	// ウィンドウクラス登録
	RegisterClassEx ( &wc_ ) ;

	// ウィンドウの作成
	SIZE size = GetClientSize_( wSize_w_ , wSize_h_ ) ;
	hWnd_ = CreateWindow(
		szClassName_ ,												// ウィンドウクラス名
		szTitleName_ ,												// キャプション文字列
		( WS_OVERLAPPEDWINDOW ) ,									// ウィンドウスタイル
		wPos_x_ ,													// 水平座標の位置
		wPos_y_ ,													// 垂直座標の位置
		size.cx ,													// 幅
		size.cy ,													// 高さ
		NULL ,														// 親ウィンドウ
		NULL ,														// ウィンドウメニュー
		hInst_ ,													// インスタンスハンドル
		this ) ;													// WM_CREATEへ情報を渡す ( 自身のハンドルを送る )
	printf( "ウィンドウ作成完了!\n" ) ;

	if ( hWnd_ == NULL )
	{
		return( FALSE ) ;
	}

	/* ____ ウィンドウを表示 ____ */
	ShowWindow ( hWnd_ , SW_SHOWNORMAL ) ;
	UpdateWindow ( hWnd_ ) ;
	
	// 時間の初期化
	old_time_ = timeGetTime( ) ;
	start_time_ = old_time_ ;

	// 裏画面生成
	HDC hDC = GetDC( hWnd_ ) ;
	hDCBack_ = CreateCompatibleDC( hDC ) ;
	bitmap_ = CreateCompatibleBitmap( hDC , wSize_w_ , wSize_h_ ) ;
	SelectObject( hDCBack_ , bitmap_ ) ;							// デストラクタで解放される
	ReleaseDC( hWnd_ , hDC ) ;

	// 初期化の呼び出し ( 画像やサウンドセットなど )
	Initalize( ) ;

	/* ____ メッセージチェックループ ____ */
	while ( true )
	{
		MSG	msg ;												// メッセージ構造体
		if ( PeekMessage( &msg , 0 , 0 , 0 , PM_REMOVE ) )
		{
			if ( msg.message == WM_QUIT )
			{
				break ;
			}
			TranslateMessage ( &msg ) ;
			DispatchMessage ( &msg ) ;

		} else {
			// 継承先のメインループの呼び出し
			Update( ) ;

			// 再描画呼び出し
			InvalidateRect( hWnd_ , NULL , FALSE ) ;

		}
	}

	// 終了化の呼び出し
	Finalize( ) ;

	return( true ) ;

}

/*/
/*	ウィンドプロシージャー
/*/
LRESULT CALLBACK WinMain::WndProc_( HWND arg_hWnd , UINT arg_msg , UINT arg_wParam , LONG arg_lParam )
{
	WinMain* winm = reinterpret_cast<WinMain*>( GetWindowLong(arg_hWnd , GWL_USERDATA) ) ;
	switch ( arg_msg ) {

		// WinMainをクラス化するために格納したインスタンスハンドルをGWL_USERDATA内から取り出している
		case WM_CREATE :
			LPCREATESTRUCT data ;
			data = reinterpret_cast<LPCREATESTRUCT>( arg_lParam ) ;
			winm = reinterpret_cast<WinMain*>( data->lpCreateParams ) ;
			SetWindowLong( arg_hWnd , GWL_USERDATA , reinterpret_cast<long>(winm) ) ;
			break;

		case WM_DESTROY :
			PostQuitMessage( 0 ) ;
			return 0;

		case WM_PAINT :
			if ( winm != nullptr )
			{
				// 描画を行う
				winm->Draw_( ) ;
			}
			break;

	}

	// 何かしら命令があった時
	if ( winm != nullptr )
	{
		return winm->WndProc( arg_hWnd , arg_msg , arg_wParam , arg_lParam ) ;
	}
	// 何もなかった時　処理を勝手にやる
	return( DefWindowProc(arg_hWnd , arg_msg , arg_wParam , arg_lParam) ) ;

}

/*/
/*	クライアントサイズの取得
/*/
SIZE WinMain::GetClientSize_( int arg_w , int arg_h )
{
	RECT		rc ;												// クライアント領域サイズ設定用

	/* ___ クライアント領域のサイズ設定 ___ */
	rc.left		= 0 ;
	rc.right	= arg_w ;
	rc.top		= 0 ;
	rc.bottom	= arg_h ;
	AdjustWindowRect( &rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, FALSE ) ;

	SIZE size = {
		rc.right - rc.left ,
		rc.bottom - rc.top ,
	} ;

	return( size ) ;
}

/*/
/*	描画処理
/*/
void WinMain::Draw_( )
{
	printf( "<- Draw ! ->\n" ) ;

	PAINTSTRUCT ps ;
	HDC hDC = BeginPaint( hWnd_ , &ps ) ;

	//printf( "WM_PAINTイベントが発行されました\n" );
	BitBlt( hDC , 0 , 0 , wSize_w_ , wSize_h_ , hDCBack_ , 0 , 0 , SRCCOPY ) ;

	EndPaint( hWnd_ , &ps );

}


