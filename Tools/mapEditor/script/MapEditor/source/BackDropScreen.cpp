/*
______________________________________________________________________________________________

	FILE : BackDropScreen.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		BackDropScreen �N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p

#include "Common.h"

// �R���X�g���N�^
BackDropScreen::BackDropScreen( )
{
	m_bmpNo = NULL ;
}

// �f�X�g���N�^
BackDropScreen::~BackDropScreen( )
{
}

// �`�悵�����w�i�̔ԍ����Z�b�g
int BackDropScreen::selectBmp( int arg_bmpNo )
{
	m_bmpNo = arg_bmpNo ;

	return ( true ) ;
}

// �o�b�N�h���b�v�`��
int BackDropScreen::draw()
{
	SelectObject( g_hWorkBuf , g_bDataBGTable[ m_bmpNo ].getBmpData( ) ) ;

	BitBlt(
		g_hBackBuf ,
		0 ,
		0 ,
		g_bDataBGTable[ m_bmpNo ].getBmpWidth( ) ,
		g_bDataBGTable[ m_bmpNo ].getBmpHeight( ) ,
		g_hWorkBuf ,
		0 ,
		0 ,
		SRCCOPY
	) ;

	return ( true ) ;
}


