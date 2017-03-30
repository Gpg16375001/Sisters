/*
________________________________________________________________________________________________________________

	FILE : BitmapData.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		BitmapData クラスの実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include <windows.h>
#include <stdio.h>

#include "BitmapData.h"

// コンストラクタ
BitmapData::BitmapData( LPCTSTR arg_pStr , int arg_width , int arg_height )
{
	loadData( arg_pStr , arg_width , arg_height ) ;
}

BitmapData::BitmapData( )
{
	m_hBmp = NULL ;
	m_width = 0 ;
	m_height = 0 ;
}

// デストラクタ
BitmapData::~BitmapData( )
{
	// --- 使用されていたらオブジェクト破棄
	clearData( ) ; 
}

int BitmapData::clearData( )
{
	if( m_hBmp != NULL ) DeleteObject( m_hBmp ) ;

	return ( true ) ;
}

// --- イメージ読み込み
int BitmapData::loadData( LPCTSTR arg_pStr , int arg_width , int arg_height )
{
	// --- 使用されていたらオブジェクト破棄
	clearData( ) ;

	// --- データの読み込みと幅と高さをセット
	m_hBmp = (HBITMAP)LoadImage( NULL , arg_pStr , IMAGE_BITMAP , 0 , 0 , LR_LOADFROMFILE ) ;

	m_width = arg_width ;
	m_height = arg_height ;

	printf( "%S was loaded.\n" , arg_pStr ) ;

	return ( true ) ;
}

// --- ビットマップのハンドルのアクセッサ
HBITMAP BitmapData::getBmpData( )
{
	return ( m_hBmp ) ;
}

// --- ビットマップ幅のアクセッサ
int BitmapData::getBmpWidth( )
{
	return ( m_width ) ;
}

// --- ビットマップ高さのアクセッサ
int BitmapData::getBmpHeight( )
{
	return ( m_height ) ;
}


