/*
________________________________________________________________________________________________________________

	FILE : BitmapData.cpp

	________/ Explanation of file /___________________________________________________________

		BitmapData �N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>
#include <stdio.h>

#include "BitmapData.h"

/*/
/*	�f�X�g���N�^
/*/
BitmapData::~BitmapData( )
{
	// --- �g�p����Ă�����I�u�W�F�N�g�j��
	for ( int i = 0 ; i < MAX_BMP_IMAGES ; ++i )
	{
		clearData( i ) ; 
	}
}

/*/
/*	������
/*/
void BitmapData::Initialize( )
{
	// --- �g�p����Ă�����I�u�W�F�N�g�j��
	for ( int i = 0 ; i < MAX_BMP_IMAGES ; ++i )
	{
		clearData( i ) ; 
	}
}

/*/
/*	�摜�f�[�^�̃N���A
/*/
int BitmapData::clearData( int arg_bmpNo )
{
	if( bmpDataTable_[ arg_bmpNo ]._hBmp != NULL )
	{
		DeleteObject( bmpDataTable_[ arg_bmpNo ]._hBmp ) ;
	}

	return ( true ) ;
}

/*/
/*	�C���[�W�ǂݍ���
/*/
int BitmapData::loadData( int arg_bmpNo , LPCTSTR arg_pStr , int arg_width , int arg_height )
{
	// �g�p����Ă�����I�u�W�F�N�g�j��
	clearData( arg_bmpNo ) ;

	// �f�[�^�̓ǂݍ��݂ƕ��ƍ������Z�b�g
	bmpDataTable_[ arg_bmpNo ]._hBmp = (HBITMAP)LoadImage( NULL , arg_pStr , IMAGE_BITMAP , 0 , 0 , LR_LOADFROMFILE ) ;

	bmpDataTable_[ arg_bmpNo ]._width = arg_width ;
	bmpDataTable_[ arg_bmpNo ]._height = arg_height ;

	printf( "%S was loaded.\n" , arg_pStr ) ;

	return ( true ) ;
}

/*/
/*	�r�b�g�}�b�v�̃n���h���̃A�N�Z�b�T
/*/
HBITMAP BitmapData::getBmpData( int arg_bmpNo )
{
	return ( bmpDataTable_[ arg_bmpNo ]._hBmp ) ;
}

/*/
/*	�r�b�g�}�b�v���̃A�N�Z�b�T
/*/
int BitmapData::getBmpWidth( int arg_bmpNo )
{
	return ( bmpDataTable_[ arg_bmpNo ]._width ) ;
}

/*/
/*	�r�b�g�}�b�v�����̃A�N�Z�b�T
/*/
int BitmapData::getBmpHeight( int arg_bmpNo )
{
	return ( bmpDataTable_[ arg_bmpNo ]._height ) ;
}


