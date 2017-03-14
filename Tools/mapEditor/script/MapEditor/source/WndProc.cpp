/*
	ウィンドウプロシージャ
*/

#include <windows.h>
#include <stdio.h>	// --- コンソール用

#include "Common.h"	// --- 全ファイルでの共通ヘッダー

LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	HDC					hDC;			// ディスプレイデバイスコンテキスト
	PAINTSTRUCT			ps;				// 描画構造体
	static HBITMAP s_hBackBufBmp ;		// バックバッファ
	TCHAR s[512] ;						// デバッグ用

	static 	int mouseX , mouseY ;
	static 	int arrayX , arrayY ;
	static 	int index ;
	static	bool dragF = false ;


	// --- メッセージで分岐
	switch ( message )
	{
		/* -------------------------
		|		WM_CREATE
		+ ----------------------- */
		case WM_CREATE:
			printf( "WM_CREATEイベントが発行されました\n" );

			// --- ウィンドウハンドルのコピー
			g_hWindow = hWnd;

			// --- フレーム単位でタイマーイベントを発生させる
			SetTimer( g_hWindow, 1, GAME_FRAME, NULL );

			// 裏画面の作成
			hDC = GetDC( hWnd ) ;													// 指定ウィンドウクラスのデバイスコンテキストの取得
			g_hWorkBuf = CreateCompatibleDC( hDC ) ;								// 共用のデバイスコンテキスト
			s_hBackBufBmp = CreateCompatibleBitmap( hDC , WINDOW_W , WINDOW_H ) ;	// クライアント領域のビットマップを生成
			g_hBackBuf = CreateCompatibleDC( hDC ) ;								// バックバッファ用のデバイスコンテキスト
			SelectObject( g_hBackBuf , s_hBackBufBmp ) ;							// バックバッファのDCにBMPをセットする
			ReleaseDC( hWnd , hDC ) ;												// デバイスコンテキストの解放

			// 画像の読み込み
			g_bDataBGTable[ 0 ].loadData( TEXT("source/cg/background01.bmp") , WINDOW_W , WINDOW_H ) ;
			g_bDataBGTable[ 1 ].loadData( TEXT("source/cg/neko.bmp") , WINDOW_W , WINDOW_H ) ;
			g_bDataBGTable[ 2 ].loadData( TEXT("source/cg/background02.bmp") , WINDOW_W , WINDOW_H ) ;
			g_bDataBGTable[ 3 ].loadData( TEXT("source/cg/background03.bmp") , WINDOW_W , WINDOW_H ) ;

			// スプライトの読み込み
			g_bDataSprTable[ 0 ].loadData( TEXT("source/cg/Player.bmp") , 256 , 256 ) ;
			g_bDataSprTable[ 1 ].loadData( TEXT("source/cg/Test.bmp") , 64 , 64 ) ;
			g_bDataSprTable[ 2 ].loadData( TEXT("source/cg/Test.bmp") , 64 , 64 ) ;
			g_bDataSprTable[ 3 ].loadData( TEXT("source/cg/Test.bmp") , 64 , 64 ) ;

			// 画像のセット
			g_bScreen.selectBmp( 0 ) ;
			g_bgScreen[ 0 ].selectBmp( 2 ) ;
			g_bgScreen[ 1 ].selectBmp( 3 ) ;
			g_bgScreen[ 2 ].selectBmp( 1 ) ;

			// チップのセット
			g_bDataCBGTable[ 0 ].loadData( TEXT("source/cg/Block.bmp") , 32 , 256 ) ;

			// BGMのセット
			g_sBGM.play( BGM_FILE_PASS_01 ) ;
			
			// アニメーションの初期セット
			enum AnimName {
				A_STANDBY ,
			} ;

			break;

		/* -------------------------
		|		WM_TIMER
		+ ----------------------- */
		case WM_TIMER:
			//printf( "WM_TIMERイベントが発行されました\n" );
			g_key.update( );	// --- キー情報の更新

			// --------------
			SceneLoop( ) ;
			DrawLoop( ) ;

			// --------------

			// --- 再描画の要求
			InvalidateRect( hWnd, NULL, FALSE );
			break;

		case MM_MCINOTIFY :
			if ( wParam == MCI_NOTIFY_SUCCESSFUL ) {
				printf( "SE再生終了\n" ) ;
				g_sSE.stop( ) ;
			}
			break ;

		/* -------------------------
		|		WM_LBUTTONDOWN
		+ ----------------------- */
		case WM_LBUTTONDOWN :
			// ドラッグフラグを立てる
			dragF = true ;

			// マウスのクリック座標の取得
			mouseX = LOWORD( lParam ) ;
			mouseY = HIWORD( lParam ) ;

			// クリック座標を配列座標に直す
			arrayX = (mouseX - 738 / 2) / (CHIP_X / 2) ;
			arrayY = (mouseY - 64 / 2) / (CHIP_Y / 2) ;

			// 配列座標を一次元座標に直す
			index = arrayY * MAP_X + arrayX ;

			if ( (index <= (MAP_X * MAP_Y))					// 要素数が配列のサイズ内で収まっていたら
					&& (MAP_X >= arrayX) && (arrayX >= 0)	// 横幅が座標内
					&& (MAP_Y >= arrayY) && (arrayY >= 0)	// 
				)
			{
				// 配列内の値を判定
				if ( g_mapData01[ index ] == 0 ) {
					// ブロックを表す値を代入
					g_mapData01[ index ] = 1 ;
					printf( "X = %4d , Y = %4d  Set Chip\n" , arrayX , arrayY ) ;

				} else {
					// ブロックを消す
					g_mapData01[ index ] = 0 ;
					printf( "X = %4d , Y = %4d  Delete Chip\n" , arrayX , arrayY ) ;
				}
			}
			break ;

		/* -------------------------
		|		WM_LBUTTONUP
		+ ----------------------- */
		case WM_LBUTTONUP :
			dragF = false ;
			break ;

		case WM_MOUSEMOVE :
			if ( dragF ) {
				// マウスのクリック座標の取得
				mouseX = LOWORD( lParam ) ;
				mouseY = HIWORD( lParam ) ;

				// クリック座標を配列座標に直す
				arrayX = mouseX / CHIP_X ;
				arrayY = mouseY / CHIP_Y ;

				// 配列座標を一次元座標に直す
				index = arrayY * MAP_X + arrayX ;

				// 要素数が配列のサイズ内で収まっていたら
				if ( index <= (MAP_X * MAP_Y) ) {
					// 配列内の値を判定
					if ( g_mapData01[ index ] == 0 ) {
						// ブロックを表す値を代入
						g_mapData01[ index ] = 1 ;
						printf( "X = %4d , Y = %4d  Set Chip\n" , arrayX , arrayY ) ;
					}
				} 
			}
			break ;

		/* -------------------------
		|		WM_RBUTTONDOWN
		+ ----------------------- */
		case WM_RBUTTONDOWN :
			g_cmap.CreateMapData( "map01" ) ;
			printf( "Created MapData\n" ) ;
			break ;

		/* -------------------------
		|		WM_PAINT
		+ ----------------------- */
		case WM_PAINT:
			//printf( "WM_PAINTイベントが発行されました\n" );
			hDC = BeginPaint( hWnd, &ps );

			BitBlt( hDC , 0 , 0 , WINDOW_W , WINDOW_H , g_hBackBuf , 0 , 0 , SRCCOPY ) ;

			// グリッド
			for ( int x = 0 ; x < 32 ; x++ ) {
				MoveToEx( hDC , (x * 32) , 0 , 0 ) ;
				LineTo( hDC , (x * 32) , WINDOW_H ) ;
			}
			for ( int y = 0 ; y < 32 ; y++ ) {
				MoveToEx( hDC , 0, (y * 32) , 0 ) ;
				LineTo( hDC , WINDOW_W , (y * 32) ) ;
			}

			EndPaint( hWnd, &ps );
			break;

		/* -------------------------
		|		WM_DESTROY
		+ ----------------------- */
		case WM_DESTROY:
			printf( "WM_DESTROYイベントが発行されました\n" );

			// --- タイマーの削除
			KillTimer( hWnd, 1 );

			// バッファの削除
			DeleteDC( g_hWorkBuf ) ;

			// --- アプリケーション終了を発行
			PostQuitMessage( 0 );
			break;

		/* -------------------------
		|		default文
		+ ----------------------- */
		default:
			return ( DefWindowProc( hWnd, message, wParam, lParam ) );
	}

	return 0;
}
