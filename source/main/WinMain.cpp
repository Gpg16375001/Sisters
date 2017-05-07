
#include "WinMain.h"
#include "Common.h"

bool *WinMain::fpsp_ = NULL ;

/*/
/*	コンストラクタ
/*/
WinMain::WinMain( TCHAR* arg_szClassName , TCHAR* arg_szTitleName )
	: wPos_x_		( 32 )
	, wPos_y_		( 32 )
	, wSize_w_		( 800 )
	, wSize_h_		( 640 )
	, hWnd_			( NULL )
	, hDCBackBmp_	( NULL )
	, hDCBack_		( NULL )
{
	// 時間の精度を上げる
	timeBeginPeriod( 1 ) ;
	fps_  = true ;

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
	if ( hDCBackBmp_ != NULL )
	{
		DeleteObject( hDCBackBmp_ ) ;
	}

	if ( hDCBack_ != NULL )
	{
		DeleteDC( hDCBack_ ) ;
	}

	if ( hDCWork_ != NULL )
	{
		DeleteDC( hDCWork_ ) ;
	}

	// 時間の精度を戻す
	timeKillEvent( timerID_ ) ;
	timeEndPeriod( 1 ) ;
	DeleteObject( TimerProc ) ;

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
/*	表示が可能かどうかをセット
/*/
void WinMain::SetFpsFlg( bool arg_fpsFlg )
{
	*fpsp_ = arg_fpsFlg ;
}

/*/
/*	開始
/*/
bool WinMain::Start( )
{
	// コンソールの初期化
	ConsoleWindow::GetInstance()->Initialize( ) ;

	// ウィンドウクラス登録
	RegisterClassEx ( &wc_ ) ;

	// ウィンドウの作成
	SIZE size = GetClientSize_( wSize_w_ , wSize_h_ ) ;
	hWnd_ = CreateWindow(
		szClassName_ ,												// ウィンドウクラス名
		szTitleName_ ,												// キャプション文字列
		( WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU ) ,				// ウィンドウスタイル
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

	// 裏画面の作成
	HDC hDC = GetDC( hWnd_ ) ;											// 指定ウィンドウクラスのデバイスコンテキストの取得
	hDCWork_ = CreateCompatibleDC( hDC ) ;								// 共用のデバイスコンテキスト
	hDCBackBmp_ = CreateCompatibleBitmap( hDC , wSize_w_, wSize_h_ ) ;	// クライアント領域のビットマップを生成
	hDCBack_ = CreateCompatibleDC( hDC ) ;								// バックバッファ用のデバイスコンテキスト
	SelectObject( hDCBack_ , hDCBackBmp_ ) ;							// バックバッファのDCにBMPをセットする
	ReleaseDC( hWnd_ , hDC ) ;											// デバイスコンテキストの解放

	// 初期化の呼び出し ( 画像やサウンドセットなど )
	Initalize( ) ;

	/* ____ メッセージチェックループ ____ */
	while ( true )
	{
		MSG	msg ;														// メッセージ構造体
		if ( PeekMessage( &msg , 0 , 0 , 0 , PM_REMOVE ) )
		{
			if ( msg.message == WM_QUIT )
			{
				break ;
			}
			TranslateMessage ( &msg ) ;
			DispatchMessage ( &msg ) ;

		} else {
			if ( fps_ )
			{
				fps_ = false ;

				// 継承先のメインループの呼び出し
				Update( ) ;

				// 再描画呼び出し
				InvalidateRect( hWnd_ , NULL , FALSE ) ;

			}

		}
	}

	// 終了化の呼び出し
	Finalize( ) ;

	return( true ) ;

}

/*/
/*	____/ WinMainのウィンドプロシージャー /______________
/*
/*	MainApp ですべての処理が終了したらやってくる
/*	MainAppのプロシージャより前に呼ばれる
/*/
LRESULT CALLBACK WinMain::WndProc_( HWND arg_hWnd , UINT arg_msg , UINT arg_wParam , LONG arg_lParam )
{
//	printf( "WinMainのプロシージャが発行されました。\n" ) ;

	WinMain* winm = reinterpret_cast<WinMain*>( GetWindowLong(arg_hWnd , GWL_USERDATA) ) ;
	switch ( arg_msg ) {

		// WinMainをクラス化するために格納したインスタンスハンドルをGWL_USERDATA内から取り出している
		case WM_CREATE :
			LPCREATESTRUCT data ;
			data = reinterpret_cast<LPCREATESTRUCT>( arg_lParam ) ;
			winm = reinterpret_cast<WinMain*>( data->lpCreateParams ) ;
			SetWindowLong( arg_hWnd , GWL_USERDATA , reinterpret_cast<long>(winm) ) ;

			winm->fpsp_ = &winm->fps_ ;
			winm->timerID_ = timeSetEvent( (1000 / 60) , 1 , TimerProc , NULL , TIME_PERIODIC ) ;
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

		case MM_MCINOTIFY :
			if ( arg_wParam == MCI_NOTIFY_SUCCESSFUL ) {
				printf( "SE再生終了\n" ) ;
				g_sSE[ use_se ].stop( ) ;
			}
			break ;

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
/*	タイムプロシージャ
/*/
void CALLBACK WinMain::TimerProc( UINT arg_ID , UINT arg_Msg , DWORD arg_User , DWORD arg_dw1 , DWORD arg_dw2 )
{
	SetFpsFlg( true ) ;
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
	AdjustWindowRect( &rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, FALSE );

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
	PAINTSTRUCT ps ;
	HDC hDC = BeginPaint( hWnd_ , &ps ) ;

	//printf( "WM_PAINTイベントが発行されました\n" );
	BitBlt( hDC , 0 , 0 , wSize_w_ , wSize_h_ , hDCBack_ , 0 , 0 , SRCCOPY ) ;

	EndPaint( hWnd_ , &ps );

}


