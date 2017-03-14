/*
______________________________________________________________________________________________

	FILE : BackGround.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		BackGround �N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p

#include "Common.h"

// �R���X�g���N�^
BackGround::BackGround( )
{
	m_bmpNo = NULL ;
	m_x = 0 ;
	m_y = 0 ;
}

// �f�X�g���N�^
BackGround::~BackGround( )
{
}

// �`�悵���� X�� ���Z�b�g
int BackGround::setX( int arg_x )
{
	m_x = arg_x ;

	return ( true ) ;
}

// �`�悵���� Y�� ���Z�b�g
int BackGround::setY( int arg_y )
{
	m_y = arg_y ;

	return ( true ) ;
}

// �`�悵�����w�i�̔ԍ����Z�b�g
int BackGround::selectBmp( int arg_bmpNo )
{
	m_bmpNo = arg_bmpNo ;

	return ( true ) ;
}

// �o�b�N�O���E���h�`��
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


