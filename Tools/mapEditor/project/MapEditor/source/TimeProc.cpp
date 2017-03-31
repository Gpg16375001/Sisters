/*
______________________________________________________________________________________________

	FILE : TimeProc.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		TimeProc クラスの実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/

#include <windows.h>
#include <stdio.h>	// --- コンソール用

#include "TimeProc.h"

// コンストラクタ
TimeProc::TimeProc( ) {
	timeBeginPeriod( 1 ) ;												// 時間取得の精度を上げる
}

// デストラクタ
TimeProc::~TimeProc( ) {
	timeEndPeriod( 1 ) ;												// 時間取得の精度を元に戻す
}

// 時間の取得
DWORD TimeProc::getTime( ) {
	return( timeGetTime( ) ) ;											// システムタイムを受け取る
}

// 測定開始
DWORD TimeProc::startTime( ) {
	m_sTime = timeGetTime( ) ;											// システムタイムを受け取る
	return( m_sTime ) ;
}

// 測定終了
DWORD TimeProc::endTime( ) {
	m_eTime = timeGetTime( ) ;											// システムタイムを受け取る
	m_pTime = m_eTime - m_sTime ;										// 経過時間
	return( m_pTime ) ;
}

// スリープ
int TimeProc::TheWorld( int arg_theWorldTime ) {
	Sleep( arg_theWorldTime ) ;											// スレッドを止める
	return( true ) ;
}


