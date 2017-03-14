/*
	ウィンドウプロシージャ
*/

#include <windows.h>
#include <stdio.h>	// --- コンソール用

#include "Common.h"	// --- 全ファイルでの共通ヘッダー
#include "LoadMapData.h"

LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	HDC					hDC;			// ディスプレイデバイスコンテキスト
	PAINTSTRUCT			ps;				// 描画構造体
	static HBITMAP s_hBackBufBmp ;		// バックバッファ
	static OPENFILENAME	 ofn ;			// ファイルの保存
	char s[512] ;						// デバッグ用
	static 	int arrayX , arrayY ;
	static 	int index ;
	static	bool dragF = false ;

	g_lParam = lParam ;

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
			g_bDataSprTable[ 0 ].loadData( TEXT("source/cg/bg01.bmp") , 1000 , 1000 ) ;
			g_bDataSprTable[ 1 ].loadData( TEXT("source/cg/chips/all_grass.bmp") , 320 , 256 ) ;
			g_bDataSprTable[ 2 ].loadData( TEXT("source/cg/arrow.bmp") , 32 , 32 ) ;
//			g_bDataSprTable[ 2 ].loadData( TEXT("source/cg/.bmp") , 64 , 64 ) ;
//			g_bDataSprTable[ 3 ].loadData( TEXT("source/cg/.bmp") , 64 , 64 ) ;

			// チップのセット
			g_bDataCBGTable[ 0 ].loadData( TEXT("source/cg/chips/all_grass.bmp") , 320 , 256 ) ;
			
			// pen
			g_redPen = CreatePen( 0 , 1 , RGB(255 , 0 , 0) ) ;

			// brush
			g_brush[ 0 ] = CreateSolidBrush( RGB(153 , 153 , 153) ) ; // グレー
			g_brush[ 1 ] = CreateSolidBrush( RGB(100 , 100 , 100) ) ; // 黒いグレー

			break;

		/* -------------------------
		|		WM_TIMER
		+ ----------------------- */
		case WM_TIMER:
			//printf( "WM_TIMERイベントが発行されました\n" );
			g_key.update( );	// --- キー情報の更新

			// --------------
			if ( g_key.getKeyState( VK_F2 ) )
			{
				LoadMapData::ReLoad( ) ;
			}

			SetLoop( ) ;

			// 描画
			DrawLoop( ) ;

			// --------------

			// --- 再描画の要求
			InvalidateRect( hWnd, NULL, FALSE );
			break;

		/* -------------------------
		|		WM_LBUTTONDOWN
		+ ----------------------- */
		case WM_LBUTTONDOWN :
			// チップ変更
			actionLoop( ) ;

			// ドラッグフラグを立てる
			dragF = true ;

			// マウスのクリック座標の取得
			g_mouseX = LOWORD( lParam ) ;
			g_mouseY = HIWORD( lParam ) ;

			// クリック座標を配列座標に直す-
			arrayX = (g_mouseX - 32) / CHIP_W + g_scroll ;
			arrayY = (g_mouseY - 32) / CHIP_H ;

			// 配列座標を一次元座標に直す
			index = arrayY * MAP_X + arrayX ;

			if ( (index <= (MAP_X * MAP_Y))					// 要素数が配列のサイズ内で収まっていたら
					&& (cell(2) < g_mouseX) && (g_mouseX < cell(48))	// 横幅が座標内
					&& (cell(2) < g_mouseY) && (g_mouseY < cell(26))	// 
				)
			{
				// 配列内の値を判定
				if ( g_mapData01[ index ] == 0 ) {
					// ブロックを表す値を代入
					g_mapData01[ index ] = g_chip ;
					printf( "X = %4d , Y = %4d  Set Chip\n" , arrayX , arrayY ) ;

				} else {
					// ブロックを消す
					g_mapData01[ index ] = 0 ;
					printf( "X = %4d , Y = %4d  Delete Chip\n" , arrayX , arrayY ) ;
					dragF = false ;
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
			if ( (cell(2) < g_mouseX) && (g_mouseX < cell(48))	// 横幅が座標内
				&&(cell(2) < g_mouseY) && (g_mouseY < cell(26))	// 
				)
			{
			} else {
				dragF = false ;
			}

			// マウスのクリック座標の取得
			g_mouseX = LOWORD( lParam ) ;
			g_mouseY = HIWORD( lParam ) ;

			// クリック座標を配列座標に直す
			arrayX = (g_mouseX - 32) / CHIP_W + g_scroll ;
			arrayY = (g_mouseY - 32) / CHIP_H ;

			// 配列座標を一次元座標に直す
			index = arrayY * MAP_X + arrayX ;

			if ( dragF )
			{
				// 要素数が配列のサイズ内で収まっていたら
				if ( (index <= (MAP_X * MAP_Y))					// 要素数が配列のサイズ内で収まっていたら
						&& (cell(2) < g_mouseX) && (g_mouseX < cell(48))	// 横幅が座標内
						&& (cell(2) < g_mouseY) && (g_mouseY < cell(26))	// 
					)
				{
					// 配列内の値を判定
					if ( g_mapData01[ index ] == 0 ) {
						// ブロックを表す値を代入
						g_mapData01[ index ] = g_chip ;
						printf( "X = %4d , Y = %4d  Set Chip\n" , arrayX , arrayY ) ;
					}
				}

			} else if ( (g_mapData01[ index ] != 0) && (g_key.getKeyState(VK_SPACE)) ) {
				// ブロックを消す
				g_mapData01[ index ] = 0 ;
				printf( "X = %4d , Y = %4d  Delete Chip\n" , arrayX , arrayY ) ;
			}


			break ;

		/* -------------------------
		|		WM_RBUTTONDOWN
		+ ----------------------- */
		case WM_RBUTTONDOWN :
			funcFileSave( hWnd ) ;
			printf( "Created MapData\n" ) ;
			break ;

		/* -------------------------
		|		WM_KEYDOWN
		+ ----------------------- */
		case WM_KEYDOWN :
			break ;

		/* -------------------------
		|		WM_KEYUP
		+ ----------------------- */
		case WM_KEYUP :
			break ;

		/* -------------------------
		|		WM_PAINT
		+ ----------------------- */
		case WM_PAINT:
			//printf( "WM_PAINTイベントが発行されました\n" );
			hDC = BeginPaint( hWnd, &ps );

			BitBlt( hDC , 0 , 0 , WINDOW_W , WINDOW_H , g_hBackBuf , 0 , 0 , SRCCOPY ) ;

			EndPaint( hWnd, &ps );
			break;

		/* -------------------------
		|		WM_DESTROY
		+ ----------------------- */
		case WM_DESTROY:
			printf( "WM_DESTROYイベントが発行されました\n" );

			// オブジェクトの削除
			DeleteObject( g_redPen ) ;
			DeleteObject( g_brush ) ;

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




