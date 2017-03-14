/*
________________________________________________________________________________________________________________

	FILE : BitmapData.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		BitmapData �N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>
#include <stdio.h>

#include "BitmapData.h"

// �R���X�g���N�^
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

// �f�X�g���N�^
BitmapData::~BitmapData( )
{
	// --- �g�p����Ă�����I�u�W�F�N�g�j��
	clearData( ) ; 
}

int BitmapData::clearData( )
{
	if( m_hBmp != NULL ) DeleteObject( m_hBmp ) ;

	return ( true ) ;
}

// --- �C���[�W�ǂݍ���
int BitmapData::loadData( LPCTSTR arg_pStr , int arg_width , int arg_height )
{
	// --- �g�p����Ă�����I�u�W�F�N�g�j��
	clearData( ) ;

	// --- �f�[�^�̓ǂݍ��݂ƕ��ƍ������Z�b�g
	m_hBmp = (HBITMAP)LoadImage( NULL , arg_pStr , IMAGE_BITMAP , 0 , 0 , LR_LOADFROMFILE ) ;

	m_width = arg_width ;
	m_height = arg_height ;

	printf( "%S was loaded.\n" , arg_pStr ) ;

	return ( true ) ;
}

// --- �r�b�g�}�b�v�̃n���h���̃A�N�Z�b�T
HBITMAP BitmapData::getBmpData( )
{
	return ( m_hBmp ) ;
}

// --- �r�b�g�}�b�v���̃A�N�Z�b�T
int BitmapData::getBmpWidth( )
{
	return ( m_width ) ;
}

// --- �r�b�g�}�b�v�����̃A�N�Z�b�T
int BitmapData::getBmpHeight( )
{
	return ( m_height ) ;
}


