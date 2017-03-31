/*
	マスターサンプル
*/

#include <windows.h>
#include <stdio.h>		// --- コンソール用

#include "WndProc.h"	// --- ウィンドウプロシージャ
#include "Common.h"		// --- 全ファイルでの共通ヘッダー

// --- エントリポイント
int WINAPI WinMain( HINSTANCE hCurInst, HINSTANCE hPrevInst, LPSTR lpsCmdLine, int nCmdShow )
{
	WNDCLASSEX	wc;		// --- ウィンドウクラス構造体
	HWND		hWnd;	// --- ウィンドウハンドル
	BOOL		bRet;	// --- GetMessage() の戻り値
	MSG			msg;	// --- MSG構造体
	RECT		rc;		// --- クライアント領域サイズ設定用

	// --- インスタンスハンドルをグローバル変数にコピー
	g_hInstance = hCurInst;

	// --- クライアント領域のサイズ設定
	rc.left		= 0;
	rc.right	= WINDOW_W;
	rc.top		= 0;
	rc.bottom	= WINDOW_H;
	AdjustWindowRect( &rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, FALSE );

	// --- ウィンドウクラスの定義（ウィンドウクラス構造体の初期化）
	wc.cbSize			= sizeof( WNDCLASSEX );				// --- この構造体のサイズ
	wc.style			= ( CS_HREDRAW | CS_VREDRAW );		// --- ウインドウのスタイル
	wc.lpfnWndProc		= ( WNDPROC )WndProc;				// --- メッセージ処理関数の登録
	wc.cbClsExtra		= 0;								// --- 通常は使わないので常に0
	wc.cbWndExtra		= 0;								// --- 通常は使わないので常に0
	wc.hInstance		= g_hInstance;						// --- インスタンスへのハンドル
	wc.hIcon			= NULL;								// --- アイコン（なし）
	wc.hIconSm			= NULL;								// --- 小アイコン（なし）
	wc.hCursor			= LoadCursor( NULL, IDC_ARROW );	// --- カーソルの形
	wc.hbrBackground	= ( HBRUSH )( COLOR_WINDOW + 1 );	// --- 背景なし
	wc.lpszMenuName		= NULL;								// --- メニューなし
	wc.lpszClassName	= g_szWndClass;						// --- クラス名の指定

	// --- ウィンドウクラスの登録
	if( RegisterClassEx( &wc ) == 0 ) { return ( false ); }	// --- 登録失敗 

	// --- ウィンドウの作成
	hWnd = CreateWindow
	(
		g_szWndClass,								// ウィンドウクラス名
		g_szAppTitle,								// タイトル
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,	// ウィンドウスタイル
		CW_USEDEFAULT,								// 水平位置
		CW_USEDEFAULT,								// 垂直位置
		rc.right - rc.left,							// 幅
		rc.bottom - rc.top,							// 高さ
		NULL,
		NULL,
		g_hInstance,
		NULL
	);

	if ( !hWnd ) return FALSE;

	// ウィンドウの表示
	ShowWindow( hWnd, nCmdShow );
	UpdateWindow( hWnd );

	// メッセージループ
	while( ( bRet = GetMessage( &msg, NULL, 0, 0 ) ) != 0 )
	{
		if ( bRet == -1 ) 
		{
			// WM_TIMER を使わない場合ここにFPSを測り、ゲーム処理を書く
			break;
		}
		else 
		{
			TranslateMessage( &msg );
			DispatchMessage( &msg );
		}
	}

	// --- WinMain() の戻り値
	return ( ( int )msg.wParam );
}


















