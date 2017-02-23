/*
______________________________________________________________________________________________

	FILE	: KeyManager.cpp
	NAME	: Teacher.K

	________/ Explanation of file /___________________________________________________________
    
		KeyManagerクラスの実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/

#include <windows.h>
#include <stdio.h>

#include "KeyManager.h"


/*/
/*	デストラクタ
/*/
KeyManager::~KeyManager( )
{
	// 終了を出力
	printf( "Management of a keystroke is ended.\n" ) ;
}

/*/
/*	初期化
/*/
void KeyManager::Initialize( )
{
	// とりあえずデータ入れとく
	GetKeyboardState( m_bKeyTbl ) ;

	// 開始を出力
	printf( "Management of a keystroke is started.\n" ) ;

}

/*/
/*	キー情報の更新
/*/
int KeyManager::update( )
{
	// とりあえずデータ入れとく
	return( GetKeyboardState( m_bKeyTbl ) ) ;
}

/*/
/*	キー情報の取得
/*/
BYTE KeyManager::getKeyState( BYTE arg_keyCode )
{
	// 渡されたキー情報を返す
	return( m_bKeyTbl[ arg_keyCode ] & 0x80 ) ;
}


		
