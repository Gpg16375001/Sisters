/*
______________________________________________________________________________________________

	FILE : BackGround.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		BackGround クラスの実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/

#include <windows.h>
#include <stdio.h>	// --- コンソール用

#include "Common.h"

// コンストラクタ
BackGround::BackGround( )
{
	m_bmpNo = NULL ;
	m_x = 0 ;
	m_y = 0 ;
}

// デストラクタ
BackGround::~BackGround( )
{
}

// 描画したい X軸 をセット
int BackGround::setX( int arg_x )
{
	m_x = arg_x ;

	return ( true ) ;
}

// 描画したい Y軸 をセット
int BackGround::setY( int arg_y )
{
	m_y = arg_y ;

	return ( true ) ;
}

// 描画したい背景の番号をセット
int BackGround::selectBmp( int arg_bmpNo )
{
	m_bmpNo = arg_bmpNo ;

	return ( true ) ;
}

// バックグラウンド描画
int BackGround::draw()
{
	SelectObject( g_hWorkBuf , g_bDataBGTable[ m_bmpNo ].getBmpData( ) ) ;

	BitBlt(
		g_hBackBuf ,
		m_x ,
		m_y ,
		g_bDataBGTable[ m_bmpNo ].getBmpWidth( ) ,
		g_bDataBGTable[ m_bmpNo ].getBmpHeight( ) ,
		g_hWorkBuf ,
		0 ,
		0 ,
		SRCCOPY
	) ;

	return ( true ) ;
}


