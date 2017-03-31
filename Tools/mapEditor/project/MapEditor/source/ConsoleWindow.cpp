
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: ConsoleWindow.cpp
	NAME	: Teacher.K

+ ------ Explanation of file --------------------------------------------------------------------------
       
    ConsoleWindowクラスの実装部

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>	// --- コンソール用

#include "ConsoleWindow.h"

// --- コンストラクタ
ConsoleWindow::ConsoleWindow( )
{
	// --- 簡易デバッグ用にprintfを使えるようにする
	AllocConsole( );
	
	freopen_s( &m_fIn,  "CON", "r", stdin );     // --- 標準入力の割り当て
	freopen_s( &m_fOut, "CON", "w", stdout );    // --- 標準出力の割り当て

	printf( "It succeeded in starting of a console screen.\nA standard input/output can be used.\n\n" );
}

// --- デストラクタ
ConsoleWindow::~ConsoleWindow( )
{
	// --- コンソールの削除
	fclose( m_fIn );
	fclose( m_fIn );
	FreeConsole( );                
}
		
